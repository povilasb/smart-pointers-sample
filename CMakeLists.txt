cmake_minimum_required(VERSION 2.6)

# Configurable.

if (NOT DEFINED PROJECT_NAME)
	set(PROJECT_NAME "main")
endif(NOT DEFINED PROJECT_NAME)


project(${PROJECT_NAME} CXX)
set(PROJECT_EXEC "${PROJECT_NAME}")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -pedantic")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

add_executable("${PROJECT_EXEC}" "${SRC_FILES}")
