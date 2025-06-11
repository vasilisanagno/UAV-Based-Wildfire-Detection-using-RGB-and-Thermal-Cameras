// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs:msg/DetectionWithGPS.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__DETECTION_WITH_GPS__TRAITS_HPP_
#define MSGS__MSG__DETAIL__DETECTION_WITH_GPS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs/msg/detail/detection_with_gps__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'gps'
#include "sensor_msgs/msg/detail/nav_sat_fix__traits.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionWithGPS & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: labels
  {
    if (msg.labels.size() == 0) {
      out << "labels: []";
    } else {
      out << "labels: [";
      size_t pending_items = msg.labels.size();
      for (auto item : msg.labels) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: confidences
  {
    if (msg.confidences.size() == 0) {
      out << "confidences: []";
    } else {
      out << "confidences: [";
      size_t pending_items = msg.confidences.size();
      for (auto item : msg.confidences) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: boxes
  {
    if (msg.boxes.size() == 0) {
      out << "boxes: []";
    } else {
      out << "boxes: [";
      size_t pending_items = msg.boxes.size();
      for (auto item : msg.boxes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tracking_ids
  {
    if (msg.tracking_ids.size() == 0) {
      out << "tracking_ids: []";
    } else {
      out << "tracking_ids: [";
      size_t pending_items = msg.tracking_ids.size();
      for (auto item : msg.tracking_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gps
  {
    out << "gps: ";
    to_flow_style_yaml(msg.gps, out);
    out << ", ";
  }

  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionWithGPS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: labels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.labels.size() == 0) {
      out << "labels: []\n";
    } else {
      out << "labels:\n";
      for (auto item : msg.labels) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: confidences
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.confidences.size() == 0) {
      out << "confidences: []\n";
    } else {
      out << "confidences:\n";
      for (auto item : msg.confidences) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.boxes.size() == 0) {
      out << "boxes: []\n";
    } else {
      out << "boxes:\n";
      for (auto item : msg.boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tracking_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tracking_ids.size() == 0) {
      out << "tracking_ids: []\n";
    } else {
      out << "tracking_ids:\n";
      for (auto item : msg.tracking_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps:\n";
    to_block_style_yaml(msg.gps, out, indentation + 2);
  }

  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionWithGPS & msg, bool use_flow_style = false)
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
  const msgs::msg::DetectionWithGPS & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs::msg::DetectionWithGPS & msg)
{
  return msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs::msg::DetectionWithGPS>()
{
  return "msgs::msg::DetectionWithGPS";
}

template<>
inline const char * name<msgs::msg::DetectionWithGPS>()
{
  return "msgs/msg/DetectionWithGPS";
}

template<>
struct has_fixed_size<msgs::msg::DetectionWithGPS>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<msgs::msg::DetectionWithGPS>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<msgs::msg::DetectionWithGPS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS__MSG__DETAIL__DETECTION_WITH_GPS__TRAITS_HPP_
