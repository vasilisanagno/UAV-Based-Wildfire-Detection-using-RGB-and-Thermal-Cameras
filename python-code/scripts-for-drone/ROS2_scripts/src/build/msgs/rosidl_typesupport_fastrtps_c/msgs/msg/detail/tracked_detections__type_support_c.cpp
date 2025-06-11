// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/tracked_detections__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "msgs/msg/detail/tracked_detections__struct.h"
#include "msgs/msg/detail/tracked_detections__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "msgs/msg/detail/tracked_object__functions.h"  // tracks
#include "sensor_msgs/msg/detail/image__functions.h"  // rgb_image, thermal_image
#include "sensor_msgs/msg/detail/nav_sat_fix__functions.h"  // gps

// forward declare type support functions
size_t get_serialized_size_msgs__msg__TrackedObject(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_msgs__msg__TrackedObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, msgs, msg, TrackedObject)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
size_t get_serialized_size_sensor_msgs__msg__NavSatFix(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
size_t max_serialized_size_sensor_msgs__msg__NavSatFix(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, NavSatFix)();


using _TrackedDetections__ros_msg_type = msgs__msg__TrackedDetections;

static bool _TrackedDetections__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TrackedDetections__ros_msg_type * ros_message = static_cast<const _TrackedDetections__ros_msg_type *>(untyped_ros_message);
  // Field name: gps
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, NavSatFix
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->gps, cdr))
    {
      return false;
    }
  }

  // Field name: tracks
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, msgs, msg, TrackedObject
      )()->data);
    size_t size = ros_message->tracks.size;
    auto array_ptr = ros_message->tracks.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: rgb_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->rgb_image, cdr))
    {
      return false;
    }
  }

  // Field name: thermal_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->thermal_image, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _TrackedDetections__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TrackedDetections__ros_msg_type * ros_message = static_cast<_TrackedDetections__ros_msg_type *>(untyped_ros_message);
  // Field name: gps
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, NavSatFix
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->gps))
    {
      return false;
    }
  }

  // Field name: tracks
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, msgs, msg, TrackedObject
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->tracks.data) {
      msgs__msg__TrackedObject__Sequence__fini(&ros_message->tracks);
    }
    if (!msgs__msg__TrackedObject__Sequence__init(&ros_message->tracks, size)) {
      fprintf(stderr, "failed to create array for field 'tracks'");
      return false;
    }
    auto array_ptr = ros_message->tracks.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: rgb_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->rgb_image))
    {
      return false;
    }
  }

  // Field name: thermal_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->thermal_image))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t get_serialized_size_msgs__msg__TrackedDetections(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TrackedDetections__ros_msg_type * ros_message = static_cast<const _TrackedDetections__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name gps

  current_alignment += get_serialized_size_sensor_msgs__msg__NavSatFix(
    &(ros_message->gps), current_alignment);
  // field.name tracks
  {
    size_t array_size = ros_message->tracks.size;
    auto array_ptr = ros_message->tracks.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_msgs__msg__TrackedObject(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name rgb_image

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->rgb_image), current_alignment);
  // field.name thermal_image

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->thermal_image), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _TrackedDetections__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_msgs__msg__TrackedDetections(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t max_serialized_size_msgs__msg__TrackedDetections(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: gps
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__NavSatFix(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: tracks
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_msgs__msg__TrackedObject(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: rgb_image
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: thermal_image
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = msgs__msg__TrackedDetections;
    is_plain =
      (
      offsetof(DataType, thermal_image) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TrackedDetections__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_msgs__msg__TrackedDetections(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TrackedDetections = {
  "msgs::msg",
  "TrackedDetections",
  _TrackedDetections__cdr_serialize,
  _TrackedDetections__cdr_deserialize,
  _TrackedDetections__get_serialized_size,
  _TrackedDetections__max_serialized_size
};

static rosidl_message_type_support_t _TrackedDetections__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TrackedDetections,
  get_message_typesupport_handle_function,
  &msgs__msg__TrackedDetections__get_type_hash,
  &msgs__msg__TrackedDetections__get_type_description,
  &msgs__msg__TrackedDetections__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, msgs, msg, TrackedDetections)() {
  return &_TrackedDetections__type_support;
}

#if defined(__cplusplus)
}
#endif
