//
// Created by Bori on 10/24/2020.
//

#ifndef LAB1_SORTING__RANDOMIZED_QUICK_SELECT_TEST_H_
#define LAB1_SORTING__RANDOMIZED_QUICK_SELECT_TEST_H_

#include "gtest/gtest.h"

class RandomizedQuickSelectTest : public ::testing::Test {
 public:
  static bool CorrectSelectedElement(int *v, int no_elements, int index, int selected_value);

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

#endif //LAB1_SORTING__RANDOMIZED_QUICK_SELECT_TEST_H_
