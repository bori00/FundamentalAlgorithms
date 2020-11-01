//
// Created by Bori on 10/27/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_H_
#define LAB4_KWAYMERGE__LIST_H_

#include "node.h"
#include "Profiler.h"
template<class T>
class List {
 public:
  List(Operation* op_assign, Operation* op_pointer_assign);

  List(T v[], int no_elements, Operation* op_assign, Operation* op_pointer_assign);

  List(const List<T>& l2, Operation* op_assign, Operation* op_pointer_assign);

  ~List();

  void PushBack(T data);

  void PushBack(Node<T>* node);

  Node<T>* PopFrontNode();

  T PopFrontValue();

  bool IsEmpty();

 private:
  Node<T>* first;
  Node<T>* last;
  Operation* op_pointer_assign;
  Operation* op_assign;
};

#endif //LAB4_KWAYMERGE__LIST_H_
