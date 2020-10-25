//
// Created by Bori on 10/18/2020.
//

#include "akl_quick_sorter.h"
#include "insertion_sorter.h"
#include <stdlib.h>
#include <assert.h>
#include "sorter_test.h"

using namespace std;

const char *AklQuickSorter::kAssignOpName = "AklQuickSort-Assign";
const char *AklQuickSorter::kCompOpName = "AklQuickSort-Comp";
const char *AklQuickSorter::kSorterName = "AklQuickSort";

void AklQuickSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  SortHelper(v, no_elements, &op_comp, &op_assign);
}

void AklQuickSorter::SortHelper(int *v, int no_elements, Operation *op_comp, Operation *op_assign) {
  if (no_elements <= 1) {
    return;
  }
  AklSelect(v, no_elements, no_elements / 2, op_comp, op_assign);
  SortHelper(v, no_elements / 2, op_comp, op_assign);
  SortHelper(v + no_elements / 2, no_elements - (no_elements / 2), op_comp, op_assign);
}

const char *AklQuickSorter::GetCompOpName() {
  return kCompOpName;
}

const char *AklQuickSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *AklQuickSorter::GetSorterName() {
  return kSorterName;
}

void AklQuickSorter::AklSelect(int *v,
                               int no_elements,
                               int index,
                               Operation *op_comp,
                               Operation *op_assign) {
  int medians[no_elements / 5 + 1];
  int no_medians = 0;
  InsertionSorter insertion_sorter;
  for (int i = 0; i < no_elements; i += 5) {
    int curr_no_elements = min(no_elements - i, 5);
    insertion_sorter.Sort(v + i, curr_no_elements, op_comp, op_assign);
    medians[no_medians++] = v[i + (curr_no_elements / 2)];
    op_assign->count();
  }
  if (no_medians > 1) {
    AklSelect(medians, no_medians, no_medians / 2, op_comp, op_assign);
    op_assign->count();
    int m = medians[no_medians / 2];
    int m_index = partition(v, no_elements, m, op_comp, op_assign);
    if (index < m_index) {
      AklSelect(v, m_index, index, op_comp, op_assign);
    } else if (index > m_index) {
      AklSelect(v + m_index + 1,
                no_elements - m_index - 1,
                index - m_index - 1,
                op_comp,
                op_assign);
    }
  }
}

int AklQuickSorter::partition(int *v, int no_elements, int pivot, Operation *op_comp, Operation *
op_assign) {
  int i = 0;
  bool pivot_found = false;
  for (int j = 0; j < no_elements - 1; j++) {
    if (!pivot_found) {
      op_comp->count();
      if (v[j] == pivot) {
        Swap(v, j, no_elements - 1, op_assign);
        pivot_found = true;
      }
    }
    op_comp->count();
    if (v[j] <= pivot) {
      Swap(v, i, j, op_assign);
      i++;
    }
  }
  Swap(v, i, no_elements - 1, op_assign);
  return i;
}
