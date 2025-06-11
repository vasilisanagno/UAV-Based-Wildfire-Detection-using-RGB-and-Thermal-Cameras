import os
import shutil

def normalize_filename(name):
    """
    Normalize file names by converting all spaces to dashes and handling the suffix:
    1. Replace spaces with dashes.
    2. If the file has a suffix '_jpg.rf.<hash>', remove that part.
    3. If the file has a standard '.jpg' extension, remove it.
    """
    # Replace spaces with dashes
    name = name.replace(' ', '-')
    
    # If the filename contains the _jpg.rf.<hash> pattern, strip everything after '_jpg.rf.'
    if '_jpg.rf.' in name:
        base_name = name.split('_jpg.rf.')[0]
    else:
        # Otherwise, just remove the standard file extension (e.g., .jpg)
        base_name = os.path.splitext(name)[0]
    
    return base_name

def image_exists_in_folders(normalized_name, compare_folders):
    """Check if the normalized image exists in any of the compare folders (train, test, valid)"""
    for folder in compare_folders:
        folder_path = os.path.join(folder, 'images')
        if os.path.exists(folder_path):
            for image_name in os.listdir(folder_path):
                base_image_name = normalize_filename(image_name)
                if normalized_name == base_image_name:
                    return True
    return False

def find_and_copy_images_in_all_folders(src_parent_folder, compare_folders, dest_folder):
    if not os.path.exists(dest_folder):
        os.makedirs(dest_folder)
    
    copied_images = 0

    # Iterate over all folders in the source parent directory (e.g., A Distancia, A Normal, etc.)
    for src_folder_name in os.listdir(src_parent_folder):
        src_folder_path = os.path.join(src_parent_folder, src_folder_name)
        
        if os.path.isdir(src_folder_path):
            print(f"Processing folder: {src_folder_name}")
            
            for image_name in os.listdir(src_folder_path):
                normalized_name = normalize_filename(image_name)

                # Check if the image exists in any of the compare folders
                if not image_exists_in_folders(normalized_name, compare_folders):
                    # Copy the image to the destination folder
                    src_image_path = os.path.join(src_folder_path, image_name)
                    dest_image_path = os.path.join(dest_folder, image_name)
                    shutil.copy2(src_image_path, dest_image_path)
                    copied_images += 1
                    print(f"Copied: {image_name} from {src_folder_name}")

    print(f"Total copied images: {copied_images}")

# Example usage:
# Folders to compare with: 'train', 'test', 'valid'
compare_folders = [
    '../datasets/human_thermal_dataset/dataset_2/train',
    '../datasets/human_thermal_dataset/dataset_2/valid',
    '../datasets/human_thermal_dataset/dataset_2/test'
]

# Call the function for the src folder against the compare folders
find_and_copy_images_in_all_folders('../images', compare_folders, './images')