cmake_minimum_required (VERSION 2.8.2)
set(PROJECT_NAME last)
project (${PROJECT_NAME})

# The version number.
set (last_VERSION_MAJOR 0)
set (last_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/lastconfig.h.in"
  "${PROJECT_BINARY_DIR}/src/lastconfig.h"
)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

# add the binary tree to the search path for include files
# so that we will find last headers
include_directories("${PROJECT_BINARY_DIR}")
include_directories(src/)

# Define library. Only source files here!
cmake_minimum_required (VERSION 2.6)
project(liblast LANGUAGES CXX)

SET(SOURCE
	src/last_ast.cpp
	src/last_evaluator.cpp
	src/last_parser.cpp
)

SET(HEADERS
	src/last_ast.h
	src/last_evaluator.h
	src/last_parser.h
)

add_library(liblast
	${SOURCE}
	${HEADERS}
)

add_executable(last src/main.cpp)
target_link_libraries(last liblast)

# Testing support
include(cmake/googletest.cmake)

# Trivial example using gtest and gmock
add_executable(last-test-runner tests/last-test-runner.cpp)
target_link_libraries(last-test-runner liblast gtest gmock_main)
add_test(NAME last-test-runner_test COMMAND last-test-runner)
