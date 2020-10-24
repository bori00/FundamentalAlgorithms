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
#include "heap_sorter.h"
#include "akl_quick_sorter.h"
#include "randomized_quick_sorter.h"
#include "lomuto_quick_sorter.h"
#include "lomuto_middle_quick_sorter.h"

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

TEST_F(SorterTest, HeapSorter_AverageArray) {
  int *v = GetAverageArray();
  HeapSorter heapSorter;
  heapSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, HeapSorter_SortedArray) {
  int *v = GetSortedArray();
  HeapSorter heapSorter;
  heapSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, HeapSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  HeapSorter heapSorter;
  heapSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, HeapSorter_RandomArrays) {
  int v[MAX_ARRAY_SIZE];
  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_ARRAY_SIZE;
    FillRandomArray(v, size);
    HeapSorter heapSorter;
    heapSorter.Sort(v, size, ignoreP);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
  }
}

TEST_F(SorterTest, AklQuickSorter_AverageArray) {
  int *v = GetAverageArray();
  AklQuickSorter aklQuickSorter;
  aklQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, AklQuickSorter_SortedArray) {
  int *v = GetSortedArray();
  AklQuickSorter aklQuickSorter;
  aklQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, AklQuickSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  AklQuickSorter aklQuickSorter;
  aklQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, AklQuickSorter_RandomArrays) {
  int v[MAX_ARRAY_SIZE];
  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_ARRAY_SIZE;
    FillRandomArray(v, size, 10, 50000, false, UNSORTED);
    AklQuickSorter aklQuickSorter;
    aklQuickSorter.Sort(v, size, ignoreP);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
  }
}

TEST_F(SorterTest, RandomizedQuickSorter_AverageArray) {
  int *v = GetAverageArray();
  RandomizedQuickSorter randomizedQuickSorter;
  randomizedQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, RandomizedQuickSorter_SortedArray) {
  int *v = GetSortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  randomizedQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, RandomizedQuickSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  randomizedQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, RandomizedQuickSorter_RandomArrays) {
  int v[MAX_ARRAY_SIZE];
  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_ARRAY_SIZE;
    FillRandomArray(v, size, 10, 50000, false, UNSORTED);
    RandomizedQuickSorter randomizedQuickSorter;
    randomizedQuickSorter.Sort(v, size, ignoreP);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
  }
}

TEST_F(SorterTest, LomutoQuickSorter_AverageArray) {
  int *v = GetAverageArray();
  LomutoQuickSorter lomutoQuickSorter;
  lomutoQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoQuickSorter_SortedArray) {
  int *v = GetSortedArray();
  LomutoQuickSorter lomutoQuickSorter;
  lomutoQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoQuickSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  LomutoQuickSorter lomutoQuickSorter;
  lomutoQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoQuickSorter_RandomArrays) {
  int v[MAX_ARRAY_SIZE];
  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_ARRAY_SIZE;
    FillRandomArray(v, size, 10, 50000, false, UNSORTED);
    LomutoQuickSorter lomutoQuickSorter;
    lomutoQuickSorter.Sort(v, size, ignoreP);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
  }
}

TEST_F(SorterTest, LomutoMiddleQuickSorter_AverageArray) {
  int *v = GetAverageArray();
  LomutoMiddleQuickSorter lomutoMiddleQuickSorter;
  lomutoMiddleQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoMiddleQuickSorter_SortedArray) {
  int *v = GetSortedArray();
  LomutoMiddleQuickSorter lomutoMiddleQuickSorter;
  lomutoMiddleQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoMiddleQuickSorter_InvSortedArray) {
  int *v = GetInverselySortedArray();
  LomutoMiddleQuickSorter lomutoMiddleQuickSorter;
  lomutoMiddleQuickSorter.Sort(v, kArrayLength, ignoreP);
  EXPECT_TRUE(SorterTest::ArrayIsSorted(v, SorterTest::kArrayLength));
}

TEST_F(SorterTest, LomutoMiddleMiddleQuickSorter_RandomArrays) {
  int v[MAX_ARRAY_SIZE];
  for (int i = 0; i < NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_ARRAY_SIZE;
    FillRandomArray(v, size, 10, 50000, false, UNSORTED);
    LomutoMiddleQuickSorter lomutoMiddleQuickSorter;
    lomutoMiddleQuickSorter.Sort(v, size, ignoreP);
    EXPECT_TRUE(SorterTest::ArrayIsSorted(v, size));
  }
}