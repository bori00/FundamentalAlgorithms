//
// Created by Bori on 10/10/2020.
//

#include "heap.h"

Heap::Heap(int *content,
           int no_elements,
           Heap::HeapType heap_type,
           Operation &op_comp,
           Operation &op_assign) {

}

void Heap::push(int value) {

}

void Heap::heapify(int rootIndex) {

}

int Heap::findSupposedRootIndex(int current_root_index) {
  int min_index, max_index;
  switch (heap_type) {
    case HeapType::kMinHeap:min_index = current_root_index;
      if (min_index * 2 <= size && v[min_index] > v[min_index * 2]) {
        min_index = min_index * 2;
      }
      if (min_index * 2 + 1 <= size && v[min_index] > v[min_index * 2 + 1]) {
        min_index = min_index * 2 + 1;
      }
      return min_index;
    case HeapType::kMaxHeap:max_index = current_root_index;
      if (max_index * 2 <= size && v[max_index] < v[max_index * 2]) {
        max_index = max_index * 2;
      }
      if (max_index * 2 + 1 <= size && v[max_index] < v[max_index * 2 + 1]) {
        max_index = max_index * 2 + 1;
      }
      return max_index;
  }
}

int Heap::pop() {
  return 0;
}


