# UAV-Based Wildfire Detection using RGB and Thermal Cameras

## Overview

This repository accompanies the diploma thesis **"UAV-Based Wildfire Detection using RGB and Thermal Cameras"** conducted at the University of Thessaly, Department of Electrical and Computer Engineering, under the supervision of Prof. Christos Antonopoulos.

The project presents the design, development, and evaluation of a **real-time, modular wildfire detection system** using **Unmanned Aerial Vehicles (UAVs)** equipped with **RGB and thermal cameras**. The system is tested in a simulated environment (Unreal Engine + AirSim) and is orchestrated via **ROS 2**. It incorporates **deep learning-based object detection**, **image registration**, **multi-modal data fusion**, **object tracking**, and **GPS-based alerting**.

---

## Contents

### `Thesis.pdf`
The **full written thesis** (in English) presenting the detailed methodology, implementation, experiments, results, and future work.

It includes:
- Background on deep learning, UAVs, and multi-modal sensing
- Creation of custom datasets for RGB and thermal imagery
- Evaluation of object detection models (YOLOv8, Faster R-CNN, SSD, EfficientDet)
- Optimization with TensorRT for deployment on NVIDIA Jetson Orin Nano and RTX 4090
- Full system architecture and implementation using ROS 2
- Simulation setup using Unreal Engine and AirSim
- Image alignment using calibration and homography
- Evaluation results and real-time demo screenshots

### `Thesis-Presentation.pptx`
The **official thesis presentation slides**, summarizing the core contributions of the project, including:
- Motivation and objectives
- Dataset samples
- Training results and performance metrics
- Architecture diagrams and simulation screenshots
- Conclusions and future directions

---

## Key Features

- **Wildfire detection** using both RGB (fire/smoke) and thermal (fire/humans/animals) modalities
- **Custom datasets** built from real and synthetic sources
- **Model comparison** with benchmarks on accuracy, inference speed, and resource usage
- **Real-time inference** on NVIDIA Jetson Orin Nano and RTX 4090 using TensorRT optimizations (FP16 & INT8)
- **Simulation environment** with realistic fire, smoke, humans, and wildlife in Unreal Engine
- **Image registration pipeline** for frame-level alignment of RGB and thermal inputs
- **GPS-enabled alerting** and visualization
- **ROS 2-based modular architecture** supporting scalability and extensibility

---

## Related Links

- [System Demo Video](https://youtu.be/7VyGpnn9aZ4)
- [Source Code Repository](https://github.com/vasilisanagno/UAV-Based-Wildfire-Detection-using-RGB-and-Thermal-Cameras)

---

## Technologies Used

- Python, PyTorch, OpenCV, TensorRT
- ROS 2 (Iron)
- Unreal Engine 5 + AirSim
- NVIDIA Jetson Orin Nano, RTX 4090
- YOLOv8, Faster R-CNN with MobileNetV3, SSD with VGG16, EfficientDet D1
- DeepSORT, ByteTrack, BoT-SORT-ReID

---

## Author

**Vasileios Anagnostopoulos**

University of Thessaly, Department of ECE

Supervisor: Prof. Christos Antonopoulos

July 2025

---


