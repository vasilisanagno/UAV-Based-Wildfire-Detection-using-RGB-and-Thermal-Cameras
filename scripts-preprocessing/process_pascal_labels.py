import os
from lxml import etree

def remove_polygon_from_xml(file_path):
    """
    Remove <polygon> tags from a Pascal VOC XML file.
    
    :param file_path: Path to the XML file.
    """
    try:
        tree = etree.parse(file_path)
        root = tree.getroot()

        # Find and remove all <polygon> tags
        for polygon in root.findall(".//polygon"):
            parent = polygon.getparent()  # Get the parent element
            if parent is not None:
                parent.remove(polygon)

        # Save the updated XML back to the same file
        with open(file_path, 'wb') as f:
            tree.write(f, pretty_print=True, encoding='UTF-8', xml_declaration=True)

        print(f"Removed <polygon> tag from '{file_path}'.")

    except Exception as e:
        print(f"Failed to process '{file_path}' for polygon removal: {e}")


def rename_label_in_xml(file_path, old_label, new_label):
    """
    Rename a label in a Pascal VOC XML file.
    
    :param file_path: Path to the XML file.
    :param old_label: The label name to rename.
    :param new_label: The new label name.
    """
    try:
        tree = etree.parse(file_path)
        root = tree.getroot()

        # Rename labels
        for obj in root.findall(".//object"):
            name = obj.find("name")
            if name is not None and name.text == old_label:
                name.text = new_label

        # Save the updated XML back to the same file
        with open(file_path, 'wb') as f:
            tree.write(f, pretty_print=True, encoding='UTF-8', xml_declaration=True)

        print(f"Renamed label '{old_label}' to '{new_label}' in '{file_path}'.")

    except Exception as e:
        print(f"Failed to process '{file_path}' for label renaming: {e}")


def process_folder(base_dir, function, *args):
    """
    Apply a given function to all XML files in `labels` subdirectories
    of `train`, `test`, `valid` folders.
    
    :param base_dir: Path to the base directory containing train/test/valid folders.
    :param function: The function to apply to each XML file.
    :param args: Additional arguments to pass to the function.
    """
    subdirs = ['train', 'valid', 'test']

    for subdir in subdirs:
        labels_dir = os.path.join(base_dir, subdir, 'labels_pascal')
        if not os.path.exists(labels_dir):
            print(f"Skipping: {labels_dir} (Directory does not exist)")
            continue

        # Process all .xml files in the labels directory
        for filename in os.listdir(labels_dir):
            if filename.endswith('.xml'):
                file_path = os.path.join(labels_dir, filename)
                print(f"Processing: {file_path}")
                function(file_path, *args)

def rename_xml_files(xml_folder):
    """
    Renames XML files to remove '.bmp' from the filenames.
    
    :param xml_folder: Path to the folder containing XML files.
    """
    for filename in os.listdir(xml_folder):
        # Process only XML files
        if filename.endswith(".xml") and ".bmp" in filename:
            # Construct the old file path
            old_file_path = os.path.join(xml_folder, filename)
            
            # Remove the '.bmp' part from the filename
            new_filename = filename.replace(".bmp", "")
            new_file_path = os.path.join(xml_folder, new_filename)
            
            # Rename the file
            os.rename(old_file_path, new_file_path)
            print(f"Renamed '{old_file_path}' to '{new_file_path}'")
            
def clamp(value, min_value, max_value):
    """Clamp a value between a minimum and maximum value."""
    return max(min_value, min(value, max_value))

def fix_xml_bounding_boxes(xml_file):
    """
    Fix bounding boxes in a Pascal VOC XML file so they don't exceed image dimensions.
    
    :param xml_file: Path to the XML file.
    """
    try:
        tree = etree.parse(xml_file)
        root = tree.getroot()

        # Fetch image dimensions from the XML file
        size = root.find("size")
        img_width = int(size.find("width").text)
        img_height = int(size.find("height").text)

        for obj in root.findall("object"):
            bndbox = obj.find("bndbox")
            xmin = int(float(bndbox.find("xmin").text))
            ymin = int(float(bndbox.find("ymin").text))
            xmax = int(float(bndbox.find("xmax").text))
            ymax = int(float(bndbox.find("ymax").text))

            # Clamp bounding box values
            new_xmin = clamp(xmin, 0, img_width - 1)
            new_ymin = clamp(ymin, 0, img_height - 1)
            new_xmax = clamp(xmax, 0, img_width - 1)
            new_ymax = clamp(ymax, 0, img_height - 1)

            # Update XML values
            bndbox.find("xmin").text = str(new_xmin)
            bndbox.find("ymin").text = str(new_ymin)
            bndbox.find("xmax").text = str(new_xmax)
            bndbox.find("ymax").text = str(new_ymax)

            # Log changes if any
            if (xmin != new_xmin or ymin != new_ymin or xmax != new_xmax or ymax != new_ymax):
                print(f"Fixed: {xml_file} -> xmin: {xmin}->{new_xmin}, ymin: {ymin}->{new_ymin}, "
                      f"xmax: {xmax}->{new_xmax}, ymax: {ymax}->{new_ymax}")

        # Save the fixed XML file
        tree.write(xml_file)
    except Exception as e:
        print(f"Error processing {xml_file}: {e}")

def main():
    base_dir = "../models-training/datasets/dataset-rgb"

    print("\nChoose an option:")
    print("1. Remove <polygon> tags from XML files")
    print("2. Rename a label in XML files")
    print("3. Rename XML files to remove '.bmp' from filenames")
    print("4. Fix bounding boxes to not exceed the coordinates from the image")
    print("5. Exit")
    choice = input("Enter your choice (1/2/3/4/5): ").strip()

    if choice == "1":
        print("\nRemoving <polygon> tags...")
        process_folder(base_dir, remove_polygon_from_xml)

    elif choice == "2":
        old_label = input("Enter the label name to rename: ").strip()
        new_label = input("Enter the new label name: ").strip()
        print(f"\nRenaming labels from '{old_label}' to '{new_label}'...")
        process_folder(base_dir, rename_label_in_xml, old_label, new_label)

    elif choice == "3":
            print("\nRenaming XML files to remove '.bmp' from filenames...")
            process_folder(base_dir, rename_xml_files)
    
    elif choice == "4":
            print("\nFix bounding boxes...")
            process_folder(base_dir, fix_xml_bounding_boxes)
            
    elif choice == "5":
        print("Exiting the program.")
        
if __name__ == "__main__":
    main()
