cmake_minimum_required(VERSION 3.14)

project(print)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(print STATIC sources/print.cpp)
include_directories(include)
include_directories(example)
add_executable(example1 examples/example1.cpp)
add_executable(example2 examples/example2.cpp)

target_link_libraries(example1 print)
target_link_libraries(example2 print)


if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/googletest)
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} gtest_main)
  add_test(NAME check COMMAND check)
endif()
