// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__DETECTION_WITH_GPS__BUILDER_HPP_
#define MSGS__MSG__DETAIL__DETECTION_WITH_GPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/detection_with_gps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_DetectionWithGPS_image
{
public:
  explicit Init_DetectionWithGPS_image(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  ::msgs::msg::DetectionWithGPS image(::msgs::msg::DetectionWithGPS::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_gps
{
public:
  explicit Init_DetectionWithGPS_gps(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  Init_DetectionWithGPS_image gps(::msgs::msg::DetectionWithGPS::_gps_type arg)
  {
    msg_.gps = std::move(arg);
    return Init_DetectionWithGPS_image(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_tracking_ids
{
public:
  explicit Init_DetectionWithGPS_tracking_ids(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  Init_DetectionWithGPS_gps tracking_ids(::msgs::msg::DetectionWithGPS::_tracking_ids_type arg)
  {
    msg_.tracking_ids = std::move(arg);
    return Init_DetectionWithGPS_gps(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_boxes
{
public:
  explicit Init_DetectionWithGPS_boxes(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  Init_DetectionWithGPS_tracking_ids boxes(::msgs::msg::DetectionWithGPS::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return Init_DetectionWithGPS_tracking_ids(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_confidences
{
public:
  explicit Init_DetectionWithGPS_confidences(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  Init_DetectionWithGPS_boxes confidences(::msgs::msg::DetectionWithGPS::_confidences_type arg)
  {
    msg_.confidences = std::move(arg);
    return Init_DetectionWithGPS_boxes(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_labels
{
public:
  explicit Init_DetectionWithGPS_labels(::msgs::msg::DetectionWithGPS & msg)
  : msg_(msg)
  {}
  Init_DetectionWithGPS_confidences labels(::msgs::msg::DetectionWithGPS::_labels_type arg)
  {
    msg_.labels = std::move(arg);
    return Init_DetectionWithGPS_confidences(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

class Init_DetectionWithGPS_header
{
public:
  Init_DetectionWithGPS_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionWithGPS_labels header(::msgs::msg::DetectionWithGPS::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectionWithGPS_labels(msg_);
  }

private:
  ::msgs::msg::DetectionWithGPS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::DetectionWithGPS>()
{
  return msgs::msg::builder::Init_DetectionWithGPS_header();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__DETECTION_WITH_GPS__BUILDER_HPP_
