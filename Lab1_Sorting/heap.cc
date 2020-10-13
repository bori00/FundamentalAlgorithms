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
  heap_type_ = heap_type;
  size_ = no_elements;
  this->op_assign_ = op_assign;
  this->op_comp_ = op_comp;
  for (int i = 0; i <= no_elements - 1; i++) {
    v_[i] = content[i];
    op_assign->count();
  }
  for (int i = no_elements / 2; i >= 1; i--) {
    heapify(i - 1);
  }
}

Heap::Heap(Heap::HeapType heap_type, Operation *op_comp, Operation *op_assign) {
  size_ = 0;
  heap_type_ = heap_type;
  this->op_assign_ = op_assign;
  this->op_comp_ = op_comp;
}


void Heap::push(int value) {
  size_++;
  v_[size_ - 1] = value;
  int value_index = size_ - 1;
  if (heap_type_ == HeapType::kMaxHeap) {
    while (value_index > 0 && v_[value_index] > v_[ParentIndex(value_index)]) {
      swap(value_index, ParentIndex(value_index));
      value_index = ParentIndex(value_index);
    }
  } else {
    while (value_index > 0 && v_[value_index] < v_[ParentIndex(value_index)]) {
      swap(value_index, ParentIndex(value_index));
      value_index = ParentIndex(value_index);
    }
  }
}

void Heap::heapify(int rootIndex) {
  int supposed_root_index = findSupposedRootIndex(rootIndex);
  while (rootIndex != supposed_root_index) {
    swap(rootIndex, supposed_root_index);
    rootIndex = supposed_root_index;
    supposed_root_index = findSupposedRootIndex(rootIndex);
  }
}

//todo: improve naming
int Heap::findSupposedRootIndex(int current_root_index) {
  int min_index, max_index;
  switch (heap_type_) {
    case HeapType::kMinHeap:min_index = current_root_index;
      if (current_root_index * 2 <= size_) {
        op_comp_->count();
        if (v_[min_index] > v_[current_root_index * 2]) {
          min_index = current_root_index * 2;
        }
      }
      if (current_root_index * 2 + 1 <= size_) {
        op_comp_->count();
        if (v_[min_index] > v_[current_root_index * 2 + 1]) {
          min_index = current_root_index * 2 + 1;
        }
      }
      return min_index;
    case HeapType::kMaxHeap:max_index = current_root_index;
      if (current_root_index * 2 <= size_) {
        op_comp_->count();
        if (v_[max_index] < v_[current_root_index * 2]) {
          max_index = current_root_index * 2;
        }
      }
      if (current_root_index * 2 + 1 <= size_) {
        op_comp_->count();
        if (v_[max_index] < v_[current_root_index * 2 + 1]) {
          max_index = current_root_index * 2 + 1;
        }
      }
      return max_index;
  }
  return current_root_index;
}

int Heap::pop() {
  int top_value = v_[0];
  v_[0] = v_[size_ - 1];
  heapify(0);
  size_--;
  return top_value;
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

int Heap::ParentIndex(int i) {
  return (i - 1) / 2;
}

int Heap::LeftChildIndex(int i) {
  return 2 * i + 1;
}

int Heap::RightChildIndex(int i) {
  return 2 * i + 2;
}


