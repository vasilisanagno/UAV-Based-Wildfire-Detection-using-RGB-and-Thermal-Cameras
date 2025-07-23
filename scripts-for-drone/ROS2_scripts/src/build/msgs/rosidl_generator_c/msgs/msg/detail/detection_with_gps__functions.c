// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice
#include "msgs/msg/detail/detection_with_gps__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `labels`
#include "rosidl_runtime_c/string_functions.h"
// Member `confidences`
// Member `boxes`
// Member `tracking_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `gps`
#include "sensor_msgs/msg/detail/nav_sat_fix__functions.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
msgs__msg__DetectionWithGPS__init(msgs__msg__DetectionWithGPS * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // labels
  if (!rosidl_runtime_c__String__Sequence__init(&msg->labels, 0)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // confidences
  if (!rosidl_runtime_c__float__Sequence__init(&msg->confidences, 0)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // boxes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->boxes, 0)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // tracking_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->tracking_ids, 0)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__init(&msg->gps)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    msgs__msg__DetectionWithGPS__fini(msg);
    return false;
  }
  return true;
}

void
msgs__msg__DetectionWithGPS__fini(msgs__msg__DetectionWithGPS * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // labels
  rosidl_runtime_c__String__Sequence__fini(&msg->labels);
  // confidences
  rosidl_runtime_c__float__Sequence__fini(&msg->confidences);
  // boxes
  rosidl_runtime_c__float__Sequence__fini(&msg->boxes);
  // tracking_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->tracking_ids);
  // gps
  sensor_msgs__msg__NavSatFix__fini(&msg->gps);
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
msgs__msg__DetectionWithGPS__are_equal(const msgs__msg__DetectionWithGPS * lhs, const msgs__msg__DetectionWithGPS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // labels
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->labels), &(rhs->labels)))
  {
    return false;
  }
  // confidences
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->confidences), &(rhs->confidences)))
  {
    return false;
  }
  // boxes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->boxes), &(rhs->boxes)))
  {
    return false;
  }
  // tracking_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->tracking_ids), &(rhs->tracking_ids)))
  {
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__are_equal(
      &(lhs->gps), &(rhs->gps)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
msgs__msg__DetectionWithGPS__copy(
  const msgs__msg__DetectionWithGPS * input,
  msgs__msg__DetectionWithGPS * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // labels
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->labels), &(output->labels)))
  {
    return false;
  }
  // confidences
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->confidences), &(output->confidences)))
  {
    return false;
  }
  // boxes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->boxes), &(output->boxes)))
  {
    return false;
  }
  // tracking_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->tracking_ids), &(output->tracking_ids)))
  {
    return false;
  }
  // gps
  if (!sensor_msgs__msg__NavSatFix__copy(
      &(input->gps), &(output->gps)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

msgs__msg__DetectionWithGPS *
msgs__msg__DetectionWithGPS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__DetectionWithGPS * msg = (msgs__msg__DetectionWithGPS *)allocator.allocate(sizeof(msgs__msg__DetectionWithGPS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs__msg__DetectionWithGPS));
  bool success = msgs__msg__DetectionWithGPS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs__msg__DetectionWithGPS__destroy(msgs__msg__DetectionWithGPS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs__msg__DetectionWithGPS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs__msg__DetectionWithGPS__Sequence__init(msgs__msg__DetectionWithGPS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__DetectionWithGPS * data = NULL;

  if (size) {
    data = (msgs__msg__DetectionWithGPS *)allocator.zero_allocate(size, sizeof(msgs__msg__DetectionWithGPS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs__msg__DetectionWithGPS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs__msg__DetectionWithGPS__fini(&data[i - 1]);
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
msgs__msg__DetectionWithGPS__Sequence__fini(msgs__msg__DetectionWithGPS__Sequence * array)
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
      msgs__msg__DetectionWithGPS__fini(&array->data[i]);
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

msgs__msg__DetectionWithGPS__Sequence *
msgs__msg__DetectionWithGPS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs__msg__DetectionWithGPS__Sequence * array = (msgs__msg__DetectionWithGPS__Sequence *)allocator.allocate(sizeof(msgs__msg__DetectionWithGPS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs__msg__DetectionWithGPS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs__msg__DetectionWithGPS__Sequence__destroy(msgs__msg__DetectionWithGPS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs__msg__DetectionWithGPS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs__msg__DetectionWithGPS__Sequence__are_equal(const msgs__msg__DetectionWithGPS__Sequence * lhs, const msgs__msg__DetectionWithGPS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs__msg__DetectionWithGPS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs__msg__DetectionWithGPS__Sequence__copy(
  const msgs__msg__DetectionWithGPS__Sequence * input,
  msgs__msg__DetectionWithGPS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs__msg__DetectionWithGPS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs__msg__DetectionWithGPS * data =
      (msgs__msg__DetectionWithGPS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs__msg__DetectionWithGPS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs__msg__DetectionWithGPS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs__msg__DetectionWithGPS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
