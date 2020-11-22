#include <iostream>
#include "os_tree.h"
#include "gtest/gtest.h"
#include "os_tree_evaluator.h"

using namespace std;

void demo11();

int main(int argc, char *argv[]) {
  demo11();
  ::testing::InitGoogleTest(&argc, argv);
  OSTreeEvaluator::Evaluate();
  return RUN_ALL_TESTS();
}

void demo11() {
  Profiler p("ignore");
  Operation op_comp_select = p.createOperation("ignorecomp", 0);
  Operation op_assign_select = p.createOperation("ignoreassign", 0);
  Operation op_comp_delete = p.createOperation("ignorecompdelete", 0);
  Operation op_assign_delete = p.createOperation("ignoreassigndelete", 0);
  Operation op_pointer_comp_delete = p.createOperation("ignorecompdeletepointer", 0);
  Operation op_pointer_assign_delete = p.createOperation("ignoreassigndeletepointer", 0);
  OSTree os_tree(11);
  cout << "------Original Tree" << endl;
  os_tree.PrettyPrint();
  cout << "------ Selected the 2nd element: " << os_tree.Select(2, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 2 (leaf)" << endl;
  os_tree.Delete(2, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
      &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 1st element: " << os_tree.Select(1, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 1 (one single child)" << endl;
  os_tree.Delete(1, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 7th element: " << os_tree.Select(7, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 9 (two children)" << endl;
  os_tree.Delete(9, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 4th element: " << os_tree.Select(4, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 6 (root)" << endl;
  os_tree.Delete(6, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
}