cmake_minimum_required(VERSION 3.14)

project(print)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(prin STATIC sources/print.cpp)
include_directories(include)
add_executable(example1 examples/example1.cpp)
add_executable(example2 examples/example2.cpp)

target_link_libraries(example1 print)
target_link_libraries(example2 print)

