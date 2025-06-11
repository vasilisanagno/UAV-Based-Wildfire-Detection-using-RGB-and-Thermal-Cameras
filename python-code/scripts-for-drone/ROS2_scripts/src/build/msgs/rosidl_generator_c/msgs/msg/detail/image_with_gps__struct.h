// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/ImageWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_H_
#define MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__struct.h"

/// Struct defined in msg/ImageWithGPS in the package msgs.
typedef struct msgs__msg__ImageWithGPS
{
  sensor_msgs__msg__Image image;
  sensor_msgs__msg__NavSatFix gps;
} msgs__msg__ImageWithGPS;

// Struct for a sequence of msgs__msg__ImageWithGPS.
typedef struct msgs__msg__ImageWithGPS__Sequence
{
  msgs__msg__ImageWithGPS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__ImageWithGPS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__IMAGE_WITH_GPS__STRUCT_H_
