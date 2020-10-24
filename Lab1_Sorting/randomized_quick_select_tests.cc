//
// Created by Bori on 10/24/2020.
//

#include "gtest/gtest.h"
#include "randomized_quick_select_test.h"
#include "randomized_quick_sorter.h"
#include "sorter_test.h"

static Profiler ignorePQuickSelect("ignore");
static Operation op_comp = ignorePQuickSelect.createOperation("op_comp", 0);
static Operation op_assign = ignorePQuickSelect.createOperation("op_assign", 0);

#define MAX_SIZE 10000
#define  NO_RANDOM_TESTS 10

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_AverageArray_FirstElement) {
  int index = 0;
  int *v = GetAverageArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
      &op_comp,
      &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
      RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_AverageArray_MiddleElement) {
  int index = kArrayLength / 2;
  int *v = GetAverageArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_AverageArray_LastElement) {
  int index = kArrayLength - 1;
  int *v = GetAverageArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_SortedArray_FirstElement) {
  int index = 0;
  int *v = GetSortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_SortedArray_MiddleElement) {
  int index = kArrayLength / 2;
  int *v = GetSortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_SortedArray_LastElement) {
  int index = kArrayLength -1;
  int *v = GetSortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_InvSortedArray_FirstElement) {
  int index = 0;
  int *v = GetInverselySortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_InvSortedArray_MiddleElement) {
  int index = kArrayLength / 2;
  int *v = GetInverselySortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_InvSortedArray_LastElement) {
  int index = kArrayLength -1;
  int *v = GetInverselySortedArray();
  RandomizedQuickSorter randomizedQuickSorter;
  int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, kArrayLength, index,
                                                                   &op_comp,
                                                                   &op_assign);
  EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v,
                                                                RandomizedQuickSelectTest::kArrayLength, index, selected_value));
}

TEST_F(RandomizedQuickSelectTest, RandomizedQuickSelect_RandomArray_RandomElement) {
  for (int i = 1; i <= NO_RANDOM_TESTS; i++) {
    int size = rand() % MAX_SIZE;
    int index = rand() % size;
    int v[size];
    FillRandomArray(v, size);
    RandomizedQuickSorter randomizedQuickSorter;
    int selected_value = randomizedQuickSorter.RandomizedQuickSelect(v, size, index,
                                                                     &op_comp,
                                                                     &op_assign);
    EXPECT_TRUE(RandomizedQuickSelectTest::CorrectSelectedElement(v, size, index, selected_value));
  }
}