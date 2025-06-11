import os
import cv2
import numpy as np
from pathlib import Path
from ultralytics import YOLO
import sys

# Check if the mode (thermal or RGB) is provided as a command-line argument
if len(sys.argv) < 2:
    print("Usage: python script.py <mode>")
    print("<mode> should be either 'thermal' or 'rgb'")
    sys.exit(1)

mode = sys.argv[1].lower()  # Get the mode ('thermal' or 'rgb')
if mode not in ["thermal", "rgb"]:
    print("Invalid mode! Use 'thermal' or 'rgb'.")
    sys.exit(1)

# Define input and output directories based on mode
input_folder = f"{mode}_test"  # Folder containing original images
output_folder = f"{mode}_output_images"  # Folder to save processed images with predictions

# Create output folder if it doesn't exist
os.makedirs(output_folder, exist_ok=True)

# Load the YOLOv8 model based on mode
if mode == "thermal":
    model_path = "runs/detect/train63/weights/best.engine"  # Thermal model path
    label_colors = {
        "fire": (255, 0, 0),  # Blue in BGR
        "human": (0, 0, 128),  # Dark Red in BGR
        "animal": (0, 165, 128)  # Dark Green in BGR
    }
else:  # mode == "rgb"
    model_path = "runs/detect/train64/weights/best.engine"  # RGB model path
    label_colors = {
        "fire": (255, 0, 0),  # Blue in BGR
        "smoke": (0, 128, 0),  # Dark Green in BGR
    }

# Load the YOLO model
model = YOLO(model_path)

# Define class names from the model
class_names = model.names  # Automatically loads class names

def adjust_label_placement(image, box, label, color, offset=5):
    """
    Adjusts label placement to avoid exceeding image borders (top, right, and left).
    Draws the label text inside or near the bounding box at a better position.
    """
    x1, y1, x2, y2 = map(int, box)
    label_size, _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 2)
    text_width, text_height = label_size

    # Initialize default position (above the bounding box)
    y_label = y1 - offset
    x_label = x1

    # Adjust for upper boundary (if too close to the top, place label below the box)
    if y1 - text_height - offset < 0:
        y_label = y2 + text_height + offset

    # Adjust for right boundary (if label exceeds the right side, shift it left)
    if x1 + text_width > image.shape[1]:
        x_label = image.shape[1] - text_width - offset

    # Adjust for left boundary (if label exceeds the left side, shift it right)
    if x_label < 0:
        x_label = offset

    # Draw background rectangle for label
    cv2.rectangle(
        image,
        (x_label - 2, y_label - text_height - 5),
        (x_label + text_width + 2, y_label + 5),
        color,
        -1,
    )

    # Draw label text
    cv2.putText(
        image,
        label,
        (x_label, y_label - 2),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.5,
        (255, 255, 255),
        1,
        lineType=cv2.LINE_AA,
    )

# Process each image in the input folder
for image_name in os.listdir(input_folder):
    if image_name.lower().endswith((".jpg", ".jpeg", ".png", ".bmp")):  # Check valid image formats
        input_path = os.path.join(input_folder, image_name)  # Full input image path
        output_path = os.path.join(output_folder, f"pre_{image_name}")  # Output image path

        # Load the image
        image = cv2.imread(input_path)
        
        # Run inference
        results = model.predict(image, conf=0.4, imgsz=640, nms=True, iou=0.5)

        # Loop through detections and draw boxes
        for result in results:
            boxes = result.boxes.xyxy.cpu().numpy()  # Bounding boxes (x1, y1, x2, y2)
            confidences = result.boxes.conf.cpu().numpy()  # Confidence scores
            class_ids = result.boxes.cls.cpu().numpy().astype(int)  # Class IDs

            for box, conf, class_id in zip(boxes, confidences, class_ids):
                x1, y1, x2, y2 = map(int, box)  # Convert box coordinates to int
                class_name = class_names[class_id]
                label = f"{class_name} {conf:.2f}"  # Include confidence in label

                # Get color for the label based on class name
                color = label_colors.get(class_name, (128, 128, 128))  # Default to gray if class not in label_colors

                # Draw bounding box
                cv2.rectangle(image, (x1, y1), (x2, y2), color, 2)

                # Adjust label placement to avoid boundary overlap
                adjust_label_placement(image, box, label, color)

        # Save the full annotated image
        cv2.imwrite(output_path, image)

print(f"Processed images are saved in '{output_folder}/'")
