cmake_minimum_required (VERSION 2.6)
project (last)

# The version number.
set (last_VERSION_MAJOR 0)
set (last_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/lastconfig.h.in"
  "${PROJECT_BINARY_DIR}/lastconfig.h"
)

# add the binary tree to the search path for include files
# so that we will find last.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(last main.cpp)