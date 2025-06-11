// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_H_
#define MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'labels'
#include "rosidl_runtime_c/string.h"
// Member 'confidences'
// Member 'boxes'
// Member 'tracking_ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.h"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/DetectionWithGPS in the package msgs.
typedef struct msgs__msg__DetectionWithGPS
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String__Sequence labels;
  rosidl_runtime_c__float__Sequence confidences;
  /// Format: [x1, y1, x2, y2, x1, y1, x2, y2, ...]
  rosidl_runtime_c__float__Sequence boxes;
  rosidl_runtime_c__int32__Sequence tracking_ids;
  sensor_msgs__msg__NavSatFix gps;
  sensor_msgs__msg__Image image;
} msgs__msg__DetectionWithGPS;

// Struct for a sequence of msgs__msg__DetectionWithGPS.
typedef struct msgs__msg__DetectionWithGPS__Sequence
{
  msgs__msg__DetectionWithGPS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__DetectionWithGPS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__DETECTION_WITH_GPS__STRUCT_H_
