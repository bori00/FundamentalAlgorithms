//
// Created by Bori on 10/27/2020.
//

#include "node.h"

template<class T>
Node<T>::Node(T data) {
  this->data = data;
  this->next = nullptr;
}

template<class T>
Node<T>::Node(T data, Node *next) {
 // todo use the other constructor
 this->data = data;
 this->next = next;
}

template<class T>
Node<T>::Node() {
  this->data = nullptr;
  this->next = nullptr;
}

template<class T>
T Node<T>::getData() {
  return data;
}

template<class T>
Node<T> *Node<T>::getNext() {
  return next;
}

template<class T>
bool Node<T>::hasNext() {
  return this->next != nullptr;
}

template<class T>
void Node<T>::setNext(Node *node) {
  this->next = node;
}
