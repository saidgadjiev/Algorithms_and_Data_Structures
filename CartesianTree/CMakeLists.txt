cmake_minimum_required(VERSION 3.5)
project(CartesianTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CartesianTree.h)
add_executable(CartesianTree ${SOURCE_FILES})