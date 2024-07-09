// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "radar_interfaces/msg/detail/ground_truth__rosidl_typesupport_introspection_c.h"
#include "radar_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "radar_interfaces/msg/detail/ground_truth__functions.h"
#include "radar_interfaces/msg/detail/ground_truth__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `relative_landmark_range`
// Member `relative_landmark_angle`
// Member `relative_position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  radar_interfaces__msg__GroundTruth__init(message_memory);
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_fini_function(void * message_memory)
{
  radar_interfaces__msg__GroundTruth__fini(message_memory);
}

size_t radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_landmark_range(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_range(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_range(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_landmark_range(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_range(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_landmark_range(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_range(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_landmark_range(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_landmark_angle(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_angle(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_angle(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_landmark_angle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_angle(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_landmark_angle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_angle(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_landmark_angle(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_position(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces__msg__GroundTruth, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative_landmark_range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces__msg__GroundTruth, relative_landmark_range),  // bytes offset in struct
    NULL,  // default value
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_landmark_range,  // size() function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_range,  // get_const(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_range,  // get(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_landmark_range,  // fetch(index, &value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_landmark_range,  // assign(index, value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_landmark_range  // resize(index) function pointer
  },
  {
    "relative_landmark_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces__msg__GroundTruth, relative_landmark_angle),  // bytes offset in struct
    NULL,  // default value
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_landmark_angle,  // size() function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_landmark_angle,  // get_const(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_landmark_angle,  // get(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_landmark_angle,  // fetch(index, &value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_landmark_angle,  // assign(index, value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_landmark_angle  // resize(index) function pointer
  },
  {
    "is_moving",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces__msg__GroundTruth, is_moving),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces__msg__GroundTruth, relative_position),  // bytes offset in struct
    NULL,  // default value
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__size_function__GroundTruth__relative_position,  // size() function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_const_function__GroundTruth__relative_position,  // get_const(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__get_function__GroundTruth__relative_position,  // get(index) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__fetch_function__GroundTruth__relative_position,  // fetch(index, &value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__assign_function__GroundTruth__relative_position,  // assign(index, value) function pointer
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__resize_function__GroundTruth__relative_position  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_members = {
  "radar_interfaces__msg",  // message namespace
  "GroundTruth",  // message name
  5,  // number of fields
  sizeof(radar_interfaces__msg__GroundTruth),
  radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_member_array,  // message members
  radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_init_function,  // function to initialize message memory (memory has to be allocated)
  radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_type_support_handle = {
  0,
  &radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_radar_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, radar_interfaces, msg, GroundTruth)() {
  radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_type_support_handle.typesupport_identifier) {
    radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &radar_interfaces__msg__GroundTruth__rosidl_typesupport_introspection_c__GroundTruth_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
