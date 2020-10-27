//
// Created by Bori on 10/10/2020.
//

#include <iostream>
#include "heap.h"
#include "node.h"

template<class T>
Heap<T>::Heap(T *content,
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
    Heapify(i - 1);
  }
}

template<class T>
Heap<T>::Heap(Heap::HeapType heap_type, Operation *op_comp, Operation *op_assign) {
  size_ = 0;
  heap_type_ = heap_type;
  this->op_assign_ = op_assign;
  this->op_comp_ = op_comp;
}

template<class T>
void Heap<T>::Push(T value) {
  size_++;
  v_[size_ - 1] = value;
  op_assign_->count();
  int value_index = size_ - 1;
  while (value_index > 0 && !IsCorrectRelation(ParentIndex(value_index), value_index)) {
    Swap(value_index, ParentIndex(value_index));
    value_index = ParentIndex(value_index);
  }
}

template<class T>
void Heap<T>::Heapify(int rootIndex) {
  int supposed_root_index = FindSupposedRootIndex(rootIndex);
  while (rootIndex != supposed_root_index) {
    Swap(rootIndex, supposed_root_index);
    rootIndex = supposed_root_index;
    supposed_root_index = FindSupposedRootIndex(rootIndex);
  }
}

template<class T>
int Heap<T>::FindSupposedRootIndex(int current_root_index) {
  int supposed_root_index = current_root_index;
  if (LeftChildIndex(current_root_index) < size_ && !IsCorrectRelation(supposed_root_index,
                                                                       LeftChildIndex(
                                                                           current_root_index))) {
    supposed_root_index = LeftChildIndex(current_root_index);
  }
  if (RightChildIndex(current_root_index) < size_ && !IsCorrectRelation(supposed_root_index,
                                                                        RightChildIndex(
                                                                            current_root_index))) {
    supposed_root_index = RightChildIndex(current_root_index);
  }
  return supposed_root_index;
}

template<class T>
T Heap<T>::Pop() {
  op_assign_->count(2);
  T top_value = v_[0];
  v_[0] = v_[size_ - 1];
  size_--;
  Heapify(0);
  return top_value;
}

template<class T>
void Heap<T>::Swap(int index_1, int index_2) {
  T helper = v_[index_1];
  v_[index_1] = v_[index_2];
  v_[index_2] = helper;
  op_assign_->count(3);
}

template<class T>
T *Heap<T>::GetContent() {
  T *v_copy = (T *) malloc(sizeof(T) * size_);
  for (int i = 0; i < size_; i++) {
    v_copy[i] = v_[i];
  }
  return v_copy;
}

template<class T>
int Heap<T>::size() {
  return size_;
}

template<class T>
typename Heap<T>::HeapType Heap<T>::GetHeapType() {
  return heap_type_;
}

template<class T>
int Heap<T>::ParentIndex(int i) {
  return (i - 1) / 2;
}

template<class T>
int Heap<T>::LeftChildIndex(int i) {
  return 2 * i + 1;
}

template<class T>
int Heap<T>::RightChildIndex(int i) {
  return 2 * i + 2;
}

template<class T>
bool Heap<T>::IsCorrectRelation(int parentIndex, int childIndex) {
  op_comp_->count();
  if (heap_type_ == HeapType::kMaxHeap) {
    return v_[parentIndex] >= v_[childIndex];
  } else {
    return v_[parentIndex] <= v_[childIndex];
  }
}

template class Heap<Node<int>>;


