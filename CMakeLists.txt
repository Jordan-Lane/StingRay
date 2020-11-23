cmake_minimum_required(VERSION 3.17)
project(StingRay)

set(CMAKE_CXX_STANDARD 14)

add_executable(StingRay src/main.cpp)
add_subdirectory(tests)