import cv2
from PIL import Image, ImageEnhance
import numpy as np

def sharpen_image(input_path, output_path, sharpness_factor=2.0):
    # Load the image with OpenCV
    image = cv2.imread(input_path)
    if image is None:
        raise FileNotFoundError(f"Cannot load image at {input_path}")

    # Convert from BGR (OpenCV format) to RGB (PIL format)
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Convert to PIL Image
    pil_image = Image.fromarray(image_rgb)

    # Apply sharpening
    enhancer = ImageEnhance.Sharpness(pil_image)
    sharpened_image = enhancer.enhance(sharpness_factor)

    # Convert back to OpenCV format (BGR)
    sharpened_bgr = cv2.cvtColor(np.array(sharpened_image), cv2.COLOR_RGB2BGR)

    # Save the sharpened image
    cv2.imwrite(output_path, sharpened_bgr)

    print(f"Sharpened image saved to {output_path}")

def center_crop(image, target_width, target_height):
    """Crop the center of an image to (target_width, target_height)."""
    height, width = image.shape[:2]
    center_x, center_y = width // 2, height // 2

    x1 = max(center_x - target_width // 2, 0)
    y1 = max(center_y - target_height // 2, 0)
    x2 = x1 + target_width
    y2 = y1 + target_height

    cropped_image = image[y1:y2, x1:x2]
    return cropped_image

if __name__ == "__main__":
    image_path_rgb = "image_11_camera_0.png"    # Change this to your input image path
    image_path_ir = "image_11_camera_1.png"  # Output path

    sharpen_image(image_path_rgb, image_path_rgb, sharpness_factor=7)  # You can adjust the sharpness
    
    img0 = cv2.imread(image_path_rgb)
    img1 = cv2.imread(image_path_ir)  # Change this to your second image path
    # For RGB
    #img0 = center_crop(img0, 1280, 1024)

    # For Thermal
    #img1 = cv2.resize(img1, (1280, 1024), interpolation=cv2.INTER_NEAREST)
    # Convert images to grayscale
    gray0 = cv2.cvtColor(img0, cv2.COLOR_BGR2GRAY)
    gray1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
    # Find the chessboard corners
    ret0, corners0 = cv2.findChessboardCorners(gray0, (9,6), criteria)
    print(ret0)
    ret1, corners1 = cv2.findChessboardCorners(gray1, (9,6), criteria)
    print(ret1)
    # cv2.drawChessboardCorners(img0, (9,6), corners0, ret0)
    # cv2.drawChessboardCorners(img1, (9,6), corners1, ret1)
    cv2.imwrite(image_path_rgb, img0)
    cv2.imwrite(image_path_ir, img1)
