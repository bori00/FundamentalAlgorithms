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
   Node(Operation* op_assign, Operation* op_pointer_assign);

  Node(T data, Operation* op_assign, Operation* op_pointer_assign);

  Node(T data, Node* next, Operation* op_assign, Operation* op_pointer_assign);

  void setNext(Node* node);

  T getData();

  Node<T>* getNext();

  bool hasNext();

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
