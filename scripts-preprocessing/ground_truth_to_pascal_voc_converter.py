import os
import xml.etree.ElementTree as ET
from PIL import Image
import shutil

def restore_original_filenames(img_folder, folder_name):
    """Restore images to their original names by removing the folder prefix."""
    for filename in os.listdir(img_folder):
        if filename.startswith(f"{folder_name}_"):
            # Remove the folder prefix
            original_filename = filename[len(folder_name) + 1:]  # Skip the folder prefix and underscore
            original_path = os.path.join(img_folder, filename)
            restored_path = os.path.join(img_folder, original_filename)
            
            # Rename file if the restored name does not already exist
            if not os.path.exists(restored_path):
                shutil.move(original_path, restored_path)
                print(f"Restored '{original_path}' to '{restored_path}'")
            else:
                print(f"Skipping renaming as '{restored_path}' already exists.")

def create_voc_xml(folder_name, image_filename, bboxes, img_width, img_height, output_folder):
    """Creates a Pascal VOC XML file for a given image and its bounding boxes."""
    filename_with_folder = f"{folder_name}_{os.path.splitext(image_filename)[0]}"
    
    annotation = ET.Element("annotation")
    ET.SubElement(annotation, "folder").text = "images"
    ET.SubElement(annotation, "filename").text = filename_with_folder
    custom_path = os.path.join("train", "images", filename_with_folder)
    ET.SubElement(annotation, "path").text = custom_path

    size = ET.SubElement(annotation, "size")
    ET.SubElement(size, "width").text = str(img_width)
    ET.SubElement(size, "height").text = str(img_height)
    ET.SubElement(size, "depth").text = "3"  # Assuming RGB images

    for bbox in bboxes:
        obj = ET.SubElement(annotation, "object")
        ET.SubElement(obj, "name").text = "human"
        ET.SubElement(obj, "pose").text = "Unspecified"
        ET.SubElement(obj, "truncated").text = "0"
        ET.SubElement(obj, "difficult").text = "0"

        bndbox = ET.SubElement(obj, "bndbox")
        ET.SubElement(bndbox, "xmin").text = str(bbox[0])
        ET.SubElement(bndbox, "xmax").text = str(bbox[2])
        ET.SubElement(bndbox, "ymin").text = str(bbox[1])
        ET.SubElement(bndbox, "ymax").text = str(bbox[3])

    tree = ET.ElementTree(annotation)
    output_path = os.path.join(output_folder, f"{filename_with_folder}.xml")
    tree.write(output_path)

def process_labels(label_file, img_folder, output_folder):
    """Processes the label file and generates Pascal VOC XML files, adding folder prefix to images."""
    folder_name = os.path.basename(os.path.dirname(label_file))

    with open(label_file, "r") as f:
        lines = f.readlines()
        
    # Skip the first three comment lines
    lines = lines[3:]

    for line in lines[1:]:
        parts = line.strip().split()
        image_filename = parts[0]  # Ground truth format, e.g., 'img_00001.bmp'
        
        # Construct the path for the original image based on ground truth format
        original_image_path = os.path.join(img_folder, image_filename)
        
        # New image filename with folder name prefix
        new_image_filename = f"{folder_name}_{image_filename}"
        new_image_path = os.path.join(img_folder, new_image_filename)
        
        # Check if the original image exists
        if not os.path.exists(original_image_path):
            print(f"Image file '{original_image_path}' not found. Skipping.")
            continue
        
        # Rename the image to the new path with the correct filename
        shutil.move(original_image_path, new_image_path)
        print(f"Renamed '{original_image_path}' to '{new_image_path}'")

        # Open the renamed image to get dimensions
        with Image.open(new_image_path) as img:
            img_width, img_height = img.size

        num_bboxes = int(parts[1])
        bboxes = []
        
        # Parse bounding boxes, removing parentheses
        for i in range(num_bboxes):
            bbox_str = parts[2 + i * 4 : 6 + i * 4]
            xmin = int(bbox_str[0].replace("(", ""))
            ymin = int(bbox_str[1])
            xmax = int(bbox_str[2])
            ymax = int(bbox_str[3].replace(")", ""))
            bboxes.append((xmin, ymin, xmax, ymax))
        
        # Generate XML with the updated filename
        create_voc_xml(folder_name, image_filename, bboxes, img_width, img_height, output_folder)

def main():
    # Paths
    label_file = "../datasets/human_thermal_dataset/dataset_3/00010/groundTruth.txt"
    img_folder = "../datasets/human_thermal_dataset/dataset_3/00010/train"
    output_folder = "../datasets/human_thermal_dataset/dataset_3/pascal_voc/train/labels"

    # Step 1: Restore images to original filenames (without folder prefix)
    folder_name = os.path.basename(os.path.dirname(label_file))
    restore_original_filenames(img_folder, folder_name)

    # Step 2: Process labels and rename images to include folder prefix
    os.makedirs(output_folder, exist_ok=True)
    process_labels(label_file, img_folder, output_folder)

if __name__ == "__main__":
    main()
