import rclpy
from rclpy.node import Node
from msgs.msg import TrackedDetections
from datetime import datetime

class AlertSystemNode(Node):
    def __init__(self):
        super().__init__('alert_system_node')
        self.subscription = self.create_subscription(
            TrackedDetections,
            '/camera/fused/tracked/detections_with_gps',
            self.callback,
            10
        )

        # Separate seen ID sets
        self.rgb_seen_ids = set()
        self.thermal_seen_ids = set()
        self.matched_rgb_ids, self.matched_thermal_ids = set(), set()

        # Frame counters to reset after 50 frames
        self.rgb_miss_counter = 0
        self.thermal_miss_counter = 0
        self.max_miss_threshold = 50

        self.get_logger().info("Alert system node started.")

    def callback(self, msg: TrackedDetections):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        lat, lon, alt = msg.gps.latitude, msg.gps.longitude, msg.gps.altitude - 100
        grouped_fire_lines = []
        alert_lines = []

        rgb_fires, thermal_fires = [], []
        new_detections = []

        rgb_found, thermal_found = False, False

        for obj in msg.tracks:
            # RGB modality labels
            if obj.label in ["rgb_fire", "smoke"]:
                rgb_found = True
                if obj.id not in self.rgb_seen_ids:
                    new_detections.append(obj)
                    if obj.label == "rgb_fire":
                        rgb_fires.append(obj)
                elif obj.id not in self.matched_rgb_ids:
                    if obj.label == "rgb_fire":
                        rgb_fires.append(obj)

            # Thermal modality labels
            elif obj.label in ["thermal_fire", "human", "animal"]:
                thermal_found = True
                if obj.id not in self.thermal_seen_ids:
                    new_detections.append(obj)
                    if obj.label == "thermal_fire":
                        thermal_fires.append(obj)
                elif obj.id not in self.matched_thermal_ids:
                    if obj.label == "thermal_fire":
                        thermal_fires.append(obj)
        
        # Reset RGB IDs if nothing seen
        if not rgb_found:
            self.rgb_miss_counter += 1
            if self.rgb_miss_counter >= self.max_miss_threshold:
                self.get_logger().info("Resetting RGB seen IDs after 50 frames of no RGB detections.")
                self.rgb_seen_ids.clear()
                self.matched_rgb_ids.clear()
                self.rgb_miss_counter = 0
        else:
            self.rgb_miss_counter = 0

        # Reset Thermal IDs if nothing seen
        if not thermal_found:
            self.thermal_miss_counter += 1
            if self.thermal_miss_counter >= self.max_miss_threshold:
                self.get_logger().info("Resetting Thermal seen IDs after 50 frames of no Thermal detections.")
                self.thermal_seen_ids.clear()
                self.matched_thermal_ids.clear()
                self.thermal_miss_counter = 0
        else:
            self.thermal_miss_counter = 0

        # Match RGB and Thermal Fires
        for t_obj in thermal_fires:
            for r_obj in rgb_fires:
                iou = self.compute_iou(t_obj.box, r_obj.box)
                if iou >= 0.5:
                    conf = max(t_obj.confidence, r_obj.confidence)
                    grouped_fire_lines.append(
                        f"[WARNING!] FIRE DETECTED (THERMAL+RGB) | Confidence: {conf:.2f} | Thermal ID: {t_obj.id}, RGB ID: {r_obj.id}"
                    )
                    self.rgb_seen_ids.add(r_obj.id)
                    self.thermal_seen_ids.add(t_obj.id)
                    self.matched_rgb_ids.add(r_obj.id)
                    self.matched_thermal_ids.add(t_obj.id)
                    break

        # RGB ONLY
        for obj in rgb_fires:
            if obj.id not in self.rgb_seen_ids and obj.confidence >= 0.7:
                grouped_fire_lines.append(
                    f"[WARNING!] FIRE DETECTED (RGB ONLY) | Confidence: {obj.confidence:.2f} | RGB ID: {obj.id}"
                )
                self.rgb_seen_ids.add(obj.id)

        # THERMAL ONLY
        for obj in thermal_fires:
            if obj.id not in self.thermal_seen_ids and obj.confidence >= 0.5:
                grouped_fire_lines.append(
                    f"[WARNING!] FIRE DETECTED (THERMAL ONLY) | Confidence: {obj.confidence:.2f} | Thermal ID: {obj.id}"
                )
                self.thermal_seen_ids.add(obj.id)

        # Other alerts
        types = {"human": [], "smoke": [], "animal": []}
        for obj in new_detections:
            if obj.label in types:
                types[obj.label].append((obj.confidence, obj.id))

        for label in types:
            for conf, obj_id in types[label]:
                if label == "smoke" :
                    self.rgb_seen_ids.add(obj_id)
                else:
                    self.thermal_seen_ids.add(obj_id)
                prefix = "[WARNING!] " if label == "smoke" else ""
                alert_lines.append(f"{prefix}{label.upper()} DETECTED | Confidence: {conf:.2f} | ID: {obj_id}")

        # Print logs
        if grouped_fire_lines or alert_lines:
            header = f"[{timestamp}] ALERT @ GPS: (Lat: {lat:.5f}, Lon: {lon:.5f} and Alt: {alt:.2f} m)"
            full_log = [header] + grouped_fire_lines + alert_lines
            self.get_logger().warn("\n".join(full_log))

    def compute_iou(self, box1, box2):
        xA = max(box1[0], box2[0])
        yA = max(box1[1], box2[1])
        xB = min(box1[2], box2[2])
        yB = min(box1[3], box2[3])
        inter_area = max(0, xB - xA) * max(0, yB - yA)
        if inter_area == 0:
            return 0.0
        box1_area = (box1[2] - box1[0]) * (box1[3] - box1[1])
        box2_area = (box2[2] - box2[0]) * (box2[3] - box2[1])
        return inter_area / float(box1_area + box2_area - inter_area)


def main(args=None):
    rclpy.init(args=args)
    node = AlertSystemNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
