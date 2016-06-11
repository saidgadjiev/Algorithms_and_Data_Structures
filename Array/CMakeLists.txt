cmake_minimum_required(VERSION 3.5)
project(Array)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Array.h)
add_executable(Array ${SOURCE_FILES})