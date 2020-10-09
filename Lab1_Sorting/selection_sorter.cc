//
// Created by Bori on 10/4/2020.
//

#include "selection_sorter.h"
#include "sorter_evaluator.h"

const char *SelectionSorter::kAssignOpName = "SelectionSort-Assign";
const char *SelectionSorter::kCompOpName = "SelectionSort-Comp";
const char *SelectionSorter::kSorterName = "SelectionSort";

void SelectionSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  for (int i = 0; i < no_elements - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < no_elements; j++) {
      op_comp.count();
      if (v[min_index] > v[j]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      op_assign.count(3);
      // swap
      const int helper = v[i];
      v[i] = v[min_index];
      v[min_index] = helper;
    }
  }
}

const char *SelectionSorter::GetCompOpName() {
  return kCompOpName;
}

const char *SelectionSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *SelectionSorter::GetSorterName() {
  return kSorterName;
}
