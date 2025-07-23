// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from msgs:msg/TrackedObject.idl
// generated code does not contain a copyright notice

#include "msgs/msg/detail/tracked_object__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_msgs
const rosidl_type_hash_t *
msgs__msg__TrackedObject__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x26, 0xb6, 0xbc, 0x08, 0xc0, 0x75, 0x46, 0x0e,
      0x45, 0x65, 0x27, 0x00, 0x82, 0xa2, 0x51, 0x8a,
      0xdf, 0xe4, 0x10, 0x3a, 0xa4, 0xad, 0x54, 0xdb,
      0x12, 0xb2, 0xe6, 0x1b, 0x51, 0xe6, 0x69, 0x97,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char msgs__msg__TrackedObject__TYPE_NAME[] = "msgs/msg/TrackedObject";

// Define type names, field names, and default values
static char msgs__msg__TrackedObject__FIELD_NAME__id[] = "id";
static char msgs__msg__TrackedObject__FIELD_NAME__label[] = "label";
static char msgs__msg__TrackedObject__FIELD_NAME__confidence[] = "confidence";
static char msgs__msg__TrackedObject__FIELD_NAME__box[] = "box";
static char msgs__msg__TrackedObject__FIELD_NAME__source[] = "source";

static rosidl_runtime_c__type_description__Field msgs__msg__TrackedObject__FIELDS[] = {
  {
    {msgs__msg__TrackedObject__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__TrackedObject__FIELD_NAME__label, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__TrackedObject__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__TrackedObject__FIELD_NAME__box, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      4,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__TrackedObject__FIELD_NAME__source, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
msgs__msg__TrackedObject__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {msgs__msg__TrackedObject__TYPE_NAME, 22, 22},
      {msgs__msg__TrackedObject__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 id\n"
  "string label\n"
  "float32 confidence\n"
  "float32[4] box   # [x1, y1, x2, y2]\n"
  "string source  # \"rgb\" or \"thermal\"";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
msgs__msg__TrackedObject__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {msgs__msg__TrackedObject__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 113, 113},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
msgs__msg__TrackedObject__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *msgs__msg__TrackedObject__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
