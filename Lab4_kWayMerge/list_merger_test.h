//
// Created by Bori on 11/1/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_MERGER_TEST_H_
#define LAB4_KWAYMERGE__LIST_MERGER_TEST_H_

#include "gtest/gtest.h"
#include "list.h"

class ListMergerTest : public ::testing::Test {
 public:
  List<int>* GetList(int index);

  List<int>* GetRandomList();

  static bool IsSorted(List<int> l);

 private:
  int array1[5] = {3, 6, 10, 17, 18};
  int array1_size = 5;
  int array2[10] = {102, 200, 305, 1000, 2500, 2501, 2501, 2501, 3008, 30010};
  int array2_size = 10;
  int array3[1] = {0};
  int array3_size = 1;
  int array4[5] = {3, 6, 10, 17, 18};
  int array4_size = 5;
  int array5[6] = {-100, -50, -10, 0, 10, 20};
  int array5_size = 5;
  int kMaxSize = 10000;
};

#endif //LAB4_KWAYMERGE__LIST_MERGER_TEST_H_
