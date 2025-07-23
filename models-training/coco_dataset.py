import os
import torch
from torch.utils.data import Dataset
from PIL import Image
from pycocotools.coco import COCO
import numpy as np

class COCODataset(Dataset):
    def __init__(self, root_dir, annotation_file, transforms=None):
        """
        Initialize the COCO Dataset.

        Args:
            root_dir (str): Root directory of the images.
            annotation_file (str): Path to the COCO annotation file (JSON).
            transforms (callable, optional): A function/transform to apply to the images and targets.
        """
        self.root_dir = root_dir
        self.transforms = transforms
        self.coco = COCO(annotation_file)
        self.image_ids = list(self.coco.imgs.keys())

    def __len__(self):
        return len(self.image_ids)

    def __getitem__(self, idx):
        """
        Get an item (image and its annotations) at a given index.
        """
        image_id = self.image_ids[idx]
        image_info = self.coco.loadImgs(image_id)[0]
        img_path = os.path.join(self.root_dir, image_info['file_name'])

        # Load image
        img = Image.open(img_path).convert("RGB")

        # Load annotations
        annotation_ids = self.coco.getAnnIds(imgIds=image_id)
        annotations = self.coco.loadAnns(annotation_ids)

        # Extract boxes and labels
        boxes = []
        labels = []
        for ann in annotations:
            # COCO bbox format is [x, y, width, height], convert to [xmin, ymin, xmax, ymax]
            xmin = ann['bbox'][0]
            ymin = ann['bbox'][1]
            xmax = xmin + ann['bbox'][2]
            ymax = ymin + ann['bbox'][3]
            boxes.append([xmin, ymin, xmax, ymax])
            labels.append(ann['category_id'])

        # Convert to PyTorch tensors
        if not boxes:
            boxes = torch.zeros((0, 4), dtype=torch.float32)
        else:  
            boxes = torch.as_tensor(boxes, dtype=torch.float32)
        labels = torch.as_tensor(labels, dtype=torch.float32)
        
        # Create target dictionary
        target = {"bbox": boxes, "cls": labels}

        # Apply transformations
        if self.transforms:
            img, target = self.apply_transforms(img, target)
        target["bbox"] = target["bbox"][:, [1, 0, 3, 2]]
        return img, target
    
    def apply_transforms(self, img, target):
        """
        Apply albumentations transforms to the image and adjust bounding boxes.
        """
        # Convert bounding boxes and labels into Albumentations format
        bboxes = target["bbox"].tolist() if target["bbox"].numel() > 0 else []
        labels = target["cls"].tolist() if target["cls"].numel() > 0 else []

        # Apply Albumentations transformations
        transformed = self.transforms(image=np.array(img), bboxes=bboxes, labels=labels)
        
        # Update image, boxes, and labels
        img = transformed["image"].clone().detach().float()
        target["bbox"] = torch.tensor(transformed["bboxes"], dtype=torch.float32) if transformed["bboxes"] else torch.zeros((0, 4), dtype=torch.float32)
        target["cls"] = torch.tensor(transformed["labels"], dtype=torch.int64) if transformed["labels"] else torch.zeros((0,), dtype=torch.int64)

        return img, target
    
    def custom_collate_fn(self, batch):
        """
        Custom collate function to batch images and targets.
        Args:
            batch: List of tuples (image, target), where target is a dictionary.
        Returns:
            images: List of images.
            targets: List of dictionaries (one dictionary per image).
        """
        images, targets = zip(*batch)
        return list(images), list(targets)