import os
import xml.etree.ElementTree as ET
from PIL import Image
import cv2

def yolo_to_voc_xml(annotation_data, img_path, img_width, img_height, class_names):
    """Convert YOLO annotations to Pascal VOC XML format with multiple objects."""
    # Read the image to determine its depth dynamically
    image = cv2.imread(img_path)
    if image is None:
        raise ValueError(f"Could not read the image at {img_path}. Please check the file path.")
    depth = image.shape[2] if len(image.shape) == 3 else 1  # Depth: 3 for RGB, 1 for grayscale
    # Create root element
    annotation_xml = ET.Element("annotation")
    
    # Create and append folder, filename, and path elements
    ET.SubElement(annotation_xml, "folder").text = "images"
    ET.SubElement(annotation_xml, "filename").text = annotation_data["filename"]
    ET.SubElement(annotation_xml, "path").text = annotation_data["filepath"]
    
    # Create and append size element
    size = ET.SubElement(annotation_xml, "size")
    ET.SubElement(size, "width").text = str(img_width)
    ET.SubElement(size, "height").text = str(img_height)
    ET.SubElement(size, "depth").text = str(depth)
    
    # Add each bounding box as a separate object element
    for bbox in annotation_data["bboxes"]:
        obj = ET.SubElement(annotation_xml, "object")
        class_name = class_names[bbox["class_id"]]  # Get the class name from the ID
        ET.SubElement(obj, "name").text = class_name
        ET.SubElement(obj, "pose").text = "Unspecified"
        ET.SubElement(obj, "truncated").text = "0"
        ET.SubElement(obj, "difficult").text = "0"
        
        # Add bounding box coordinates
        bndbox = ET.SubElement(obj, "bndbox")
        ET.SubElement(bndbox, "xmin").text = str(round(max(1, min(bbox["xmin"], img_width))))
        ET.SubElement(bndbox, "xmax").text = str(round(max(1, min(bbox["xmax"], img_width))))
        ET.SubElement(bndbox, "ymin").text = str(round(max(1, min(bbox["ymin"], img_height))))
        ET.SubElement(bndbox, "ymax").text = str(round(max(1, min(bbox["ymax"], img_height))))
    
    return ET.ElementTree(annotation_xml)

def convert_yolo_to_voc(yolo_annotation_path, img_folder, output_folder, class_names, folder):
    """Convert YOLO annotations to Pascal VOC XML format with multiple objects per image."""
    os.makedirs(output_folder, exist_ok=True)
    
    for root, _, files in os.walk(yolo_annotation_path):
        for file in files:
            if file.endswith(".txt"):
                image_file = os.path.join(img_folder, file.replace(".txt", ".jpg"))
                if not os.path.exists(image_file):
                    print(f"Image file '{image_file}' not found. Skipping.")
                    continue
                
                # Open image to get dimensions
                with Image.open(image_file) as img:
                    img_width, img_height = img.size
                
                # Read YOLO annotations
                with open(os.path.join(root, file), "r") as f:
                    lines = f.readlines()
                
                # Prepare annotation data with multiple bounding boxes
                bboxes = []
                for line in lines:
                    class_id, x_center, y_center, width, height = map(float, line.strip().split())
                    x_center_px = x_center * img_width
                    y_center_px = y_center * img_height
                    width_px = width * img_width
                    height_px = height * img_height
                    
                    xmin = x_center_px - width_px / 2
                    ymin = y_center_px - height_px / 2
                    xmax = x_center_px + width_px / 2
                    ymax = y_center_px + height_px / 2
                    
                    bboxes.append({
                        "class_id": int(class_id),
                        "xmin": xmin,
                        "xmax": xmax,
                        "ymin": ymin,
                        "ymax": ymax
                    })
                
                # Prepare annotation data dictionary
                annotation_data = {
                    "filename": os.path.basename(image_file),
                    "filepath": os.path.join(folder, "images", os.path.basename(image_file)),
                    "bboxes": bboxes,
                }
                
                # Convert to XML with multiple objects
                xml_tree = yolo_to_voc_xml(annotation_data, image_file, img_width, img_height, class_names)
                
                # Save XML file
                output_path = os.path.join(output_folder, file.replace(".txt", ".xml"))
                xml_tree.write(output_path)

def main():
    # Define paths for train, valid, and test sets
    pascal_voc_dataset = "../models-training/datasets/dataset-r-aug/pascal_voc"
    yolo_dataset = "../models-training/datasets/dataset-r-aug"
    class_names = ["fire", "smoke"]  # List of class names, corresponding to class IDs in YOLO format

    for folder in ["train", "valid", "test"]:
        label_path = os.path.join(yolo_dataset, folder, "labels")
        img_folder = os.path.join(yolo_dataset, folder, "images")
        output_folder = os.path.join(pascal_voc_dataset, folder, "labels")

        if os.path.exists(label_path) and os.path.exists(img_folder):
            convert_yolo_to_voc(label_path, img_folder, output_folder, class_names, folder)
        else:
            print(f"Folder '{label_path}' or '{img_folder}' does not exist.")

if __name__ == "__main__":
    main()
