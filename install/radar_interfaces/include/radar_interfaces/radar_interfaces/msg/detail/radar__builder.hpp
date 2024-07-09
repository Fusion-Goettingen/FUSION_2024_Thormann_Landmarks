// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from radar_interfaces:msg/Radar.idl
// generated code does not contain a copyright notice

#ifndef RADAR_INTERFACES__MSG__DETAIL__RADAR__BUILDER_HPP_
#define RADAR_INTERFACES__MSG__DETAIL__RADAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "radar_interfaces/msg/detail/radar__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace radar_interfaces
{

namespace msg
{

namespace builder
{

class Init_Radar_data
{
public:
  explicit Init_Radar_data(::radar_interfaces::msg::Radar & msg)
  : msg_(msg)
  {}
  ::radar_interfaces::msg::Radar data(::radar_interfaces::msg::Radar::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::radar_interfaces::msg::Radar msg_;
};

class Init_Radar_header
{
public:
  Init_Radar_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Radar_data header(::radar_interfaces::msg::Radar::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Radar_data(msg_);
  }

private:
  ::radar_interfaces::msg::Radar msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::radar_interfaces::msg::Radar>()
{
  return radar_interfaces::msg::builder::Init_Radar_header();
}

}  // namespace radar_interfaces

#endif  // RADAR_INTERFACES__MSG__DETAIL__RADAR__BUILDER_HPP_
