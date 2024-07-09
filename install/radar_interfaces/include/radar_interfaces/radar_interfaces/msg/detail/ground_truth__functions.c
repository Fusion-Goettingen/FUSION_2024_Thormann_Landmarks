// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice
#include "radar_interfaces/msg/detail/ground_truth__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `relative_landmark_range`
// Member `relative_landmark_angle`
// Member `relative_position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
radar_interfaces__msg__GroundTruth__init(radar_interfaces__msg__GroundTruth * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    radar_interfaces__msg__GroundTruth__fini(msg);
    return false;
  }
  // relative_landmark_range
  if (!rosidl_runtime_c__double__Sequence__init(&msg->relative_landmark_range, 0)) {
    radar_interfaces__msg__GroundTruth__fini(msg);
    return false;
  }
  // relative_landmark_angle
  if (!rosidl_runtime_c__double__Sequence__init(&msg->relative_landmark_angle, 0)) {
    radar_interfaces__msg__GroundTruth__fini(msg);
    return false;
  }
  // is_moving
  // relative_position
  if (!rosidl_runtime_c__double__Sequence__init(&msg->relative_position, 0)) {
    radar_interfaces__msg__GroundTruth__fini(msg);
    return false;
  }
  return true;
}

void
radar_interfaces__msg__GroundTruth__fini(radar_interfaces__msg__GroundTruth * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // relative_landmark_range
  rosidl_runtime_c__double__Sequence__fini(&msg->relative_landmark_range);
  // relative_landmark_angle
  rosidl_runtime_c__double__Sequence__fini(&msg->relative_landmark_angle);
  // is_moving
  // relative_position
  rosidl_runtime_c__double__Sequence__fini(&msg->relative_position);
}

bool
radar_interfaces__msg__GroundTruth__are_equal(const radar_interfaces__msg__GroundTruth * lhs, const radar_interfaces__msg__GroundTruth * rhs)
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
  // relative_landmark_range
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->relative_landmark_range), &(rhs->relative_landmark_range)))
  {
    return false;
  }
  // relative_landmark_angle
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->relative_landmark_angle), &(rhs->relative_landmark_angle)))
  {
    return false;
  }
  // is_moving
  if (lhs->is_moving != rhs->is_moving) {
    return false;
  }
  // relative_position
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->relative_position), &(rhs->relative_position)))
  {
    return false;
  }
  return true;
}

bool
radar_interfaces__msg__GroundTruth__copy(
  const radar_interfaces__msg__GroundTruth * input,
  radar_interfaces__msg__GroundTruth * output)
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
  // relative_landmark_range
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->relative_landmark_range), &(output->relative_landmark_range)))
  {
    return false;
  }
  // relative_landmark_angle
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->relative_landmark_angle), &(output->relative_landmark_angle)))
  {
    return false;
  }
  // is_moving
  output->is_moving = input->is_moving;
  // relative_position
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->relative_position), &(output->relative_position)))
  {
    return false;
  }
  return true;
}

radar_interfaces__msg__GroundTruth *
radar_interfaces__msg__GroundTruth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__GroundTruth * msg = (radar_interfaces__msg__GroundTruth *)allocator.allocate(sizeof(radar_interfaces__msg__GroundTruth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(radar_interfaces__msg__GroundTruth));
  bool success = radar_interfaces__msg__GroundTruth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
radar_interfaces__msg__GroundTruth__destroy(radar_interfaces__msg__GroundTruth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    radar_interfaces__msg__GroundTruth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
radar_interfaces__msg__GroundTruth__Sequence__init(radar_interfaces__msg__GroundTruth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__GroundTruth * data = NULL;

  if (size) {
    data = (radar_interfaces__msg__GroundTruth *)allocator.zero_allocate(size, sizeof(radar_interfaces__msg__GroundTruth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = radar_interfaces__msg__GroundTruth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        radar_interfaces__msg__GroundTruth__fini(&data[i - 1]);
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
radar_interfaces__msg__GroundTruth__Sequence__fini(radar_interfaces__msg__GroundTruth__Sequence * array)
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
      radar_interfaces__msg__GroundTruth__fini(&array->data[i]);
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

radar_interfaces__msg__GroundTruth__Sequence *
radar_interfaces__msg__GroundTruth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__GroundTruth__Sequence * array = (radar_interfaces__msg__GroundTruth__Sequence *)allocator.allocate(sizeof(radar_interfaces__msg__GroundTruth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = radar_interfaces__msg__GroundTruth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
radar_interfaces__msg__GroundTruth__Sequence__destroy(radar_interfaces__msg__GroundTruth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    radar_interfaces__msg__GroundTruth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
radar_interfaces__msg__GroundTruth__Sequence__are_equal(const radar_interfaces__msg__GroundTruth__Sequence * lhs, const radar_interfaces__msg__GroundTruth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!radar_interfaces__msg__GroundTruth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
radar_interfaces__msg__GroundTruth__Sequence__copy(
  const radar_interfaces__msg__GroundTruth__Sequence * input,
  radar_interfaces__msg__GroundTruth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(radar_interfaces__msg__GroundTruth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    radar_interfaces__msg__GroundTruth * data =
      (radar_interfaces__msg__GroundTruth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!radar_interfaces__msg__GroundTruth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          radar_interfaces__msg__GroundTruth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!radar_interfaces__msg__GroundTruth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
