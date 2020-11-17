//
// Created by Bori on 11/17/2020.
//


#include <iostream>
#include "os_tree.h"

using namespace std;

OSTree::OSTree(int n) {
  this->root = BuildTree(1, n);
}

OSTree::Node *OSTree::BuildTree(int min, int max) {
  if (min > max) return nullptr;
  int middle = (min + max) / 2;
  Node* left = nullptr, *right = nullptr;
  if (min <= middle - 1) {
    left = BuildTree(min, middle - 1);
  }
  if (max >= middle + 1) {
    right = BuildTree(middle + 1, max);
  }
  return new Node(middle, left, right);
}

void OSTree::PrettyPrint() {
  this->root->PrettyPrint(0);
}

int OSTree::Select(int index) {
  return this->root->Select(index);
}

void OSTree::Delete(int value) {
  return this->root->Delete(value);
}

void OSTree::Node::PrettyPrint(int level) {
  for (int i = 0; i < level; i++) {
    cout << "  ";
  }
  cout << this->data_ << endl;
  if (this->left_ != nullptr) {
    this->left_->PrettyPrint(level + 1);
  }
  if (this->right_ != nullptr) {
    this->right_->PrettyPrint(level + 1);
  }
}

void OSTree::Node::ComputeSize() {
  int size = 0;
  if (this->left_ != nullptr) {
    size += this->left_->size_;
  }
  if (this->right_ != nullptr) {
    size += this->right_->size_;
  }
  this->size_ = size + 1;
}

void OSTree::Node::Delete(int value) {
  this->size_--;
  if (this->data_ == value) {
    // delete from here
  } else if (this->data_ < value) {
    this->left_->Delete(value);
  } else {
    this->right_->Delete(value);
  }
}

int OSTree::Node::Select(int index) {
  int left_size = 0;
  if (this->left_ != nullptr) {
    left_size = this->left_->size_;
  }
  if (index == left_size + 1) {
    return this->data_;
  } else if (index <= left_size) {
    return this->left_->Select(index);
  } else {
    return this->right_->Select(index - left_size - 1);
  }
}
