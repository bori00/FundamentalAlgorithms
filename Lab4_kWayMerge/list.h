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
  List(Operation* op_assign, Operation* op_pointer_assign) {
    this->first = nullptr;
    this->last = nullptr;
    this->op_pointer_assign = op_pointer_assign;
    this->op_assign = op_assign;
  }

  List(T v[], int no_elements, Operation* op_assign, Operation* op_pointer_assign) {
    this->op_pointer_assign = op_pointer_assign;
    this->op_assign = op_assign;
    this->first = nullptr;
    this->last = nullptr;
    for (int i = 0; i < no_elements; i++) {
      this->PushBack(v[i]);
    }
  }

  List(const List<T>& l2, Operation* op_assign, Operation* op_pointer_assign) {
    this->op_pointer_assign = op_pointer_assign;
    this->op_assign = op_assign;
    this->first = nullptr;
    this->last = nullptr;
    Node<T>* nodeToCopy = l2.first;
    while (nodeToCopy != nullptr) {
      this->PushBack(nodeToCopy->getData());
      nodeToCopy = nodeToCopy->getNext();
    }
  }

  void PushBack(T data) {
    auto* new_node = new Node<T>(data, op_assign, op_pointer_assign);
    if (last != nullptr) {
      last->setNext(new_node);
      last = new_node;
      op_pointer_assign->count();
    } else {
      first = last = new_node;
      op_pointer_assign->count(2);
    }
  }

  void PushBack(Node<T>* node) {
    if (last != nullptr) {
      last->setNext(node);
      last = node;
      op_pointer_assign->count(2);
    } else {
      first = last = node;
      op_pointer_assign->count(2);
    }
    last->setNext(nullptr);
    op_pointer_assign->count();
  }

  Node<T>* PopFrontNode() {
    Node<T>* result = this->first;
    op_pointer_assign->count();
    if (this->first != nullptr) {
      if (this->last == this->first) {
        this->last = nullptr;
        op_pointer_assign->count();
      }
      this->first = this->first->getNext();
      op_pointer_assign->count();
    }
    return result;
  }

  T PopFrontValue() {
   return PopFrontNode()->getData();
  }

  bool IsEmpty() {
    return first == nullptr;
  }

 private:
  Node<T>* first;
  Node<T>* last;
  Operation* op_pointer_assign;
  Operation* op_assign;
};

#endif //LAB4_KWAYMERGE__LIST_H_
