//
// Created by Bori on 10/24/2020.
//

#include "lomuto_quick_sorter.h"
#include "sorter_test.h"

const char *LomutoQuickSorter::kAssignOpName = "LomutoQuickSort-Assign";
const char *LomutoQuickSorter::kCompOpName = "LomutoQuickSort-Comp";
const char *LomutoQuickSorter::kSorterName = "LomutoQuickSort";

void LomutoQuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  SortHelper(v, no_elements, &op_comp, &op_assign);
}

const char *LomutoQuickSorter::GetCompOpName() {
  return kCompOpName;
}

const char *LomutoQuickSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *LomutoQuickSorter::GetSorterName() {
  return kSorterName;
}

int LomutoQuickSorter::LomutoPartition(int *v, int no_elements, Operation *op_comp,
                                       Operation *op_assign) {
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

void LomutoQuickSorter::SortHelper(int *v,
                                   int no_elements,
                                   Operation *op_comp,
                                   Operation *op_assign) {
  if (no_elements <= 1) {
    return;
  }
  int q = LomutoPartition(v, no_elements, op_comp, op_assign);
  SortHelper(v, q, op_comp, op_assign);
  SortHelper(v + q + 1, no_elements - q - 1, op_comp, op_assign);
}