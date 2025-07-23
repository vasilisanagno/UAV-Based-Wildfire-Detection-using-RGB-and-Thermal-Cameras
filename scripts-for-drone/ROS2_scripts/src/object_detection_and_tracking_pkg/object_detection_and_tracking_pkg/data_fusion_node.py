import rclpy
from rclpy.node import Node
from msgs.msg import DetectionWithGPS, TrackedDetections, TrackedObject
from message_filters import Subscriber, ApproximateTimeSynchronizer

class DataFusionNode(Node):
    """
    A ROS2 node that subscribes to RGB and Thermal detection messages,
    fuses them, and publishes the fused results.
    """
    def __init__(self):
        super().__init__('data_fusion_node')

        # Subscribers for RGB and Thermal detections
        self.rgb_sub = Subscriber(self, DetectionWithGPS, '/camera/rgb/detections_with_gps')
        self.thermal_sub = Subscriber(self, DetectionWithGPS, '/camera/thermal/detections_with_gps')

        self.sync = ApproximateTimeSynchronizer(
            [self.rgb_sub, self.thermal_sub],
            queue_size=10,
            slop=0.1
        )
        self.sync.registerCallback(self.fusion_callback)

        # Publisher for fused detections
        self.pub = self.create_publisher(TrackedDetections, '/camera/fused/tracked/detections_with_gps', 10)
        
        self.get_logger().info("Data Fusion Node started.")
        
    def fusion_callback(self, rgb_msg, thermal_msg):
        fused_msg = TrackedDetections()
        fused_msg.gps = rgb_msg.gps
        fused_msg.rgb_image = rgb_msg.image
        fused_msg.thermal_image = thermal_msg.image

        tracks = []

        # --- Process RGB detections ---
        for i in range(len(rgb_msg.labels)):
            obj = TrackedObject()
            obj.id = rgb_msg.tracking_ids[i]
            obj.label = "rgb_fire" if rgb_msg.labels[i] == "fire" else rgb_msg.labels[i]
            obj.confidence = rgb_msg.confidences[i]
            obj.box = rgb_msg.boxes[i*4:(i+1)*4]  # 4 values per box
            obj.source = "rgb"
            tracks.append(obj)

        # --- Process Thermal detections ---
        for i in range(len(thermal_msg.labels)):
            obj = TrackedObject()
            obj.id = thermal_msg.tracking_ids[i]
            obj.label = "thermal_fire" if thermal_msg.labels[i] == "fire" else thermal_msg.labels[i]
            obj.confidence = thermal_msg.confidences[i]
            obj.box = thermal_msg.boxes[i*4:(i+1)*4]
            obj.source = "thermal"
            tracks.append(obj)

        # Assign to message and publish
        fused_msg.tracks = tracks
        self.pub.publish(fused_msg)

def main(args=None):
    rclpy.init(args=args)
    node = DataFusionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.log_file.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
 
