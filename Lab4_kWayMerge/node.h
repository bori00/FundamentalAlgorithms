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
  explicit Node();

  explicit Node(T data);

  explicit Node(T data, Node* next);

  void setNext(Node* node);

  T getData();

  Node<T>* getNext();

  bool hasNext();
};

#endif //LAB4_KWAYMERGE__NODE_H_
