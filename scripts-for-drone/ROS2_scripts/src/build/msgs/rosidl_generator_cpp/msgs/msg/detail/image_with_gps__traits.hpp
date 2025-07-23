// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs:msg/ImageWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__IMAGE_WITH_GPS__TRAITS_HPP_
#define MSGS__MSG__DETAIL__IMAGE_WITH_GPS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs/msg/detail/image_with_gps__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__traits.hpp"

namespace msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImageWithGPS & msg,
  std::ostream & out)
{
  out << "{";
  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
    out << ", ";
  }

  // member: gps
  {
    out << "gps: ";
    to_flow_style_yaml(msg.gps, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ImageWithGPS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }

  // member: gps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps:\n";
    to_block_style_yaml(msg.gps, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImageWithGPS & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msgs

namespace rosidl_generator_traits
{

[[deprecated("use msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msgs::msg::ImageWithGPS & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs::msg::ImageWithGPS & msg)
{
  return msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs::msg::ImageWithGPS>()
{
  return "msgs::msg::ImageWithGPS";
}

template<>
inline const char * name<msgs::msg::ImageWithGPS>()
{
  return "msgs/msg/ImageWithGPS";
}

template<>
struct has_fixed_size<msgs::msg::ImageWithGPS>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<sensor_msgs::msg::NavSatFix>::value> {};

template<>
struct has_bounded_size<msgs::msg::ImageWithGPS>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<sensor_msgs::msg::NavSatFix>::value> {};

template<>
struct is_message<msgs::msg::ImageWithGPS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS__MSG__DETAIL__IMAGE_WITH_GPS__TRAITS_HPP_
