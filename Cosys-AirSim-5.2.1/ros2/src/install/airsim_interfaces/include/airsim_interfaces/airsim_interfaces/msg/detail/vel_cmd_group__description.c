// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:msg/VelCmdGroup.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/msg/detail/vel_cmd_group__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__msg__VelCmdGroup__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9d, 0xcb, 0xad, 0xd1, 0xd7, 0x73, 0xac, 0x8e,
      0x00, 0xa8, 0x4a, 0xf6, 0x53, 0xed, 0x41, 0x1f,
      0xc8, 0x57, 0x72, 0x88, 0xe5, 0x9d, 0xdf, 0x7b,
      0xca, 0x1b, 0xfe, 0xcb, 0x69, 0x52, 0x35, 0x06,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/twist__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "airsim_interfaces/msg/detail/vel_cmd__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t airsim_interfaces__msg__VelCmd__EXPECTED_HASH = {1, {
    0x37, 0x1a, 0x1e, 0xc0, 0xf9, 0x79, 0xb4, 0xe3,
    0x82, 0x12, 0xea, 0xd0, 0x74, 0x98, 0x2f, 0xb4,
    0x5f, 0x46, 0xfa, 0xf7, 0x1f, 0x26, 0x70, 0x3d,
    0xf3, 0x5b, 0x58, 0xd4, 0xcf, 0xe5, 0x7d, 0xf3,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Twist__EXPECTED_HASH = {1, {
    0x9c, 0x45, 0xbf, 0x16, 0xfe, 0x09, 0x83, 0xd8,
    0x0e, 0x3c, 0xfe, 0x75, 0x0d, 0x68, 0x35, 0x84,
    0x3d, 0x26, 0x5a, 0x9a, 0x6c, 0x46, 0xbd, 0x2e,
    0x60, 0x9f, 0xcd, 0xdd, 0xe6, 0xfb, 0x8d, 0x2a,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
#endif

static char airsim_interfaces__msg__VelCmdGroup__TYPE_NAME[] = "airsim_interfaces/msg/VelCmdGroup";
static char airsim_interfaces__msg__VelCmd__TYPE_NAME[] = "airsim_interfaces/msg/VelCmd";
static char geometry_msgs__msg__Twist__TYPE_NAME[] = "geometry_msgs/msg/Twist";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";

// Define type names, field names, and default values
static char airsim_interfaces__msg__VelCmdGroup__FIELD_NAME__vel_cmd[] = "vel_cmd";
static char airsim_interfaces__msg__VelCmdGroup__FIELD_NAME__vehicle_names[] = "vehicle_names";

static rosidl_runtime_c__type_description__Field airsim_interfaces__msg__VelCmdGroup__FIELDS[] = {
  {
    {airsim_interfaces__msg__VelCmdGroup__FIELD_NAME__vel_cmd, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {airsim_interfaces__msg__VelCmd__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__VelCmdGroup__FIELD_NAME__vehicle_names, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__msg__VelCmdGroup__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {airsim_interfaces__msg__VelCmd__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Twist__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__msg__VelCmdGroup__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__msg__VelCmdGroup__TYPE_NAME, 33, 33},
      {airsim_interfaces__msg__VelCmdGroup__FIELDS, 2, 2},
    },
    {airsim_interfaces__msg__VelCmdGroup__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&airsim_interfaces__msg__VelCmd__EXPECTED_HASH, airsim_interfaces__msg__VelCmd__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = airsim_interfaces__msg__VelCmd__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Twist__EXPECTED_HASH, geometry_msgs__msg__Twist__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Twist__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "airsim_interfaces/VelCmd vel_cmd\n"
  "string[] vehicle_names";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__msg__VelCmdGroup__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__msg__VelCmdGroup__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 55, 55},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__msg__VelCmdGroup__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__msg__VelCmdGroup__get_individual_type_description_source(NULL),
    sources[1] = *airsim_interfaces__msg__VelCmd__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Twist__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
