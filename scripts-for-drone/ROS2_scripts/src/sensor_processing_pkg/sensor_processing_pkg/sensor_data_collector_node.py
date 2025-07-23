import rclpy
from rclpy.node import Node
from msgs.msg import SensorData
from sensor_msgs.msg import NavSatFix
from cv_bridge import CvBridge
import cosysairsim as airsim
import numpy as np
import time
import cv2

class AirSimDataPublisher(Node):
    """
    A ROS2 node that captures RGB, Thermal images, and GPS data from AirSim
    and publishes them as SensorData messages.
    """
    def __init__(self):
        super().__init__('airsim_data_publisher')

        # Publishers
        self.sensor_data_pub = self.create_publisher(SensorData, '/airsim/thesis_drone/sensors/rgb_thermal_gps_data', 10)

        self.bridge = CvBridge()
        
        while True:
            try:
                # Connect to AirSim
                self.client = airsim.MultirotorClient()
                self.client.confirmConnection()
                self.client.enableApiControl(True)
                self.client.armDisarm(True)
                self.get_logger().info("Connected to AirSim.")
                break
            except Exception as e:
                self.get_logger().warn(f"Waiting for AirSim: {e}")
                time.sleep(1)

        # 10 FPS
        self.timer = self.create_timer(0.1, self.publish_data)
        self.get_logger().info("AirSim Data Publisher started at 10 FPS.")

    def publish_data(self):
        sensor_data = SensorData()
        try:
            # === Image Capture from the 2 Cameras ===
            responses = self.client.simGetImages([
                airsim.ImageRequest("my_rgb_camera", airsim.ImageType.Scene, pixels_as_float=False, compress=False),
                airsim.ImageRequest("my_infrared_camera", airsim.ImageType.FireVisionThermal, pixels_as_float=False, compress=False)
            ])

            for i, response in enumerate(responses):
                if response.width == 0 or response.height == 0:
                    self.get_logger().warn("Empty image received.")
                    continue

                img = np.frombuffer(response.image_data_uint8, dtype=np.uint8)
                img = img.reshape((response.height, response.width, 3))
                img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
                msg = self.bridge.cv2_to_imgmsg(img, encoding='rgb8')

                if i == 0:
                    sensor_data.rgb_image = msg
                else:
                    sensor_data.thermal_image = msg

            # === GPS Capture ===
            gps_data = self.client.getGpsData()
            gps_msg = NavSatFix()
            gps_msg.latitude = gps_data.gnss.geo_point.latitude
            gps_msg.longitude = gps_data.gnss.geo_point.longitude
            gps_msg.altitude = gps_data.gnss.geo_point.altitude
            sensor_data.gps = gps_msg

            self.sensor_data_pub.publish(sensor_data)

        except Exception as e:
            self.get_logger().error(f"Error capturing or publishing data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = AirSimDataPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
