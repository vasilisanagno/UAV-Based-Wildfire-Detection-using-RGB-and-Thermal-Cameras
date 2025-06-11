import os
import pandas as pd
import xml.etree.ElementTree as ET
from PIL import Image

def create_voc_xml(prefix, frame_number, object_data, img_width, img_height, output_folder):
    """Creates a Pascal VOC XML file for a given frame and object data."""
    # Define the filename based on the frame number
    filename = f"{prefix}{frame_number:010d}.xml"
    
    # Create the XML structure
    annotation = ET.Element("annotation")
    
    ET.SubElement(annotation, "folder").text = "images"
    ET.SubElement(annotation, "filename").text = f"{prefix}{frame_number:010d}.jpg"
    ET.SubElement(annotation, "path").text = os.path.join("train", "images", f"{prefix}{frame_number:010d}.jpg")

    # Set image size dynamically
    size = ET.SubElement(annotation, "size")
    ET.SubElement(size, "width").text = str(img_width)
    ET.SubElement(size, "height").text = str(img_height)
    ET.SubElement(size, "depth").text = "3"  # Assuming RGB images

    # Add each object in the frame if there are annotations
    if not object_data.empty:
        for _, obj in object_data.iterrows():
            obj_elem = ET.SubElement(annotation, "object")
            class_name = "human" if obj['class'] == 1 else "animal"
            ET.SubElement(obj_elem, "name").text = class_name
            ET.SubElement(obj_elem, "pose").text = "Unspecified"
            ET.SubElement(obj_elem, "truncated").text = "0"
            ET.SubElement(obj_elem, "difficult").text = "0"
            
            # Calculate bounding box coordinates
            x, y, w, h = obj['x'], obj['y'], obj['w'], obj['h']
            xmin = int(x)
            ymin = int(y)
            xmax = int(x + w)
            ymax = int(y + h)
            
            # Add bounding box
            bndbox = ET.SubElement(obj_elem, "bndbox")
            ET.SubElement(bndbox, "xmin").text = str(xmin)
            ET.SubElement(bndbox, "ymin").text = str(ymin)
            ET.SubElement(bndbox, "xmax").text = str(xmax)
            ET.SubElement(bndbox, "ymax").text = str(ymax)

    # Write to file
    tree = ET.ElementTree(annotation)
    output_path = os.path.join(output_folder, f"{filename}")
    tree.write(output_path)
    print(f"Saved {output_path}")

def mot_to_voc(csv_path, img_folder, output_folder, prefix):
    """Convert MOT format CSV annotations to Pascal VOC XML format with dynamic image dimensions."""
    os.makedirs(output_folder, exist_ok=True)

    # Read the CSV file
    columns = ['frame_number', 'object_id', 'x', 'y', 'w', 'h', 'class', 'species', 'occlusion', 'noise']
    data = pd.read_csv(csv_path, header=None, names=columns)

    # Group data by frame number
    grouped_data = data.groupby('frame_number')

    # Process each image file in the folder
    for image_filename in os.listdir(img_folder):
        if image_filename.endswith(".jpg"):
            # Extract the frame number from the filename
            frame_number = int(image_filename[len(prefix):-4])  # Remove prefix and ".jpg"
            image_path = os.path.join(img_folder, image_filename)

            # Open the image to get its dimensions
            try:
                with Image.open(image_path) as img:
                    img_width, img_height = img.size
            except FileNotFoundError:
                print(f"Image file '{image_path}' not found. Skipping.")
                continue

            # Get object data for this frame, if any
            frame_data = grouped_data.get_group(frame_number) if frame_number in grouped_data.groups else pd.DataFrame()
            
            # Create XML file with dynamic dimensions
            create_voc_xml(prefix, frame_number, frame_data, img_width, img_height, output_folder)

def main():
    # Input paths
    csv_path = "../datasets/human_thermal_dataset/dataset_5/0000000371_0000000000_testReal.csv"
    img_folder = "../datasets/human_thermal_dataset/dataset_5/0000000371_0000000000_testReal/"
    output_folder = "../datasets/human_thermal_dataset/dataset_5/pascal_voc/human_animal/"
    prefix = "0000000371_0000000000_"

    # Convert annotations
    mot_to_voc(csv_path, img_folder, output_folder, prefix)

if __name__ == "__main__":
    main()
