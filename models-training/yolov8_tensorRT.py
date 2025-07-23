from ultralytics import YOLO
import torch

class YOLOv8TensorRT:
    def __init__(self, model_path, device="cuda", img_size=(640,640)):
        """
        Initialize YOLOv8 model for export and evaluation.
        """
        self.model = YOLO(model_path, task="detect")
        self.device = torch.device(device if torch.cuda.is_available() else "cpu")
        self.model.to(self.device)
        self.model.overrides['amp'] = False
        self.img_size = img_size

    def export_fp16_trt(self):
        """
        Export YOLOv8 model to FP16 TensorRT engine.
        """
        print("Exporting model to TensorRT FP16 engine...")
        save_path = self.model.export(format="engine", device=self.device, imgsz=self.img_size, batch=1, half=True)
        print(f"TensorRT FP16 model exported to {save_path}")
        return save_path

    def export_int8_trt(self, calibration_data):
        """
        Export YOLOv8 model to INT8 TensorRT engine with calibration.
        """
        print("Exporting model to TensorRT INT8 engine with calibration...")
        save_path = self.model.export(format="engine", device=self.device, imgsz=self.img_size, int8=True, batch=1, data=calibration_data)
        print(f"TensorRT INT8 model exported to {save_path}")
        return save_path