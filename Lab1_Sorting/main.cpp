#include <iostream>
#include "SelectionSorter.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
    SelectionSorter selectionSorter;
    int* v = (int*) malloc(sizeof(int)*10);
    selectionSorter.sort(v, sizeof(v) / sizeof(v[0]));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}