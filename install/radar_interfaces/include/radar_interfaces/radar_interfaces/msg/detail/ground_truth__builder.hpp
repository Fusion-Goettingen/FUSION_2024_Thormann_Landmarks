// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from radar_interfaces:msg/GroundTruth.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__BUILDER_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "radar_interfaces/msg/detail/ground_truth__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace radar_interfaces
{

namespace msg
{

namespace builder
{

class Init_GroundTruth_relative_position
{
public:
  explicit Init_GroundTruth_relative_position(::radar_interfaces::msg::GroundTruth & msg)
  : msg_(msg)
  {}
  ::radar_interfaces::msg::GroundTruth relative_position(::radar_interfaces::msg::GroundTruth::_relative_position_type arg)
  {
    msg_.relative_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::radar_interfaces::msg::GroundTruth msg_;
};

class Init_GroundTruth_is_moving
{
public:
  explicit Init_GroundTruth_is_moving(::radar_interfaces::msg::GroundTruth & msg)
  : msg_(msg)
  {}
  Init_GroundTruth_relative_position is_moving(::radar_interfaces::msg::GroundTruth::_is_moving_type arg)
  {
    msg_.is_moving = std::move(arg);
    return Init_GroundTruth_relative_position(msg_);
  }

private:
  ::radar_interfaces::msg::GroundTruth msg_;
};

class Init_GroundTruth_relative_landmark_angle
{
public:
  explicit Init_GroundTruth_relative_landmark_angle(::radar_interfaces::msg::GroundTruth & msg)
  : msg_(msg)
  {}
  Init_GroundTruth_is_moving relative_landmark_angle(::radar_interfaces::msg::GroundTruth::_relative_landmark_angle_type arg)
  {
    msg_.relative_landmark_angle = std::move(arg);
    return Init_GroundTruth_is_moving(msg_);
  }

private:
  ::radar_interfaces::msg::GroundTruth msg_;
};

class Init_GroundTruth_relative_landmark_range
{
public:
  explicit Init_GroundTruth_relative_landmark_range(::radar_interfaces::msg::GroundTruth & msg)
  : msg_(msg)
  {}
  Init_GroundTruth_relative_landmark_angle relative_landmark_range(::radar_interfaces::msg::GroundTruth::_relative_landmark_range_type arg)
  {
    msg_.relative_landmark_range = std::move(arg);
    return Init_GroundTruth_relative_landmark_angle(msg_);
  }

private:
  ::radar_interfaces::msg::GroundTruth msg_;
};

class Init_GroundTruth_header
{
public:
  Init_GroundTruth_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GroundTruth_relative_landmark_range header(::radar_interfaces::msg::GroundTruth::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GroundTruth_relative_landmark_range(msg_);
  }

private:
  ::radar_interfaces::msg::GroundTruth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::radar_interfaces::msg::GroundTruth>()
{
  return radar_interfaces::msg::builder::Init_GroundTruth_header();
}

}  // namespace radar_interfaces

#endif  // RADAR_INTERFACES__MSG__DETAIL__GROUND_TRUTH__BUILDER_HPP_
