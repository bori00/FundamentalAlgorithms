//
// Created by Bori on 11/22/2020.
//

#include <iostream>
#include "os_tree_evaluator.h"
#include "os_tree.h"

using namespace std;

void OSTreeEvaluator::Evaluate() {
  Profiler p("OSTree evaluation");
  for (int size = kMinSize; size < kMaxSize; size += kStepSize) {
    cout << "Evaluate size " << size << endl;
    Operation op_comp_select = p.createOperation("Selection Comparisons (on size)", size);
    Operation op_assign_select = p.createOperation("Selection Assignments (on size)", size);
    Operation op_comp_delete = p.createOperation("Deletion Comparisons", size);
    Operation op_assign_delete = p.createOperation("Deletion Assignments", size);
    Operation op_comp_delete_pointer = p.createOperation("Deletion Comparisons-(on pointers)",
        size);
    Operation op_assign_delete_pointer = p.createOperation("Deletion Assignments-(on pointers)",
        size);
    for (int testNr = 0; testNr < kNoTests; testNr++) {
      OSTree os_tree(size);
      for (int rem_size = size; rem_size > 0; rem_size--) {
        int selection_index = rand() % rem_size + 1;
        int value = os_tree.Select(selection_index, &op_comp_select, &op_assign_select);
        os_tree.Delete(value, &op_comp_delete, &op_assign_delete, &op_comp_delete_pointer,
            &op_assign_delete_pointer);
      }
    }
  }
  p.divideValues("Selection Comparisons (on size)", kNoTests);
  p.divideValues("Selection Assignments (on size)", kNoTests);
  p.divideValues("Deletion Comparisons", kNoTests);
  p.divideValues("Deletion Assignments", kNoTests);
  p.divideValues("Deletion Comparisons (on pointers)", kNoTests);
  p.divideValues("Deletion Assignments (on pointers)", kNoTests);
  p.showReport();
}
