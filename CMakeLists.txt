cmake_minimum_required(VERSION 3.17)
project(StingRay)

set(CMAKE_CXX_STANDARD 14)

add_executable(StingRay src/main.cpp src/common/vec3.h)
add_subdirectory(tests)