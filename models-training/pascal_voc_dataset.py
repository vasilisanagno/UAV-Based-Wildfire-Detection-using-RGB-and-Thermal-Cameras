import os
from glob import glob
import xml.etree.ElementTree as ET
import torch
import torchvision
from torch.utils.data import Dataset
from PIL import Image
import numpy as np

class PascalVOCDataset(Dataset):
    def __init__(self, root_dir, transforms=None):
        """
        Initialize the Pascal VOC Dataset.

        Args:
            root_dir (str): Root directory of the dataset (e.g., 'dataset/train').
            transforms (callable, optional): A function/transform to apply to the images and targets.
        """
        self.root_dir = root_dir
        self.transforms = transforms
        self.image_dir = os.path.join(self.root_dir, "images")
        self.annotation_dir = os.path.join(self.root_dir, "labels_pascal")
        self.image_ids = self._load_image_ids()

    def _load_image_ids(self):
        """
        Load the image IDs based on filenames in the images directory (supports various formats).
        """
        valid_extensions = {".jpg", ".jpeg", ".png", ".bmp", ".tiff"}
        image_paths = glob(os.path.join(self.image_dir, "*"))
        image_ids = [
            os.path.splitext(os.path.basename(path))[0]
            for path in image_paths if os.path.splitext(path)[1].lower() in valid_extensions
        ]
        return image_ids

    def __len__(self):
        return len(self.image_ids)

    def __getitem__(self, idx):
        """
        Get an item (image and its annotations) at a given index.
        """
        image_id = self.image_ids[idx]
        img_path = self._find_image_path(image_id)
        annotation_path = os.path.join(self.annotation_dir, f"{image_id}.xml")

        # Ensure annotation exists
        if not os.path.exists(annotation_path):
            raise FileNotFoundError(f"Annotation file not found: {annotation_path}")

        # Load image
        img = Image.open(img_path).convert("RGB")

        # Parse annotations
        target = self._parse_voc_xml(annotation_path)

        # Apply transformations
        if self.transforms:
            img, target = self.apply_transforms(img, target)
        target["bbox"] = target["bbox"][:, [1, 0, 3, 2]]
        return img, target

    def _find_image_path(self, image_id):
        """
        Find the full path of an image file based on its ID, irrespective of format.
        """
        valid_extensions = {".jpg", ".jpeg", ".png", ".bmp", ".tiff"}
        for ext in valid_extensions:
            img_path = os.path.join(self.image_dir, f"{image_id}{ext}")
            if os.path.exists(img_path):
                return img_path
        raise FileNotFoundError(f"Image file not found for ID: {image_id}")
    
    def apply_transforms(self, img, target):
        """
        Apply albumentations transforms to the image and adjust bounding boxes.
        """
        # Convert bounding boxes and labels into Albumentations format
        bboxes = target.get("bbox", []).tolist() if target["bbox"].numel() > 0 else []
        labels = target.get("cls", []).tolist() if target["cls"].numel() > 0 else []
        
        # Apply Albumentations transformations
        transformed = self.transforms(image=np.array(img), bboxes=bboxes, labels=labels)
    
        # Update image, boxes, and labels
        img = transformed["image"].clone().detach().float()
        target["bbox"] = torch.tensor(transformed["bboxes"], dtype=torch.float32) if transformed["bboxes"] else torch.zeros((0, 4), dtype=torch.float32)
        target["cls"] = torch.tensor(transformed["labels"], dtype=torch.int64) if transformed["labels"] else torch.zeros((0,), dtype=torch.int64)

        return img, target

    def _parse_voc_xml(self, annotation_path):
        """
        Parse a Pascal VOC XML file to extract annotations for fire and smoke or human and animal only.
        """
        tree = ET.parse(annotation_path)
        root = tree.getroot()
        boxes = []
        labels = []
        for obj in root.findall("object"):
            # Extract class label
            label = obj.find("name").text
            if label not in ["fire", "human", "animal"]:
                continue  # Skip unwanted classes

            # Extract bounding box
            bbox = obj.find("bndbox")
            xmin = int(bbox.find("xmin").text)
            ymin = int(bbox.find("ymin").text)
            xmax = int(bbox.find("xmax").text)
            ymax = int(bbox.find("ymax").text)
            boxes.append([xmin, ymin, xmax, ymax])

            # Add class label
            labels.append(self.class_to_idx(label))

        # Convert to PyTorch tensors
        if not boxes:
            boxes = torch.zeros((0, 4), dtype=torch.float32)
        else:  
            boxes = torch.as_tensor(boxes, dtype=torch.float32)
        labels = torch.as_tensor(labels, dtype=torch.int64)

        target = {"bbox": boxes, "cls": labels}
        return target

    @staticmethod
    def class_to_idx(label):
        """
        Map class names to integer indices for fire and smoke or human and animal.
        """
        voc_classes = ["fire", "human", "animal"]
        return voc_classes.index(label) + 1  # 1-based index (background class is 0)
