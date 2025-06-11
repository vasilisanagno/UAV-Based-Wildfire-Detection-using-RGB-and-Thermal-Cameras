import argparse
from ultralytics import YOLO
from jtop import jtop
import cv2
import time
import glob
import psutil
import os
import torch
import threading

class JetsonYOLOv8Evaluator:
    def __init__(self, model_paths, image_folder, img_size=640):
        if isinstance(model_paths, str):
            model_paths = [model_paths]
        self.models = [YOLO(p) for p in model_paths]
        self.image_folder = image_folder
        self.img_size = img_size
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

        for model in self.models:
            model.to(self.device)
            model.overrides['amp'] = False

    def run_single_model(self, model_idx, image_paths, results_dict):
        inference_times = []
        jtop_metrics = []

        with jtop() as jetson:
            for frame_count, path in enumerate(image_paths, 1):
                image = cv2.imread(path)
                if image is None:
                    continue

                start = time.time()
                _ = self.models[model_idx].predict(image, device=self.device, imgsz=self.img_size, verbose=False)
                end = time.time()

                frame_time = (end - start) * 1000  # ms
                inference_times.append(frame_time)

                if jetson.ok():
                    stats = {
                        "cpu": psutil.cpu_percent(interval=None),
                        "ram": jetson.memory['RAM']['used'] // 1024,
                        "gpu": jetson.gpu['gpu']['status']['load'],
                        "temp": jetson.temperature['gpu']['temp'],
                        "power": jetson.power['tot']['power'] / 1000
                    }
                    jtop_metrics.append(stats)
                    print(f"[Model {model_idx + 1} Frame {frame_count}] Inference time: {frame_time:.2f} ms | "
                          f"GPU: {stats['gpu']}% | CPU: {stats['cpu']}% | RAM: {stats['ram']}MB")

        results_dict[model_idx] = {
            "inference_times": inference_times,
            "jtop_metrics": jtop_metrics,
            "frames_processed": len(inference_times)
        }

    def run_sequential(self):
        image_paths = sorted(glob.glob(os.path.join(self.image_folder, "*.*")))
        num_images = len(image_paths)
        print(f"Found {num_images} images for inference.")

        with jtop() as jetson:
            time.sleep(1)  # stabilize jtop
            # BEFORE inference metrics
            if jetson.ok():
                cpu_before = psutil.cpu_percent()
                ram_before = jetson.memory['RAM']['used'] // 1024
                gpu_before = jetson.gpu['gpu']['status']['load']
                temp_before = jetson.temperature['gpu']['temp']
                power_before = jetson.power['tot']['power'] / 1000
                print("\n📊 System state BEFORE inference:")
                print(f"CPU: {cpu_before}%, RAM: {ram_before}MB, GPU: {gpu_before}%, TEMP: {temp_before}°C, POWER: {power_before}W")

            results = {}
            start_total = time.time()
            self.run_single_model(0, image_paths, results)
            total_time = time.time() - start_total

            # AFTER inference metrics
            if jetson.ok():
                cpu_after = psutil.cpu_percent(interval=None)
                ram_after = jetson.memory['RAM']['used'] // 1024
                gpu_after = jetson.gpu['gpu']['status']['load']
                temp_after = jetson.temperature['gpu']['temp']
                power_after = jetson.power['tot']['power'] / 1000

                print("\n📊 System state AFTER inference:")
                print(f"CPU: {cpu_after}%, RAM: {ram_after}MB, GPU: {gpu_after}%, TEMP: {temp_after}°C, POWER: {power_after}W")

                print("\n📉 Δ Resource Usage Changes:")
                print(f"Δ CPU: {cpu_after - cpu_before:+.2f}%")
                print(f"Δ RAM: {ram_after - ram_before:+.2f} MB")
                print(f"Δ GPU Load: {gpu_after - gpu_before:+.2f}%")
                print(f"Δ Temp: {temp_after - temp_before:+.2f}°C")
                print(f"Δ Power: {power_after - power_before:+.2f}W")

            times = results.get(0, {}).get("inference_times", [])
            frames = results.get(0, {}).get("frames_processed", 0)
            avg_inf_time = sum(times) / len(times) if times else 0
            fps = 1000 / avg_inf_time if avg_inf_time > 0 else 0

            print(f"\n✅ Model inference complete on {frames} frames")
            print(f"📸 Average Inference Time: {avg_inf_time:.2f} ms")
            print(f"🎥 Average FPS: {fps:.2f}")

    def run_parallel(self):
        image_paths = sorted(glob.glob(os.path.join(self.image_folder, "*.*")))
        num_images = len(image_paths)
        print(f"Found {num_images} images for inference.")

        images_model1 = image_paths
        images_model2 = image_paths

        with jtop() as jetson:
            time.sleep(1)  # stabilize jtop

            if jetson.ok():
                cpu_before = psutil.cpu_percent()
                ram_before = jetson.memory['RAM']['used'] // 1024
                gpu_before = jetson.gpu['gpu']['status']['load']
                temp_before = jetson.temperature['gpu']['temp']
                power_before = jetson.power['tot']['power'] / 1000
                print("\n📊 System state BEFORE inference:")
                print(f"CPU: {cpu_before}%, RAM: {ram_before}MB, GPU: {gpu_before}%, TEMP: {temp_before}°C, POWER: {power_before}W")

            results = {}

            t1 = threading.Thread(target=self.run_single_model, args=(0, images_model1, results))
            t2 = threading.Thread(target=self.run_single_model, args=(1, images_model2, results))

            start_total = time.time()
            t1.start()
            t2.start()
            t1.join()
            t2.join()
            total_time = time.time() - start_total

            if jetson.ok():
                cpu_after = psutil.cpu_percent(interval=None)
                ram_after = jetson.memory['RAM']['used'] // 1024
                gpu_after = jetson.gpu['gpu']['status']['load']
                temp_after = jetson.temperature['gpu']['temp']
                power_after = jetson.power['tot']['power'] / 1000

                print("\n📊 System state AFTER inference:")
                print(f"CPU: {cpu_after}%, RAM: {ram_after}MB, GPU: {gpu_after}%, TEMP: {temp_after}°C, POWER: {power_after}W")

                print("\n📉 Δ Resource Usage Changes:")
                print(f"Δ CPU: {cpu_after - cpu_before:+.2f}%")
                print(f"Δ RAM: {ram_after - ram_before:+.2f} MB")
                print(f"Δ GPU Load: {gpu_after - gpu_before:+.2f}%")
                print(f"Δ Temp: {temp_after - temp_before:+.2f}°C")
                print(f"Δ Power: {power_after - power_before:+.2f}W")

            total_fps = 0
            for idx in [0, 1]:
                times = results.get(idx, {}).get("inference_times", [])
                frames = results.get(idx, {}).get("frames_processed", 0)
                avg_inf_time = sum(times) / len(times) if times else 0
                fps = 1000 / avg_inf_time if avg_inf_time > 0 else 0
                total_fps = total_fps + fps
                print(f"\n✅ Model {idx + 1} inference complete on {frames} frames")
                print(f"📸 Average Inference Time: {avg_inf_time:.2f} ms")
                print(f"🎥 Average FPS: {fps:.2f}")

            avg_total_fps = total_fps / 2
            print(f"\n🎯 Total system FPS (both models in parallel): {avg_total_fps:.2f}")

    def run(self, parallel=False):
        if parallel:
            self.run_parallel()
        else:
            self.run_sequential()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="YOLOv8 Jetson Inference Evaluator")
    parser.add_argument('--parallel', type=str, default="false",
                        help="Run two models in parallel if true, else single model. (true/false)")

    args = parser.parse_args()
    parallel = args.parallel.lower() == "true"

    if parallel:
        MODEL_PATHS = ["rgb_model.pt", "rgb_model.pt"]
    else:
        MODEL_PATHS = "rgb_model.pt"  # Single model path

    IMAGE_FOLDER = "valid-rgb"

    evaluator = JetsonYOLOv8Evaluator(MODEL_PATHS, IMAGE_FOLDER)
    evaluator.run(parallel=parallel)
