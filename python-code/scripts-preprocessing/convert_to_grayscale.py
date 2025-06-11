from PIL import Image, ImageOps
import os

def convert_folder_to_grayscale(input_folder, output_folder):
    # Ensure the output directory exists
    os.makedirs(output_folder, exist_ok=True)

    # Loop through all files in the input folder
    for filename in os.listdir(input_folder):
        # Construct full file path
        input_path = os.path.join(input_folder, filename)
        output_path = os.path.join(output_folder, filename)

        # Check if the file is an image (optional, you can add more formats if needed)
        if filename.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.tiff')):
            try:
                # Load the image
                image = Image.open(input_path)

                # Convert the image to grayscale
                grayscale_image = ImageOps.grayscale(image)

                # Save the grayscale image
                grayscale_image.save(output_path)
                print(f"Grayscale image saved: {output_path}")
            except Exception as e:
                print(f"Failed to process {filename}: {e}")

# Example usage
input_folder = '../test/images'
output_folder = 'test_grayscale'

convert_folder_to_grayscale(input_folder, output_folder)