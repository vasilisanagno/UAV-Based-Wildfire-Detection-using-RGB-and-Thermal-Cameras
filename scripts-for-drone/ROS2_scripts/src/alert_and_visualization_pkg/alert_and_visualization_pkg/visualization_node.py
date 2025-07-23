import rclpy
from rclpy.node import Node
from msgs.msg import TrackedDetections
from cv_bridge import CvBridge
import cv2
import numpy as np

class VisualizationNode(Node):
    """
    A ROS2 node that subscribes to tracked detection messages,
    visualizes the detections on RGB and Thermal images, and displays them.
    """
    def __init__(self):
        super().__init__('visualization_node')
        self.subscription = self.create_subscription(
            TrackedDetections,
            '/camera/fused/tracked/detections_with_gps',
            self.callback,
            10
        )

        self.bridge = CvBridge()
        self.rgb_ids = {}
        self.thermal_ids = {}
        self.global_id_counter = 1

        self.get_logger().info("Visualization node with OpenCV started.")

    def callback(self, msg: TrackedDetections):
        try:
            rgb_frame = self.bridge.imgmsg_to_cv2(msg.rgb_image, desired_encoding='rgb8')
        except Exception as e:
            self.get_logger().warn(f"RGB image failed: {e}")
            rgb_frame = None

        try:
            thermal_frame = self.bridge.imgmsg_to_cv2(msg.thermal_image, desired_encoding='rgb8')
        except Exception as e:
            self.get_logger().warn(f"Thermal image failed: {e}")
            thermal_frame = None

        if rgb_frame is None and thermal_frame is None:
            self.get_logger().warn("No images available to visualize.")
            return

        for obj in msg.tracks:
            if obj.confidence < 0.5:
                continue
            x1, y1, x2, y2 = map(int, obj.box)
            color = (0, 255, 0)
            frame = rgb_frame

            if obj.label == "rgb_fire":
                color = (0, 0, 255)
                label = "fire"
            elif obj.label == "thermal_fire":
                color = (0, 0, 255)
                frame = thermal_frame
                label = "fire"
            elif obj.label == "human":
                color = (255, 0, 0)
                frame = thermal_frame
                label = "human"
            elif obj.label == "smoke":
                color = (0, 255, 255)
                label = "smoke"
            elif obj.label == "animal":
                color = (255, 0, 255)
                frame = thermal_frame
                label = "animal"
            else:
                label = obj.label
            
            track_text = f"{label} ID:{obj.id} ({obj.confidence:.2f})"
            cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
            cv2.putText(frame, track_text, (x1, y1 - 5),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, color, 2)

        header = "GPS Data"
        latlon_text = f"Lat: {msg.gps.latitude:.5f}  Lon: {msg.gps.longitude:.5f}"
        alt_text = f"Alt: {msg.gps.altitude - 100:.2f} m"

        def format_gps(frame):
            cv2.putText(frame, header, (10, 25),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            cv2.putText(frame, latlon_text, (10, 50),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
            cv2.putText(frame, alt_text, (10, 75),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

        if rgb_frame is not None:
            format_gps(rgb_frame)
            cv2.imshow("RGB Tracked Detections", rgb_frame)

        if thermal_frame is not None:
            format_gps(thermal_frame)
            cv2.imshow("Thermal Tracked Detections", thermal_frame)

        cv2.waitKey(1)

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = VisualizationNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
