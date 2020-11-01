//
// Created by Bori on 10/27/2020.
//

#ifndef LAB4_KWAYMERGE__NODE_H_
#define LAB4_KWAYMERGE__NODE_H_

#include "Profiler.h"

template<class T>
class Node {
  T data;
  Node* next;
  Operation* op_assign;
  Operation* op_pointer_assign;

 public:
   Node(Operation* op_assign, Operation* op_pointer_assign){
    this->next = nullptr;
    this->op_assign = op_assign;
    this->op_pointer_assign = op_pointer_assign;
    this->op_pointer_assign->count();
  }

  Node(T data, Operation* op_assign, Operation* op_pointer_assign) {
    this->data = data;
    this->next = nullptr;
    this->op_assign = op_assign;
    this->op_pointer_assign = op_pointer_assign;
    this->op_pointer_assign->count();
    this->op_assign->count();
  }

  Node(T data, Node* next, Operation* op_assign, Operation* op_pointer_assign) {
    this->data = data;
    this->next = next;
    this->op_assign = op_assign;
    this->op_pointer_assign = op_pointer_assign;
    this->op_pointer_assign->count();
    this->op_assign->count();
  }

  void setNext(Node* node) {
    this->next = node;
    op_pointer_assign->count();
  }

  T getData() {
    return this->data;
  }

  Node<T>* getNext() {
    return this->next;
  }

  bool hasNext() {
    return this->next != nullptr;
  }

  friend bool operator >(const Node<T> &node1, const Node<T> &node2) {
    return node1.data > node2.data;
  }

  friend bool operator <(const Node<T> &node1, const Node<T> &node2) {
    return node1.data < node2.data;
  }

  friend bool operator >=(const Node<T> &node1, const Node<T> &node2) {
    return node1.data >= node2.data;
  }

  friend bool operator <=(const Node<T> &node1, const Node<T> &node2) {
    return node1.data <= node2.data;
  }
};

#endif //LAB4_KWAYMERGE__NODE_H_
