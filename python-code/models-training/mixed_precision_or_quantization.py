import torch
import argparse
from torch.utils.data import DataLoader
from torchvision import transforms as T
from object_detection_evaluator import ObjectDetectionEvaluator
from coco_dataset import COCODataset
from pascal_voc_dataset import PascalVOCDataset
from faster_rcnn_or_ssd import FasterRCNNOrSSD
from efficient_det import EfficientDetTrainer
from torchvision.models.detection import  _utils, fasterrcnn_mobilenet_v3_large_fpn, ssd300_vgg16
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
from torchvision.models.detection.ssd import SSDClassificationHead
import torch_tensorrt

# # Transforms
# def get_transforms():
#     return T.Compose([
#         T.Resize((640, 640)),  # Resize all images to 640x640
#         T.ToTensor()  # Convert image to tensor and scale pixel values to [0, 1]
#     ])
        
# # Dataset loader function
# def get_dataloader(dataset_name, test_root="dataset_pascal/test", annotation_file_test="dataset/test/annotations_test.json"):
#     test_dataset = None
#     test_dataloader_with_bs_1 = None
#     test_dataloader_with_bs_8 = None
#     if dataset_name == "pascal_voc":
#         test_dataset = PascalVOCDataset(root_dir=test_root, transforms=get_transforms())
#         test_dataloader_with_bs_1 = DataLoader(test_dataset, batch_size=1, shuffle=False, collate_fn=lambda x: tuple(zip(*x)))
#         test_dataloader_with_bs_8 = DataLoader(test_dataset, batch_size=8, shuffle=False, collate_fn=lambda x: tuple(zip(*x)))
#     elif dataset_name == "coco":
#         test_dataset = COCODataset(test_root, annotation_file_test, transforms=get_transforms())
#         test_dataloader_with_bs_1 = DataLoader(test_dataset, batch_size=1, shuffle=False, collate_fn=test_dataset.custom_collate_fn)
#         test_dataloader_with_bs_8 = DataLoader(test_dataset, batch_size=8, shuffle=False, collate_fn=test_dataset.custom_collate_fn)
#     else:
#         raise ValueError("Unsupported dataset")

#     return test_dataloader_with_bs_1, test_dataloader_with_bs_8

# # Model initialization function
# def get_model(model_path=None, model_name="ssd"):
#     if model_path:
#         print(f"Loading model from {model_path}")
#         model = ssd300_vgg16(weights=None)
#         in_channels = _utils.retrieve_out_channels(model.backbone, (640, 640))
#         # List containing number of anchors based on aspect ratios.
#         num_anchors = model.anchor_generator.num_anchors_per_location()
#         # The classification head.
#         model.head.classification_head = SSDClassificationHead(
#             in_channels=in_channels,
#             num_anchors=num_anchors,
#             num_classes=3
#         )
#         # Image size for transforms.
#         model.transform.min_size = (640,)
#         model.transform.max_size = 640
#         model.score_thresh = 0.2
#         model.nms_thresh = 0.5
#         model_weights = torch.load(model_path, weights_only=True)
#         model.load_state_dict(model_weights, strict=False)
#         if model_name == "ssd" or model_name == "faster_rcnn":
#             model_class = FasterRCNNOrSSD(model=model, model_type="loaded")
#         else:
#             model_class = EfficientDetTrainer(model=model, model_type="loaded")
#     else:
#         raise ValueError("Unsupported model")
#     return model, model_class

# # Optimization wrapper
# def optimize_model(model, mode):
#     if mode == "amp":
#         return model  # AMP is applied during evaluation using autocast
#     elif mode == "half":
#         return model.half()
#     elif mode == "int8":
#         model = torch.quantization.quantize_dynamic(
#             model, {torch.nn.Linear}, dtype=torch.qint8
#         )
#         return model
#     else:
#         raise ValueError("Unsupported mode. Use 'amp', 'half', or 'int8'.")

# # Main function
# def main():
#     parser = argparse.ArgumentParser(description="Model evaluation with optimization modes")
#     parser.add_argument("--model", choices=["ssd", "faster_rcnn", "effdet"], required=True, help="Model type to evaluate")
#     parser.add_argument("--dataset", choices=["pascal_voc", "coco"], required=True, help="Dataset type to use")
#     parser.add_argument("--mode", choices=["amp", "half", "int8"], required=True, help="Optimization mode")
#     parser.add_argument("--model_path", type=str, help="Path to the saved model file")
#     args = parser.parse_args()

#     device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

#     # Class mapping
#     class_mapping = {1: "fire", 2: "smoke"}

#     # Load model
#     num_classes = 0
#     if args.model == "ssd" or args.model == "faster_rcnn":
#         num_classes = len(class_mapping) + 1  # Including background
#     else:
#         num_classes = len(class_mapping)
#     model, model_class = get_model(args.model_path, args.model)
#     model.to(device)
#     model_class.model = model

#     # Load dataset
#     test_dataloader_with_bs_1, test_dataloader_with_bs_8 = get_dataloader(
#         dataset_name=args.dataset,
#         test_root="dataset_pascal/test/images" if args.dataset == "coco" else "dataset_pascal/test",
#         annotation_file_test="dataset_pascal/test/annotations_test.json" if args.dataset == "coco" else None
#     )

#     # Optimize model
#     optimized_model = optimize_model(model, args.mode)
#     model_class.model = optimized_model

#     if args.mode == "amp":
#         test_metrics, evaluation_time, inference_fps = model_class.evaluate(
#             test_loader_with_bs_8=test_dataloader_with_bs_8,
#             test_loader_with_bs_1=test_dataloader_with_bs_1,
#             split="test",
#             class_mapping=class_mapping,
#             method=torch.autocast(device_type="cuda", dtype=torch.float16)
#         )
#     else:
#         test_metrics, evaluation_time, inference_fps = model_class.evaluate(
#             test_loader_with_bs_8=test_dataloader_with_bs_8,
#             test_loader_with_bs_1=test_dataloader_with_bs_1,
#             split="test",
#             class_mapping=class_mapping,
#             method=torch.no_grad()
#         )
    
#     # Construct the experiment name
#     experiment_name_map = {
#         "ssd": "SSD_Experiment",
#         "faster_rcnn": "FasterRCNN_Experiment",
#         "effdet": "EfficientDet_Experiment"
#     }

#     optimization_suffix_map = {
#         "amp": "_AMP",
#         "half": "_HALF",
#         "int8": "_INT8"
#     }

#     experiment_name = f"{experiment_name_map[args.model]}{optimization_suffix_map[args.mode]}"

#     ObjectDetectionEvaluator.log_metrics_to_mlflow(
#         metrics_per_epoch=None, 
#         val_metrics=None, 
#         test_metrics=test_metrics, 
#         training_time=None, 
#         evaluation_time=evaluation_time, 
#         inference_fps=inference_fps,
#         experiment_name=experiment_name
#     )

# if __name__ == "__main__":
#     main()
