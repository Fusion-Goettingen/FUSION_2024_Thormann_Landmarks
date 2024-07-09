// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "radar_interfaces/msg/detail/ground_truth__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace radar_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GroundTruth_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) radar_interfaces::msg::GroundTruth(_init);
}

void GroundTruth_fini_function(void * message_memory)
{
  auto typed_message = static_cast<radar_interfaces::msg::GroundTruth *>(message_memory);
  typed_message->~GroundTruth();
}

size_t size_function__GroundTruth__relative_landmark_range(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GroundTruth__relative_landmark_range(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__GroundTruth__relative_landmark_range(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__GroundTruth__relative_landmark_range(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__GroundTruth__relative_landmark_range(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__GroundTruth__relative_landmark_range(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__GroundTruth__relative_landmark_range(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__GroundTruth__relative_landmark_range(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GroundTruth__relative_landmark_angle(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GroundTruth__relative_landmark_angle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__GroundTruth__relative_landmark_angle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__GroundTruth__relative_landmark_angle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__GroundTruth__relative_landmark_angle(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__GroundTruth__relative_landmark_angle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__GroundTruth__relative_landmark_angle(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__GroundTruth__relative_landmark_angle(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GroundTruth__relative_position(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GroundTruth__relative_position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__GroundTruth__relative_position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__GroundTruth__relative_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__GroundTruth__relative_position(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__GroundTruth__relative_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__GroundTruth__relative_position(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__GroundTruth__relative_position(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GroundTruth_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces::msg::GroundTruth, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "relative_landmark_range",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces::msg::GroundTruth, relative_landmark_range),  // bytes offset in struct
    nullptr,  // default value
    size_function__GroundTruth__relative_landmark_range,  // size() function pointer
    get_const_function__GroundTruth__relative_landmark_range,  // get_const(index) function pointer
    get_function__GroundTruth__relative_landmark_range,  // get(index) function pointer
    fetch_function__GroundTruth__relative_landmark_range,  // fetch(index, &value) function pointer
    assign_function__GroundTruth__relative_landmark_range,  // assign(index, value) function pointer
    resize_function__GroundTruth__relative_landmark_range  // resize(index) function pointer
  },
  {
    "relative_landmark_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces::msg::GroundTruth, relative_landmark_angle),  // bytes offset in struct
    nullptr,  // default value
    size_function__GroundTruth__relative_landmark_angle,  // size() function pointer
    get_const_function__GroundTruth__relative_landmark_angle,  // get_const(index) function pointer
    get_function__GroundTruth__relative_landmark_angle,  // get(index) function pointer
    fetch_function__GroundTruth__relative_landmark_angle,  // fetch(index, &value) function pointer
    assign_function__GroundTruth__relative_landmark_angle,  // assign(index, value) function pointer
    resize_function__GroundTruth__relative_landmark_angle  // resize(index) function pointer
  },
  {
    "is_moving",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces::msg::GroundTruth, is_moving),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "relative_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(radar_interfaces::msg::GroundTruth, relative_position),  // bytes offset in struct
    nullptr,  // default value
    size_function__GroundTruth__relative_position,  // size() function pointer
    get_const_function__GroundTruth__relative_position,  // get_const(index) function pointer
    get_function__GroundTruth__relative_position,  // get(index) function pointer
    fetch_function__GroundTruth__relative_position,  // fetch(index, &value) function pointer
    assign_function__GroundTruth__relative_position,  // assign(index, value) function pointer
    resize_function__GroundTruth__relative_position  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GroundTruth_message_members = {
  "radar_interfaces::msg",  // message namespace
  "GroundTruth",  // message name
  5,  // number of fields
  sizeof(radar_interfaces::msg::GroundTruth),
  GroundTruth_message_member_array,  // message members
  GroundTruth_init_function,  // function to initialize message memory (memory has to be allocated)
  GroundTruth_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GroundTruth_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GroundTruth_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace radar_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<radar_interfaces::msg::GroundTruth>()
{
  return &::radar_interfaces::msg::rosidl_typesupport_introspection_cpp::GroundTruth_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, radar_interfaces, msg, GroundTruth)() {
  return &::radar_interfaces::msg::rosidl_typesupport_introspection_cpp::GroundTruth_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
