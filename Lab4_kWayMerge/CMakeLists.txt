cmake_minimum_required(VERSION 3.15)
project(Lab4_kWayMerge)

set(CMAKE_CXX_STANDARD 14)

# setup Google Test framework
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Lab4_kWayMerge main.cpp list.cc list.h node.h node.cc heap.h heap.cc list_merger.h
        list_merger.cc list_merger_test.h list_merger_test.cc list_merger_tests.cc
        list_merger_evaluator.h list_merger_evaluator.cc)

target_link_libraries(Lab4_kWayMerge gtest gtest_main)