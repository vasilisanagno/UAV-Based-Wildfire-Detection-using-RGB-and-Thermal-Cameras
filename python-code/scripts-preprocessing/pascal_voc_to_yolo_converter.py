import os
import xml.etree.ElementTree as ET
from PIL import Image

# Base paths for Pascal VOC and YOLO directories
BASE_PASCAL_DIR = r'../../models-datasets/datasets-original/fire_thermal_dataset/dataset_5/pascal_voc'
BASE_YOLO_DIR = r'../../models-datasets/datasets-original/fire_thermal_dataset/dataset_5/yolo'

# Define a mapping between class names and class IDs for YOLO
CLASS_MAPPING = {
    'fire': 0
}

def convert_voc_to_yolo(xml_file, img_width, img_height):
    """Convert a single Pascal VOC XML annotation to YOLO format."""
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    yolo_annotations = []
    
    for obj in root.findall('object'):
        class_name = obj.find('name').text
        if class_name not in CLASS_MAPPING:
            print(f"Class '{class_name}' not in class mapping. Skipping.")
            continue
        
        class_id = CLASS_MAPPING[class_name]
        
        bndbox = obj.find('bndbox')
        xmin = int(bndbox.find('xmin').text)
        xmax = int(bndbox.find('xmax').text)
        ymin = int(bndbox.find('ymin').text)
        ymax = int(bndbox.find('ymax').text)
        
        # Convert to YOLO format (normalized)
        x_center = (xmin + xmax) / 2 / img_width
        y_center = (ymin + ymax) / 2 / img_height
        width = (xmax - xmin) / img_width
        height = (ymax - ymin) / img_height
        
        # Format: class_id x_center y_center width height
        yolo_annotation = f"{class_id} {x_center:.6f} {y_center:.6f} {width:.6f} {height:.6f}"
        yolo_annotations.append(yolo_annotation)
    
    return yolo_annotations

def convert_all_voc_to_yolo(base_pascal_dir, base_yolo_dir):
    """Convert Pascal VOC XML files in train, test, and valid folders to YOLO format."""
    subsets = ['train', 'valid', 'test']
    
    for subset in subsets:
        xml_dir = os.path.join(base_pascal_dir, subset, 'labels')
        img_dir = os.path.join(base_yolo_dir, subset, 'images')
        yolo_dir = os.path.join(base_yolo_dir, subset, 'labels')
        
        if not os.path.exists(xml_dir):
            print(f"Skipping: {xml_dir} (Directory does not exist)")
            continue
        
        if not os.path.exists(yolo_dir):
            os.makedirs(yolo_dir)
        
        for xml_file in os.listdir(xml_dir):
            if xml_file.endswith('.xml'):
                # Parse image size from XML file
                xml_path = os.path.join(xml_dir, xml_file)
                tree = ET.parse(xml_path)
                root = tree.getroot()
                
                img_filename = root.find('filename').text
                img_path = os.path.join(img_dir, img_filename)
                
                # Open the image to get its size
                try:
                    img = Image.open(img_path)
                    img_width, img_height = img.size
                except Exception as e:
                    print(f"Image '{img_filename}' not found or not accessible: {e}")
                    continue
                
                # Convert the annotation
                yolo_annotations = convert_voc_to_yolo(xml_path, img_width, img_height)
                
                # Save YOLO annotations to .txt file
                yolo_filename = img_filename.replace('.jpg', '.txt').replace('.jpeg', '.txt')
                yolo_path = os.path.join(yolo_dir, yolo_filename)
                
                with open(yolo_path, 'w') as f:
                    f.write('\n'.join(yolo_annotations))
                
                print(f"Converted {xml_file} to {yolo_filename}")

if __name__ == '__main__':
    convert_all_voc_to_yolo(BASE_PASCAL_DIR, BASE_YOLO_DIR)
