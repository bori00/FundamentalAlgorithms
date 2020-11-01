//
// Created by Bori on 10/27/2020.
//

#include "list.h"

template<class T>
List<T>::List(Operation* op_assign, Operation* op_pointer_assign) {
  this->first = nullptr;
  this->last = nullptr;
  this->op_pointer_assign = op_pointer_assign;
  this->op_assign = op_assign;
}

template<class T>
List<T>::List(T v[], int no_elements, Operation* op_assign, Operation* op_pointer_assign) {
  this->op_pointer_assign = op_pointer_assign;
  this->op_assign = op_assign;
  this->first = nullptr;
  this->last = nullptr;
  for (int i = 0; i < no_elements; i++) {
  this->PushBack(v[i]);
  }
}

template<class T>
List<T>::List(const List<T>& l2, Operation* op_assign, Operation* op_pointer_assign) {
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

template<class T>
List<T>::~List() {
  Node<T>* node = first;
  Node<T>* next;
  while (node != nullptr) {
    next = node->getNext();
    delete node;
    node = next;
  }
}

template<class T>
void List<T>::PushBack(T data) {
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

template<class T>
void List<T>::PushBack(Node<T>* node) {
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

template<class T>
Node<T>* List<T>::PopFrontNode() {
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

template<class T>
T List<T>::PopFrontValue() {
  return PopFrontNode()->getData();
}

template<class T>
bool List<T>::IsEmpty() {
  return first == nullptr;
}

template class List<int>;