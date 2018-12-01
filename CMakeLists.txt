cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(shape)

#Bring the headers, such as Shape.h into the project
include_directories(include)

file(GLOB SOURCES "src/*.cpp")


add_executable(shapes ${SOURCES})
