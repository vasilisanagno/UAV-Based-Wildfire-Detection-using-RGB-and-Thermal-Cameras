import os
import cv2
import albumentations as A
from albumentations.augmentations.geometric.resize import LongestMaxSize
from albumentations.core.composition import OneOf

def resize_images_with_albumentations(input_dir, output_dir, max_dim=640):
    """
    Resize all images in the input directory using Albumentations while maintaining aspect ratio.

    Args:
        input_dir (str): Path to the directory containing the input images.
        output_dir (str): Path to the directory where resized images will be saved.
        max_dim (int): The maximum dimension (width or height) of the resized images.
    """
    # Ensure the output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Define the Albumentations transformation
    transform = A.Compose([
        A.LongestMaxSize(max_size=max_dim, interpolation=cv2.INTER_AREA)  # Resize maintaining aspect ratio
    ])

    # Iterate over all files in the input directory
    for filename in os.listdir(input_dir):
        input_path = os.path.join(input_dir, filename)

        # Check if the file is an image
        if not filename.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.tiff')):
            continue

        # Read the image
        image = cv2.imread(input_path)
        if image is None:
            print(f"Could not read image: {filename}")
            continue

        # Apply the resizing transformation
        augmented = transform(image=image)
        resized_image = augmented["image"]

        # Save the resized image with the same filename
        output_path = os.path.join(output_dir, filename)
        cv2.imwrite(output_path, resized_image)
        print(f"Resized and saved: {output_path}")

if __name__ == "__main__":
    input_dir = "images"  # Replace with your input directory
    output_dir = "resized_images"  # Replace with your output directory
    max_dim = 640  # Maximum dimension for resized images
    resize_images_with_albumentations(input_dir, output_dir, max_dim)

