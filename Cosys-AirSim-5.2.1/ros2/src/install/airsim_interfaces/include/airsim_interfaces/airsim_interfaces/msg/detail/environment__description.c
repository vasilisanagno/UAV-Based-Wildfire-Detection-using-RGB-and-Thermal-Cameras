// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:msg/Environment.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/msg/detail/environment__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__msg__Environment__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8f, 0x4c, 0xfb, 0x4a, 0xf1, 0xe1, 0x2a, 0x4f,
      0xa8, 0x4d, 0x3b, 0x4b, 0x5d, 0x75, 0x1b, 0xc6,
      0xf8, 0x3e, 0xb6, 0x9e, 0xc1, 0x65, 0x9c, 0x1e,
      0xe9, 0xdb, 0x9f, 0x1a, 0xc3, 0xf6, 0x91, 0x21,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "geographic_msgs/msg/detail/geo_point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geographic_msgs__msg__GeoPoint__EXPECTED_HASH = {1, {
    0x60, 0x2c, 0x64, 0x7c, 0xf8, 0x7b, 0xbe, 0x95,
    0xa0, 0x23, 0x1b, 0x45, 0x9b, 0x5a, 0xc3, 0x00,
    0x51, 0x87, 0x5d, 0x07, 0xc0, 0xc7, 0x40, 0xb3,
    0x1a, 0xd7, 0xa8, 0xc4, 0x66, 0x2b, 0x97, 0x1e,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char airsim_interfaces__msg__Environment__TYPE_NAME[] = "airsim_interfaces/msg/Environment";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geographic_msgs__msg__GeoPoint__TYPE_NAME[] = "geographic_msgs/msg/GeoPoint";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char airsim_interfaces__msg__Environment__FIELD_NAME__header[] = "header";
static char airsim_interfaces__msg__Environment__FIELD_NAME__position[] = "position";
static char airsim_interfaces__msg__Environment__FIELD_NAME__geo_point[] = "geo_point";
static char airsim_interfaces__msg__Environment__FIELD_NAME__gravity[] = "gravity";
static char airsim_interfaces__msg__Environment__FIELD_NAME__air_pressure[] = "air_pressure";
static char airsim_interfaces__msg__Environment__FIELD_NAME__temperature[] = "temperature";
static char airsim_interfaces__msg__Environment__FIELD_NAME__air_density[] = "air_density";

static rosidl_runtime_c__type_description__Field airsim_interfaces__msg__Environment__FIELDS[] = {
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__geo_point, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geographic_msgs__msg__GeoPoint__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__gravity, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__air_pressure, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__temperature, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__Environment__FIELD_NAME__air_density, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription airsim_interfaces__msg__Environment__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geographic_msgs__msg__GeoPoint__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__msg__Environment__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__msg__Environment__TYPE_NAME, 33, 33},
      {airsim_interfaces__msg__Environment__FIELDS, 7, 7},
    },
    {airsim_interfaces__msg__Environment__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geographic_msgs__msg__GeoPoint__EXPECTED_HASH, geographic_msgs__msg__GeoPoint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geographic_msgs__msg__GeoPoint__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "geometry_msgs/Vector3 position\n"
  "geographic_msgs/GeoPoint geo_point\n"
  "geometry_msgs/Vector3 gravity\n"
  "float32 air_pressure\n"
  "float32 temperature\n"
  "float32 air_density\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__msg__Environment__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__msg__Environment__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 181, 181},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__msg__Environment__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__msg__Environment__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geographic_msgs__msg__GeoPoint__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
