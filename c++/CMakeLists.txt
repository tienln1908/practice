cmake_minimum_required(VERSION 2.8)

option(gtest "Build all tests." OFF)

set(PROJECT_NAME programming)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(programming ${PROJECT_SOURCE_DIR}/src/main.cpp)

################################
# Testing
################################
if (gtest)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/googletest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests ${PROJECT_SOURCE_DIR}/src/unit_tests.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  add_test(NAME UnitTests COMMAND runUnitTests)
endif()

