//
// Created by Bori on 10/10/2020.
//

#ifndef LAB1_SORTING__HEAP_H_
#define LAB1_SORTING__HEAP_H_

#include <string>

using namespace std;

#include "Profiler.h"
class Heap {
 public:
  enum class HeapType { kMaxHeap, kMinHeap };

  /** This corresponds to the build_heap() method, which builds the heap from the given content. */
  Heap(int *content, int no_elements, HeapType heap_type, Operation *op_comp, Operation *op_assign);

  /** This corresponds to the build_heap() method, and builds an empty heap. */
  Heap(HeapType heap_type, Operation *op_comp, Operation *op_assign);

  /**
   * Inserts @param value into the heap(unless the maximum size is exceeded) by preserving the
   * heap structure.
   */
  void Push(int value);

  /** Removes and returns the top element of the heap by preserving the heap structure. */
  int Pop();

  int *GetContent();

  int size();

  HeapType GetHeapType();

 private:
  void Heapify(int rootIndex);

  /**
   * Returns the index of the element which should be the root of the tree currently
   * rooted at @current_root_index, assuming that the left and right subtrees are heaps.
   */
  int FindSupposedRootIndex(int current_root_index);

  void Swap(int index_1, int index_2);

  static int LeftChildIndex(int i);

  static int RightChildIndex(int i);

  static int ParentIndex(int i);

  bool IsCorrectRelation(int parentIndex, int childIndex);

  static const int kMaxSize = 1e5;
  int size_;
  int v_[kMaxSize];
  HeapType heap_type_;
  Operation *op_comp_;
  Operation *op_assign_;
  const string kSizeExceeded = "Maximum number of elements exceeded. Operation failed!";
};

#endif //LAB1_SORTING__HEAP_H_
