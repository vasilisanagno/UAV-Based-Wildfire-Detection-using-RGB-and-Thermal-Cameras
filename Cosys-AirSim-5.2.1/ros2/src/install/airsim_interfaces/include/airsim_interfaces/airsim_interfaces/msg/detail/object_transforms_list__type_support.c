// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from airsim_interfaces:msg/ObjectTransformsList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "airsim_interfaces/msg/detail/object_transforms_list__rosidl_typesupport_introspection_c.h"
#include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "airsim_interfaces/msg/detail/object_transforms_list__functions.h"
#include "airsim_interfaces/msg/detail/object_transforms_list__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "geometry_msgs/msg/transform_stamped.h"
// Member `objects`
#include "geometry_msgs/msg/detail/transform_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__msg__ObjectTransformsList__init(message_memory);
}

void airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_fini_function(void * message_memory)
{
  airsim_interfaces__msg__ObjectTransformsList__fini(message_memory);
}

size_t airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__size_function__ObjectTransformsList__objects(
  const void * untyped_member)
{
  const geometry_msgs__msg__TransformStamped__Sequence * member =
    (const geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_const_function__ObjectTransformsList__objects(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__TransformStamped__Sequence * member =
    (const geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_function__ObjectTransformsList__objects(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__TransformStamped__Sequence * member =
    (geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__fetch_function__ObjectTransformsList__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__TransformStamped * item =
    ((const geometry_msgs__msg__TransformStamped *)
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_const_function__ObjectTransformsList__objects(untyped_member, index));
  geometry_msgs__msg__TransformStamped * value =
    (geometry_msgs__msg__TransformStamped *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__assign_function__ObjectTransformsList__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__TransformStamped * item =
    ((geometry_msgs__msg__TransformStamped *)
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_function__ObjectTransformsList__objects(untyped_member, index));
  const geometry_msgs__msg__TransformStamped * value =
    (const geometry_msgs__msg__TransformStamped *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__resize_function__ObjectTransformsList__objects(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__TransformStamped__Sequence * member =
    (geometry_msgs__msg__TransformStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__TransformStamped__Sequence__fini(member);
  return geometry_msgs__msg__TransformStamped__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__msg__ObjectTransformsList, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__msg__ObjectTransformsList, objects),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__size_function__ObjectTransformsList__objects,  // size() function pointer
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_const_function__ObjectTransformsList__objects,  // get_const(index) function pointer
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__get_function__ObjectTransformsList__objects,  // get(index) function pointer
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__fetch_function__ObjectTransformsList__objects,  // fetch(index, &value) function pointer
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__assign_function__ObjectTransformsList__objects,  // assign(index, value) function pointer
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__resize_function__ObjectTransformsList__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_members = {
  "airsim_interfaces__msg",  // message namespace
  "ObjectTransformsList",  // message name
  2,  // number of fields
  sizeof(airsim_interfaces__msg__ObjectTransformsList),
  airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_member_array,  // message members
  airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_type_support_handle = {
  0,
  &airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__msg__ObjectTransformsList__get_type_hash,
  &airsim_interfaces__msg__ObjectTransformsList__get_type_description,
  &airsim_interfaces__msg__ObjectTransformsList__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, msg, ObjectTransformsList)() {
  airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, TransformStamped)();
  if (!airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__msg__ObjectTransformsList__rosidl_typesupport_introspection_c__ObjectTransformsList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
