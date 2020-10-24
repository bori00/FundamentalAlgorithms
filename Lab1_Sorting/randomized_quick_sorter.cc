//
// Created by Bori on 10/20/2020.
//

#include <assert.h>
#include "randomized_quick_sorter.h"
#include "sorter_test.h"

const char *RandomizedQuickSorter::kAssignOpName = "RandomizedQuickSort-Assign";
const char *RandomizedQuickSorter::kCompOpName = "RandomizedQuickSort-Comp";
const char *RandomizedQuickSorter::kSorterName = "RandomizedQuickSort";

// todo pass operations instead, to count them recursively --> modify sorter interface too
void RandomizedQuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  SortHelper(v, no_elements, &op_comp, &op_assign);
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

bool contains(int *v, int value, int no_elements) {
  for (int i = 0; i < no_elements; i++) {
    if (v[i] == value) {
      return true;
    }
  }
  return false;
}

void RandomizedQuickSorter::RandomizedQuickSelect(int *v,
                               int no_elements,
                               int index,
                               Operation *op_comp,
                               Operation *op_assign) {
 if (no_elements > 0) {
   int q = RandomizedPartition(v, no_elements, op_comp, op_assign);
   if (index < q) {
     RandomizedQuickSelect(v, q, index, op_comp, op_assign);
   } else if (q < index) {
     RandomizedQuickSelect(v + q + 1, no_elements - q - 1, index - q - 1, op_comp, op_assign);
   }
   for (int i = 0; i < index; i++) {
     assert(v[i] <= v[index]);
   }
   for (int i = index + 1; i < no_elements; i++) {
     assert(v[i] >= v[index]);
   }
 }
}

int RandomizedQuickSorter::RandomizedPartition(int *v, int no_elements, Operation* op_comp,
    Operation* op_assign) {
  int pivot_index = rand() % no_elements;
  int pivot = v[pivot_index];
  swap(v, pivot_index, no_elements-1, op_assign);
  int i = 0;
  for (int j = 0; j < no_elements - 1; j++) {
    if (v[j] <= pivot) {
      swap(v, i, j, op_assign);
      i++;
    }
  }
  swap(v, i, no_elements - 1, op_assign);
  return i;
}

void RandomizedQuickSorter::SortHelper(int *v,
                                       int no_elements,
                                       Operation *op_comp,
                                       Operation *op_assign) {
  if (no_elements <= 1) {
    return;
  }
  RandomizedQuickSelect(v, no_elements, no_elements / 2, op_comp, op_assign);
  SortHelper(v, no_elements / 2, op_comp, op_assign);
  SortHelper(v + no_elements / 2, no_elements - (no_elements / 2), op_comp, op_assign);
  if (!SorterTest::ArrayIsSorted(v, no_elements)) {
    v[0] = 1;
    //exit(111);
  }
}