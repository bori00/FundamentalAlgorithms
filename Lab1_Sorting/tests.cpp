//
// Created by Bori on 10/4/2020.
//

#include "gtest/gtest.h"
#include "SorterTest.h"
#include "SelectionSorter.h"
#include "InsertionSorter.h"
#include "BubbleSorter.h"

TEST_F(SorterTest, SelectionSorter_RandomArray) {
    int* v = GetAverageArray();
    SelectionSorter selectionSorter;
    selectionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, SelectionSorter_SortedArray) {
    int* v = GetSortedArray();
    SelectionSorter selectionSorter;
    selectionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, SelectionSorter_InvSortedArray) {
    int* v = GetInverselySortedArray();
    SelectionSorter selectionSorter;
    selectionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, InsertionSorter_RandomArray) {
    int* v = GetAverageArray();
    InsertionSorter insertionSorter;
    insertionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, InsertionSorter_SortedArray) {
    int* v = GetSortedArray();
    InsertionSorter insertionSorter;
    insertionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, InsertionSorter_InvSortedArray) {
    int* v = GetInverselySortedArray();
    InsertionSorter insertionSorter;
    insertionSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, BubbleSorter_RandomArray) {
    int* v = GetAverageArray();
    BubbleSorter bubbleSorter;
    bubbleSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, BubbleSorter_SortedArray) {
    int* v = GetSortedArray();
    BubbleSorter bubbleSorter;
    bubbleSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}

TEST_F(SorterTest, BubbleSorter_InvSortedArray) {
    int* v = GetInverselySortedArray();
    BubbleSorter bubbleSorter;
    bubbleSorter.sort(v, ARRAY_LENGTH);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::ARRAY_LENGTH));
}