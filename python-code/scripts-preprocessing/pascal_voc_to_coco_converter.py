import os
import json
import xml.etree.ElementTree as ET
from pathlib import Path

# Paths to dataset folders
DATASET_PATHS = {
    "train": "../models-training/datasets/dataset-rgb-aug/train/labels_pascal",
    "valid": "../models-training/datasets/dataset-rgb-aug/valid/labels_pascal",
    "test": "../models-training/datasets/dataset-rgb-aug/test/labels_pascal",
}

# Categories (customize this based on your dataset)
CATEGORIES = [
    {"id": 1, "name": "fire"},
    {"id": 2, "name": "smoke"}
]

def parse_voc_annotation(xml_file, image_id, annotation_id, categories):
    """Parse a single Pascal VOC XML file to extract COCO annotations."""
    tree = ET.parse(xml_file)
    root = tree.getroot()

    # Extract image info
    file_name = root.find("filename").text
    width = int(root.find("size/width").text)
    height = int(root.find("size/height").text)

    # Create image entry
    image_info = {
        "id": image_id,
        "file_name": file_name,
        "width": width,
        "height": height,
    }

    # Extract object annotations
    annotations = []
    for obj in root.findall("object"):
        category_name = obj.find("name").text
        category_id = next(
            (c["id"] for c in categories if c["name"] == category_name), None
        )
        if category_id is None:
            continue  # Skip unknown categories

        # Get bounding box
        bndbox = obj.find("bndbox")
        xmin = int(bndbox.find("xmin").text)
        ymin = int(bndbox.find("ymin").text)
        xmax = int(bndbox.find("xmax").text)
        ymax = int(bndbox.find("ymax").text)
        bbox_width = xmax - xmin
        bbox_height = ymax - ymin

        # COCO annotation format
        annotation = {
            "id": annotation_id,
            "image_id": image_id,
            "category_id": category_id,
            "bbox": [xmin, ymin, bbox_width, bbox_height],
            "area": bbox_width * bbox_height,
            "iscrowd": 0,
        }
        annotations.append(annotation)
        annotation_id += 1

    return image_info, annotations, annotation_id

def convert_voc_to_coco(voc_dir, categories):
    """Convert Pascal VOC files in a directory to COCO format."""
    images = []
    annotations = []
    image_id = 1
    annotation_id = 1

    for xml_file in Path(voc_dir).glob("*.xml"):
        image_info, image_annotations, annotation_id = parse_voc_annotation(
            xml_file, image_id, annotation_id, categories
        )
        images.append(image_info)
        annotations.extend(image_annotations)
        image_id += 1

    return {
        "images": images,
        "annotations": annotations,
        "categories": categories,
    }

def main():
    # Process each split
    for split, voc_dir in DATASET_PATHS.items():
        print(f"Processing {split} dataset...")
        coco_data = convert_voc_to_coco(voc_dir, CATEGORIES)

        # Save to JSON
        output_file = f"{voc_dir}/../../annotations_{split}.json"
        with open(output_file, "w") as f:
            json.dump(coco_data, f, indent=4)
        print(f"COCO annotations saved to {output_file}")

if __name__ == "__main__":
    main()
