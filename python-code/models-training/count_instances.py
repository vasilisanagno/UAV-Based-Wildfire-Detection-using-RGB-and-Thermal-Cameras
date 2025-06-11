import os
from collections import Counter

def count_yolo_classes(annotations_dir):
    """
    Counts the number of instances for each class in YOLO annotation files.

    Args:
        annotations_dir (str): Path to the directory containing YOLO .txt files.

    Returns:
        dict: A dictionary with class IDs as keys and their counts as values.
    """
    class_counts = Counter()

    # Iterate through all .txt files in the directory
    for filename in os.listdir(annotations_dir):
        if filename.endswith('.txt'):
            file_path = os.path.join(annotations_dir, filename)

            with open(file_path, 'r') as file:
                for line in file:
                    parts = line.strip().split()
                    if parts:  # Ensure the line is not empty
                        class_id = int(parts[0])  # The first value is the class ID
                        class_counts[class_id] += 1

    return dict(class_counts)


# Example usage
if __name__ == "__main__":
    #annotations_path = "../../models-datasets/datasets-original/animal_thermal_dataset/dataset_9/yolo/train/labels"
    annotations_path = "datasets/dataset-thermal-aug/test/labels"  # Replace with your annotations directory path
    class_counts = count_yolo_classes(annotations_path)

    print("Class Counts:")
    print(f"Fire (0): {class_counts.get(0, 0)}")
    print(f"Smoke or Human (1): {class_counts.get(1, 0)}")
    print(f"Animal (2): {class_counts.get(2, 0)}")
