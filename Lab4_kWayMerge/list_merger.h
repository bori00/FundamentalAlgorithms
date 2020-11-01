//
// Created by Bori on 10/27/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_MERGER_H_
#define LAB4_KWAYMERGE__LIST_MERGER_H_

#include <iostream>
#include "list.h"
#include "heap.h"

using namespace std;

template <class T>
class ListMerger {
  static const int kMaxNoLists = 1000;
  int no_lists = 0;
  List<T>* lists[kMaxNoLists];

 public:
  ListMerger() = default;

  void AddList(List<T> *list) {
    if (no_lists == kMaxNoLists) {
      cerr << "Maximum number of lists exceeded" << endl;
      exit(1);
    }
    lists[no_lists] = list;
    no_lists++;
  }

  /**
   * This function merges the lists previously added to the ListMerger into one single list.
   * Remark that the original lists are destroyed by that.
   */
  List<T>* merge(Operation* op_comp, Operation* op_assign, Operation* op_pointer_assign) {
    Heap<Node<T>> min_heap(Heap<Node<T>>::HeapType::kMinHeap, op_comp, op_pointer_assign);
    for (int i = 0; i < no_lists; i++) {
      min_heap.Push(lists[i]->PopFrontNode());
    }
    List<T>* result = new List<int>(op_assign, op_pointer_assign);
    while (min_heap.size() > 0) {
      op_pointer_assign->count();
      Node<T>* minim = min_heap.Pop();
      if (minim->hasNext()) {
        min_heap.Push(minim->getNext());
      }
      result->PushBack(minim);
    }
    return result;
  }
};

#endif //LAB4_KWAYMERGE__LIST_MERGER_H_
