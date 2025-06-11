import torch
from torch.utils.data import DataLoader
from effdet import create_model
from object_detection_evaluator import ObjectDetectionEvaluator
from coco_dataset import COCODataset
from torchvision import transforms as T
import time
import numpy as np
from torchvision.ops import nms
from early_stopping import EarlyStopping
import albumentations as A
from albumentations.pytorch import ToTensorV2
import cv2
import gc
import psutil
from pynvml import nvmlInit, nvmlShutdown, nvmlDeviceGetHandleByIndex, nvmlDeviceGetUtilizationRates, nvmlDeviceGetMemoryInfo, nvmlDeviceGetTemperature, nvmlDeviceGetPowerUsage

class EfficientDetTrainer:
    def __init__(
        self,
        num_classes,
        model_name="tf_efficientdet_d1",
        epochs=5,
        batch_size=8,
        learning_rate=0.0001,
        save_model_path="efficientdet_model.pt",
        nms_threshold=0.5,
        model=None,
        model_type="default"
    ):
        """
        Initialize the EfficientDet model for training.
        """
        if model_type == "loaded":
            self.model = model
        elif model_type == "default":
            self.image_size = 640
            self.num_classes = num_classes
            self.model = create_model(
                model_name=model_name,
                pretrained=True,
                num_classes=self.num_classes,
                image_size=(self.image_size, self.image_size),
                bench_task="train",  # Automatically applies DetBenchTrain
                bench_labeler=True,
                jit_loss=True,
                soft_nms=False
            )

            self.epochs = epochs
            self.batch_size = batch_size
            self.learning_rate = learning_rate
            self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
            self.model.to(self.device)

            # Optimizer
            self.optimizer = torch.optim.SGD(
                self.model.parameters(), lr=self.learning_rate, momentum=0.937, weight_decay=0.0005
            )

            # Scheduler: CosineAnnealingLR
            self.scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(self.optimizer, T_max=self.epochs - 3, eta_min=self.learning_rate * 0.1)

            # Evaluator
            self.evaluator = ObjectDetectionEvaluator()
            self.save_model_path = save_model_path

            # NMS and Confidence thresholds
            self.nms_threshold = nms_threshold
            self.early_stopping = EarlyStopping(patience=7, verbose=True)

    def train_and_validate(self, train_loader, valid_loader, class_mapping):
        """
        Train the model and validate it after each epoch.
        """
        start_time = time.time()

        best_metric_score = None
        best_val_metrics = None
        metrics_per_epoch = []
        for epoch in range(self.epochs):
            print(f"Epoch [{epoch + 1}/{self.epochs}]")
            self.model.train()
            train_loss = 0

            if epoch < 3:  # Warm-up phase
                warmup_lr = 0.0001 + (self.learning_rate - 0.0001) * (epoch / 3)
                for param_group in self.optimizer.param_groups:
                    param_group['lr'] = warmup_lr
                print(f"Epoch {epoch + 1}, Warm-Up Learning Rate: {warmup_lr:.6f}")
            elif epoch == 3:
                # Reset learning rate to original and activate scheduler
                for param_group in self.optimizer.param_groups:
                    param_group['lr'] = self.learning_rate
                print(f"Epoch {epoch + 1}, Learning Rate Reset to: {self.learning_rate:.6f}")
                
            for images, original_targets in train_loader:
                images = torch.stack([img.to(self.device) for img in images]).float()  # Shape: [batch_size, C, H, W]
                targets = self.creation_of_targets(
                    images=images,
                    original_targets=original_targets
                )

                self.optimizer.zero_grad()

                # Forward pass
                loss_dict = self.model(images, targets)
                loss = loss_dict["loss"]
                train_loss += loss

                # Backward pass
                loss.backward()
                self.optimizer.step()
            
            # Update the learning rate using the scheduler after warm-up
            if epoch >= 3:
                self.scheduler.step()
                print(f"Updated Learning Rate by Scheduler: {self.optimizer.param_groups[0]['lr']}")

            avg_train_loss = train_loss / len(train_loader)
            print(f"Training Loss (Epoch {epoch + 1}): {avg_train_loss:.4f}")

            # Validate after each epoch
            val_metrics, avg_val_loss = self.validate(valid_loader, class_mapping)
            val_metrics["val_loss"] = avg_val_loss  # Include validation loss in metrics
            print(f"Validation Loss (Epoch {epoch + 1}): {avg_val_loss:.4f}")
            metrics_per_epoch.append({
                "epoch": epoch + 1,
                "train_loss": avg_train_loss,
                **val_metrics
            })

            # Save the best model based on the custom metric
            map50 = val_metrics.get("val_mAP-0.5", 0)
            map50_95 = val_metrics.get("val_mAP-0.5:0.95", 0)
            metric_score = 0.1 * map50 + 0.9 * map50_95
            print(f"Custom Metric Score (Epoch {epoch + 1}): {metric_score:.4f}")

            if best_metric_score is None or metric_score > best_metric_score:
                best_metric_score = metric_score
                best_val_metrics = val_metrics  # Save validation metrics for the best model
                torch.save(self.model.state_dict(), self.save_model_path)
                print(f"Best model saved with metric score: {best_metric_score:.4f}")

            self.early_stopping(avg_val_loss, self.model)
            if self.early_stopping.early_stop:
                print("Stopping training early!")
                break

        end_time = time.time()
        training_time = end_time - start_time

        return metrics_per_epoch, best_val_metrics, training_time, epoch+1

    def validate(self, valid_loader, class_mapping):
        """
        Validate the model and compute metrics.
        """
        self.model.eval()
        val_loss = 0
        image_metrics = []

        with torch.no_grad():
            for images, original_targets in valid_loader:
                images = torch.stack([img.to(self.device) for img in images]).float()
                targets = self.creation_of_targets(
                    images=images,
                    original_targets=original_targets
                )

                outputs = self.model(images, targets)
                val_loss += outputs["loss"]

                targets_for_metrics = [{k: v.to(self.device) for k, v in t.items()} for t in original_targets]
                image_metrics = self.evaluation_of_metrics_per_batch(
                    image_metrics=image_metrics,
                    outputs=outputs["detections"],
                    targets=targets_for_metrics,
                    class_mapping=class_mapping,
                    split="val"
                )
        
        average_metrics = self.evaluator.calculate_total_metrics(image_metrics, ["fire", "human", "animal"], "val_")
        # Print Results
        for key, value in average_metrics.items():
            print(f"{key}: {value:.4f}")

        avg_val_loss = val_loss / len(valid_loader)

        return average_metrics, avg_val_loss

    def evaluate(self, test_loader_with_bs_8, test_loader_with_bs_1, split, class_mapping):
        """
        Evaluate the model on the test set.
        """
        predict_model = self.create_predict_model()
        image_metrics = []
        inference_times = []
        
        # Initialize NVIDIA Management Library (NVML) for GPU monitoring
        nvmlInit()

        # Get GPU Handle (Assuming Single GPU, Index 0)
        gpu_handle = nvmlDeviceGetHandleByIndex(0)

        # Get Memory Before Inference
        ram_usage_before = psutil.virtual_memory().used / (1024 ** 3)  # Convert to GB
        cpu_usage_before = psutil.cpu_percent(interval=None)

        # GPU Memory Before Inference
        gpu_mem_before = nvmlDeviceGetMemoryInfo(gpu_handle).used / (1024 ** 3)  # Convert to GB
        gpu_power_before = nvmlDeviceGetPowerUsage(gpu_handle) / 1000  # Convert mW to W
        gpu_temp_before = nvmlDeviceGetTemperature(gpu_handle, 0)  # °C
        
        with torch.no_grad():
            for images, original_targets in test_loader_with_bs_1:
                images = torch.stack([img.to(self.device) for img in images]).float()
                start_time = time.time()
                _ = predict_model(images)  # Perform inference only
                end_time = time.time()
                print("Inference time for 1 image:", (end_time - start_time)*1000, "ms")

                inference_times.append(end_time - start_time)

        inference_fps = 1 / np.mean(inference_times) if np.mean(inference_times) > 0 else 0
        
        # Get CPU & Memory After Inference
        cpu_usage_after = psutil.cpu_percent(interval=None)
        ram_usage_after = psutil.virtual_memory().used / (1024 ** 3)  # Convert to GB

        cpu_usage = cpu_usage_after - cpu_usage_before
        # GPU Utilization & Memory After Inference
        gpu_utilization = nvmlDeviceGetUtilizationRates(gpu_handle).gpu
        gpu_mem_after = nvmlDeviceGetMemoryInfo(gpu_handle).used / (1024 ** 3)  # Convert to GB
        gpu_power_after = nvmlDeviceGetPowerUsage(gpu_handle) / 1000  # Convert mW to W
        gpu_temp_after = nvmlDeviceGetTemperature(gpu_handle, 0)  # °C
        
        total_ram_usage = ram_usage_after - ram_usage_before
        total_gpu_mem_usage = gpu_mem_after - gpu_mem_before
        total_gpu_power_usage = gpu_power_after - gpu_power_before
        gpu_temp = gpu_temp_after - gpu_temp_before
        
        nvmlShutdown()  # Shutdown NVML

        start_time_evaluation = time.time()
        with torch.no_grad():
            for images, original_targets in test_loader_with_bs_8:
                images = torch.stack([img.to(self.device) for img in images]).float()

                outputs = predict_model(images)

                targets_for_metrics = [{k: v.to(self.device) for k, v in t.items()} for t in original_targets]
                image_metrics = self.evaluation_of_metrics_per_batch(
                    image_metrics=image_metrics,
                    outputs=outputs,
                    targets=targets_for_metrics,
                    class_mapping=class_mapping,
                    split=split
                )
        end_time_evaluation = time.time()

        average_metrics = self.evaluator.calculate_total_metrics(image_metrics, ["fire", "human", "animal"], "test_")
        # Print Results
        for key, value in average_metrics.items():
            print(f"{key}: {value:.4f}")

        evaluation_time = end_time_evaluation - start_time_evaluation

        return average_metrics, evaluation_time, inference_fps, cpu_usage, total_ram_usage, gpu_utilization, total_gpu_mem_usage, total_gpu_power_usage, gpu_temp

    def create_predict_model(self):
        """
        Create the DetBenchPredict model loading the saved training model.
        """
        predict_model = create_model(
            model_name = 'tf_efficientdet_d1',
            pretrained = False,
            num_classes = self.num_classes,
            image_size = (self.image_size,self.image_size),
            bench_task = "predict"
        )

        state_dict = torch.load(self.save_model_path, weights_only=True)
        predict_model.load_state_dict(state_dict)
        predict_model = predict_model.to(self.device)
        predict_model.eval()

        return predict_model

    def evaluation_of_metrics_per_batch(self, image_metrics, outputs, targets, class_mapping, split):
        """
        Calculate the metrics per batch of images.
        """
        # Process predictions and ground truths for individual images
        for _, (output, target) in enumerate(zip(outputs, targets)):
            predictions, ground_truths = self.calculation_pred_gtruth(
                predictions=[],
                ground_truths=[],
                targets=[target],
                outputs=[output]
            )

            # Evaluate metrics for this image
            metrics = self.evaluator.evaluate(
                predictions=predictions,
                ground_truths=ground_truths,
                num_classes=len(class_mapping),
                split=split,
                class_mapping=class_mapping
            )
            image_metrics.append(metrics)

        return image_metrics

    def calculation_pred_gtruth(self, predictions, ground_truths, targets, outputs):
        """
        Calculate the predictions and the ground truths and append them to the respective lists.

        Args:
            predictions (list): List to store prediction dictionaries.
            ground_truths (list): List to store ground truth dictionaries.
            targets (dict): Dictionary containing target ground truth data (bounding boxes and class labels).
            outputs (tensor): Model outputs containing predicted boxes, scores, and labels.

        Returns:
            tuple: Updated predictions and ground_truths lists.
        """
        # Combine bounding boxes and class labels from all levels
        for target, output in zip(targets, outputs):
            output[:, [1,0,3,2]] = output[:, [0,1,2,3]] # convert to xyxy
            boxes = output[:,:4]  # First 4 columns are bbox coordinates
            scores = output[:, 4]  # 5th column is confidence score
            predicted_labels = output[:, 5]  # 6th column is label

            # Apply nms to remove unnecessary bounding boxes
            keep_indices = nms(boxes, scores, iou_threshold=self.nms_threshold)
            pred_boxes = boxes[keep_indices]
            pred_scores = scores[keep_indices]
            predicted_labels = predicted_labels[keep_indices]
            predictions.append({
                "boxes": pred_boxes.detach().cpu().numpy(),
                "scores": pred_scores.detach().cpu().numpy(),
                "labels": predicted_labels.detach().cpu().numpy()
            })

            ground_truths.append({
                "boxes": target["bbox"].detach().cpu().numpy(),
                "labels": target["cls"].detach().cpu().numpy(),
            })

        return predictions, ground_truths

    def creation_of_targets(self, images, original_targets):
        # Prepare raw bounding boxes and class labels
        raw_boxes = [t['bbox'].to(self.device) for t in original_targets]
        raw_labels = [t['cls'].to(self.device) for t in original_targets]
        targets = {}
        targets["bbox"] = raw_boxes
        targets["cls"] = raw_labels

        # # Add img_scale and img_size
        targets['img_scale'] = torch.ones(len(images), dtype=torch.float32, device=self.device).float()
        targets['img_size'] = torch.tensor(
            [[self.image_size, self.image_size] for _ in range(len(images))], dtype=torch.float32, device=self.device
        ).float()

        return targets

# Main Training Script
if __name__ == "__main__":
    # Dataset paths
    train_root = "datasets/dataset-thermal-aug/train/images"
    valid_root = "datasets/dataset-thermal-aug/valid/images"
    test_root = "datasets/dataset-thermal-aug/test/images"
    annotation_file_train = "datasets/dataset-thermal-aug/train/annotations_train.json"
    annotation_file_valid = "datasets/dataset-thermal-aug/valid/annotations_valid.json"
    annotation_file_test = "datasets/dataset-thermal-aug/test/annotations_test.json"

    # Class mapping
    class_mapping = {1: "fire", 2: "human", 3: "animal"}

    # Transforms
    def get_transforms():
        return A.Compose(
        [
            A.LongestMaxSize(max_size=640),
            A.PadIfNeeded(min_height=640, min_width=640, border_mode=cv2.BORDER_CONSTANT),
            A.Normalize(normalization="min_max_per_channel"),
            ToTensorV2()
        ],
        A.BboxParams(format="pascal_voc", label_fields=["labels"], clip=True)
    )
    from pascal_voc_dataset import PascalVOCDataset
    # Dataset paths
    train_root = "datasets/dataset-thermal-aug/train"
    valid_root = "datasets/dataset-thermal-aug/valid"
    test_root = "datasets/dataset-thermal-aug/test"
    # Datasets and DataLoaders
    train_dataset = PascalVOCDataset(train_root, transforms=get_transforms())
    valid_dataset = PascalVOCDataset(valid_root, transforms=get_transforms())
    test_dataset = PascalVOCDataset(test_root, transforms=get_transforms())

    train_loader = DataLoader(train_dataset, batch_size=16, shuffle=True, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    valid_loader = DataLoader(valid_dataset, batch_size=16, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    test_loader_with_bs_1 = DataLoader(test_dataset, batch_size=1, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    # Change the batch size to be the same with valid and train datasets
    test_loader_with_bs_8 = DataLoader(test_dataset, batch_size=16, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    # Initialize EfficientDet
    trainer = EfficientDetTrainer(num_classes=3, model_name="tf_efficientdet_d1", epochs=30, batch_size=16, learning_rate=0.001)

    # Train and validate the model
    print("Starting training...")
    metrics_per_epoch_list, best_val_metrics, training_time, epochs = trainer.train_and_validate(train_loader, valid_loader, class_mapping)
    print(f"Training completed in {training_time:.2f} seconds")

    # Process val metrics to separate the metrics per epoch with the final val metrics
    metrics_per_epoch, final_val_metrics = ObjectDetectionEvaluator.process_metrics(
        epochs=epochs,
        metrics_per_epoch_list=metrics_per_epoch_list,
        best_val_metrics=best_val_metrics
    )

    # Test the model
    print("Starting testing...")
    test_metrics, evaluation_time, inference_fps, cpu_usage, total_ram_usage, gpu_utilization, total_gpu_mem_usage, total_gpu_power_usage, gpu_temp = trainer.evaluate(
        test_loader_with_bs_8=test_loader_with_bs_8,
        test_loader_with_bs_1=test_loader_with_bs_1,
        split="test",
        class_mapping=class_mapping
    )

    # Log metrics to MLflow
    ObjectDetectionEvaluator.log_metrics_to_mlflow(
        metrics_per_epoch=metrics_per_epoch,
        val_metrics=final_val_metrics,
        test_metrics=test_metrics,
        training_time=training_time,
        evaluation_time=evaluation_time,
        inference_fps=inference_fps,
        cpu_usage=cpu_usage,
        total_ram_usage=total_ram_usage,
        gpu_utilization=gpu_utilization,
        total_gpu_mem_usage=total_gpu_mem_usage,
        total_gpu_power_usage=total_gpu_power_usage,
        gpu_temp=gpu_temp,
        save_model_path=trainer.save_model_path,
        experiment_name="EfficientDet_Experiment_Thermal_Aug_1"
    )
