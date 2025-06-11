from ultralytics import YOLO
import time
from mlflow_logger import MLflowLogger
from yolov8_tensorRT import YOLOv8TensorRT
import glob
import os
import pandas as pd
import yaml
import torch
import numpy as np
import argparse
import psutil
from pynvml import nvmlInit, nvmlShutdown, nvmlDeviceGetHandleByIndex, nvmlDeviceGetUtilizationRates, nvmlDeviceGetMemoryInfo, nvmlDeviceGetTemperature, nvmlDeviceGetPowerUsage

class YOLOv8:
    def __init__(self, model_path='yolov8m.pt', epochs=10, batch_size=8, img_size=640, mode = "train"):
        """
        Initialize the YOLOv8 model with the provided parameters.
        """
        self.model = YOLO(model_path, task="detect")  # Load the pretrained YOLOv8 model
        if mode == "train":
            self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
            self.model.to(self.device)
            self.model.overrides['amp'] = False
        self.epochs = epochs
        self.batch_size = batch_size
        self.img_size = img_size
        self.best_model_path = model_path  # Path to the best model during training

    def train(self, data_yaml_path):
        """
        Train the YOLOv8 model and return the training results, including the time taken.
        """
        start_time = time.time()  # Start the timer
        print(f"Training model for {self.epochs} epochs...")
        self.model.train(
            data = data_yaml_path, 
            epochs = self.epochs, 
            imgsz = self.img_size, 
            batch = self.batch_size,
            patience = 10,
            device = 'cuda', 
            workers = 16,
            close_mosaic = 0,
            nms = True,
            mosaic = 0.0,
            conf = 0.25,
            auto_augment = None,
            val = True,
            cos_lr = True,
            optimizer = "sgd",
            lr0 = 0.01,
            warmup_bias_lr = 0.1,
            weight_decay = 0.0005
        )
        end_time = time.time()  # End the timer
        training_time = end_time - start_time  # Calculate the total training time
        
        # Save the best model after training
        self.best_model_path = "runs/detect/train82/weights/best.pt"
        
        return training_time

    def get_num_images(self, split="val"):
        """
        Counts the number of images in the dataset split (train/val/test).
        """    
        # Count images
        image_files = glob.glob(os.path.join("datasets", "thermal_dataset", split, "images", "*.*"))
        return image_files, len(image_files)

    def evaluate(self, data_yaml_path, split="val", mode = "train"):
        """
        Evaluate the YOLOv8 model on the provided dataset and return the results, including the time taken.
        """
        # Load the best model
        print(f"Loading best model from {self.best_model_path}...")
        self.model = YOLO(self.best_model_path, task="detect")
        if mode == "train":
            self.model.to(self.device)
            self.model.overrides['amp'] = False
        
        start_time = time.time()  # Start the timer
        print(f"Evaluating model on {split} dataset...")
        results = self.model.val(
            data = data_yaml_path, 
            imgsz = self.img_size, 
            split = split,
            batch = self.batch_size,
            nms = True,
            save_json = True,
            workers = 16,
            conf = 0.25
        )
        end_time = time.time()  # End the timer
        evaluation_time = end_time - start_time  # Calculate the time taken for evaluation
        
        return results, evaluation_time
    
    def calculate_inference_fps(self):
        """
        Calculate inference FPS using YOLOv8.
        
        Returns:
            float: Inference FPS (frames per second).
        """

        images, num_images = self.get_num_images(split="test")
        # Create batches of images
        batch_size = 1
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
        
        # Process images in batches
        for i in range(0, num_images, batch_size):
            batch_images = images[i:i+batch_size]  # Get the next batch of images

            # Measure the time for prediction on the batch
            results = self.model.predict(batch_images, device="cuda", batch=batch_size, workers=16, imgsz=self.img_size)
            
            # Calculate the inference time for the batch
            print(f"Inference time for 1 image:", results[0].speed["inference"], "ms")
            inference_times.append(results[0].speed["inference"])

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
        
        # Calculate FPS (frames per second)
        avg_inference_time = np.mean(inference_times)
        inference_fps = (batch_size * 1000) / avg_inference_time if avg_inference_time > 0 else 0
        
        return inference_fps, cpu_usage, total_ram_usage, gpu_utilization, total_gpu_mem_usage, total_gpu_power_usage, gpu_temp
        
    def extract_metrics(self, val_results, test_results):
        """
        Extract all metrics from the training, validation, and test results 
        and return as a single flat dictionary.
        """
        metrics = {}

        csv_path = "runs/detect/train82/results.csv"
        df = pd.read_csv(csv_path)
        
        train_loss = (df["train/box_loss"] + df["train/cls_loss"] + df["train/dfl_loss"]).to_list()
        val_loss = (df["val/box_loss"] + df["val/cls_loss"] + df["val/dfl_loss"]).to_list()
        precision_per_epoch = df["metrics/precision(B)"].to_numpy()
        recall_per_epoch = df["metrics/recall(B)"].to_numpy()
        f1_score_per_epoch = []
        for precision, recall in zip(precision_per_epoch, recall_per_epoch):
            if precision == 0 or recall == 0:
                f1_score_per_epoch.append(0.0)  # F1 score is 0 if either precision or recall is 0
            else:
                f1 = (2 * precision * recall) / (precision + recall)
                f1_score_per_epoch.append(f1)
        precision_per_epoch = precision_per_epoch.tolist()
        recall_per_epoch = recall_per_epoch.tolist()
        map_50_per_epoch = df["metrics/mAP50(B)"].to_list()
        map_75_per_epoch = df["metrics/mAP75(B)"].to_list()
        map_50_95_per_epoch = df["metrics/mAP50-95(B)"].to_list()
        
        metrics_per_epoch = {
            "epochs": len(precision_per_epoch),
            "train_loss": train_loss,
            "val_loss": val_loss,
            "precision_per_epoch": precision_per_epoch,
            "recall_per_epoch": recall_per_epoch,
            "f1_score_per_epoch": f1_score_per_epoch,
            "mAP-0.5_per_epoch": map_50_per_epoch,
            "mAP-0.75_per_epoch": map_75_per_epoch,
            "mAP-0.5:0.95_per_epoch": map_50_95_per_epoch
        }

        precision = val_results.box.p.mean()
        recall = val_results.box.r.mean()
        # Extract metrics for validation stage
        metrics.update({
            "val_precision": val_results.box.p.mean(),
            "val_recall": val_results.box.r.mean(),
            "val_mAP-0.5": val_results.box.map50.mean(),
            "val_mAP-0.75": val_results.box.map75.mean(),
            "val_mAP-0.5:0.95": val_results.box.maps.mean(),
            "val_f1_score": (2 * precision * recall) / (precision + recall)
        })

        precision = test_results.box.p.mean()
        recall = test_results.box.r.mean()
        # Extract metrics for test stage
        metrics.update({
            "test_precision": test_results.box.p.mean(),
            "test_recall": test_results.box.r.mean(),
            "test_mAP-0.5": test_results.box.map50.mean(),
            "test_mAP-0.75": test_results.box.map75.mean(),
            "test_mAP-0.5:0.95": test_results.box.maps.mean(),
            "test_f1_score": (2 * precision * recall) / (precision + recall)
        })

        with open("data.yaml", 'r') as file:
            data = yaml.safe_load(file)  # Load YAML file safely

        class_names = data.get('names', [])  # Extract class names
        # Extract class-specific metrics for all stages
        for class_id, _ in enumerate(test_results.names):
            class_metrics = {
                f"{class_names[class_id]}_val_precision": val_results.box.p[class_id],
                f"{class_names[class_id]}_val_recall": val_results.box.r[class_id],
                f"{class_names[class_id]}_val_f1": val_results.box.f1[class_id],
                f"{class_names[class_id]}_val_AP-0.5": val_results.box.ap50[class_id],
                f"{class_names[class_id]}_val_AP-0.75": val_results.box.ap75[class_id],
                f"{class_names[class_id]}_val_AP-0.5:0.95": val_results.box.ap[class_id],
                f"{class_names[class_id]}_test_precision": test_results.box.p[class_id],
                f"{class_names[class_id]}_test_recall": test_results.box.r[class_id],
                f"{class_names[class_id]}_test_f1": test_results.box.f1[class_id],
                f"{class_names[class_id]}_test_AP-0.5": test_results.box.ap50[class_id],
                f"{class_names[class_id]}_test_AP-0.75": test_results.box.ap75[class_id],
                f"{class_names[class_id]}_test_AP-0.5:0.95": test_results.box.ap[class_id],
            }
            metrics.update(class_metrics)

        return metrics, metrics_per_epoch
    
    def log_metrics_to_mlflow(
        self, 
        val_results, 
        test_results,
        training_time, 
        evaluation_time, 
        inference_fps,
        cpu_usage,
        total_ram_usage,
        gpu_utilization,
        total_gpu_mem_usage,
        total_gpu_power_usage,
        gpu_temp,
        mode = "train"
    ):
        """
        Log the metrics to MLflow.
        """
        with MLflowLogger(experiment_name="YOLOv8_Experiment_Rgb_Aug") as logger:
            time.sleep(15)
            # Log training and evaluation times
            metrics = {
                "evaluation_time": evaluation_time,
                "inference_fps": inference_fps,
                "cpu_usage": cpu_usage,
                "total_ram_usage": total_ram_usage,
                "gpu_utilization": gpu_utilization,
                "total_gpu_mem_usage": total_gpu_mem_usage,
                "total_gpu_power_usage": total_gpu_power_usage,
                "gpu_temp": gpu_temp
            }

            if training_time is not None:
                metrics["training_time"] = training_time

            logger.log_metrics(metrics)
        
            # Extract and log metrics for different stages (train, val, test)
            metrics, metrics_per_epoch = self.extract_metrics(val_results, test_results)
            
            if mode == "train":
                # Plot and log metrics per epoch
                logger.plot_and_log_artifacts(metrics_per_epoch=metrics_per_epoch)
            
            logger.log_metrics(metrics)
            if mode == "train":
                logger.log_metrics_per_epoch(metrics_per_epoch)
            
            logger.log_model(self.best_model_path)
            
            logger.end_run()
            
        print("Metrics logged to MLflow.")
            
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Train or Validate YOLOv8 Model")
    parser.add_argument("--mode", type=str, required=True, choices=["train", "val"], help="Choose between 'train' or 'val' mode.")
    parser.add_argument("--fp16_int8", type=str, required=False, choices=["fp16", "int8"], default="fp16", help="Optional: Choose 'fp16' or 'int8' for validation.")
    args = parser.parse_args()
    mode = args.mode
    fp16_int8 = args.fp16_int8
    
    if mode == "train":
        # Initialize YOLOv8 model with hyperparameters
        yolov8_model = YOLOv8(model_path='mlruns/841130081327109506/28b81e6261444ac5b629711d0d8c0abb/artifacts/model/best.pt', epochs=40, batch_size=8, img_size=640, mode=mode)

        # Train the model
        training_time = yolov8_model.train('data.yaml')
       
    elif mode == "val":
        if fp16_int8 == "fp16":
            # Initialize YOLOv8 TensorRT model with hyperparameters
            yolov8_model = YOLOv8TensorRT(model_path='runs/detect/train82/weights/best.pt', img_size=(512,640))
            
            yolov8_model.export_fp16_trt()
            
            yolov8_model = YOLOv8(model_path='runs/detect/train82/weights/best.pt', batch_size=16, img_size=640, mode=mode)
        elif fp16_int8 == "int8":
            # Initialize YOLOv8 TensorRT model with hyperparameters
            yolov8_model = YOLOv8TensorRT(model_path='runs/detect/train64/weights/best.pt', img_size=640)
            
            yolov8_model.export_int8_trt(calibration_data='data.yaml')
            
            yolov8_model = YOLOv8(model_path='runs/detect/train64/weights/best.engine', batch_size=8, img_size=640, mode=mode)
        
    # Evaluate the model in val dataset
    val_results, _ = yolov8_model.evaluate('data.yaml', split="val", mode=mode)
        
    # Evaluate the model in test dataset
    test_results, evaluation_time = yolov8_model.evaluate('data.yaml', split="test", mode=mode)
    
    inference_fps, cpu_usage, total_ram_usage, gpu_utilization, total_gpu_mem_usage, total_gpu_power_usage, gpu_temp = yolov8_model.calculate_inference_fps()

    # Log the metrics to MLflow
    yolov8_model.log_metrics_to_mlflow(
        val_results=val_results, 
        test_results=test_results,
        training_time=training_time if mode == "train" else None, 
        evaluation_time=evaluation_time, 
        inference_fps=inference_fps,
        cpu_usage=cpu_usage,
        total_ram_usage=total_ram_usage,
        gpu_utilization=gpu_utilization,
        total_gpu_mem_usage=total_gpu_mem_usage,
        total_gpu_power_usage=total_gpu_power_usage, 
        gpu_temp=gpu_temp
    )