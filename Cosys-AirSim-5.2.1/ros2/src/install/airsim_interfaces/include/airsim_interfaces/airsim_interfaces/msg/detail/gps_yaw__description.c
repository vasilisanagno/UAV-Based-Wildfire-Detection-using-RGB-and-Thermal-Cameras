// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:msg/GPSYaw.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/msg/detail/gps_yaw__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__msg__GPSYaw__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x62, 0xee, 0x69, 0xe8, 0x12, 0x15, 0x25, 0x80,
      0x14, 0x2d, 0x53, 0x09, 0x90, 0xb9, 0x63, 0x1b,
      0xa5, 0x17, 0xe1, 0x74, 0xb9, 0x50, 0x4b, 0x48,
      0x0b, 0x38, 0xa5, 0x6e, 0x7e, 0x83, 0xd3, 0xa9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char airsim_interfaces__msg__GPSYaw__TYPE_NAME[] = "airsim_interfaces/msg/GPSYaw";

// Define type names, field names, and default values
static char airsim_interfaces__msg__GPSYaw__FIELD_NAME__latitude[] = "latitude";
static char airsim_interfaces__msg__GPSYaw__FIELD_NAME__longitude[] = "longitude";
static char airsim_interfaces__msg__GPSYaw__FIELD_NAME__altitude[] = "altitude";
static char airsim_interfaces__msg__GPSYaw__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field airsim_interfaces__msg__GPSYaw__FIELDS[] = {
  {
    {airsim_interfaces__msg__GPSYaw__FIELD_NAME__latitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__GPSYaw__FIELD_NAME__longitude, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__GPSYaw__FIELD_NAME__altitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__GPSYaw__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__msg__GPSYaw__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__msg__GPSYaw__TYPE_NAME, 28, 28},
      {airsim_interfaces__msg__GPSYaw__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 latitude\n"
  "float64 longitude\n"
  "float64 altitude\n"
  "float64 yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__msg__GPSYaw__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__msg__GPSYaw__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 63, 63},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__msg__GPSYaw__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__msg__GPSYaw__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
