// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_
#define MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'label'
// Member 'source'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TrackedObject in the package msgs.
typedef struct msgs__msg__TrackedObject
{
  int32_t id;
  rosidl_runtime_c__String label;
  float confidence;
  /// [x1, y1, x2, y2]
  float box[4];
  /// "rgb" or "thermal"
  rosidl_runtime_c__String source;
} msgs__msg__TrackedObject;

// Struct for a sequence of msgs__msg__TrackedObject.
typedef struct msgs__msg__TrackedObject__Sequence
{
  msgs__msg__TrackedObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__TrackedObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__TRACKED_OBJECT__STRUCT_H_
