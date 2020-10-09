//
// Created by Bori on 10/4/2020.
//

#include "insertion_sorter.h"
#include "Profiler.h"
#include "sorter_evaluator.h"
// todo remove
#include <iostream>

const char *InsertionSorter::kAssignOpName = "InsertionSort-Assign";
const char *InsertionSorter::kCompOpName = "InsertionSort-Comp";
const char *InsertionSorter::kSorterName = "InsertionSort";

void InsertionSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  for (int i = 1; i < no_elements; i++) {
    int to_insert_value = v[i];
    op_assign.count();
    int insertion_index = getInsertionIndex(v, v[i], i, op_comp);
    shiftElementsToRight(v, insertion_index, i - 1, op_assign);
    if (i != insertion_index) {
      v[insertion_index] = to_insert_value;
      op_assign.count();
    }
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

int InsertionSorter::getInsertionIndex(int *v, int value, int no_elements, Operation &op_comp) {
  int min = 0;
  int max = no_elements - 1;
  int middle;
  while (min < max) {
    middle = (min + max) / 2;
    op_comp.count();
    if (v[middle] == value) {
      return middle + 1;
    } else {
      op_comp.count();
      if (v[middle] > value) {
        max = middle - 1;
      } else {
        min = middle + 1;
      }
    }
  }
  op_comp.count();
  if (v[min] > value) {
    return min;
  } else {
    return min + 1;
  }
}

void InsertionSorter::shiftElementsToRight(int *v, int lowIndex, int highIndex, Operation &op_assign) {
  for (int i = highIndex + 1; i >= lowIndex + 1; i--) {
    v[i] = v[i - 1];
  }
  op_assign.count(highIndex - lowIndex + 1);
}

