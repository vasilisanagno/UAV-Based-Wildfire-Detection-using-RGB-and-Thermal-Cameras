import os

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

def count_unique_images(folder_path):
    """
    Count images in a folder, only counting those with different normalized names.
    """
    # Check if the folder exists
    if not os.path.exists(folder_path):
        print("Folder does not exist.")
        return 0
    
    images = os.listdir(folder_path)
    previous_normalized_name = None
    unique_image_count = 0

    for image_name in images:
        normalized_name = normalize_filename(image_name)
        
        if normalized_name != previous_normalized_name:
            unique_image_count += 1
            previous_normalized_name = normalized_name  # Update the previous name for the next iteration
    
    return unique_image_count

# Example usage:
folder_path = '../datasets/human_thermal_dataset/dataset_2/train/images'
unique_image_count = count_unique_images(folder_path)
print(f"Total unique images: {unique_image_count}")