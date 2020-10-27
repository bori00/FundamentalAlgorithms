//
// Created by Bori on 10/27/2020.
//

#ifndef LAB4_KWAYMERGE__NODE_H_
#define LAB4_KWAYMERGE__NODE_H_

template<class T>
class Node {
  T data;
  Node* next;

 public:
  explicit Node(){
    this->data = nullptr;
    this->next = nullptr;
  }

  explicit Node(T data) {
    this->data = data;
    this->next = nullptr;
  }

  explicit Node(T data, Node* next) {
    // todo use the other constructor
    this->data = data;
    this->next = next;
  }

  void setNext(Node* node) {
    this->next = next;
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

  friend bool operator ==(const Node<T> &node1, const Node<T> &node2) {
    return node1.data == node2.data;
  }

  friend bool operator !=(const Node<T> &node1, const Node<T> &node2) {
    return node1.data != node2.data;
  }

};

#endif //LAB4_KWAYMERGE__NODE_H_
