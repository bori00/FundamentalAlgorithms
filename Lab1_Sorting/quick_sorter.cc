//
// Created by Bori on 10/18/2020.
//

#include "quick_sorter.h"
#include "insertion_sorter.h"
#include <stdlib.h>
#include <assert.h>
// todo remove
#include <iostream>
#include "sorter_test.h"

using namespace std;

const char *QuickSorter::kAssignOpName = "QuickSort-Assign";
const char *QuickSorter::kCompOpName = "QuickSort-Comp";
const char *QuickSorter::kSorterName = "QuickSort";

void QuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  int q = partition(v, no_elements, v[no_elements / 2]);
  // AklSelect(v, no_elements, no_elements / 2, &op_comp, &op_assign);
  if (q > 1) {
    Sort(v, q, p);
    assert(SorterTest::ArrayIsSorted(v, q));
  }
  if (q < no_elements - 1) {
    Sort(v + q + 1, no_elements - q - 1, p);
    assert(SorterTest::ArrayIsSorted(v + q + 1, no_elements - q - 1));
  }
  if (!SorterTest::ArrayIsSorted(v, no_elements)) {
    exit(111);
  }
}

const char *QuickSorter::GetCompOpName() {
  return kCompOpName;
}

const char *QuickSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *QuickSorter::GetSorterName() {
  return kSorterName;
}

int compare(const void *a, const void *b) {
  return (*(int *) a - *(int *) b);
}

bool contains(int *v, int value, int no_elements) {
  for (int i = 0; i < no_elements; i++) {
    if (v[i] == value) {
      return true;
    }
  }
  return false;
}

void QuickSorter::AklSelect(int *v,
                            int no_elements,
                            int index,
                            Operation *op_comp,
                            Operation *op_assign) {
  int medians[no_elements / 5 + 1];
  int no_medians = 0;
  for (int i = 0; i < no_elements; i += 5) {
    int curr_no_elements = min(no_elements - i, 5);
    //todo change to insertion sort, count operations
    qsort(v + i, curr_no_elements, sizeof(int), compare);
    medians[no_medians++] = v[i + (curr_no_elements) / 2];
  }
  if (no_medians > 1) {
    AklSelect(medians, no_medians, no_medians / 2, op_comp, op_assign);
    int m = medians[no_medians / 2];
    assert(contains(v, m, no_elements));
    int m_index = partition(v, no_elements, m);
    if (index < m_index) {
      AklSelect(v, m_index - 1, index, op_comp, op_assign);
    } else if (index > m_index) {
      AklSelect(v + m_index + 1,
                no_elements - m_index - 1,
                index - m_index - 1,
                op_comp,
                op_assign);
    }
  }
  for (int i = 0; i < index; i++) {
    assert(v[i] <= v[index]);
  }
  for (int i = index + 1; i < no_elements; i++) {
    assert(v[i] >= v[index]);
  }
}

void swap(int *v, int i, int j) {
  int helper = v[i];
  v[i] = v[j];
  v[j] = helper;
}

int QuickSorter::partition(int *v, int no_elements, int pivot) {
  assert(contains(v, pivot, no_elements));
  int i = 0;
  bool swapped = false;
  for (int j = 0; j < no_elements - 1; j++) {
    if (v[j] == pivot) {
      swap(v, j, no_elements - 1);
      swapped = true;
    }
    if (v[j] <= pivot) {
      swap(v, i, j);
      assert(v[i] <= pivot);
      i++;
    }
  }
  assert(v[no_elements - 1] == pivot);
//  if (!swapped) {
//    cout << "Swapped = " << swapped << endl;
//  }
  swap(v, i, no_elements - 1);
  for (int k = 0; k < i; k++) {
    if (v[k] > pivot) {
      cout << "Fail at 99" << endl;
    }
    assert(v[k] <= pivot);
  }
  assert (v[i] == pivot);
  for (int k = i + 1; k < no_elements; k++) {
    assert(v[k] >= pivot);
  }
  return i;
}

