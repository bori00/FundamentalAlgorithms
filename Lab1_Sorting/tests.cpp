//
// Created by Bori on 10/4/2020.
//

#include "gtest/gtest.h"
#include "SorterTest.h"
#include "SelectionSorter.h"

TEST_F(SorterTest, SelectionSorter_RandomArray) {
    int* v = GetRandomArray();
    SelectionSorter selectionSorter;
    selectionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}