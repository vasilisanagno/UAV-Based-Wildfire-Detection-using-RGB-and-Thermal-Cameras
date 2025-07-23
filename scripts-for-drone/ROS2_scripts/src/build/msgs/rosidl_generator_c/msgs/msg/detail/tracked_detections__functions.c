// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/tracked_detections__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gps`
#include "sensor_msgs/msg/detail/nav_sat_fix__functions.h"
// Member `tracks`
#include "msgs/msg/detail/tracked_object__functions.h"
// Member `rgb_image`
// Member `thermal_image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
msgs__msg__TrackedDetections__init(msgs__msg__TrackedDetections * msg)
{
  if (!msg) {
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__init(&msg->gps)) {
    msgs__msg__TrackedDetections__fini(msg);
    return false;
  }
  // tracks
  if (!msgs__msg__TrackedObject__Sequence__init(&msg->tracks, 0)) {
    msgs__msg__TrackedDetections__fini(msg);
    return false;
  }
  // rgb_image
  if (!sensor_msgs__msg__Image__init(&msg->rgb_image)) {
    msgs__msg__TrackedDetections__fini(msg);
    return false;
  }
  // thermal_image
  if (!sensor_msgs__msg__Image__init(&msg->thermal_image)) {
    msgs__msg__TrackedDetections__fini(msg);
    return false;
  }
  return true;
}

void
msgs__msg__TrackedDetections__fini(msgs__msg__TrackedDetections * msg)
{
  if (!msg) {
    return;
  }
  // gps
  sensor_msgs__msg__NavSatFix__fini(&msg->gps);
  // tracks
  msgs__msg__TrackedObject__Sequence__fini(&msg->tracks);
  // rgb_image
  sensor_msgs__msg__Image__fini(&msg->rgb_image);
  // thermal_image
  sensor_msgs__msg__Image__fini(&msg->thermal_image);
}

bool
msgs__msg__TrackedDetections__are_equal(const msgs__msg__TrackedDetections * lhs, const msgs__msg__TrackedDetections * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__are_equal(
      &(lhs->gps), &(rhs->gps)))
  {
    return false;
  }
  // tracks
  if (!msgs__msg__TrackedObject__Sequence__are_equal(
      &(lhs->tracks), &(rhs->tracks)))
  {
    return false;
  }
  // rgb_image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->rgb_image), &(rhs->rgb_image)))
  {
    return false;
  }
  // thermal_image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->thermal_image), &(rhs->thermal_image)))
  {
    return false;
  }
  return true;
}

bool
msgs__msg__TrackedDetections__copy(
  const msgs__msg__TrackedDetections * input,
  msgs__msg__TrackedDetections * output)
{
  if (!input || !output) {
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__copy(
      &(input->gps), &(output->gps)))
  {
    return false;
  }
  // tracks
  if (!msgs__msg__TrackedObject__Sequence__copy(
      &(input->tracks), &(output->tracks)))
  {
    return false;
  }
  // rgb_image
  if (!sensor_msgs__msg__Image__copy(
      &(input->rgb_image), &(output->rgb_image)))
  {
    return false;
  }
  // thermal_image
  if (!sensor_msgs__msg__Image__copy(
      &(input->thermal_image), &(output->thermal_image)))
  {
    return false;
  }
  return true;
}

msgs__msg__TrackedDetections *
msgs__msg__TrackedDetections__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrackedDetections * msg = (msgs__msg__TrackedDetections *)allocator.allocate(sizeof(msgs__msg__TrackedDetections), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__msg__TrackedDetections));
  bool success = msgs__msg__TrackedDetections__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__msg__TrackedDetections__destroy(msgs__msg__TrackedDetections * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__msg__TrackedDetections__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__msg__TrackedDetections__Sequence__init(msgs__msg__TrackedDetections__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrackedDetections * data = NULL;

  if (size) {
    data = (msgs__msg__TrackedDetections *)allocator.zero_allocate(size, sizeof(msgs__msg__TrackedDetections), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__msg__TrackedDetections__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__msg__TrackedDetections__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
msgs__msg__TrackedDetections__Sequence__fini(msgs__msg__TrackedDetections__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      msgs__msg__TrackedDetections__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

msgs__msg__TrackedDetections__Sequence *
msgs__msg__TrackedDetections__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__TrackedDetections__Sequence * array = (msgs__msg__TrackedDetections__Sequence *)allocator.allocate(sizeof(msgs__msg__TrackedDetections__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__msg__TrackedDetections__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__msg__TrackedDetections__Sequence__destroy(msgs__msg__TrackedDetections__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__msg__TrackedDetections__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__msg__TrackedDetections__Sequence__are_equal(const msgs__msg__TrackedDetections__Sequence * lhs, const msgs__msg__TrackedDetections__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__msg__TrackedDetections__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__msg__TrackedDetections__Sequence__copy(
  const msgs__msg__TrackedDetections__Sequence * input,
  msgs__msg__TrackedDetections__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__msg__TrackedDetections);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__msg__TrackedDetections * data =
      (msgs__msg__TrackedDetections *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__msg__TrackedDetections__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__msg__TrackedDetections__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__msg__TrackedDetections__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
