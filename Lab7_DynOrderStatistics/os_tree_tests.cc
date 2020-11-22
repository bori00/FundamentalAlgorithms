//
// Created by Bori on 11/22/2020.
//

#include "gtest/gtest.h"
#include "os_tree.h"

Profiler p("ignore");
Operation op_comp_select = p.createOperation("ignorecomp", 0);
Operation op_assign_select = p.createOperation("ignoreassign", 0);
Operation op_comp_delete = p.createOperation("ignorecompdelete", 0);
Operation op_assign_delete = p.createOperation("ignoreassigndelete", 0);
Operation op_pointer_comp_delete = p.createOperation("ignorecompdeletepointer", 0);
Operation op_pointer_assign_delete = p.createOperation("ignoreassigndeletepointer", 0);

TEST(OSTree, select_1) {
  OSTree os_tree(10);
  EXPECT_EQ(4, os_tree.Select(4, &op_comp_select, &op_assign_select));
}

TEST(OSTree, select_2) {
  OSTree os_tree(19);
  EXPECT_EQ(7, os_tree.Select(7, &op_comp_select, &op_assign_select));
}


TEST(OSTree, select_3) {
  OSTree os_tree(1001);
  EXPECT_EQ(523, os_tree.Select(523, &op_comp_select, &op_assign_select));
}

TEST(OSTree, select_4) {
  OSTree os_tree(1000);
  EXPECT_EQ(500, os_tree.Select(500, &op_comp_select, &op_assign_select));
}

TEST(OSTree, select_after_delete_1) {
  OSTree os_tree(10);
  os_tree.Delete(2, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(8, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(3, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  EXPECT_EQ(6, os_tree.Select(4, &op_comp_select, &op_assign_select));
}

TEST(OSTree, select_after_delete_2) {
  OSTree os_tree(25);
  os_tree.Delete(1, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(10, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(22, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(7, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(23, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(18, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  EXPECT_EQ(25, os_tree.Select(19, &op_comp_select, &op_assign_select));
}

TEST(OSTree, select_after_delete_3) {
  OSTree os_tree(25);
  os_tree.Delete(1, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(10, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(22, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(7, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(23, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.Delete(18, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  EXPECT_EQ(13, os_tree.Select(10, &op_comp_select, &op_assign_select));
}

