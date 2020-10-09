//
// Created by Bori on 10/4/2020.
//

#include "gtest/gtest.h"
#include "selection_sorter.h"
#include "sorter_test.h"

int SorterTest::average_array_[] = {3, -7, 2, 10, -5, 9, 4, 12, 10, 10};
int SorterTest::sorted_array_[] = {-10, 0, 3, 7, 10, 23, 101, 103, 1000, 1500};
int SorterTest::inv_sorted_array_[] = {1002, 987, 540, 10, -24, -105, -900, -901, -901, -1000};

int *SorterTest::GetArrayWithContent(const int content[]) {
  int *result = (int *) malloc(sizeof(int) * kArrayLength);
  for (int i = 0; i < kArrayLength; i++) {
    result[i] = content[i];
  }
  return result;
}

bool SorterTest::ArrayIsSorted(const int *v, int no_elements) {
  for (int i = 0; i < no_elements - 1; i++) {
    if (v[i] > v[i + 1]) {
      return false;
    }
  }
  return true;
}
