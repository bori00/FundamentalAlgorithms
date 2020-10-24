//
// Created by Bori on 10/24/2020.
//

#include "lomuto_middle_quick_sorter.h"
#include "sorter_test.h"

const char *LomutoMiddleQuickSorter::kAssignOpName = "LomutoMiddleQuickSort-Assign";
const char *LomutoMiddleQuickSorter::kCompOpName = "LomutoMiddleQuickSort-Comp";
const char *LomutoMiddleQuickSorter::kSorterName = "LomutoMiddleQuickSort";

void LomutoMiddleQuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  SortHelper(v, no_elements, &op_comp, &op_assign);
}

const char *LomutoMiddleQuickSorter::GetCompOpName() {
  return kCompOpName;
}

const char *LomutoMiddleQuickSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *LomutoMiddleQuickSorter::GetSorterName() {
  return kSorterName;
}

int LomutoMiddleQuickSorter::LomutoMiddlePartition(int *v, int no_elements, Operation *op_comp,
                                                   Operation *op_assign) {
  int pivot_index = no_elements / 2;
  swap(v, pivot_index, no_elements - 1, op_assign);
  int i = 0;
  for (int j = 0; j < no_elements - 1; j++) {
    op_comp->count();
    if (v[j] <= v[no_elements - 1]) {
      swap(v, i, j, op_assign);
      i++;
    }
  }
  swap(v, i, no_elements - 1, op_assign);
  return i;
}

void LomutoMiddleQuickSorter::SortHelper(int *v,
                                         int no_elements,
                                         Operation *op_comp,
                                         Operation *op_assign) {
  if (no_elements <= 1) {
    return;
  }
  int q = LomutoMiddlePartition(v, no_elements, op_comp, op_assign);
  SortHelper(v, q, op_comp, op_assign);
  SortHelper(v + q + 1, no_elements - q - 1, op_comp, op_assign);
}