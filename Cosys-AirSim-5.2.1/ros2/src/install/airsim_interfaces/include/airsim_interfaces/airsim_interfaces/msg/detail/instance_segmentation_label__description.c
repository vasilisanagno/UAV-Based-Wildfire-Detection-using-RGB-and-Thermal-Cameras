// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from airsim_interfaces:msg/InstanceSegmentationLabel.idl
// generated code does not contain a copyright notice

#include "airsim_interfaces/msg/detail/instance_segmentation_label__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_airsim_interfaces
const rosidl_type_hash_t *
airsim_interfaces__msg__InstanceSegmentationLabel__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xac, 0x8f, 0x5b, 0x6d, 0xac, 0x6b, 0x0f, 0x47,
      0x58, 0x42, 0x2f, 0x9a, 0x08, 0x4b, 0x9f, 0x39,
      0xaf, 0xb2, 0x52, 0xe1, 0xed, 0x88, 0x57, 0x75,
      0x74, 0x3d, 0xff, 0xfa, 0xd1, 0xc8, 0x6c, 0xeb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char airsim_interfaces__msg__InstanceSegmentationLabel__TYPE_NAME[] = "airsim_interfaces/msg/InstanceSegmentationLabel";

// Define type names, field names, and default values
static char airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__name[] = "name";
static char airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__index[] = "index";
static char airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__r[] = "r";
static char airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__g[] = "g";
static char airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__b[] = "b";

static rosidl_runtime_c__type_description__Field airsim_interfaces__msg__InstanceSegmentationLabel__FIELDS[] = {
  {
    {airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__index, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__r, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__g, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {airsim_interfaces__msg__InstanceSegmentationLabel__FIELD_NAME__b, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
airsim_interfaces__msg__InstanceSegmentationLabel__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {airsim_interfaces__msg__InstanceSegmentationLabel__TYPE_NAME, 47, 47},
      {airsim_interfaces__msg__InstanceSegmentationLabel__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name\n"
  "uint32 index\n"
  "uint8 r\n"
  "uint8 g\n"
  "uint8 b";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
airsim_interfaces__msg__InstanceSegmentationLabel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {airsim_interfaces__msg__InstanceSegmentationLabel__TYPE_NAME, 47, 47},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 48, 48},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
airsim_interfaces__msg__InstanceSegmentationLabel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *airsim_interfaces__msg__InstanceSegmentationLabel__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
