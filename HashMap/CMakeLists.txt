cmake_minimum_required(VERSION 3.5)
project(HashMap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp hashentry.cpp hashmap.cpp)
add_executable(HashMap ${SOURCE_FILES})