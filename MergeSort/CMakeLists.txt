cmake_minimum_required(VERSION 3.5)
project(MergeSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MergeSort.h)
add_executable(MergeSort ${SOURCE_FILES})