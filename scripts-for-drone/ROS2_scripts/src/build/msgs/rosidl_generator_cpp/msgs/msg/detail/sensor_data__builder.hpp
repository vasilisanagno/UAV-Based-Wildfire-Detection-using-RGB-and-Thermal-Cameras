// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/SensorData.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_
#define MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/sensor_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_SensorData_gps
{
public:
  explicit Init_SensorData_gps(::msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  ::msgs::msg::SensorData gps(::msgs::msg::SensorData::_gps_type arg)
  {
    msg_.gps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::SensorData msg_;
};

class Init_SensorData_thermal_image
{
public:
  explicit Init_SensorData_thermal_image(::msgs::msg::SensorData & msg)
  : msg_(msg)
  {}
  Init_SensorData_gps thermal_image(::msgs::msg::SensorData::_thermal_image_type arg)
  {
    msg_.thermal_image = std::move(arg);
    return Init_SensorData_gps(msg_);
  }

private:
  ::msgs::msg::SensorData msg_;
};

class Init_SensorData_rgb_image
{
public:
  Init_SensorData_rgb_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorData_thermal_image rgb_image(::msgs::msg::SensorData::_rgb_image_type arg)
  {
    msg_.rgb_image = std::move(arg);
    return Init_SensorData_thermal_image(msg_);
  }

private:
  ::msgs::msg::SensorData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::SensorData>()
{
  return msgs::msg::builder::Init_SensorData_rgb_image();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__SENSOR_DATA__BUILDER_HPP_
