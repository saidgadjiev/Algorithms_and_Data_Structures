cmake_minimum_required(VERSION 3.5)
project(Dequeue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp dequeue.h)
add_executable(Dequeue ${SOURCE_FILES})