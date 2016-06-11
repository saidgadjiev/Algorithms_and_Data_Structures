cmake_minimum_required(VERSION 3.5)
project(QuickSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp QuickSort.h)
add_executable(QuickSort ${SOURCE_FILES})