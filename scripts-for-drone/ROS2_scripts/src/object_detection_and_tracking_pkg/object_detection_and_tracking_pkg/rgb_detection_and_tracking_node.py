import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from msgs.msg import ImageWithGPS
from msgs.msg import DetectionWithGPS
from cv_bridge import CvBridge
from ultralytics import YOLO
from deep_sort_realtime.deepsort_tracker import DeepSort
from ament_index_python.packages import get_package_share_directory
import os

class RGBDetectionNode(Node):
    """
    A ROS2 node that subscribes to RGB images with GPS data,
    performs object detection using YOLOv8 and tracking using DEEPSORT or BOTSORT or BYTETRACK, and publishes the results.
    """
    def __init__(self):
        super().__init__('rgb_detection_node')
        pkg_path = get_package_share_directory('object_detection_and_tracking_pkg')
        model_path = os.path.join(pkg_path, 'weights', 'yolo_rgb.engine')

        # Load YOLOv8 model
        self.model = YOLO(model_path)
        self.get_logger().info(f"YOLOv8 model loaded from {model_path}")
        
        self.declare_parameter('tracker_type', 'deepsort')
        
        # Get the value
        self.tracker_type = self.get_parameter('tracker_type').get_parameter_value().string_value

        self.get_logger().info(f"Using tracker type: {self.tracker_type}")
        
        if self.tracker_type == 'deepsort':
            self.rgb_tracker = DeepSort(max_age=50, max_iou_distance=0.5, nms_max_overlap=0.5, bgr=False, embedder="mobilenet", n_init=3)

        # Subscribe to ImageWithGPS
        self.subscription = self.create_subscription(
            ImageWithGPS,
            '/camera/rgb/image_with_gps',
            self.listener_callback,
            10
        )

        # Publisher for detection results
        self.detection_pub = self.create_publisher(DetectionWithGPS, '/camera/rgb/detections_with_gps', 10)
        self.bridge = CvBridge()
        self.rgb_empty_count = 0  # count consecutive empty RGB frames

    def listener_callback(self, msg: ImageWithGPS):
        try:
            rgb_image = self.bridge.imgmsg_to_cv2(msg.image, desired_encoding='rgb8')
        except Exception as e:
            self.get_logger().error(f"cv_bridge error: {e}")
            return
        
        results = None
        # Run prediction
        if self.tracker_type == 'deepsort':
            results = next(self.model.predict(source=rgb_image, verbose=False, conf=0.4, imgsz=(512, 640), stream=True))
        elif self.tracker_type in ['botsort', 'bytetrack']:
            results = next(self.model.track(source=rgb_image, verbose=False, conf=0.4, imgsz=(512, 640), stream=True, persist=True, tracker=f"{self.tracker_type}.yaml"))

        if len(results.boxes) == 0:
            self.rgb_empty_count += 1
            if self.rgb_empty_count >= 50:
                self.get_logger().warn("No RGB detections for 50 frames, resetting RGB tracker.")
                if self.tracker_type == 'deepsort':
                    self.rgb_tracker = DeepSort(max_age=50, max_iou_distance=0.5, nms_max_overlap=0.5, bgr=False, embedder="mobilenet", n_init=3)
                elif self.tracker_type in ['botsort', 'bytetrack']:
                    self.model.predictor.trackers[0].reset()
                self.rgb_empty_count = 0
        else:
            self.rgb_empty_count = 0
        
        # Parse predictions
        labels = []
        confidences = []
        boxes = []
        tracking_ids = []
        
        if self.tracker_type == 'deepsort':
            rgb_detections = []
            for box, conf, cls in zip(results.boxes.xyxy, results.boxes.conf, results.boxes.cls):
                x1, y1, x2, y2 = map(int, box.tolist())
                w, h = x2 - x1, y2 - y1
                label = self.model.names[int(cls)]
                
                if label in ['fire', 'smoke']:
                    rgb_detections.append(((x1, y1, w, h), float(conf), label))
                    
            rgb_tracks = self.rgb_tracker.update_tracks(rgb_detections, frame=rgb_image)
            for track in rgb_tracks:
                if not track.is_confirmed() or track.get_det_conf() is None:
                    continue
                
                label = track.get_det_class()
                conf = track.get_det_conf()
                track_id = int(track.track_id)
                x1, y1, x2, y2 = track.to_ltrb()
                labels.append(label)
                confidences.append(float(conf))
                boxes.extend([int(x1), int(y1), int(x2), int(y2)])
                tracking_ids.append(track_id)
        elif self.tracker_type in ['botsort', 'bytetrack']:
            for box in results.boxes:
                cls_id = int(box.cls.item())
                conf = float(box.conf.item())
                xyxy = box.xyxy.squeeze().tolist()  # [x1, y1, x2, y2]

                labels.append(self.model.names[cls_id])
                confidences.append(conf)
                boxes.extend(xyxy)  # flatten the boxes list
                
                # Track ID (if available, else -1)
                track_id = int(box.id.item()) if box.id is not None else -1
                tracking_ids.append(track_id)

        # Create and publish DetectionWithGPS
        detection_msg = DetectionWithGPS()
        detection_msg.header = Header()
        detection_msg.header.stamp = self.get_clock().now().to_msg()
        detection_msg.labels = labels
        detection_msg.confidences = confidences
        detection_msg.boxes = boxes
        detection_msg.tracking_ids = tracking_ids
        detection_msg.gps = msg.gps
        detection_msg.image = msg.image

        self.detection_pub.publish(detection_msg)

        #self.get_logger().info(f"Published {len(labels)} RGB detections with GPS")

def main(args=None):
    rclpy.init(args=args)
    node = RGBDetectionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
