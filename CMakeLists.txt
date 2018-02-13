cmake_minimum_required (VERSION 2.8.2)
set(PROJECT_NAME last)
project (${PROJECT_NAME})

# The version number.
set (last_VERSION_MAJOR 0)
set (last_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/lastconfig.h.in"
  "${PROJECT_BINARY_DIR}/src/lastconfig.h"
)

# Must use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

# project defines
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/src)

# add the binary tree to the search path for include files so that we will find lastconfig.h
SET (LAST_INCLUDES
	${PROJECT_BINARY_DIR}/src
	${PROJECT_SOURCE_DIR}/src
)

include_directories(${LAST_INCLUDES})

SET(SOURCE
	src/last_ast.cpp
	src/last_evaluator.cpp
	src/last_parser.cpp
	src/last_token.cpp
	src/last_utils.cpp
)

SET(HEADERS
	src/last_ast.h
	src/last_evaluator.h
	src/last_parser.h
	src/last_token.h
	src/last_utils.h
)

add_library(liblast
	${SOURCE}
	${HEADERS}
)

# main target
add_executable(last src/main.cpp)
target_link_libraries(last liblast)

# Testing support
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# Testing
add_executable(liblast_test test/test_last.cpp)
target_link_libraries(liblast_test liblast gtest gmock_main)
add_test(NAME Runner COMMAND liblast_test)
add_test(NAME Creator COMMAND liblast_test)
