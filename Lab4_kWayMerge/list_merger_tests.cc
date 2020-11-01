//
// Created by Bori on 11/1/2020.
//

#include "gtest/gtest.h"
#include "list_merger_test.h"
#include "list_merger.h"

TEST_F(ListMergerTest, 2arrays) {
  ListMerger<int> listMerger;
  int no_lists = 2;
  for (int i = 1; i <= no_lists; i++) {
    listMerger.AddList(GetList(i));
  }
  List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
  EXPECT_TRUE(IsSorted(*result));
}

TEST_F(ListMergerTest, 3arrays) {
  ListMerger<int> listMerger;
  int no_lists = 3;
  for (int i = 1; i <= no_lists; i++) {
    listMerger.AddList(GetList(i));
  }
  List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
  EXPECT_TRUE(IsSorted(*result));
}

TEST_F(ListMergerTest, 4arrays) {
  ListMerger<int> listMerger;
  int no_lists = 4;
  for (int i = 1; i <= no_lists; i++) {
    listMerger.AddList(GetList(i));
  }
  List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
  EXPECT_TRUE(IsSorted(*result));
}

TEST_F(ListMergerTest, 5arrays) {
  ListMerger<int> listMerger;
  int no_lists = 5;
  for (int i = 1; i <= no_lists; i++) {
    listMerger.AddList(GetList(i));
  }
  List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
  EXPECT_TRUE(IsSorted(*result));
}

TEST_F(ListMergerTest, random_arrays) {
  ListMerger<int> listMerger;
  int no_lists = 10;
  for (int i = 1; i <= no_lists; i++) {
    listMerger.AddList(GetRandomList());
  }
  List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
  EXPECT_TRUE(IsSorted(*result));
}