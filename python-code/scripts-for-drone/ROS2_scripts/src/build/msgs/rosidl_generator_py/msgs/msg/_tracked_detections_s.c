// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from msgs:msg/TrackedDetections.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "msgs/msg/detail/tracked_detections__struct.h"
#include "msgs/msg/detail/tracked_detections__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "msgs/msg/detail/tracked_object__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__nav_sat_fix__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__nav_sat_fix__convert_to_py(void * raw_ros_message);
bool msgs__msg__tracked_object__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * msgs__msg__tracked_object__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool msgs__msg__tracked_detections__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("msgs.msg._tracked_detections.TrackedDetections", full_classname_dest, 46) == 0);
  }
  msgs__msg__TrackedDetections * ros_message = _ros_message;
  {  // gps
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__nav_sat_fix__convert_from_py(field, &ros_message->gps)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // tracks
    PyObject * field = PyObject_GetAttrString(_pymsg, "tracks");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'tracks'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!msgs__msg__TrackedObject__Sequence__init(&(ros_message->tracks), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create msgs__msg__TrackedObject__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    msgs__msg__TrackedObject * dest = ros_message->tracks.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!msgs__msg__tracked_object__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // rgb_image
    PyObject * field = PyObject_GetAttrString(_pymsg, "rgb_image");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->rgb_image)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // thermal_image
    PyObject * field = PyObject_GetAttrString(_pymsg, "thermal_image");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->thermal_image)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * msgs__msg__tracked_detections__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TrackedDetections */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("msgs.msg._tracked_detections");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TrackedDetections");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  msgs__msg__TrackedDetections * ros_message = (msgs__msg__TrackedDetections *)raw_ros_message;
  {  // gps
    PyObject * field = NULL;
    field = sensor_msgs__msg__nav_sat_fix__convert_to_py(&ros_message->gps);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tracks
    PyObject * field = NULL;
    size_t size = ros_message->tracks.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    msgs__msg__TrackedObject * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->tracks.data[i]);
      PyObject * pyitem = msgs__msg__tracked_object__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "tracks", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rgb_image
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->rgb_image);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "rgb_image", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thermal_image
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->thermal_image);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "thermal_image", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
