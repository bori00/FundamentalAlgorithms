//
// Created by Bori on 10/4/2020.
//

#include "insertion_sorter.h"
#include "Profiler.h"

const char *InsertionSorter::kAssignOpName = "InsertionSort-Assign";
const char *InsertionSorter::kCompOpName = "InsertionSort-Comp";
const char *InsertionSorter::kSorterName = "InsertionSort";

void InsertionSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  Sort(v, no_elements, &op_comp, &op_assign);
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

int InsertionSorter::getInsertionIndex(const int *v, int value, int no_elements,
                                       Operation *op_comp) {
  int min = 0;
  int max = no_elements - 1;
  int middle;
  while (min < max) {
    middle = (min + max) / 2;
    op_comp->count();
    if (v[middle] == value) {
      // ensure stability by inserting after the rightmost element equal to it
      int insertion_index = middle;
      while (insertion_index < no_elements && v[insertion_index] == value) {
        insertion_index++;
        op_comp->count();
      }
      if (insertion_index < no_elements) {
        op_comp->count();
      }
      return insertion_index;
    } else {
      op_comp->count();
      if (v[middle] > value) {
        max = middle - 1;
      } else {
        min = middle + 1;
      }
    }
  }
  op_comp->count();
  if (v[min] > value) {
    return min;
  } else {
    return min + 1;
  }
}

void InsertionSorter::shiftElementsToRight(int *v, int low_index, int high_index,
                                           Operation *op_assign) {
  if (high_index >= low_index) {
    for (int i = high_index + 1; i >= low_index + 1; i--) {
      v[i] = v[i - 1];
    }
    op_assign->count(high_index - low_index + 1);
  }
}

void InsertionSorter::Sort(int *v, int no_elements, Operation *op_comp, Operation *op_assign) {
  int to_insert_value;
  for (int i = 1; i < no_elements; i++) {
    int insertion_index = getInsertionIndex(v, v[i], i, op_comp);
    if (insertion_index != i) {
      to_insert_value = v[i];
      shiftElementsToRight(v, insertion_index, i - 1, op_assign);
      v[insertion_index] = to_insert_value;
      op_assign->count(2);
    }
  }
}

