// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from airsim_interfaces:srv/TakeoffGroup.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "airsim_interfaces/srv/detail/takeoff_group__rosidl_typesupport_introspection_c.h"
#include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "airsim_interfaces/srv/detail/takeoff_group__functions.h"
#include "airsim_interfaces/srv/detail/takeoff_group__struct.h"


// Include directives for member types
// Member `vehicle_names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__TakeoffGroup_Request__init(message_memory);
}

void airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_fini_function(void * message_memory)
{
  airsim_interfaces__srv__TakeoffGroup_Request__fini(message_memory);
}

size_t airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Request__vehicle_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Request__vehicle_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Request__vehicle_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Request__vehicle_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Request__vehicle_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Request__vehicle_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Request__vehicle_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Request__vehicle_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_member_array[2] = {
  {
    "vehicle_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Request, vehicle_names),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Request__vehicle_names,  // size() function pointer
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Request__vehicle_names,  // get_const(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Request__vehicle_names,  // get(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Request__vehicle_names,  // fetch(index, &value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Request__vehicle_names,  // assign(index, value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Request__vehicle_names  // resize(index) function pointer
  },
  {
    "wait_on_last_task",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Request, wait_on_last_task),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "TakeoffGroup_Request",  // message name
  2,  // number of fields
  sizeof(airsim_interfaces__srv__TakeoffGroup_Request),
  airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_member_array,  // message members
  airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__TakeoffGroup_Request__get_type_hash,
  &airsim_interfaces__srv__TakeoffGroup_Request__get_type_description,
  &airsim_interfaces__srv__TakeoffGroup_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Request)() {
  if (!airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__rosidl_typesupport_introspection_c.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__functions.h"
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__TakeoffGroup_Response__init(message_memory);
}

void airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_fini_function(void * message_memory)
{
  airsim_interfaces__srv__TakeoffGroup_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "TakeoffGroup_Response",  // message name
  1,  // number of fields
  sizeof(airsim_interfaces__srv__TakeoffGroup_Response),
  airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_member_array,  // message members
  airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__TakeoffGroup_Response__get_type_hash,
  &airsim_interfaces__srv__TakeoffGroup_Response__get_type_description,
  &airsim_interfaces__srv__TakeoffGroup_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Response)() {
  if (!airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__rosidl_typesupport_introspection_c.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__functions.h"
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "airsim_interfaces/srv/takeoff_group.h"
// Member `request`
// Member `response`
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  airsim_interfaces__srv__TakeoffGroup_Event__init(message_memory);
}

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_fini_function(void * message_memory)
{
  airsim_interfaces__srv__TakeoffGroup_Event__fini(message_memory);
}

size_t airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Event__request(
  const void * untyped_member)
{
  const airsim_interfaces__srv__TakeoffGroup_Request__Sequence * member =
    (const airsim_interfaces__srv__TakeoffGroup_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__request(
  const void * untyped_member, size_t index)
{
  const airsim_interfaces__srv__TakeoffGroup_Request__Sequence * member =
    (const airsim_interfaces__srv__TakeoffGroup_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__request(
  void * untyped_member, size_t index)
{
  airsim_interfaces__srv__TakeoffGroup_Request__Sequence * member =
    (airsim_interfaces__srv__TakeoffGroup_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const airsim_interfaces__srv__TakeoffGroup_Request * item =
    ((const airsim_interfaces__srv__TakeoffGroup_Request *)
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__request(untyped_member, index));
  airsim_interfaces__srv__TakeoffGroup_Request * value =
    (airsim_interfaces__srv__TakeoffGroup_Request *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  airsim_interfaces__srv__TakeoffGroup_Request * item =
    ((airsim_interfaces__srv__TakeoffGroup_Request *)
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__request(untyped_member, index));
  const airsim_interfaces__srv__TakeoffGroup_Request * value =
    (const airsim_interfaces__srv__TakeoffGroup_Request *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Event__request(
  void * untyped_member, size_t size)
{
  airsim_interfaces__srv__TakeoffGroup_Request__Sequence * member =
    (airsim_interfaces__srv__TakeoffGroup_Request__Sequence *)(untyped_member);
  airsim_interfaces__srv__TakeoffGroup_Request__Sequence__fini(member);
  return airsim_interfaces__srv__TakeoffGroup_Request__Sequence__init(member, size);
}

size_t airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Event__response(
  const void * untyped_member)
{
  const airsim_interfaces__srv__TakeoffGroup_Response__Sequence * member =
    (const airsim_interfaces__srv__TakeoffGroup_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__response(
  const void * untyped_member, size_t index)
{
  const airsim_interfaces__srv__TakeoffGroup_Response__Sequence * member =
    (const airsim_interfaces__srv__TakeoffGroup_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__response(
  void * untyped_member, size_t index)
{
  airsim_interfaces__srv__TakeoffGroup_Response__Sequence * member =
    (airsim_interfaces__srv__TakeoffGroup_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const airsim_interfaces__srv__TakeoffGroup_Response * item =
    ((const airsim_interfaces__srv__TakeoffGroup_Response *)
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__response(untyped_member, index));
  airsim_interfaces__srv__TakeoffGroup_Response * value =
    (airsim_interfaces__srv__TakeoffGroup_Response *)(untyped_value);
  *value = *item;
}

void airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  airsim_interfaces__srv__TakeoffGroup_Response * item =
    ((airsim_interfaces__srv__TakeoffGroup_Response *)
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__response(untyped_member, index));
  const airsim_interfaces__srv__TakeoffGroup_Response * value =
    (const airsim_interfaces__srv__TakeoffGroup_Response *)(untyped_value);
  *item = *value;
}

bool airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Event__response(
  void * untyped_member, size_t size)
{
  airsim_interfaces__srv__TakeoffGroup_Response__Sequence * member =
    (airsim_interfaces__srv__TakeoffGroup_Response__Sequence *)(untyped_member);
  airsim_interfaces__srv__TakeoffGroup_Response__Sequence__fini(member);
  return airsim_interfaces__srv__TakeoffGroup_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Event, request),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Event__request,  // size() function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__request,  // get_const(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__request,  // get(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Event__request,  // fetch(index, &value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Event__request,  // assign(index, value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(airsim_interfaces__srv__TakeoffGroup_Event, response),  // bytes offset in struct
    NULL,  // default value
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__size_function__TakeoffGroup_Event__response,  // size() function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_const_function__TakeoffGroup_Event__response,  // get_const(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__get_function__TakeoffGroup_Event__response,  // get(index) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__fetch_function__TakeoffGroup_Event__response,  // fetch(index, &value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__assign_function__TakeoffGroup_Event__response,  // assign(index, value) function pointer
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__resize_function__TakeoffGroup_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_members = {
  "airsim_interfaces__srv",  // message namespace
  "TakeoffGroup_Event",  // message name
  3,  // number of fields
  sizeof(airsim_interfaces__srv__TakeoffGroup_Event),
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_member_array,  // message members
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_type_support_handle = {
  0,
  &airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_members,
  get_message_typesupport_handle_function,
  &airsim_interfaces__srv__TakeoffGroup_Event__get_type_hash,
  &airsim_interfaces__srv__TakeoffGroup_Event__get_type_description,
  &airsim_interfaces__srv__TakeoffGroup_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Event)() {
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Request)();
  airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Response)();
  if (!airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "airsim_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "airsim_interfaces/srv/detail/takeoff_group__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_members = {
  "airsim_interfaces__srv",  // service namespace
  "TakeoffGroup",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle,
  NULL,  // response message
  // airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle
  NULL  // event_message
  // airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle
};


static rosidl_service_type_support_t airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_type_support_handle = {
  0,
  &airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_members,
  get_service_typesupport_handle_function,
  &airsim_interfaces__srv__TakeoffGroup_Request__rosidl_typesupport_introspection_c__TakeoffGroup_Request_message_type_support_handle,
  &airsim_interfaces__srv__TakeoffGroup_Response__rosidl_typesupport_introspection_c__TakeoffGroup_Response_message_type_support_handle,
  &airsim_interfaces__srv__TakeoffGroup_Event__rosidl_typesupport_introspection_c__TakeoffGroup_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    airsim_interfaces,
    srv,
    TakeoffGroup
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    airsim_interfaces,
    srv,
    TakeoffGroup
  ),
  &airsim_interfaces__srv__TakeoffGroup__get_type_hash,
  &airsim_interfaces__srv__TakeoffGroup__get_type_description,
  &airsim_interfaces__srv__TakeoffGroup__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_airsim_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup)() {
  if (!airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_type_support_handle.typesupport_identifier) {
    airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, airsim_interfaces, srv, TakeoffGroup_Event)()->data;
  }

  return &airsim_interfaces__srv__detail__takeoff_group__rosidl_typesupport_introspection_c__TakeoffGroup_service_type_support_handle;
}
