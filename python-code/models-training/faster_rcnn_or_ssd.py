import torch
from torchvision.models.detection import ssd300_vgg16, SSD300_VGG16_Weights, _utils, fasterrcnn_mobilenet_v3_large_fpn, FasterRCNN_MobileNet_V3_Large_FPN_Weights
from torch.utils.data import DataLoader
import time
from pascal_voc_dataset import PascalVOCDataset
from object_detection_evaluator import ObjectDetectionEvaluator
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
from torchvision.models.detection.ssd import SSDClassificationHead
import numpy as np
from early_stopping import EarlyStopping
import sys
import argparse
from torchvision.models.detection.ssd import SSDClassificationHead
import torchvision.models.detection._utils as _utils
from albumentations.pytorch import ToTensorV2
import albumentations as A
import cv2
import os
import psutil
from pynvml import nvmlInit, nvmlShutdown, nvmlDeviceGetHandleByIndex, nvmlDeviceGetUtilizationRates, nvmlDeviceGetMemoryInfo, nvmlDeviceGetTemperature, nvmlDeviceGetPowerUsage

class FasterRCNNOrSSD:
    def __init__(
        self, 
        num_classes=3, 
        epochs=10, 
        batch_size=8, 
        learning_rate=0.005, 
        model=None, 
        model_type="faster_rcnn"
    ):
        """
        Initialize the Faster R-CNN.
        """
        if model_type == "faster_rcnn":
            self.model = fasterrcnn_mobilenet_v3_large_fpn(
                weights=FasterRCNN_MobileNet_V3_Large_FPN_Weights.COCO_V1,
                min_size=640, 
                max_size=640
            )
            in_features = self.model.roi_heads.box_predictor.cls_score.in_features
            self.model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)
            self.save_model_path = "faster_rcnn_model.pt"
        elif model_type == "ssd":
            self.model = ssd300_vgg16(weights=SSD300_VGG16_Weights.COCO_V1)
            in_channels = _utils.retrieve_out_channels(self.model.backbone, (640, 640))
            # List containing number of anchors based on aspect ratios.
            num_anchors = self.model.anchor_generator.num_anchors_per_location()
            # The classification head.
            self.model.head.classification_head = SSDClassificationHead(
                in_channels=in_channels,
                num_anchors=num_anchors,
                num_classes=num_classes
            )
            # Image size for transforms.
            self.model.transform.min_size = (640,)
            self.model.transform.max_size = 640
            self.save_model_path = "ssd_model.pt"
        elif model_type == "loaded":
            self.model = model
        
        self.epochs = epochs
        self.batch_size = batch_size
        self.learning_rate = learning_rate
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.model.to(self.device)

        # Optimizer
        self.optimizer = torch.optim.SGD(
            self.model.parameters(), lr=self.learning_rate, momentum=0.937, weight_decay=0.001
        )
        
        # Scheduler: CosineAnnealingLR
        self.scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(self.optimizer, T_max=self.epochs - 3, eta_min=self.learning_rate * 0.01)

        # Evaluator for metrics calculation
        self.evaluator = ObjectDetectionEvaluator()
        self.early_stopping = EarlyStopping(patience=7, verbose=True)
     
    def train_and_validate(self, train_loader, valid_loader, class_mapping):
        """
        Train the model and validate it after each epoch.
        """
        self.model.train()
        start_time = time.time()

        best_metric_score = None
        best_val_metrics = None
        metrics_per_epoch = []
        for epoch in range(self.epochs):
            print(f"Epoch [{epoch + 1}/{self.epochs}]")
            train_loss = 0
            
            if epoch < 3:  # Warm-up phase
                warmup_lr = 0.00001 + (self.learning_rate - 0.00001) * (epoch / 3)
                for param_group in self.optimizer.param_groups:
                    param_group['lr'] = warmup_lr
                print(f"Epoch {epoch + 1}, Warm-Up Learning Rate: {warmup_lr:.6f}")
            elif epoch == 3:
                # Reset learning rate to original and activate scheduler
                for param_group in self.optimizer.param_groups:
                    param_group['lr'] = self.learning_rate
                print(f"Epoch {epoch + 1}, Learning Rate Reset to: {self.learning_rate:.6f}")
                
            for images, targets in train_loader:
                images = [img.to(self.device) for img in images]
                targets = [{k: v.to(self.device) for k, v in t.items()} for t in targets]
                
                self.optimizer.zero_grad()
                
                # Forward pass
                loss_dict = self.model(images, targets)
                losses = sum(loss for loss in loss_dict.values())
                train_loss += losses.item()

                # Backward pass
                losses.backward()
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
        Perform validation on the dataset and compute metrics per image, 
        averaging them across the dataset.
        """
        self.model.eval()
        val_loss = 0
        image_metrics = []  # To store metrics for each image

        with torch.no_grad():
            for images, targets in valid_loader:
                images = [img.to(self.device) for img in images]
                targets = [{k: v.to(self.device) for k, v in t.items()} for t in targets]

                outputs = self.model(images)

                image_metrics = self.evaluation_of_metrics_per_batch(
                    image_metrics=image_metrics,
                    outputs=outputs,
                    targets=targets,
                    class_mapping=class_mapping,
                    split="val"
                )

        average_metrics = self.evaluator.calculate_total_metrics(image_metrics, ["fire", "human", "animal"], "val_")
        # Print Results
        for key, value in average_metrics.items():
            print(f"{key}: {value:.4f}")
    
        # Calculate validation loss
        self.model.train()
        with torch.no_grad():
            for images, targets in valid_loader:
                images = [img.to(self.device) for img in images]
                targets = [{k: v.to(self.device) for k, v in t.items()} for t in targets]

                loss_dict = self.model(images, targets)
                val_loss += sum(loss.item() for loss in loss_dict.values())

        avg_val_loss = val_loss / len(valid_loader)

        return average_metrics, avg_val_loss

    def evaluate(self, test_loader_with_bs_8, test_loader_with_bs_1, split, class_mapping):
        """
        Evaluate the model on the given dataset and return metrics.
        """
        # Ensure the best model is loaded
        if not hasattr(self, "save_model_path") or not os.path.exists(self.save_model_path):
            raise ValueError("Best model file does not exist. Ensure training is completed and the best model is saved.")

        print(f"Loading the best model from {self.save_model_path} for evaluation...")
        self.model.load_state_dict(torch.load(self.save_model_path))
        self.model.to(self.device)
        self.model.eval()
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
            for images, targets in test_loader_with_bs_1:
                images = [img.to(self.device) for img in images]
                start_time = time.time()
                _ = self.model(images)  # Perform inference only
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
            for images, targets in test_loader_with_bs_8:
                images = [img.to(self.device) for img in images]
                targets = [{k: v.to(self.device) for k, v in t.items()} for t in targets]

                outputs = self.model(images)  # Perform inference

                image_metrics = self.evaluation_of_metrics_per_batch(
                    image_metrics=image_metrics,
                    outputs=outputs,
                    targets=targets,
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
            outputs (list): Model outputs containing predicted boxes, scores, and labels.

        Returns:
            tuple: Updated predictions and ground_truths lists.
        """
        for target, output in zip(targets, outputs):
            predictions.append({
                "boxes":  output["boxes"].detach().cpu().numpy(),
                "scores": output["scores"].detach().cpu().numpy(),
                "labels": output["labels"].detach().cpu().numpy(),
            })
            ground_truths.append({
                "boxes": target["boxes"].detach().cpu().numpy(),
                "labels": target["labels"].detach().cpu().numpy(),
            })
        
        return predictions, ground_truths

if __name__ == "__main__":
    # Create an argument parser
    parser = argparse.ArgumentParser(
        description="Script for running SSD or Faster R-CNN model."
    )

    # Add the required argument
    parser.add_argument(
        "model_type",
        choices=["ssd", "faster_rcnn"],
        help="Specify the model type: 'ssd' or 'faster_rcnn'."
    )

    # Parse the arguments
    args = parser.parse_args()

    # Validate the argument (if choices are defined, this is handled automatically)
    if args.model_type not in ["ssd", "faster_rcnn"]:
        print(f"Error: Invalid model type '{args.model_type}'. Choose 'ssd' or 'faster_rcnn'.")
        sys.exit(1)

    # Print the selected model
    print(f"Running the script with model type: {args.model_type}")
    
    # Dataset paths
    train_root = "datasets/dataset-thermal-aug/train"
    valid_root = "datasets/dataset-thermal-aug/valid"
    test_root = "datasets/dataset-thermal-aug/test"

    # Class mapping
    class_mapping = {1: "fire", 2: "human", 3: "animal"}

    # Create transforms
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

    # Create datasets
    train_dataset = PascalVOCDataset(root_dir=train_root, transforms=get_transforms())
    valid_dataset = PascalVOCDataset(root_dir=valid_root, transforms=get_transforms())
    test_dataset = PascalVOCDataset(root_dir=test_root, transforms=get_transforms())

    # Create data loaders
    train_loader = DataLoader(train_dataset, batch_size=16, shuffle=True, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    valid_loader = DataLoader(valid_dataset, batch_size=16, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    test_loader_with_bs_1 = DataLoader(test_dataset, batch_size=1, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    # Change the batch size to be the same with valid and train datasets
    test_loader_with_bs_8 = DataLoader(test_dataset, batch_size=16, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=16, pin_memory=True)
    # Initialize the Faster R-CNN for 2 classes or 3 classes (fire and smoke or human and animal) + background
    trainer = FasterRCNNOrSSD(num_classes=4, epochs=30, batch_size=16, learning_rate=0.0001, model_type=args.model_type)

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
        experiment_name="FasterRCNN_Experiment_Thermal_Aug_1" if args.model_type == "faster_rcnn" else "SSD_Experiment_Thermal_Aug_1"
    )
