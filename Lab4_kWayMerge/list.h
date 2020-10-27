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
    this->first = new Node<T>(v[0]);
    this->last = new Node<T>(v[no_elements-1]);
  }

  void PushBack(T data) {
    auto* new_node = new Node<T>(data);
    if (last != nullptr) {
      last->setNext(new_node);
    } else {
      first = last = new_node;
    }
  }

  void PushBack(Node<T> node) {
    if (last != nullptr) {
      last->setNext(node);
    } else {
      first = last = node;
    }
  }

  Node<T>* PopFront() {
    Node<T>* result = this->first;
    if (this->first != nullptr) {
      if (this->last == this->first) {
        this->last = nullptr;
      }
      this->first = this->first->getNext();
    }
    return result;
  }

  Node<T>* GetFront() {
    return first;
  }


 private:
  Node<T>* first;
  Node<T>* last;
};

#endif //LAB4_KWAYMERGE__LIST_H_
