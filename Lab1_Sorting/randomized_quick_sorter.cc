//
// Created by Bori on 10/20/2020.
//

#include <assert.h>
#include "randomized_quick_sorter.h"
#include "sorter_test.h"

const char *RandomizedQuickSorter::kAssignOpName = "RandomizedQuickSort-Assign";
const char *RandomizedQuickSorter::kCompOpName = "RandomizedQuickSort-Comp";
const char *RandomizedQuickSorter::kSorterName = "RandomizedQuickSort";

void RandomizedQuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  SortHelper(v, no_elements, &op_comp, &op_assign);
}

void RandomizedQuickSorter::SortHelper(int *v,
                                       int no_elements,
                                       Operation *op_comp,
                                       Operation *op_assign) {
  if (no_elements <= 1) {
    return;
  }
  int q = RandomizedPartition(v, no_elements, op_comp, op_assign);
  SortHelper(v, q, op_comp, op_assign);
  SortHelper(v + q + 1, no_elements - q - 1, op_comp, op_assign);
}

const char *RandomizedQuickSorter::GetCompOpName() {
  return kCompOpName;
}

const char *RandomizedQuickSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *RandomizedQuickSorter::GetSorterName() {
  return kSorterName;
}

int RandomizedQuickSorter::RandomizedPartition(int *v, int no_elements, Operation* op_comp,
    Operation* op_assign) {
  int pivot_index = rand() % no_elements;
  Swap(v, pivot_index, no_elements-1, op_assign);
  int i = 0;
  for (int j = 0; j < no_elements - 1; j++) {
    op_comp->count();
    if (v[j] <= v[no_elements - 1]) {
      Swap(v, i, j, op_assign);
      i++;
    }
  }
  Swap(v, i, no_elements - 1, op_assign);
  return i;
}