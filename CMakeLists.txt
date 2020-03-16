cmake_minimum_required(VERSION 3.10.2)

set(THIS Vector_test)

project(Vector_test)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -pthread")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_custom_target(start COMMAND ${THIS})

set(DO_CLANG_FORMAT clang-format)

set(CLANG_OPT "-i")

add_custom_target(format COMMAND
  ${DO_CLANG_FORMAT} ${CLANG_OPT}
  ../Vector.hpp
  ../test_vector.cpp
  )

add_executable(Vector_test test_vector.cpp)

target_link_libraries(Vector_test ${GTEST_LIBRARIES} gtest_main)



