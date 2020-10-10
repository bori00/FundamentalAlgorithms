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
  size_ = no_elements;
  this->op_assign_ = op_assign;
  this->op_comp_ = op_comp;
  for (int i = 1; i <= no_elements; i++) {
    v_[i] = content[i - 1];
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
  switch (heap_type_) {
    case HeapType::kMinHeap:min_index = current_root_index;
      if (min_index * 2 <= size_) {
        op_comp_->count();
        if (v_[min_index] > v_[min_index * 2]) {
          min_index = min_index * 2;
        }
      }
      if (min_index * 2 + 1 <= size_) {
        op_comp_->count();
        if (v_[min_index] > v_[min_index * 2 + 1]) {
          min_index = min_index * 2 + 1;
        }
      }
      return min_index;
    case HeapType::kMaxHeap:max_index = current_root_index;
      if (max_index * 2 <= size_) {
        op_comp_->count();
        if (v_[max_index] < v_[max_index * 2]) {
          max_index = max_index * 2;
        }
      }
      if (max_index * 2 + 1 <= size_) {
        op_comp_->count();
        if (v_[max_index] < v_[max_index * 2 + 1]) {
          max_index = max_index * 2 + 1;
        }
      }
      return max_index;
  }
  return current_root_index;
}

int Heap::pop() {
  return 0;
}

void Heap::swap(int index_1, int index_2) {
  int helper = v_[index_1];
  v_[index_1] = v_[index_2];
  v_[index_2] = helper;
  op_assign_->count(3);
}

int *Heap::getContent() {
  return v_;
}

int Heap::size() {
  return size_;
}

Heap::HeapType Heap::getHeapType() {
  return heap_type_;
}


