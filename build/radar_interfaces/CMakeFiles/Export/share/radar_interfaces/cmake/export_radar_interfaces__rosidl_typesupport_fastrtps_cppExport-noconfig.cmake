#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "radar_interfaces::radar_interfaces__rosidl_typesupport_fastrtps_cpp" for configuration ""
set_property(TARGET radar_interfaces::radar_interfaces__rosidl_typesupport_fastrtps_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(radar_interfaces::radar_interfaces__rosidl_typesupport_fastrtps_cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libradar_interfaces__rosidl_typesupport_fastrtps_cpp.so"
  IMPORTED_SONAME_NOCONFIG "libradar_interfaces__rosidl_typesupport_fastrtps_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS radar_interfaces::radar_interfaces__rosidl_typesupport_fastrtps_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_radar_interfaces::radar_interfaces__rosidl_typesupport_fastrtps_cpp "${_IMPORT_PREFIX}/lib/libradar_interfaces__rosidl_typesupport_fastrtps_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
