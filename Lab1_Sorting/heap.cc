//
// Created by Bori on 10/10/2020.
//

#include <iostream>
#include "heap.h"

Heap::Heap(int *content,
           int no_elements,
           Heap::HeapType heap_type,
           Operation *op_comp,
           Operation *op_assign) {
  if (no_elements > kMaxSize) {
    cerr << kSizeExceeded << endl;
    exit(1);
  }
  this->op_assign = op_assign;
  this->op_comp = op_comp;
  for (int i = 1; i <= no_elements; i++) {
    v[i] = content[i - 1];
    op_assign->count();
  }
  for (int i = no_elements / 2; i >= 1; i--) {
    heapify(i);
  }
}

void Heap::push(int value) {

}

void Heap::heapify(int rootIndex) {
  int supposed_root_index = findSupposedRootIndex(rootIndex);
  while (rootIndex != supposed_root_index) {
    swap(rootIndex, supposed_root_index);
    rootIndex = supposed_root_index;
    supposed_root_index = findSupposedRootIndex(rootIndex);
  }
}

int Heap::findSupposedRootIndex(int current_root_index) {
  int min_index, max_index;
  switch (heap_type) {
    case HeapType::kMinHeap:min_index = current_root_index;
      if (min_index * 2 <= size) {
        op_comp->count();
        if (v[min_index] > v[min_index * 2]) {
          min_index = min_index * 2;
        }
      }
      if (min_index * 2 + 1 <= size) {
        op_comp->count();
        if (v[min_index] > v[min_index * 2 + 1]) {
          min_index = min_index * 2 + 1;
        }
      }
      return min_index;
    case HeapType::kMaxHeap:max_index = current_root_index;
      if (max_index * 2 <= size) {
        op_comp->count();
        if (v[max_index] < v[max_index * 2]) {
          max_index = max_index * 2;
        }
      }
      if (max_index * 2 + 1 <= size) {
        op_comp->count();
        if (v[max_index] < v[max_index * 2 + 1]) {
          max_index = max_index * 2 + 1;
        }
      }
      return max_index;
  }
}

int Heap::pop() {
  return 0;
}

void Heap::swap(int index_1, int index_2) {
  int helper = v[index_1];
  v[index_1] = v[index_2];
  v[index_2] = helper;
  op_assign->count(3);
}


