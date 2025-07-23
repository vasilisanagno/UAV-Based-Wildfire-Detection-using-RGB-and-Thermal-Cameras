import rclpy
from rclpy.node import Node
import cosysairsim as airsim
import math
import time

class FlightControllerNode(Node):
    """
    A ROS2 node that controls a drone in AirSim using waypoints.
    The drone will take off, hover, and then follow a series of waypoints.
    The waypoints are defined in a dense pattern to cover a wide area.
    """
    def __init__(self):
        super().__init__('flight_controller_node')
        self.get_logger().info("Waiting for AirSim to be available...")

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

        # Define dense waypoint pattern to cover wide area
        self.waypoints = []
        x_positions = list(range(0, -431, -43))  # [0, -43, ..., -430]

        for idx, x in enumerate(x_positions):
            if idx % 2 == 0:
                # Even index: go up
                self.waypoints.append((x, 0, 0))
                self.waypoints.append((x, 370, 0))
            else:
                # Odd index: go down
                self.waypoints.append((x, 370, 0))
                self.waypoints.append((x, 0, 0))

        self.waypoints.append((0, 0, 0))
        self.waypoints.append((-410, 0, 0))
        self.waypoints.append((-410, 370, 0))
        self.waypoints.append((0, 370, 0))
        self.waypoints.append((0, 0, 0))
        # Start flight sequence
        self.start_flight()

    def compute_yaw_angle(self, current_pos, target_pos):
        dx = target_pos[0] - current_pos[0]
        dy = target_pos[1] - current_pos[1]
        yaw_angle = math.atan2(dy, dx)
        return math.degrees(yaw_angle)

    def start_flight(self):
        self.get_logger().info("Taking off...")
        self.client.takeoffAsync().join()
        self.client.moveToZAsync(0, 3).join()
        self.client.hoverAsync().join()

        self.get_logger().info("Starting waypoint loop...")
        while rclpy.ok():
            for target_pos in self.waypoints:
                state = self.client.getMultirotorState()
                current_pos = (
                    state.kinematics_estimated.position.x_val,
                    state.kinematics_estimated.position.y_val,
                    state.kinematics_estimated.position.z_val
                )
                
                if target_pos != (0, 0, 0):
                    yaw_angle = self.compute_yaw_angle(current_pos, target_pos)
                    self.get_logger().info(f"Rotating to {yaw_angle:.2f}° before moving to {target_pos}")
                    self.client.rotateToYawAsync(yaw=yaw_angle).join()

                    self.get_logger().info(f"Moving to waypoint: {target_pos}")
                    self.client.moveToPositionAsync(
                        target_pos[0], target_pos[1], target_pos[2],
                        3, yaw_mode=airsim.YawMode(False, yaw_angle)
                    ).join()

            self.get_logger().info("Looping back to the first waypoint...")

def main(args=None):
    rclpy.init(args=args)
    node = FlightControllerNode()
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

# import rclpy
# from rclpy.node import Node
# from std_msgs.msg import Bool
# from geometry_msgs.msg import PoseStamped
# import cosysairsim as airsim
# import math
# import time

# class FlightControllerNode(Node):
#     def __init__(self):
#         super().__init__('flight_controller_node')

#         while True:
#             try:
#                 self.client = airsim.MultirotorClient()
#                 self.client.confirmConnection()
#                 self.client.enableApiControl(True)
#                 self.client.armDisarm(True)
#                 self.get_logger().info("Connected to AirSim.")
#                 break
#             except Exception as e:
#                 self.get_logger().warn(f"Waiting for AirSim: {e}")
#                 time.sleep(1)

#         self.get_logger().info("Connected to AirSim from flight controller.")

#         self.pause_navigation = False
#         self.current_waypoint = None
#         self.executing_waypoint = False

#         self.pause_sub = self.create_subscription(Bool, '/mission/pause_navigation', self.pause_callback, 10)
#         self.waypoint_sub = self.create_subscription(PoseStamped, '/mission/next_waypoint', self.waypoint_callback, 10)

#         self.timer = self.create_timer(1.0, self.flight_loop)

#         # === Zigzag relative waypoints ===
#         self.waypoints = []
#         x_positions = list(range(0, -431, -43))
#         for idx, x in enumerate(x_positions):
#             if idx % 2 == 0:
#                 self.waypoints.append((x, 0))
#                 self.waypoints.append((x, 370))
#             else:
#                 self.waypoints.append((x, 370))
#                 self.waypoints.append((x, 0))

#         self.waypoint_index = 0

#         # === GPS Reference ===
#         self.start_lat = 47.64323
#         self.start_lon_even = -122.14285
#         self.start_lon_odd = -122.13793
#         self.lat_step_per_370 = 0.0004  # Approx drop in latitude per 370 y-units

#         # === Takeoff ===
#         self.get_logger().info("Taking off...")
#         self.client.takeoffAsync().join()

#         # Move up to a safe height
#         self.client.moveToZAsync(0, 2).join()
#         self.client.hoverAsync().join()

#         # === Initial yaw setup ===
#         # first_x, first_y = self.waypoints[0]
#         # lat2, lon2 = self.relative_to_gps(first_x, first_y)
#         # initial_yaw = self.compute_bearing(self.start_lat, self.start_lon_even, lat2, lon2)
#         # self.client.rotateToYawAsync(yaw=initial_yaw).join()

#     def pause_callback(self, msg):
#         self.pause_navigation = msg.data
#         status = "PAUSED" if msg.data else "RESUMED"

#     def waypoint_callback(self, msg: PoseStamped):
#         x = msg.pose.position.x
#         y = msg.pose.position.y
#         self.navigate_to_waypoint((x, y))

#     def flight_loop(self):
#         if self.pause_navigation or self.executing_waypoint:
#             return

#         if self.waypoint_index < len(self.waypoints):
#             self.current_waypoint = self.waypoints[self.waypoint_index]
#             self.executing_waypoint = True
#             self.navigate_to_waypoint(self.current_waypoint)
#         else:
#             self.waypoint_index = 0

#     def navigate_to_waypoint(self, rel_pos):
#         if self.pause_navigation:
#             self.executing_waypoint = False
#             return

#         if self.waypoint_index > 0:
#             # Convert (x, y) → GPS
#             lat2, lon2 = self.relative_to_gps(rel_pos[0], rel_pos[1])

#             # Get current GPS
#             gps_data = self.client.getGpsData()
#             lat1 = gps_data.gnss.geo_point.latitude
#             lon1 = gps_data.gnss.geo_point.longitude
#             altitude = gps_data.gnss.geo_point.altitude or -10.0

#             # Compute yaw bearing
#             bearing = self.compute_bearing(lat1, lon1, lat2, lon2)
#             self.client.rotateToYawAsync(yaw=bearing).join()

#             # Move to GPS waypoint
#             self.client.moveToGPSAsync(lat2, lon2, altitude, 3, yaw_mode=airsim.YawMode(False, bearing)).join()
#             self.client.hoverAsync().join()
#         self.executing_waypoint = False
#         self.waypoint_index += 1

#     def relative_to_gps(self, x_rel, y_rel):
#         """
#         Convert relative (x, y) → GPS (lat, lon)
#         x controls latitude (vertical movement)
#         y controls longitude (horizontal zigzag between two fixed longitudes)
#         """
#         # Latitude changes gradually as x increases negatively (moving south)
#         step_index = round(abs(x_rel) / 43)
#         lat = self.start_lat - step_index * self.lat_step_per_370

#         # Longitude alternates between two values depending on y position
#         lon = self.start_lon_even if round(y_rel) == 0 else self.start_lon_odd

#         return lat, lon

#     def compute_bearing(self, lat1, lon1, lat2, lon2):
#         """
#         Calculate bearing (yaw angle) between two GPS coordinates
#         """
#         dLon = math.radians(lon2 - lon1)
#         lat1 = math.radians(lat1)
#         lat2 = math.radians(lat2)

#         x = math.sin(dLon) * math.cos(lat2)
#         y = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(dLon)

#         bearing = math.degrees(math.atan2(x, y))
#         return (bearing + 360) % 360

# def main(args=None):
#     rclpy.init(args=args)
#     node = FlightControllerNode()
#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass
#     finally:
#         node.client.armDisarm(False)
#         node.client.enableApiControl(False)
#         node.destroy_node()
#         rclpy.shutdown()

# if __name__ == '__main__':
#     main()


