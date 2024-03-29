cmake_minimum_required(VERSION 3.15)
project(Lab1_Sorting)

set(CMAKE_CXX_STANDARD 14)

# setup Google Test framework
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Lab1_Sorting main.cc sorter.h sorter.cc selection_sorter.h selection_sorter.cc
        insertion_sorter.h insertion_sorter.cc bubble_sorter.h bubble_sorter.cc sorter_test.h
        sorter_test.cc sorter_tests.cc Profiler.h sorter_evaluator.h sorter_evaluator.cc heap.cc heap.h
        heap_test.h heap_test.cc heap_tests.cc heap_sorter.h heap_sorter.cc heap_evaluator.cc
        heap_evaluator.h akl_quick_sorter.h akl_quick_sorter.cc randomized_quick_sorter.h
        randomized_quick_sorter.cc lomuto_quick_sorter.cc lomuto_quick_sorter.h
        lomuto_middle_quick_sorter.h lomuto_middle_quick_sorter.cc randomized_quick_select_test.h
        randomized_quick_select_test.cc randomized_quick_select_tests.cc
        randomized_quick_selector.h randomized_quick_selector.cc)

target_link_libraries(Lab1_Sorting gtest gtest_main)