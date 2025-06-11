from torchmetrics.detection.mean_ap import MeanAveragePrecision
import numpy as np
import time
from mlflow_logger import MLflowLogger
import torch

class ObjectDetectionEvaluator:
    def __init__(self, iou_threshold=0.5, iou_thresholds=None):
        """
        Initialize the evaluator with single or multiple IoU thresholds.
        """
        self.iou_threshold = iou_threshold
        self.iou_thresholds = np.linspace(0.5, 0.95, 10) if iou_thresholds is None else iou_thresholds
        self.map_metric = MeanAveragePrecision(iou_thresholds=iou_thresholds)

    def compute_iou(self, box1, box2):
        """
        Compute Intersection over Union (IoU) between two boxes.
        """
        x1 = max(box1[0], box2[0])
        y1 = max(box1[1], box2[1])
        x2 = min(box1[2], box2[2])
        y2 = min(box1[3], box2[3])

        intersection = max(0, x2 - x1) * max(0, y2 - y1)
        area1 = (box1[2] - box1[0]) * (box1[3] - box1[1])
        area2 = (box2[2] - box2[0]) * (box2[3] - box2[1])

        union = area1 + area2 - intersection
        return intersection / union if union > 0 else 0

    def evaluate(
        self, 
        predictions, 
        ground_truths, 
        num_classes, 
        split="test", 
        class_mapping=None
    ):
        """
        Evaluate Precision, Recall, F1 score, AP@0.5 and mAP@0.5:0.95 per class and overall.

        Args:
            predictions (list of dict): List of model predictions.
                Each dict contains "boxes", "scores", "labels".
            ground_truths (list of dict): List of ground truth data.
                Each dict contains "boxes", "labels".
            num_classes (int): Total number of classes.
            split (str): Dataset split ("val" or "test").
            class_mapping (dict): A mapping of class IDs to class names.
            final_epoch (boolean): True or False if it is the final epoch or not.

        Returns:
            dict: Metrics per class and overall.
        """
        prefix = f"{split}_"  # Add dataset split prefix (e.g., "val_" or "test_")
        metrics = {}

        for cls in range(1, num_classes + 1):
            class_name = class_mapping.get(cls, f"class_{cls}") if class_mapping else f"class_{cls}"
            tp, fp, fn = 0, 0, 0

            # Aggregate predictions and ground truths for this class
            aggregated_preds = {"boxes": [], "scores": [], "labels": []}
            aggregated_gts = {"boxes": [], "labels": []}

            for preds, gts in zip(predictions, ground_truths):
                pred_boxes = preds["boxes"][preds["labels"] == cls]
                pred_scores = preds["scores"][preds["labels"] == cls]
                gt_boxes = gts["boxes"][gts["labels"] == cls]
                
                # Ensure all data is in tensor format
                pred_boxes = torch.tensor(pred_boxes) if isinstance(pred_boxes, np.ndarray) else pred_boxes
                pred_scores = torch.tensor(pred_scores) if isinstance(pred_scores, np.ndarray) else pred_scores
                gt_boxes = torch.tensor(gt_boxes) if isinstance(gt_boxes, np.ndarray) else gt_boxes
    
                # Append to aggregated predictions and ground truths
                aggregated_preds["boxes"].append(pred_boxes)
                aggregated_preds["scores"].append(pred_scores)
                aggregated_preds["labels"].append(torch.full((len(pred_boxes),), cls, dtype=torch.int64))

                aggregated_gts["boxes"].append(gt_boxes)
                aggregated_gts["labels"].append(torch.full((len(gt_boxes),), cls, dtype=torch.int64))
                
                # Match predictions to ground truths for IoU-based calculations
                matched_gt = set()
                processed_predictions = []  # Track predictions after filtering low-confidence scores
                
                for pred_box, score in zip(pred_boxes, pred_scores):
                    if score < 0.3:
                        continue  # Skip low-confidence predictions
                    
                    processed_predictions.append(pred_box)
                    best_iou = 0
                    best_gt_idx = -1

                    for gt_idx, gt_box in enumerate(gt_boxes):
                        if gt_idx in matched_gt:
                            continue
                        iou = self.compute_iou(pred_box, gt_box)
                        if iou > best_iou:
                            best_iou = iou
                            best_gt_idx = gt_idx

                    if best_iou >= self.iou_threshold:
                        matched_gt.add(best_gt_idx)

                tp += len(matched_gt)
                fn += len(gt_boxes) - len(matched_gt)
                fp += len(processed_predictions) - len(matched_gt)

            # Convert aggregated data to tensors
            aggregated_preds["boxes"] = torch.cat(aggregated_preds["boxes"], dim=0)
            aggregated_preds["scores"] = torch.cat(aggregated_preds["scores"], dim=0)
            aggregated_preds["labels"] = torch.cat(aggregated_preds["labels"], dim=0).to(dtype=torch.int64)

            aggregated_gts["boxes"] = torch.cat(aggregated_gts["boxes"], dim=0)
            aggregated_gts["labels"] = torch.cat(aggregated_gts["labels"], dim=0).to(dtype=torch.int64)

            # Update PyTorch metrics for mAP calculation
            self.map_metric.reset()
            self.map_metric.update([aggregated_preds], [aggregated_gts])
            map_results = self.map_metric.compute()
            
            metrics[f"{class_name}_{prefix}tp"] = tp
            metrics[f"{class_name}_{prefix}fp"] = fp
            metrics[f"{class_name}_{prefix}fn"] = fn
            if map_results["map_50"].item() != -1:
                metrics[f"{class_name}_{prefix}AP-0.5"] = map_results["map_50"].item()
            if map_results["map_75"].item() != -1:
                metrics[f"{class_name}_{prefix}AP-0.75"] = map_results["map_75"].item()
            if map_results["map"].item() != -1:    
                metrics[f"{class_name}_{prefix}AP-0.5:0.95"] = map_results["map"].item()
            if map_results["map_small"].item() != -1:
                metrics[f"{class_name}_{prefix}AP-small"] = map_results["map_small"].item()
            if map_results["map_medium"].item() != -1:
                metrics[f"{class_name}_{prefix}AP-medium"] = map_results["map_medium"].item()
            if map_results["map_large"].item() != -1:
                metrics[f"{class_name}_{prefix}AP-large"] = map_results["map_large"].item()
                
        return metrics
    
    def calculate_total_metrics(self, image_metrics, classes, prefix=""):
        """
        Aggregates image-level metrics to compute per-class and overall precision, recall, F1, and mAP metrics.

        Args:
            image_metrics (list): List of dictionaries containing per-image metrics.
            classes (list): List of class names (e.g., ["fire", "human", "animal"]).
            prefix (str): Prefix for metric keys (e.g., "val_").

        Returns:
            dict: Aggregated per-class and overall metrics.
        """
        # Initialize containers for metrics
        total_tp = {class_name: 0 for class_name in classes}
        total_fp = {class_name: 0 for class_name in classes}
        total_fn = {class_name: 0 for class_name in classes}
        all_ap50 = {class_name: [] for class_name in classes}
        all_ap75 = {class_name: [] for class_name in classes}
        all_map_50_95 = {class_name: [] for class_name in classes}
        all_ap_small = {class_name: [] for class_name in classes}
        all_ap_medium = {class_name: [] for class_name in classes}
        all_ap_large = {class_name: [] for class_name in classes}
        final_metrics = {}

        # Aggregate TP, FP, FN, and AP values from image-level metrics
        for metrics in image_metrics:
            for class_name in classes:
                total_tp[class_name] += metrics.get(f"{class_name}_{prefix}tp", 0)
                total_fp[class_name] += metrics.get(f"{class_name}_{prefix}fp", 0)
                total_fn[class_name] += metrics.get(f"{class_name}_{prefix}fn", 0)
                if f"{class_name}_{prefix}AP-0.5" in metrics:
                    all_ap50[class_name].append(metrics[f"{class_name}_{prefix}AP-0.5"])
                if f"{class_name}_{prefix}AP-0.75" in metrics:
                    all_ap75[class_name].append(metrics[f"{class_name}_{prefix}AP-0.75"])
                if f"{class_name}_{prefix}AP-0.5:0.95" in metrics:
                    all_map_50_95[class_name].append(metrics[f"{class_name}_{prefix}AP-0.5:0.95"])
                if f"{class_name}_{prefix}AP-small" in metrics:
                    all_ap_small[class_name].append(metrics[f"{class_name}_{prefix}AP-small"])
                if f"{class_name}_{prefix}AP-medium" in metrics:
                    all_ap_medium[class_name].append(metrics[f"{class_name}_{prefix}AP-medium"])
                if f"{class_name}_{prefix}AP-large" in metrics:
                    all_ap_large[class_name].append(metrics[f"{class_name}_{prefix}AP-large"])

        # Calculate per-class metrics
        class_metrics = {}
        for class_name in classes:
            tp = total_tp[class_name]
            fp = total_fp[class_name]
            fn = total_fn[class_name]

            # Precision, Recall, F1
            precision = tp / (tp + fp) if (tp + fp) > 0.0 else 0.0
            recall = tp / (tp + fn) if (tp + fn) > 0.0 else 0.0
            f1 = 2 * (precision * recall) / (precision + recall) if (precision + recall) > 0.0 else 0.0

            # Average AP metrics
            ap50 = np.mean(all_ap50[class_name]) if all_ap50[class_name] else 0
            ap75 = np.mean(all_ap75[class_name]) if all_ap75[class_name] else 0
            ap_50_95 = np.mean(all_map_50_95[class_name]) if all_map_50_95[class_name] else 0
            ap_small = np.mean(all_ap_small[class_name]) if all_ap_small[class_name] else 0
            ap_medium = np.mean(all_ap_medium[class_name]) if all_ap_medium[class_name] else 0
            ap_large = np.mean(all_ap_large[class_name]) if all_ap_large[class_name] else 0

            # Store per-class metrics
            class_metrics[class_name] = {
                "precision": precision,
                "recall": recall,
                "f1": f1,
                "AP-0.5": ap50,
                "AP-0.75": ap75,
                "AP-0.5:0.95": ap_50_95,
                "AP-small": ap_small,
                "AP-medium": ap_medium,
                "AP-large": ap_large,
            }
            final_metrics.update({
                f"{class_name}_{prefix}precision": precision,
                f"{class_name}_{prefix}recall": recall,
                f"{class_name}_{prefix}f1": f1,
                f"{class_name}_{prefix}AP-0.5": ap50,
                f"{class_name}_{prefix}AP-0.75": ap75,
                f"{class_name}_{prefix}AP-0.5:0.95": ap_50_95,
                f"{class_name}_{prefix}AP-small": ap_small,
                f"{class_name}_{prefix}AP-medium": ap_medium,
                f"{class_name}_{prefix}AP-large": ap_large
            })
            
            
        # Compute overall metrics as averages of per-class metrics
        overall_precision = np.mean([class_metrics[c]["precision"] for c in classes])
        overall_recall = np.mean([class_metrics[c]["recall"] for c in classes])
        overall_f1 = 2 * (overall_precision * overall_recall) / (overall_precision + overall_recall) if (overall_precision + overall_recall) > 0.0 else 0.0
        overall_map50 = np.mean([class_metrics[c]["AP-0.5"] for c in classes])
        overall_map75 = np.mean([class_metrics[c]["AP-0.75"] for c in classes])
        overall_map_50_95 = np.mean([class_metrics[c]["AP-0.5:0.95"] for c in classes])
        overall_map_small = np.mean([class_metrics[c]["AP-small"] for c in classes])
        overall_map_medium = np.mean([class_metrics[c]["AP-medium"] for c in classes])
        overall_map_large = np.mean([class_metrics[c]["AP-large"] for c in classes])

        # Store overall metrics
        final_metrics.update({
            f"{prefix}precision": overall_precision,
            f"{prefix}recall": overall_recall,
            f"{prefix}f1": overall_f1,
            f"{prefix}mAP-0.5": overall_map50,
            f"{prefix}mAP-0.75": overall_map75,
            f"{prefix}mAP-0.5:0.95": overall_map_50_95,
            f"{prefix}mAP-small": overall_map_small,
            f"{prefix}mAP-medium": overall_map_medium,
            f"{prefix}mAP-large": overall_map_large,
        })

        return final_metrics
    
    @staticmethod
    def process_metrics(epochs, metrics_per_epoch_list, best_val_metrics):
        """
        Processes a list of metrics dictionaries to generate epoch-wise metrics and final metrics.

        Args:
            metrics_per_epoch_list (list): List of dictionaries containing metrics for each epoch.
            best_val_metrics (dict): Dictionary that contains metrics for the best model during training.

        Returns:
            tuple: A tuple containing:
                - metrics_per_epoch (dict): A dictionary of lists with metrics for each epoch.
                - final_metrics (dict): A dictionary with the last epoch's metrics and per-class metrics.
        """
        # Initialize dictionaries
        metrics_per_epoch = {
            "epochs": epochs,
            "train_loss": [],
            "val_loss": [],
            "precision_per_epoch": [],
            "recall_per_epoch": [],
            "f1_score_per_epoch": [],
            "mAP-0.5_per_epoch": [],
            "mAP-0.75_per_epoch": [],
            "mAP-0.5:0.95_per_epoch": []
        }
        final_val_metrics = {}

        # Process the list
        for entry in metrics_per_epoch_list:
            # Add epoch-level metrics to the lists
            metrics_per_epoch["train_loss"].append(entry["train_loss"])
            metrics_per_epoch["val_loss"].append(entry["val_loss"])
            metrics_per_epoch["precision_per_epoch"].append(entry["val_precision"])
            metrics_per_epoch["recall_per_epoch"].append(entry["val_recall"])
            metrics_per_epoch["f1_score_per_epoch"].append(entry["val_f1"])
            metrics_per_epoch["mAP-0.5_per_epoch"].append(entry["val_mAP-0.5"])
            metrics_per_epoch["mAP-0.75_per_epoch"].append(entry["val_mAP-0.75"])
            metrics_per_epoch["mAP-0.5:0.95_per_epoch"].append(entry["val_mAP-0.5:0.95"])

        # General metrics from the last epoch
        final_val_metrics = {
            "val_precision": best_val_metrics["val_precision"],
            "val_recall": best_val_metrics["val_recall"],
            "val_f1_score": best_val_metrics["val_f1"],
            "val_mAP-0.5": best_val_metrics["val_mAP-0.5"],
            "val_mAP-0.75": best_val_metrics["val_mAP-0.75"],
            "val_mAP-0.5:0.95": best_val_metrics["val_mAP-0.5:0.95"],
            "val_mAP-small": best_val_metrics["val_mAP-small"],
            "val_mAP-medium": best_val_metrics["val_mAP-medium"],
            "val_mAP-large": best_val_metrics["val_mAP-large"]
        }

        # Dynamically extract class names from keys in the last epoch
        class_names = set()
        for key in best_val_metrics.keys():
            if key.endswith("_val_precision"):
                class_name = key.split("_val_")[0]
                class_names.add(class_name)
            
        # Dynamically add per-class metrics
        for class_name in class_names:
            for key, value in best_val_metrics.items():
                if key.startswith(f"{class_name}_val_"):
                    final_val_metrics[key] = value

        return metrics_per_epoch, final_val_metrics
    
    @staticmethod
    def log_metrics_to_mlflow(
        metrics_per_epoch, 
        val_metrics, 
        test_metrics, 
        training_time, 
        evaluation_time, 
        inference_fps,
        cpu_usage,
        total_ram_usage,
        gpu_utilization,
        total_gpu_mem_usage,
        total_gpu_power_usage,
        gpu_temp,
        save_model_path, 
        experiment_name
    ):
        """
        Log training, validation, and test metrics to MLflow.
        """
        with MLflowLogger(experiment_name=experiment_name) as logger:
            time.sleep(15)
            # Log training time
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
            
            # Log per-epoch metrics
            logger.log_metrics_per_epoch(metrics_per_epoch)
            
            logger.plot_and_log_artifacts(metrics_per_epoch=metrics_per_epoch)

            # Log val/test metrics
            logger.log_metrics(val_metrics)
            logger.log_metrics(test_metrics)
            
            logger.log_model(save_model_path)
            
            logger.end_run()
            
        print("Metrics logged to MLflow.") 
