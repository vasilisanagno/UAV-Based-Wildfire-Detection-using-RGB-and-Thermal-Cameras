import os

def update_class_id(yolo_folder_path, class_id_map):
    """
    Update specified class IDs in YOLO format annotations across train, valid, and test folders
    without adding new lines or modifying other fields.
    
    Parameters:
    yolo_folder_path (str): The base path containing train, valid, and test folders.
    class_id_map (dict): Dictionary mapping old class IDs to new ones, e.g., {0: 2}.
    """
    # Folders to check
    folders = ["train", "valid", "test"]
    
    # Process each folder
    for folder in folders:
        labels_folder = os.path.join(yolo_folder_path, folder, "labels")
        if not os.path.exists(labels_folder):
            print(f"Folder '{labels_folder}' does not exist. Skipping.")
            continue
        
        # Process each .txt file in the labels folder
        for file_name in os.listdir(labels_folder):
            if file_name.endswith(".txt"):
                file_path = os.path.join(labels_folder, file_name)
                
                # Read the file content
                with open(file_path, "r") as file:
                    lines = file.readlines()
                
                # Updated content for the file
                updated_lines = []
                for line in lines:
                    parts = line.strip().split()
                    if len(parts) >= 5:
                        class_id = int(parts[0])
                        
                        # Only change the class ID if it's in the map
                        if class_id in class_id_map:
                            parts[0] = str(class_id_map[class_id])
                        
                        # Re-join the parts to form the updated line
                        updated_lines.append(" ".join(parts))
                
                # Write updated content back to file, overwriting the original content
                with open(file_path, "w") as file:
                    file.write("\n".join(updated_lines))
                
                print(f"Updated '{file_path}'.")

# Example usage
yolo_folder_path = "../models-training/datasets/thermal_dataset"
class_id_map = {3: 2}  # Change class ID from the key to the value of the map

update_class_id(yolo_folder_path, class_id_map)
