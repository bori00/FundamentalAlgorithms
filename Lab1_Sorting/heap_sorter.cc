//
// Created by Bori on 10/10/2020.
//

#include "heap_sorter.h"
#include "heap.h"

const char *HeapSorter::kAssignOpName = "HeapSort-Assign";
const char *HeapSorter::kCompOpName = "HeapSort-Comp";
const char *HeapSorter::kSorterName = "HeapSort";

void HeapSorter::Sort(int *v, int no_elements, Profiler &p) {
  Operation op_comp = p.createOperation(kCompOpName, no_elements);
  Operation op_assign = p.createOperation(kAssignOpName, no_elements);
  Heap h(v, no_elements, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  for (int i = 0; i < no_elements; i++) {
    v[no_elements - i - 1] = h.Pop();
  }
}

const char *HeapSorter::GetCompOpName() {
  return kCompOpName;
}

const char *HeapSorter::GetAssignOpName() {
  return kAssignOpName;
}

const char *HeapSorter::GetSorterName() {
  return kSorterName;
}