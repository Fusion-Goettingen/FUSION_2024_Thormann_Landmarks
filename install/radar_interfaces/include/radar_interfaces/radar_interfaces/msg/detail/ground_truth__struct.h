// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_H_
#define RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'relative_landmark_range'
// Member 'relative_landmark_angle'
// Member 'relative_position'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/GroundTruth in the package radar_interfaces.
/**
  * Array for storing the ground truth consisting of landmarks relative to the sensor as well as the odometry changes since the initial time frame as arrays. Provides header with time stamp and ID information.
 */
typedef struct radar_interfaces__msg__GroundTruth
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence relative_landmark_range;
  rosidl_runtime_c__double__Sequence relative_landmark_angle;
  bool is_moving;
  rosidl_runtime_c__double__Sequence relative_position;
} radar_interfaces__msg__GroundTruth;

// Struct for a sequence of radar_interfaces__msg__GroundTruth.
typedef struct radar_interfaces__msg__GroundTruth__Sequence
{
  radar_interfaces__msg__GroundTruth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} radar_interfaces__msg__GroundTruth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__STRUCT_H_
