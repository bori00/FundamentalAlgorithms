//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_SORTERTEST_H
#define LAB1_SORTING_SORTERTEST_H

#include "gtest/gtest.h"
#include "Profiler.h"

static Profiler p("sorting_test");

class SorterTest : public ::testing::Test {
 public:
  static bool ArrayIsSorted(const int *v, int no_elements);

 protected:
  static int *GetAverageArray() {
    return GetArrayWithContent(average_array_);
  }

  static int *GetSortedArray() {
    return GetArrayWithContent(sorted_array_);
  }

  static int *GetInverselySortedArray() {
    return GetArrayWithContent(inv_sorted_array_);
  }

  static const int kArrayLength = 10;

 private:
  static int average_array_[kArrayLength];
  static int sorted_array_[kArrayLength];
  static int inv_sorted_array_[kArrayLength];

  static int *GetArrayWithContent(const int content[kArrayLength]);
};

#endif //LAB1_SORTING_SORTERTEST_H
