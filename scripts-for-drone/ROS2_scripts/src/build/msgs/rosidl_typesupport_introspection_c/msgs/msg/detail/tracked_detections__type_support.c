// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs/msg/detail/tracked_detections__rosidl_typesupport_introspection_c.h"
#include "msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs/msg/detail/tracked_detections__functions.h"
#include "msgs/msg/detail/tracked_detections__struct.h"


// Include directives for member types
// Member `gps`
#include "sensor_msgs/msg/nav_sat_fix.h"
// Member `gps`
#include "sensor_msgs/msg/detail/nav_sat_fix__rosidl_typesupport_introspection_c.h"
// Member `tracks`
#include "msgs/msg/tracked_object.h"
// Member `tracks`
#include "msgs/msg/detail/tracked_object__rosidl_typesupport_introspection_c.h"
// Member `rgb_image`
// Member `thermal_image`
#include "sensor_msgs/msg/image.h"
// Member `rgb_image`
// Member `thermal_image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs__msg__TrackedDetections__init(message_memory);
}

void msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_fini_function(void * message_memory)
{
  msgs__msg__TrackedDetections__fini(message_memory);
}

size_t msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__size_function__TrackedDetections__tracks(
  const void * untyped_member)
{
  const msgs__msg__TrackedObject__Sequence * member =
    (const msgs__msg__TrackedObject__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_const_function__TrackedDetections__tracks(
  const void * untyped_member, size_t index)
{
  const msgs__msg__TrackedObject__Sequence * member =
    (const msgs__msg__TrackedObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_function__TrackedDetections__tracks(
  void * untyped_member, size_t index)
{
  msgs__msg__TrackedObject__Sequence * member =
    (msgs__msg__TrackedObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__fetch_function__TrackedDetections__tracks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const msgs__msg__TrackedObject * item =
    ((const msgs__msg__TrackedObject *)
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_const_function__TrackedDetections__tracks(untyped_member, index));
  msgs__msg__TrackedObject * value =
    (msgs__msg__TrackedObject *)(untyped_value);
  *value = *item;
}

void msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__assign_function__TrackedDetections__tracks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  msgs__msg__TrackedObject * item =
    ((msgs__msg__TrackedObject *)
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_function__TrackedDetections__tracks(untyped_member, index));
  const msgs__msg__TrackedObject * value =
    (const msgs__msg__TrackedObject *)(untyped_value);
  *item = *value;
}

bool msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__resize_function__TrackedDetections__tracks(
  void * untyped_member, size_t size)
{
  msgs__msg__TrackedObject__Sequence * member =
    (msgs__msg__TrackedObject__Sequence *)(untyped_member);
  msgs__msg__TrackedObject__Sequence__fini(member);
  return msgs__msg__TrackedObject__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array[4] = {
  {
    "gps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedDetections, gps),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedDetections, tracks),  // bytes offset in struct
    NULL,  // default value
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__size_function__TrackedDetections__tracks,  // size() function pointer
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_const_function__TrackedDetections__tracks,  // get_const(index) function pointer
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__get_function__TrackedDetections__tracks,  // get(index) function pointer
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__fetch_function__TrackedDetections__tracks,  // fetch(index, &value) function pointer
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__assign_function__TrackedDetections__tracks,  // assign(index, value) function pointer
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__resize_function__TrackedDetections__tracks  // resize(index) function pointer
  },
  {
    "rgb_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedDetections, rgb_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thermal_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs__msg__TrackedDetections, thermal_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_members = {
  "msgs__msg",  // message namespace
  "TrackedDetections",  // message name
  4,  // number of fields
  sizeof(msgs__msg__TrackedDetections),
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array,  // message members
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_type_support_handle = {
  0,
  &msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_members,
  get_message_typesupport_handle_function,
  &msgs__msg__TrackedDetections__get_type_hash,
  &msgs__msg__TrackedDetections__get_type_description,
  &msgs__msg__TrackedDetections__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, TrackedDetections)() {
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, NavSatFix)();
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs, msg, TrackedObject)();
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_type_support_handle.typesupport_identifier) {
    msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs__msg__TrackedDetections__rosidl_typesupport_introspection_c__TrackedDetections_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
