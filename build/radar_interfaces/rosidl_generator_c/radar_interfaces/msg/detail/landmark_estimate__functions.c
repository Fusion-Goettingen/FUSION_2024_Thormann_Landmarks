// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from radar_interfaces:msg/LandmarkEstimate.idl
// generated code does not contain a copyright notice
#include "radar_interfaces/msg/detail/landmark_estimate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `range_bin`
// Member `heatmap`
// Member `angles_degree`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
radar_interfaces__msg__LandmarkEstimate__init(radar_interfaces__msg__LandmarkEstimate * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    radar_interfaces__msg__LandmarkEstimate__fini(msg);
    return false;
  }
  // range_bin
  if (!rosidl_runtime_c__double__Sequence__init(&msg->range_bin, 0)) {
    radar_interfaces__msg__LandmarkEstimate__fini(msg);
    return false;
  }
  // heatmap
  if (!rosidl_runtime_c__double__Sequence__init(&msg->heatmap, 0)) {
    radar_interfaces__msg__LandmarkEstimate__fini(msg);
    return false;
  }
  // angles_degree
  if (!rosidl_runtime_c__double__Sequence__init(&msg->angles_degree, 0)) {
    radar_interfaces__msg__LandmarkEstimate__fini(msg);
    return false;
  }
  return true;
}

void
radar_interfaces__msg__LandmarkEstimate__fini(radar_interfaces__msg__LandmarkEstimate * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // range_bin
  rosidl_runtime_c__double__Sequence__fini(&msg->range_bin);
  // heatmap
  rosidl_runtime_c__double__Sequence__fini(&msg->heatmap);
  // angles_degree
  rosidl_runtime_c__double__Sequence__fini(&msg->angles_degree);
}

bool
radar_interfaces__msg__LandmarkEstimate__are_equal(const radar_interfaces__msg__LandmarkEstimate * lhs, const radar_interfaces__msg__LandmarkEstimate * rhs)
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
  // range_bin
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->range_bin), &(rhs->range_bin)))
  {
    return false;
  }
  // heatmap
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->heatmap), &(rhs->heatmap)))
  {
    return false;
  }
  // angles_degree
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->angles_degree), &(rhs->angles_degree)))
  {
    return false;
  }
  return true;
}

bool
radar_interfaces__msg__LandmarkEstimate__copy(
  const radar_interfaces__msg__LandmarkEstimate * input,
  radar_interfaces__msg__LandmarkEstimate * output)
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
  // range_bin
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->range_bin), &(output->range_bin)))
  {
    return false;
  }
  // heatmap
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->heatmap), &(output->heatmap)))
  {
    return false;
  }
  // angles_degree
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->angles_degree), &(output->angles_degree)))
  {
    return false;
  }
  return true;
}

radar_interfaces__msg__LandmarkEstimate *
radar_interfaces__msg__LandmarkEstimate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__LandmarkEstimate * msg = (radar_interfaces__msg__LandmarkEstimate *)allocator.allocate(sizeof(radar_interfaces__msg__LandmarkEstimate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(radar_interfaces__msg__LandmarkEstimate));
  bool success = radar_interfaces__msg__LandmarkEstimate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
radar_interfaces__msg__LandmarkEstimate__destroy(radar_interfaces__msg__LandmarkEstimate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    radar_interfaces__msg__LandmarkEstimate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
radar_interfaces__msg__LandmarkEstimate__Sequence__init(radar_interfaces__msg__LandmarkEstimate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__LandmarkEstimate * data = NULL;

  if (size) {
    data = (radar_interfaces__msg__LandmarkEstimate *)allocator.zero_allocate(size, sizeof(radar_interfaces__msg__LandmarkEstimate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = radar_interfaces__msg__LandmarkEstimate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        radar_interfaces__msg__LandmarkEstimate__fini(&data[i - 1]);
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
radar_interfaces__msg__LandmarkEstimate__Sequence__fini(radar_interfaces__msg__LandmarkEstimate__Sequence * array)
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
      radar_interfaces__msg__LandmarkEstimate__fini(&array->data[i]);
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

radar_interfaces__msg__LandmarkEstimate__Sequence *
radar_interfaces__msg__LandmarkEstimate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  radar_interfaces__msg__LandmarkEstimate__Sequence * array = (radar_interfaces__msg__LandmarkEstimate__Sequence *)allocator.allocate(sizeof(radar_interfaces__msg__LandmarkEstimate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = radar_interfaces__msg__LandmarkEstimate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
radar_interfaces__msg__LandmarkEstimate__Sequence__destroy(radar_interfaces__msg__LandmarkEstimate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    radar_interfaces__msg__LandmarkEstimate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
radar_interfaces__msg__LandmarkEstimate__Sequence__are_equal(const radar_interfaces__msg__LandmarkEstimate__Sequence * lhs, const radar_interfaces__msg__LandmarkEstimate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!radar_interfaces__msg__LandmarkEstimate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
radar_interfaces__msg__LandmarkEstimate__Sequence__copy(
  const radar_interfaces__msg__LandmarkEstimate__Sequence * input,
  radar_interfaces__msg__LandmarkEstimate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(radar_interfaces__msg__LandmarkEstimate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    radar_interfaces__msg__LandmarkEstimate * data =
      (radar_interfaces__msg__LandmarkEstimate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!radar_interfaces__msg__LandmarkEstimate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          radar_interfaces__msg__LandmarkEstimate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!radar_interfaces__msg__LandmarkEstimate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
