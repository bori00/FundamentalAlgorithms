//
// Created by Bori on 11/22/2020.
//

#include "gtest/gtest.h"
#include "os_tree.h"

TEST(OSTree, select_1) {
  OSTree os_tree(10);
  EXPECT_EQ(4, os_tree.Select(4));
}

TEST(OSTree, select_2) {
  OSTree os_tree(19);
  EXPECT_EQ(7, os_tree.Select(7));
}


TEST(OSTree, select_3) {
  OSTree os_tree(1001);
  EXPECT_EQ(523, os_tree.Select(523));
}

TEST(OSTree, select_4) {
  OSTree os_tree(1000);
  EXPECT_EQ(500, os_tree.Select(500));
}

TEST(OSTree, select_after_delete_1) {
  OSTree os_tree(10);
  os_tree.Delete(2);
  os_tree.Delete(8);
  os_tree.Delete(3);
  EXPECT_EQ(6, os_tree.Select(4));
}

TEST(OSTree, select_after_delete_2) {
  OSTree os_tree(25);
  os_tree.Delete(1);
  os_tree.Delete(10);
  os_tree.Delete(22);
  os_tree.Delete(7);
  os_tree.Delete(23);
  os_tree.Delete(18);
  EXPECT_EQ(25, os_tree.Select(19));
}

TEST(OSTree, select_after_delete_3) {
  OSTree os_tree(25);
  os_tree.Delete(1);
  os_tree.Delete(10);
  os_tree.Delete(22);
  os_tree.Delete(7);
  os_tree.Delete(23);
  os_tree.Delete(18);
  EXPECT_EQ(13, os_tree.Select(10));
}

