import cv2
import os

video_path = '../3-WhiteHot.mov'
output_folder = 'frames/'

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

cap = cv2.VideoCapture(video_path)
frame_count = 0

if not cap.isOpened():
    print("Error: Could not open video.")
    exit()

new_width = 640
new_height = 480

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Resize the frame
    resized_frame = cv2.resize(frame, (new_width, new_height), interpolation=cv2.INTER_LINEAR)

    # Save every 5th frame
    if frame_count % 5 == 0:
        frame_path = f"{output_folder}frame_{frame_count:04d}.png"
        cv2.imwrite(frame_path, resized_frame)
    
    frame_count += 1

cap.release()