import imgaug.augmenters as iaa
import cv2
import os
from imgaug.augmentables.bbs import BoundingBox, BoundingBoxesOnImage

# Set directories
input_dir = "path_to_your_images"
labels_dir = "path_to_yolo_labels"
output_dir = "path_to_augmented_images"
output_labels_dir = "path_to_augmented_labels"

os.makedirs(output_dir, exist_ok=True)
os.makedirs(output_labels_dir, exist_ok=True)

# Define augmentations
augmentation_list = [
    iaa.Multiply((0.8, 1.2)),  # Brightness for visual data
    iaa.Fliplr(0.5),  # Flip horizontally
    iaa.AdditiveGaussianNoise(scale=(0.0, 0.05*255)),  # Noise
    iaa.Affine(scale=(0.8, 1.2), rotate=(-20, 20)),  # Scaling and rotation
    iaa.PerspectiveTransform(scale=(0.01, 0.1)),  # Perspective shift
    iaa.GaussianBlur(sigma=(0.0, 3.0))  # Blur
]

# Number of augmentations to apply for each image
num_augmentations = 3

# Function to read YOLO bounding boxes
def read_yolo_labels(label_path, img_width, img_height):
    boxes = []
    with open(label_path, 'r') as file:
        for line in file:
            class_id, x_center, y_center, width, height = map(float, line.strip().split())
            # Convert YOLO format to pixel coordinates
            x_center *= img_width
            y_center *= img_height
            width *= img_width
            height *= img_height
            x1 = x_center - width / 2
            y1 = y_center - height / 2
            x2 = x_center + width / 2
            y2 = y_center + height / 2
            boxes.append((class_id, BoundingBox(x1, y1, x2, y2)))
    return boxes

# Function to write YOLO bounding boxes
def write_yolo_labels(label_path, boxes, img_width, img_height):
    with open(label_path, 'w') as file:
        for class_id, box in boxes:
            # Convert pixel coordinates back to YOLO format
            x_center = (box.x1 + box.x2) / 2 / img_width
            y_center = (box.y1 + box.y2) / 2 / img_height
            width = (box.x2 - box.x1) / img_width
            height = (box.y2 - box.y1) / img_height
            file.write(f"{int(class_id)} {x_center} {y_center} {width} {height}\n")

# Iterate through images and labels
for img_name in os.listdir(input_dir):
    if img_name.endswith(('.png', '.jpg', '.jpeg')):
        img_path = os.path.join(input_dir, img_name)
        label_path = os.path.join(labels_dir, f"{os.path.splitext(img_name)[0]}.txt")

        # Load image
        img = cv2.imread(img_path)
        img_height, img_width = img.shape[:2]

        # Read YOLO labels
        boxes = read_yolo_labels(label_path, img_width, img_height)
        bbs = BoundingBoxesOnImage([box[1] for box in boxes], shape=img.shape)

        # Track used combinations to avoid duplicates
        used_combinations = []

        # Generate multiple augmentations for each image
        for i in range(num_augmentations):
            # Keep generating new augmentation until we find a unique one
            while True:
                augmentations = iaa.SomeOf((1, 3), augmentation_list).to_deterministic()  # Create a deterministic sequence
                # Get a string representation of the augmentations for comparison
                aug_str = str(augmentations)

                # If this combination is not used before, break the loop
                if aug_str not in used_combinations:
                    used_combinations.append(aug_str)
                    break

            # Augment image and bounding boxes
            img_aug, bbs_aug = augmentations(image=img, bounding_boxes=bbs)
            bbs_aug = bbs_aug.remove_out_of_image().clip_out_of_image()

            # Save augmented image
            output_img_name = f"{os.path.splitext(img_name)[0]}_aug_{i+1}.jpg"
            output_img_path = os.path.join(output_dir, output_img_name)
            cv2.imwrite(output_img_path, img_aug)

            # Save augmented labels in YOLO format
            augmented_boxes = [(boxes[i][0], bbs_aug[i]) for i in range(len(bbs_aug))]
            output_label_name = f"{os.path.splitext(output_img_name)[0]}.txt"
            output_label_path = os.path.join(output_labels_dir, output_label_name)
            write_yolo_labels(output_label_path, augmented_boxes, img_width, img_height)

print("Augmentation and labeling completed.")
