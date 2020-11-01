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

  void AddList(List<T> *list);

  /**
   * This function merges the lists previously added to the ListMerger into one single list.
   * Remark that the original lists are destroyed by that.
   */
  List<T>* merge(Operation* op_comp, Operation* op_assign, Operation* op_pointer_assign);
};

#endif //LAB4_KWAYMERGE__LIST_MERGER_H_
