//
// Created by Bori on 10/4/2020.
//

#include <iostream>
#include "gtest/gtest.h"
#include "sorter_test.h"
#include "selection_sorter.h"
#include "insertion_sorter.h"
#include "bubble_sorter.h"
#include "Profiler.h"

#define NO_RANDOM_TESTS 10
#define MAX_ARRAY_SIZE 10000

using namespace std;

Profiler ignoreP("ignore");

TEST_F(SorterTest, SelectionSorter_AverageArray) {
  int *v = GetAverageArray();
  SelectionSorter selectionSorter;
  selectionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, SelectionSorter_SortedArray) {
  int *v = GetSortedArray();
  SelectionSorter selectionSorter;
  selectionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, SelectionSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  SelectionSorter selectionSorter;
  selectionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

//TEST_F(SorterTest, SelectionSorter_RandomArrays) {
//  int v[MAX_ARRAY_SIZE];
//  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
//    int size = rand() % MAX_ARRAY_SIZE;
//    FillRandomArray(v, size);
//    SelectionSorter selectionSorter;
//    selectionSorter.Sort(v, size, ignoreP);
//    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
//  }
//}

TEST_F(SorterTest, InsertionSorter_AverageArray) {
  int *v = GetAverageArray();
  InsertionSorter insertionSorter;
  insertionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, InsertionSorter_SortedArray) {
  int *v = GetSortedArray();
  InsertionSorter insertionSorter;
  insertionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, InsertionSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  InsertionSorter insertionSorter;
  insertionSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

//TEST_F(SorterTest, InsertionnSorter_RandomArrays) {
//  int v[MAX_ARRAY_SIZE];
//  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
//    int size = rand() % MAX_ARRAY_SIZE;
//    FillRandomArray(v, size);
//    InsertionSorter insertionSorter;
//    insertionSorter.Sort(v, size, ignoreP);
//    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
//  }
//}

TEST_F(SorterTest, BubbleSorter_AverageArray) {
  int *v = GetAverageArray();
  BubbleSorter bubbleSorter;
  bubbleSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, BubbleSorter_SortedArray) {
  int *v = GetSortedArray();
  BubbleSorter bubbleSorter;
  bubbleSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, BubbleSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  BubbleSorter bubbleSorter;
  bubbleSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

//TEST_F(SorterTest, BubbleSorter_RandomArrays) {
//  int v[MAX_ARRAY_SIZE];
//  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
//    int size = rand() % MAX_ARRAY_SIZE;
//    FillRandomArray(v, size);
//    BubbleSorter bubbleSorter;
//    bubbleSorter.Sort(v, size, ignoreP);
//    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
//  }
//}