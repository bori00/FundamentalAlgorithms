//
// Created by Bori on 10/10/2020.
//

#ifndef LAB1_SORTING__HEAP_TEST_H_
#define LAB1_SORTING__HEAP_TEST_H_

#include "gtest/gtest.h"
#include "Profiler.h"
#include "heap.h"

static Profiler p("sorting_test");

class HeapTest : public ::testing::Test {
 public:
  static bool isHeap(Heap h);

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

#endif //LAB1_SORTING__HEAP_TEST_H_
