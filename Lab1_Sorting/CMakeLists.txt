cmake_minimum_required(VERSION 3.15)
project(Lab1_Sorting)

set(CMAKE_CXX_STANDARD 14)

# setup Google Test framework
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Lab1_Sorting main.cpp  Sorter.h Sorter.cpp SelectionSorter.h SelectionSorter.cpp InsertionSorter.h InsertionSorter.cpp BubbleSorter.h BubbleSorter.cpp SorterTest.h SorterTest.cpp tests.cpp Profiler.h)

target_link_libraries(Lab1_Sorting gtest gtest_main)