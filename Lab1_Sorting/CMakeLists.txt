cmake_minimum_required(VERSION 3.15)
project(Lab1_Sorting_CLion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1_Sorting_CLion main.cpp  Sorter.h Sorter.cpp SelectionSorter.h SelectionSorter.cpp InsertionSorter.h InsertionSorter.cpp BubbleSorter.h BubbleSorter.cpp)

add_subdirectory(Google_tests)