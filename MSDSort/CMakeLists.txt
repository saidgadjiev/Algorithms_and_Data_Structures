cmake_minimum_required(VERSION 3.5)
project(MSDSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MSDSort.h)
add_executable(MSDSort ${SOURCE_FILES})