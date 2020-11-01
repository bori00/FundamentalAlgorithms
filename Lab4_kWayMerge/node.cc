//
// Created by Bori on 10/27/2020.
//

#include "node.h"

template<class T>
Node<T>::Node(Operation* op_assign, Operation* op_pointer_assign){
  this->next = nullptr;
  this->op_assign = op_assign;
  this->op_pointer_assign = op_pointer_assign;
  this->op_pointer_assign->count();
}

template<class T>
Node<T>::Node(T data, Operation* op_assign, Operation* op_pointer_assign) {
  this->data = data;
  this->next = nullptr;
  this->op_assign = op_assign;
  this->op_pointer_assign = op_pointer_assign;
  this->op_pointer_assign->count();
  this->op_assign->count();
}

template<class T>
Node<T>::Node(T data, Node* next, Operation* op_assign, Operation* op_pointer_assign) {
  this->data = data;
  this->next = next;
  this->op_assign = op_assign;
  this->op_pointer_assign = op_pointer_assign;
  this->op_pointer_assign->count();
  this->op_assign->count();
}

template<class T>
void Node<T>::setNext(Node* node) {
  this->next = node;
  op_pointer_assign->count();
}

template<class T>
T Node<T>::getData() {
  return this->data;
}

template<class T>
Node<T>* Node<T>::getNext() {
  return this->next;
}

template<class T>
bool Node<T>::hasNext() {
  return this->next != nullptr;
}

template class Node<int>;