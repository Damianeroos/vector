cmake_minimum_required(VERSION 3.10.2)
project(Vector_test)
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -pthread")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(Vector_test test_vector.cpp)
target_link_libraries(Vector_test ${GTEST_LIBRARIES} gtest_main)


