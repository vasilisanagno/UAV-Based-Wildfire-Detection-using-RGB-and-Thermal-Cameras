import cv2
import numpy as np

# Define checkerboard size (number of inner corners in checkerboard pattern)
checkerboard_size = (9, 6)
square_size = 1.0  # The real-world size of each square (e.g., in meters or centimeters)
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

# Prepare object points based on the checkerboard size
object_points = np.zeros((np.prod(checkerboard_size), 3), np.float32)
object_points[:, :2] = np.indices(checkerboard_size).T.reshape(-1, 2)
object_points *= square_size

# Arrays to store object points and image points for each camera
obj_points = []
img_points_camera_0 = []  # For RGB camera
img_points_camera_1 = []  # For Thermal camera

# Loop through the images for both cameras
for i in range(0, 12):  # From image_0 to image_12
    # Read images for camera 0 (RGB) and camera 1 (Thermal)
    img0 = cv2.imread(f"image_{i}_camera_0.png")
    img1 = cv2.imread(f"image_{i}_camera_1.png")
    
    if img0 is None or img1 is None:
        print(f"Error: Unable to read image_{i}_camera_0.png or image_{i}_camera_1.png")
        continue
    
    # Convert images to grayscale
    gray0 = cv2.cvtColor(img0, cv2.COLOR_BGR2GRAY)
    gray1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)

    # Find the chessboard corners
    ret0, corners0 = cv2.findChessboardCorners(gray0, checkerboard_size, criteria)
    ret1, corners1 = cv2.findChessboardCorners(gray1, checkerboard_size, criteria)
    print(ret0, ret1)
    # If corners are found for both cameras, add the object points and image points
    if ret0 and ret1:
        obj_points.append(object_points)
        img_points_camera_0.append(corners0)
        img_points_camera_1.append(corners1)

        # Optionally draw the corners for visualization
        cv2.drawChessboardCorners(img0, checkerboard_size, corners0, ret0)
        cv2.drawChessboardCorners(img1, checkerboard_size, corners1, ret1)

        # Save images with drawn corners (optional)
        cv2.imwrite(f"image_{i}_camera_0_with_corners.png", img0)
        cv2.imwrite(f"image_{i}_camera_1_with_corners.png", img1)
    else :
        print(f"Chessboard corners not found for image_{i}_camera_0.png or image_{i}_camera_1.png")
        exit(1)

# Perform camera calibration for both cameras
# Camera 0 (RGB)
ret0, mtx0, dist0, rvecs0, tvecs0 = cv2.calibrateCamera(obj_points, img_points_camera_0, gray0.shape[::-1], None, None)
# Camera 1 (Thermal)
ret1, mtx1, dist1, rvecs1, tvecs1 = cv2.calibrateCamera(obj_points, img_points_camera_1, gray1.shape[::-1], None, None)

# Save the calibration results to files
np.savez("camera_0_calibration.npz", camera_matrix=mtx0, dist_coeffs=dist0)
np.savez("camera_1_calibration.npz", camera_matrix=mtx1, dist_coeffs=dist1)

# Optionally print the results
print("Camera 0 Calibration Matrix (RGB):")
print(mtx0)
print("Camera 0 Distortion Coefficients (RGB):")
print(dist0)

print("Camera 1 Calibration Matrix (Thermal):")
print(mtx1)
print("Camera 1 Distortion Coefficients (Thermal):")
print(dist1)

# Convert the rotation vectors (rvecs) to rotation matrices using cv2.Rodrigues
R0, _ = cv2.Rodrigues(rvecs0[0])
R1, _ = cv2.Rodrigues(rvecs1[0])

# Compute the relative rotation (R_rel) and translation (T_rel) between the two cameras
R_rel = R1.T @ R0  # Relative rotation (R1 to R0)
T_rel = R1.T @ (tvecs0[0] - tvecs1[0])  # Relative translation (T1 to T0)

# Print the relative rotation and translation
print("\nRelative Rotation Matrix (R_rel) between Cameras 0 (RGB) and 1 (Thermal):")
print(R_rel)

print("\nRelative Translation Vector (T_rel) between Cameras 0 (RGB) and 1 (Thermal):")
print(T_rel)

# Final homography including translation
# H = mtx0 @ middle_matrix @ np.linalg.inv(mtx1)
H, mask = cv2.findHomography(corners1, corners0, cv2.RANSAC, 5.0)
# Save the homography matrix to a file
np.savez("homography_matrix.npz", homography=H)

# Optionally print the homography matrix
print("\nFinal Homography Matrix:")
print(H)

# === Load one example image from each camera ===
img0 = cv2.imread("image_12_camera_0.png")  # RGB camera
img1 = cv2.imread("image_12_camera_1.png")  # Thermal camera

# === UNDISTORT images first ===
# Undistort correctly
# img0_undistorted = cv2.undistort(img0, mtx0, dist0, None, mtx0)
# img0_undistorted = cv2.undistort(img1, mtx1, dist1, None, mtx1)

# # Save
# cv2.imwrite("image_0_undistorted.png", img0_undistorted)
# cv2.imwrite("image_12_undistorted.png", img0_undistorted)

#img1 = cv2.undistort(img1, mtx1, dist1, None, mtx1)
# Check if images are loaded properly
if img0 is None or img1 is None:
    print("Error: Unable to load one or both images.")
    exit(1)

# === Warp img1 (camera 1) to img0 (camera 0) coordinate system using H ===
height, width = img0.shape[:2]

# Warp image1 using the computed homography
aligned_img1 = cv2.warpPerspective(img1, H, (width, height), flags=cv2.INTER_NEAREST)

gray = cv2.cvtColor(aligned_img1, cv2.COLOR_BGR2GRAY)

# Step 2: Threshold to find non-black regions
_, thresh = cv2.threshold(gray, 10, 255, cv2.THRESH_BINARY)

# Step 3: Find contours
contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

if contours:
    # Merge all contours into one bounding rectangle
    x, y, w, h = cv2.boundingRect(np.vstack(contours))

    # Optional: Add small margin
    margin = 10
    x = max(0, x - margin)
    y = max(0, y - margin)
    w = min(w + 2 * margin, aligned_img1.shape[1] - x)
    h = min(h + 2 * margin, aligned_img1.shape[0] - y)

    # === Adjust to match 640x512 aspect ratio (1.25) ===
    target_aspect = 640 / 512  # 1.25
    current_aspect = w / h

    if current_aspect > target_aspect:
        # Too wide → crop width
        new_w = int(h * target_aspect)
        delta = w - new_w
        x = x + delta // 2
        w = new_w
    else:
        # Too tall → crop height
        new_h = int(w / target_aspect)
        delta = h - new_h
        y = y + delta // 2
        h = new_h

    # Final crop for thermal (aligned image)
    cropped_thermal = aligned_img1[y:y+h, x:x+w]
    cv2.imwrite("cropped_thermal_12_image_before_resize.png", cropped_thermal)
    final_thermal = cv2.resize(cropped_thermal, (640, 512), interpolation=cv2.INTER_NEAREST)
    cv2.imwrite("cropped_thermal_12_image.png", final_thermal)

    # Final crop for RGB
    cropped_rgb = img0[y:y+h, x:x+w]
    cv2.imwrite("cropped_rgb_image_12_before_resize.png", cropped_rgb)
    final_rgb = cv2.resize(cropped_rgb, (640, 512), interpolation=cv2.INTER_NEAREST)
    cv2.imwrite("cropped_rgb_image_12.png", final_rgb)

else:
    print("No contours found! Check if the warped image is valid.")

# === Display the original and aligned images side by side for comparison ===
cv2.imwrite("warped_image_12.png", aligned_img1)