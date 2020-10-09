//
// Created by Bori on 10/4/2020.
//

#include "InsertionSorter.h"
#include "Profiler.h"
#include "SorterEvaluator.h"

const char *InsertionSorter::kAssignOpName = "InsertionSort-Assign";
const char *InsertionSorter::kCompOpName = "InsertionSort-Comp";
const char *InsertionSorter::kSorterName = "InsertionSort";

void InsertionSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  for (int i = 1; i < no_elements; i++) {
    int insertion_index = i;
    int to_insert_value = v[i];
    op_assign.count();
    while (insertion_index >= 1 && to_insert_value < v[insertion_index - 1]) {
      op_comp.count();
      v[insertion_index] = v[insertion_index - 1];
      op_assign.count();
      insertion_index--;
    }
    if (insertion_index >= 1) {
      op_comp.count();
    }
    v[insertion_index] = to_insert_value;
    op_assign.count();
  }
}

const char *InsertionSorter::GetCompOpName() {
  return kCompOpName;
}

const char *InsertionSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *InsertionSorter::GetSorterName() {
  return kSorterName;
}

