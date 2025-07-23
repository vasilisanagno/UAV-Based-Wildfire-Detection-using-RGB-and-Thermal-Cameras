import os
import xml.etree.ElementTree as ET
from pathlib import Path
import cv2
import shutil

def create_pascal_voc_xml(image_path, annotations, image_name, mode):
    """
    Creates Pascal VOC XML for a given image with its annotations and renames the image.
    """
    # Read the image using OpenCV
    image = cv2.imread(image_path)
    height, width, channels = image.shape
    
    # Get the depth (number of channels)
    depth = channels  # Depth is the number of channels (e.g., 3 for RGB, 1 for grayscale)

    # Create the XML structure
    annotation = ET.Element("annotation")
    
    folder = ET.SubElement(annotation, "folder")
    folder.text = "images"

    filename = ET.SubElement(annotation, "filename")
    filename.text = f"{image_name}"  # e.g., video_001_frame_001.jpg

    path = ET.SubElement(annotation, "path")
    path.text = f"images/{image_name}"

    source = ET.SubElement(annotation, "source")
    database = ET.SubElement(source, "database")
    database.text = "Unknown"

    size = ET.SubElement(annotation, "size")
    width_elem = ET.SubElement(size, "width")
    width_elem.text = str(width)
    height_elem = ET.SubElement(size, "height")
    height_elem.text = str(height)
    depth_elem = ET.SubElement(size, "depth")
    depth_elem.text = str(depth)

    # Loop through each annotation (smoke or fire)
    for obj in annotations:
        obj_name = obj.get("label")
        if obj_name == "smoke_region" and mode != "thermal":
            label = "smoke"
        elif obj_name == "fire_region":
            label = "fire"
        else:
            continue  # Skip if label is neither fire nor smoke

        # Create object entry
        obj_elem = ET.SubElement(annotation, "object")
        name = ET.SubElement(obj_elem, "name")
        name.text = label

        pose = ET.SubElement(obj_elem, "pose")
        pose.text = "Unspecified"

        truncated = ET.SubElement(obj_elem, "truncated")
        truncated.text = "0"

        difficult = ET.SubElement(obj_elem, "difficult")
        difficult.text = "0"

        bndbox = ET.SubElement(obj_elem, "bndbox")
        xtl = ET.SubElement(bndbox, "xmin")
        xtl.text = str(obj.get("xtl"))
        ytl = ET.SubElement(bndbox, "ymin")
        ytl.text = str(obj.get("ytl"))
        xbr = ET.SubElement(bndbox, "xmax")
        xbr.text = str(obj.get("xbr"))
        ybr = ET.SubElement(bndbox, "ymax")
        ybr.text = str(obj.get("ybr"))

    # Write the XML to a file
    output_xml_path = os.path.join(output_dir, image_name.replace(".jpg", ".xml"))
    tree = ET.ElementTree(annotation)
    tree.write(output_xml_path)

def process_annotations(folders, mode="rgb"):
    """
    Process all folders with annotations and images, renaming images based on the label.
    """
    for folder in folders:
        image_folder = os.path.join(folder, "images")
        annotations_file = os.path.join(folder, "annotations.xml")

        if not os.path.exists(annotations_file):
            print(f"Annotations file not found in {folder}")
            continue

        # Parse the annotations XML
        tree = ET.parse(annotations_file)
        root = tree.getroot()

        # Loop through each image in the annotations
        for image_elem in root.findall('image'):
            image_name = image_elem.get('name')
            image_path = os.path.join(image_folder, f"{image_name}.jpg")

            # Extract annotations for this image
            annotations = []
            for box in image_elem.findall('box'):
                label = box.get('label')
                xtl = round(float(box.get('xtl')))
                ytl = round(float(box.get('ytl')))
                xbr = round(float(box.get('xbr')))
                ybr = round(float(box.get('ybr')))

                annotations.append({
                    'label': label,
                    'xtl': xtl,
                    'ytl': ytl,
                    'xbr': xbr,
                    'ybr': ybr
                })

            folder_name = os.path.basename(folder)
            # Determine the new image name based on the label
            new_image_name = f"{folder_name}_{image_name}.jpg"  # e.g., video_001_frame_000000.jpg

            # Ensure the path to the images folder is correct
            renamed_image_path = os.path.join(os.path.dirname(folder), "images", new_image_name)  # video_001_frame_000000.jpg
            
            # Ensure that the image exists
            if not os.path.exists(image_path):
                print(f"Warning: Image {image_path} does not exist.")
                continue  # Skip if the image doesn't exist
            
            # Ensure the target directory exists
            target_directory = os.path.dirname(renamed_image_path)
            if not os.path.exists(target_directory):
                os.makedirs(target_directory)  # Create the directory if it doesn't exist
                
            # Check if the mode is "thermal", then convert it to grayscale and RGB
            if mode == "thermal":
                image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)  # Read as grayscale
                image = cv2.cvtColor(image, cv2.COLOR_GRAY2RGB)  # Convert grayscale to RGB

                shutil.copy(image_path, renamed_image_path)
                # Save the converted image
                cv2.imwrite(renamed_image_path, image)
            else:
                # For RGB mode, just copy the image
                shutil.copy(image_path, renamed_image_path)
            
            create_pascal_voc_xml(renamed_image_path, annotations, new_image_name, mode)

# Main execution
folders = [
    '../../models-datasets/Multiclass/Unimodal/thermal/valid/video_t_01', 
    '../../models-datasets/Multiclass/Unimodal/thermal/valid/video_t_02'
]
output_dir = '../../models-datasets/Multiclass/Unimodal/thermal/valid/labels'  # Define the output directory for Pascal VOC XMLs

# Ensure output directory exists
Path(output_dir).mkdir(parents=True, exist_ok=True)

# Process all folders in "rgb" mode
process_annotations(folders, mode="thermal")
