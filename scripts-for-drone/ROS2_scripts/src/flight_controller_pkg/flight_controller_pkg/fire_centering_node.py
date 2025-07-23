import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from geometry_msgs.msg import PoseStamped
from msgs.msg import TrackedDetections
import math
import time
import cosysairsim as airsim

CENTER_X = 640 // 2
CENTER_Y = 512 // 2

class FireCenteringController(Node):
    def __init__(self):
        super().__init__('fire_centering_controller')

        self.subscription = self.create_subscription(
            TrackedDetections,
            '/camera/fused/tracked/detections_with_gps',
            self.fire_callback,
            10
        )
        self.pause_pub = self.create_publisher(Bool, '/mission/pause_navigation', 10)
        self.resume_pub = self.create_publisher(PoseStamped, '/mission/resume_waypoint', 10)
        self.timer = self.create_timer(0.2, self.navigation_loop)

        self.fire_to_center = None
        self.awaiting_completion = False
        self.frames_since_detection = 0
        self.max_missed_frames = 10
        self.last_known_offset_x = 0
        self.last_known_offset_y = 0
        self.last_known_fire_detected = False
        self.holding_center = False
        self.hold_start_time = None
        self.hold_duration_sec = 10
        self.centered_frame_count = 0
        self.required_centered_frames = 1
        self.recently_centered_ids = set()
        self.last_candidates = []
        self.no_remaining_fires_count = 0

        while True:
            try:
                self.client = airsim.MultirotorClient()
                self.client.confirmConnection()
                self.client.enableApiControl(True)
                self.client.armDisarm(True)
                self.get_logger().info("Connected to AirSim.")
                break
            except Exception as e:
                self.get_logger().warn(f"Waiting for AirSim: {e}")
                time.sleep(1)

    def fire_callback(self, msg: TrackedDetections):
        tracks = msg.tracks
        rgb_fires = [obj for obj in tracks if obj.label == "rgb_fire"]
        thermal_fires = [obj for obj in tracks if obj.label == "thermal_fire"]

        candidates = []
        matched_rgb_ids = set()
        matched_thermal_ids = set()

        for t in thermal_fires:
            for r in rgb_fires:
                iou = self.compute_iou(t.box, r.box)
                if iou >= 0.5:
                    cx = ((t.box[0] + t.box[2]) + (r.box[0] + r.box[2])) // 4
                    cy = ((t.box[1] + t.box[3]) + (r.box[1] + r.box[3])) // 4
                    combined_id = f"{t.id}_{r.id}"
                    if combined_id not in self.recently_centered_ids:
                        candidates.append((cx, cy, combined_id))
                        matched_rgb_ids.add(r.id)
                        matched_thermal_ids.add(t.id)
                    break

        for r in rgb_fires:
            if r.id not in matched_rgb_ids and r.confidence >= 0.7 and str(r.id) not in self.recently_centered_ids:
                cx = (r.box[0] + r.box[2]) // 2
                cy = (r.box[1] + r.box[3]) // 2
                candidates.append((cx, cy, str(r.id)))

        for t in thermal_fires:
            if t.id not in matched_thermal_ids and t.confidence >= 0.5 and str(t.id) not in self.recently_centered_ids:
                cx = (t.box[0] + t.box[2]) // 2
                cy = (t.box[1] + t.box[3]) // 2
                candidates.append((cx, cy, str(t.id)))

        self.last_candidates = candidates

        if candidates:
            self.frames_since_detection = 0
            self.last_known_fire_detected = True
            closest = min(candidates, key=lambda x: abs(x[0] - CENTER_X) + abs(x[1] - CENTER_Y))
            offset_x = closest[0] - CENTER_X
            offset_y = closest[1] - CENTER_Y
            self.last_known_offset_x = offset_x
            self.last_known_offset_y = offset_y
            self.fire_to_center = (closest[0], closest[1])
            self.current_fire_id = closest[2]

            if not self.awaiting_completion:
                self.pause_pub.publish(Bool(data=True))
                self.awaiting_completion = True

            self.no_remaining_fires_count = 0

        else:
            self.frames_since_detection += 1
            self.last_known_fire_detected = False
            if self.frames_since_detection > self.max_missed_frames:
                self.get_logger().warn("[FIRE] Lost fire for too long. Going to next waypoint.")
                self.reset_after_fire()

    def navigation_loop(self):
        self.get_logger().info(f"[DEBUG] nav loop | holding={self.holding_center}, fire_to_center={self.fire_to_center}, offset_x={self.last_known_offset_x}")

        if self.fire_to_center and not self.holding_center:
            offset_x = self.last_known_offset_x
            offset_y = self.last_known_offset_y
            yaw_rate = max(min(0.05 * offset_x, 30), -30)

            if abs(offset_x) <= 30 and abs(offset_y) <= 30:
                self.centered_frame_count += 1
            else:
                self.centered_frame_count = 0

            if self.centered_frame_count >= self.required_centered_frames:
                if self.hold_start_time is None:
                    self.get_logger().info("[FIRE] Object centered. Holding for 10 seconds...")
                    self.client.hoverAsync().join()
                    self.hold_start_time = time.time()
                    self.holding_center = True
                return

            self.client.moveByVelocityBodyFrameAsync(
                vx=3, vy=0, vz=0,
                duration=1.0,
                drivetrain=airsim.DrivetrainType.ForwardOnly,
                yaw_mode=airsim.YawMode(is_rate=True, yaw_or_rate=yaw_rate)
            ).join()

        elif self.holding_center:
            if not self.last_known_fire_detected:
                self.get_logger().warn("[FIRE] Lost fire during hold. Resetting...")
                self.reset_after_fire()
                return

            if time.time() - self.hold_start_time >= self.hold_duration_sec:
                self.get_logger().info("[FIRE] Hold complete. Checking for other fires...")
                self.recently_centered_ids.add(self.current_fire_id)
                remaining = [c for c in self.last_candidates if c[2] not in self.recently_centered_ids]
                if remaining:
                    next_target = min(remaining, key=lambda x: abs(x[0] - CENTER_X) + abs(x[1] - CENTER_Y))
                    self.fire_to_center = (next_target[0], next_target[1])
                    self.last_known_offset_x = next_target[0] - CENTER_X
                    self.last_known_offset_y = next_target[1] - CENTER_Y
                    self.current_fire_id = next_target[2]
                    self.holding_center = False
                    self.hold_start_time = None
                    self.centered_frame_count = 0
                    self.get_logger().info("[FIRE] Switching to next fire target.")
                else:
                    self.no_remaining_fires_count += 1
                    if self.no_remaining_fires_count >= 3:
                        self.reset_after_fire()

    def reset_after_fire(self):
        self.get_logger().info("[RESET] Fire state reset → ready for new centering.")
        self.fire_to_center = None
        self.awaiting_completion = False
        self.holding_center = False
        self.hold_start_time = None
        self.centered_frame_count = 0
        self.no_remaining_fires_count = 0
        self.pause_pub.publish(Bool(data=False))

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
    node = FireCenteringController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.client.armDisarm(False)
        node.client.enableApiControl(False)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
