// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/ImageWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__IMAGE_WITH_GPS__BUILDER_HPP_
#define MSGS__MSG__DETAIL__IMAGE_WITH_GPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/image_with_gps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_ImageWithGPS_gps
{
public:
  explicit Init_ImageWithGPS_gps(::msgs::msg::ImageWithGPS & msg)
  : msg_(msg)
  {}
  ::msgs::msg::ImageWithGPS gps(::msgs::msg::ImageWithGPS::_gps_type arg)
  {
    msg_.gps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::ImageWithGPS msg_;
};

class Init_ImageWithGPS_image
{
public:
  Init_ImageWithGPS_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageWithGPS_gps image(::msgs::msg::ImageWithGPS::_image_type arg)
  {
    msg_.image = std::move(arg);
    return Init_ImageWithGPS_gps(msg_);
  }

private:
  ::msgs::msg::ImageWithGPS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::ImageWithGPS>()
{
  return msgs::msg::builder::Init_ImageWithGPS_image();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__IMAGE_WITH_GPS__BUILDER_HPP_
