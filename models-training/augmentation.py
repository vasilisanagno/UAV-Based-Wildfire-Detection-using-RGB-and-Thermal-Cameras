import os
import albumentations as A
from albumentations.core.composition import OneOf
from albumentations.pytorch import ToTensorV2
import cv2
import xml.etree.ElementTree as ET
import torch
import numpy as np

class UAVImageAugmentor:
    def __init__(self, bbox_format="pascal", mode="rgb"):
        """
        Initialize the UAVImageAugmentor with specified image format and dimensions.

        Args:
            bbox_format (str): Format of bounding boxes ('pascal').
        """
        self.bbox_format = bbox_format

        # Define bounding box parameters
        bbox_params = {
            "pascal": A.BboxParams(format="pascal_voc", label_fields=["labels"], clip=True)
        }

        if self.bbox_format not in bbox_params:
            raise ValueError(f"Unsupported image format: {self.bbox_format}. Supported formats: pascal.")

        # Define augmentations
        if mode == "rgb":
            self.transform = A.Compose(
                [
                    A.SomeOf([
                        A.RandomBrightnessContrast(brightness_limit=(-0.1, 0.1), contrast_limit=(-0.1, 0.1), p=1.0),
                        A.HueSaturationValue(hue_shift_limit=0, sat_shift_limit=10, val_shift_limit=20, p=1.0),
                        A.RandomGamma(gamma_limit=(90, 110), p=1.0),
                        A.CLAHE(clip_limit=2.0, tile_grid_size=(4, 4), p=1.0),
                        A.MotionBlur(blur_limit=(3, 5), p=1.0)
                    ], n=2),
                    A.HorizontalFlip(p=0.5),
                    A.Affine(rotate=(-15, 15), shear=(-5, 5), scale=(0.9, 1.1), p=0.5),
                    A.Affine(translate_percent={"x": (-0.1, 0.1), "y": (-0.1, 0.1)}, p=0.5)
                ],
                bbox_params=bbox_params[self.bbox_format]
            )
        elif mode == "thermal":
            self.transform = A.Compose(
                [
                    A.SomeOf([
                        A.HorizontalFlip(p=1.0),
                        A.Affine(rotate=(-10, 10), shear=(-5, 5), scale=(0.9, 1.1), p=1.0),
                        A.Affine(translate_percent={"x": (-0.1, 0.1), "y": (-0.1, 0.1)}, p=1.0),
                        A.MotionBlur(blur_limit=(3, 3), p=1.0),
                        A.SaltAndPepper(amount=(0.01,0.02), p=1.0)
                ], n=3)],
                bbox_params=bbox_params[self.bbox_format]
            )
        elif mode == "crop":
            self.crop_size = 640
            self.transform = A.Compose([], bbox_params=bbox_params[self.bbox_format])
            
    def apply_augmentation(self, image, bboxes, labels):
        """
        Applies augmentations to the given image, bounding boxes, and labels.

        Args:
            image (np.array): Input image.
            bboxes (list): List of bounding boxes.
            labels (list): List of labels corresponding to bounding boxes.

        Returns:
            Augmented image, bounding boxes, and labels.
        """
        
        augmented = self.transform(image=image, bboxes=bboxes, labels=labels)
    
        # Convert tensor back to NumPy array if necessary
        if isinstance(augmented["image"], torch.Tensor):
            augmented_image = augmented["image"].permute(1, 2, 0).cpu().numpy()  # From CHW to HWC format
        else:
            augmented_image = augmented["image"]

        return augmented_image, augmented["bboxes"], augmented["labels"]
    
    def save_augmented_dataset(self, images, bboxes, labels, output_dir):
        """
        Saves augmented images and their corresponding labels to the specified directory.

        Args:
            images (list): List of images.
            bboxes (list): List of bounding boxes for each image.
            labels (list): List of labels for each image.
            output_dir (str): Directory to save augmented images and labels.
        """
        os.makedirs(output_dir, exist_ok=True)
        labels_dir_pascal = os.path.join(output_dir, f"labels_pascal")
        labels_dir_yolo = os.path.join(output_dir, f"labels_yolo")
        os.makedirs(labels_dir_pascal, exist_ok=True)
        os.makedirs(labels_dir_yolo, exist_ok=True)

        for idx, (image, bbox, label) in enumerate(zip(images, bboxes, labels)):
            # Apply augmentation
            augmented_image, augmented_bboxes, augmented_labels = self.apply_augmentation(image, bbox, label)
            img_height, img_width, _ = augmented_image.shape

            # Save augmented image
            image_path = os.path.join(output_dir, f"aug_{idx}_27.jpg")
            cv2.imwrite(image_path, augmented_image.astype(np.uint8))

            # Save corresponding labels
            label_path = os.path.join(labels_dir_yolo, f"aug_{idx}_27.txt")
            with open(label_path, "w") as f:
                for box, lbl in zip(augmented_bboxes, augmented_labels):
                    # Convert Pascal VOC to YOLO if necessary
                    x_center, y_center, width, height = self._convert_to_yolo(box, img_width, img_height)
                    if lbl == "fire":
                        label = 0
                    elif lbl == "smoke" or lbl == "human":
                        label = 1
                    elif lbl == "animal":
                        label = 2
                    f.write(f"{label} {x_center} {y_center} {width} {height}\n")
            
            label_path = os.path.join(labels_dir_pascal, f"aug_{idx}_27.xml")
            self._save_pascal_label(img_height, img_width, label_path, augmented_bboxes, augmented_labels, f"aug_{idx}_27.jpg")

    def _convert_to_yolo(self, box, img_width, img_height):
        """
        Converts a bounding box from Pascal VOC format (x_min, y_min, x_max, y_max) 
        to YOLO format (x_center, y_center, width, height).

        Args:
            box (list): Bounding box in Pascal VOC format [x_min, y_min, x_max, y_max].
            img_width (int): Width of the image.
            img_height (int): Height of the image.

        Returns:
            tuple: Bounding box in YOLO format (x_center, y_center, width, height).
        """
        x_min, y_min, x_max, y_max = box
        x_center = (x_min + x_max) / 2 / img_width
        y_center = (y_min + y_max) / 2 / img_height
        width = (x_max - x_min) / img_width
        height = (y_max - y_min) / img_height
        return x_center, y_center, width, height
               
    def _save_pascal_label(self, img_height, img_width, label_path, bboxes, labels, filename):
        """
        Saves bounding box labels in Pascal VOC XML format.

        Args:
            img_height (int): Height of the image.
            img_width (int): Width of the image.
            label_path (str): Path to save the XML file.
            bboxes (list): List of bounding boxes.
            labels (list): List of labels.
            filename (str): Name of the image file.
        """
        annotation = ET.Element("annotation")

        folder = ET.SubElement(annotation, "folder")
        folder.text = "images"

        file_name = ET.SubElement(annotation, "filename")
        file_name.text = filename

        path = ET.SubElement(annotation, "path")
        path.text = f"images/{filename}"

        size = ET.SubElement(annotation, "size")
        ET.SubElement(size, "width").text = str(img_width)
        ET.SubElement(size, "height").text = str(img_height)
        ET.SubElement(size, "depth").text = "3"

        for box, label in zip(bboxes, labels):
            obj = ET.SubElement(annotation, "object")
            ET.SubElement(obj, "name").text = str(label)
            ET.SubElement(obj, "pose").text = "Unspecified"
            ET.SubElement(obj, "truncated").text = "0"
            ET.SubElement(obj, "difficult").text = "0"

            bndbox = ET.SubElement(obj, "bndbox")
            ET.SubElement(bndbox, "xmin").text = str(int(box[0]))
            ET.SubElement(bndbox, "ymin").text = str(int(box[1]))
            ET.SubElement(bndbox, "xmax").text = str(int(box[2]))
            ET.SubElement(bndbox, "ymax").text = str(int(box[3]))

        tree = ET.ElementTree(annotation)
        tree.write(label_path)

    @staticmethod
    def load_pascal_dataset(images_dir, xml_dir, start=0, end=None):
        """
        Load images and corresponding Pascal VOC-format labels from a dataset within a specified range.

        Args:
            images_dir (str): Directory containing image files.
            xml_dir (str): Directory containing Pascal VOC XML files.
            start (int): Starting index (inclusive) of the images to load.
            end (int): Ending index (exclusive) of the images to load. If None, loads until the end.

        Returns:
            images (list): List of images as NumPy arrays.
            bboxes (list): List of bounding boxes for each image.
            labels (list): List of labels for each image.
        """

        images = []
        bboxes = []
        labels = []

        # Get a sorted list of XML files
        xml_files = sorted([f for f in os.listdir(xml_dir) if f.endswith(".xml")])

        # Apply the start and end indices
        xml_files = xml_files[start:end]

        for xml_file in xml_files:
            tree = ET.parse(os.path.join(xml_dir, xml_file))
            root = tree.getroot()

            file_name = root.find("filename").text
            image_path = os.path.join(images_dir, file_name)

            if not os.path.exists(image_path):
                continue

            image = cv2.imread(image_path)
            images.append(image)

            image_bboxes = []
            image_labels = []

            for obj in root.findall("object"):
                label = obj.find("name").text
                bndbox = obj.find("bndbox")

                x_min = int(bndbox.find("xmin").text)
                y_min = int(bndbox.find("ymin").text)
                x_max = int(bndbox.find("xmax").text)
                y_max = int(bndbox.find("ymax").text)

                image_bboxes.append([x_min, y_min, x_max, y_max])
                image_labels.append(label)

            bboxes.append(image_bboxes)
            labels.append(image_labels)

        return images, bboxes, labels
    
    def dynamic_crop(self, image, bboxes, labels):
        """
        Dynamically crop around the fire bounding box, or slightly above and to the left 
        of the bottom-right corner of the smoke bounding box if only smoke exists.

        Args:
            image (np.array): Input image.
            bboxes (list): List of bounding boxes in Pascal VOC format [x_min, y_min, x_max, y_max].
            labels (list): List of labels corresponding to bounding boxes.

        Returns:
            Cropped image, updated bounding boxes, and labels.
        """
        img_height, img_width, _ = image.shape
        crop_size = self.crop_size

        # Filter bounding boxes for fire and smoke
        fire_bbox = None
        smoke_bboxes = []

        for bbox, label in zip(bboxes, labels):
            if label == "fire":
                fire_bbox = bbox
            elif label == "smoke":
                smoke_bboxes.append(bbox)

        if fire_bbox:
            # Get the center of the fire bounding box
            fire_x_min, fire_y_min, fire_x_max, fire_y_max = fire_bbox
            x_center = int((fire_x_min + fire_x_max) / 2)
            y_center = int((fire_y_min + fire_y_max) / 2)
        elif smoke_bboxes:
            # Get the bottom-right corner of the smoke bounding box
            smoke_x_min, smoke_y_min, smoke_x_max, smoke_y_max = smoke_bboxes[0]

            # Adjust the center to be slightly up and to the left of the bottom-right corner
            x_center = max(0, smoke_x_max - crop_size // 4)  # Move left by 1/4th of the crop size
            y_center = max(0, smoke_y_max - crop_size // 4)  # Move up by 1/4th of the crop size
        else:
            # No fire or smoke in the image; return the original center crop
            x_center = img_width // 2
            y_center = img_height // 2

        # Calculate crop boundaries
        x_start = max(0, x_center - crop_size // 2)
        y_start = max(0, y_center - crop_size // 2)
        x_end = min(img_width, x_start + crop_size)
        y_end = min(img_height, y_start + crop_size)

        # Adjust start if crop size exceeds the image dimensions
        x_start = max(0, x_end - crop_size)
        y_start = max(0, y_end - crop_size)

        # Crop the image
        cropped_image = image[y_start:y_end, x_start:x_end]

        # Adjust bounding boxes
        cropped_bboxes = []
        cropped_labels = []

        for bbox, label in zip(bboxes, labels):
            x1, y1, x2, y2 = bbox

            # Check if the bounding box is inside the crop area
            if x2 >= x_start and x1 <= x_end and y2 >= y_start and y1 <= y_end:
                # Crop the bounding box at the crop boundaries
                x1 = max(0, x1 - x_start)  # Ensure x1 is within the cropped image
                y1 = max(0, y1 - y_start)  # Ensure y1 is within the cropped image
                x2 = min(crop_size, x2 - x_start)  # Ensure x2 is within the cropped image
                y2 = min(crop_size, y2 - y_start)  # Ensure y2 is within the cropped image
                cropped_bboxes.append([x1, y1, x2, y2])
                cropped_labels.append(label)

        return cropped_image, cropped_bboxes, cropped_labels

    def save_cropped_dataset(self, images, bboxes, labels, filenames, output_images_dir, output_labels_pascal_dir, output_labels_yolo_dir):
        """
        Crop images dynamically around bounding boxes and save them along with updated labels in Pascal VOC and YOLO formats.

        Args:
            images (list): List of images as NumPy arrays.
            bboxes (list): List of bounding boxes for each image.
            labels (list): List of labels for each image.
            filenames (list): List of original filenames.
            output_images_dir (str): Directory to save cropped images.
            output_labels_pascal_dir (str): Directory to save Pascal VOC labels.
            output_labels_yolo_dir (str): Directory to save YOLO labels.
        """
        os.makedirs(output_images_dir, exist_ok=True)
        os.makedirs(output_labels_pascal_dir, exist_ok=True)
        os.makedirs(output_labels_yolo_dir, exist_ok=True)

        for image, bbox, label, filename in zip(images, bboxes, labels, filenames):
            # Apply dynamic cropping
            cropped_image, cropped_bboxes, cropped_labels = self.dynamic_crop(image, bbox, label)
            img_height, img_width, _ = cropped_image.shape

            # Save cropped image with the original name
            image_path = os.path.join(output_images_dir, filename)
            cv2.imwrite(image_path, cropped_image.astype(np.uint8))

            # Save YOLO-format labels with the original name
            yolo_label_path = os.path.join(output_labels_yolo_dir, f"{os.path.splitext(filename)[0]}.txt")
            with open(yolo_label_path, "w") as f:
                for box, lbl in zip(cropped_bboxes, cropped_labels):
                    x_center, y_center, width, height = self._convert_to_yolo(box, img_width, img_height)
                    # Map labels to integers for YOLO
                    if lbl == "fire":
                        label = 0
                    elif lbl == "smoke" or lbl == "human":
                        label = 1
                    elif lbl == "animal":
                        label = 2
                    f.write(f"{label} {x_center} {y_center} {width} {height}\n")

            # Save Pascal VOC labels with the original name
            pascal_label_path = os.path.join(output_labels_pascal_dir, f"{os.path.splitext(filename)[0]}.xml")
            self._save_pascal_label(img_height, img_width, pascal_label_path, cropped_bboxes, cropped_labels, filename)

if __name__ == "__main__":
    # Directories
    images_dir = "./datasets/dataset-rgb-aug/aug/images"
    labels_pascal_dir = "./datasets/dataset-rgb-aug/aug/labels"
    output_dir = "./datasets/dataset-rgb-aug/aug/augmented_dataset_1"

    mode = "rgb"  # Choose from "rgb", "thermal", or "crop"
    start = 0
    end = None
    # Initialize augmentor
    augmentor_pascal = UAVImageAugmentor(bbox_format="pascal", mode=mode)

    if mode == "crop":
        output_images_dir = "../../models-datasets/datasets-original/fire_rgb_dataset/dataset_5/yolo/train/for_aug"
        output_labels_pascal_dir = "../../models-datasets/datasets-original/fire_rgb_dataset/dataset_5/pascal_voc/train/for_aug_labels"
        output_labels_yolo_dir = "../../models-datasets/datasets-original/fire_rgb_dataset/dataset_5/yolo/train/cropped_labels"

        # Load dataset
        images, bboxes_pascal, labels_pascal = UAVImageAugmentor.load_pascal_dataset(images_dir, labels_pascal_dir, start, end)
        print(f"Loaded {len(images)} images for cropping.")
        filenames = sorted(os.listdir(images_dir))  # Match filenames to ensure consistency
        filenames = filenames[start:end]

        # Resize images and save
        augmentor_pascal.save_cropped_dataset(images, bboxes_pascal, labels_pascal, filenames, output_images_dir, output_labels_pascal_dir, output_labels_yolo_dir)
        print(f"Resized dataset saved in {output_images_dir}.")
    else:
        # Load dataset
        images, bboxes_pascal, labels_pascal = UAVImageAugmentor.load_pascal_dataset(images_dir, labels_pascal_dir, start, end)
        print(f"Loaded {len(images)} images for augmentation.")

        # Apply augmentations and save the dataset
        augmentor_pascal.save_augmented_dataset(images, bboxes_pascal, labels_pascal, output_dir)
        print(f"Augmented dataset saved in {output_dir}.")
