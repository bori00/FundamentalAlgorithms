//
// Created by Bori on 10/27/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_H_
#define LAB4_KWAYMERGE__LIST_H_

#include "node.h"
template<class T>
class List {
 public:
  List() {
    this->first = nullptr;
    this->last = nullptr;
  }

  explicit List(T v[], int no_elements) {
    this->first = nullptr;
    this->last = nullptr;
    for (int i = 0; i < no_elements; i++) {
      this->PushBack(v[i]);
    }
  }

  void PushBack(T data) {
    auto* new_node = new Node<T>(data);
    if (last != nullptr) {
      last->setNext(new_node);
    } else {
      first = last = new_node;
    }
  }

  void PushBack(Node<T>* node) {
    if (last != nullptr) {
      last->setNext(node);
      last = node;
    } else {
      first = last = node;
    }
    last ->setNext(nullptr);
  }

  Node<T>* PopFrontNode() {
    Node<T>* result = this->first;
    if (this->first != nullptr) {
      if (this->last == this->first) {
        this->last = nullptr;
      }
      this->first = this->first->getNext();
    }
    return result;
  }

  T GetFrontValue() {
   return PopFrontNode().getData();
  }

 private:
  Node<T>* first;
  Node<T>* last;
};

#endif //LAB4_KWAYMERGE__LIST_H_
