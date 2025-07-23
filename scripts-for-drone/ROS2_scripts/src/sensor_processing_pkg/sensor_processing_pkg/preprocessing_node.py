import rclpy
from rclpy.node import Node
from msgs.msg import ImageWithGPS, SensorData
from cv_bridge import CvBridge
import numpy as np
import cv2
from ament_index_python.packages import get_package_share_directory
import os

class CamerasSyncNode(Node):
    """
    A ROS2 node that synchronizes RGB, Thermal, and GPS data from AirSim.
    Publishes ImageWithGPS messages to share image and GPS together.
    """
    def __init__(self):
        super().__init__('cameras_sync_node')
        pkg_path = get_package_share_directory('sensor_processing_pkg')
        homography_path = os.path.join(pkg_path, 'config', 'homography_matrix.npz')
        
        try:
            self.H = np.load(homography_path)
            self.H = self.H['homography']
            self.get_logger().info(f"Loaded homography matrix. \n{self.H}")
        except Exception as e:
            self.get_logger().error(f"Failed to load homography: {e}")
            self.H = None
        # Subscriber for RGB, Thermal, and GPS
        self.sensor_data_sub = self.create_subscription(SensorData, '/airsim/thesis_drone/sensors/rgb_thermal_gps_data', self.sensor_data_callback, 10)

        # Publishers for combined messages
        self.rgb_with_gps_pub = self.create_publisher(ImageWithGPS, '/camera/rgb/image_with_gps', 10)
        self.thermal_with_gps_pub = self.create_publisher(ImageWithGPS, '/camera/thermal/image_with_gps', 10)

        self.bridge = CvBridge()
        
        self.get_logger().info("Preprocessing node started.")

    def sensor_data_callback(self, msg: SensorData):
        if self.H is None:
            self.get_logger().error("Homography not loaded.")
            return

        try:
            rgb_img = self.bridge.imgmsg_to_cv2(msg.rgb_image, desired_encoding='rgb8')
            thermal_img = self.bridge.imgmsg_to_cv2(msg.thermal_image, desired_encoding='rgb8')
        except Exception as e:
            self.get_logger().error(f"cv_bridge error: {e}")
            return

        # Warp thermal image to align with RGB
        height, width = rgb_img.shape[:2]
        aligned_thermal = cv2.warpPerspective(thermal_img, self.H, (width, height), flags=cv2.INTER_NEAREST)

        # Find overlapping region
        gray = cv2.cvtColor(aligned_thermal, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray, 10, 255, cv2.THRESH_BINARY)
        contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if not contours:
            self.get_logger().warn("No overlap found in aligned thermal image.")
            return

        x, y, w, h = cv2.boundingRect(np.vstack(contours))
        margin = 10
        x = max(0, x - margin)
        y = max(0, y - margin)
        w = min(w + 2 * margin, aligned_thermal.shape[1] - x)
        h = min(h + 2 * margin, aligned_thermal.shape[0] - y)

        # Adjust aspect ratio to 640x512
        target_aspect = 640 / 512
        current_aspect = w / h
        if current_aspect > target_aspect:
            new_w = int(h * target_aspect)
            x += (w - new_w) // 2
            w = new_w
        else:
            new_h = int(w / target_aspect)
            y += (h - new_h) // 2
            h = new_h

        cropped_rgb = rgb_img[y:y+h, x:x+w]
        cropped_thermal = aligned_thermal[y:y+h, x:x+w]

        final_rgb = cv2.resize(cropped_rgb, (640, 512), interpolation=cv2.INTER_NEAREST)
        final_thermal = cv2.resize(cropped_thermal, (640, 512), interpolation=cv2.INTER_NEAREST)

        # Publish RGB with GPS
        rgb_combined = ImageWithGPS()
        rgb_combined.image = self.bridge.cv2_to_imgmsg(final_rgb, encoding='rgb8')
        rgb_combined.gps = msg.gps
        self.rgb_with_gps_pub.publish(rgb_combined)

        # Publish Thermal with GPS
        thermal_combined = ImageWithGPS()
        thermal_combined.image = self.bridge.cv2_to_imgmsg(final_thermal, encoding='rgb8')
        thermal_combined.gps = msg.gps
        self.thermal_with_gps_pub.publish(thermal_combined)

def main(args=None):
    rclpy.init(args=args)
    node = CamerasSyncNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
