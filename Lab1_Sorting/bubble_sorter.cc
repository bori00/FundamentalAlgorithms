//
// Created by Bori on 10/4/2020.
//

#include "bubble_sorter.h"
#include "sorter_evaluator.h"

const char *BubbleSorter::kAssignOpName = "BubbleSort-Assign";
const char *BubbleSorter::kCompOpName = "BubbleSort-Comp";
const char *BubbleSorter::kSorterName = "BubbleSort";

void BubbleSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  bool exchange_made = true;
  for (int i = no_elements - 1; i >= 1 && exchange_made; i--) {
    exchange_made = false;
    for (int j = 0; j < i; j++) {
      op_comp.count();
      if (v[j] > v[j + 1]) {
        // swap
        int helper = v[j];
        v[j] = v[j + 1];
        v[j + 1] = helper;
        op_assign.count(3);
        exchange_made = true;
      }
    }
  }
}

const char *BubbleSorter::GetCompOpName() {
  return kCompOpName;
}

const char *BubbleSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *BubbleSorter::GetSorterName() {
  return kSorterName;
}

