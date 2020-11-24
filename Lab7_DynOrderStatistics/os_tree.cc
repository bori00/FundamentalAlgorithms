//
// Created by Bori on 11/17/2020.
//


#include <iostream>
#include <assert.h>
#include "os_tree.h"

using namespace std;

OSTree::OSTree(int n, Operation* op_comp, Operation* op_assign) {
  this->root = BuildTree(1, n, op_comp, op_assign);
}

OSTree::Node *OSTree::BuildTree(int min, int max, Operation* op_comp, Operation* op_assign) {
  int middle = (min + max) / 2;
  Node* left, *right;
  if (min <= middle - 1) {
    left = BuildTree(min, middle - 1, op_comp, op_assign);
  } else {
    left = nullptr;
  }
  if (max >= middle + 1) {
    right = BuildTree(middle + 1, max, op_comp, op_assign);
  } else {
    right = nullptr;
  }
  op_comp->count(2);
  op_assign->count(2);
  return new Node(middle, left, right);
}

void OSTree::PrettyPrint() {
  this->root->PrettyPrint(0);
}

int OSTree::Select(int index, Operation* op_comp, Operation* op_assign) {
  assert(this->root->size_ >= index);
  return this->root->Select(index, op_comp, op_assign);
}

void OSTree::Delete(int value, Operation* op_comp, Operation* op_assign, Operation* op_pointer_comp,
                    Operation* op_pointer_assign) {
  this->root = this->root->Delete(value, nullptr, op_comp, op_assign, op_pointer_comp, op_pointer_assign);
  op_pointer_assign->count();
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

OSTree::Node* OSTree::Node::Delete(int value, Node* parent, Operation* op_comp,
                                    Operation* op_assign, Operation* op_pointer_comp,
                                   Operation* op_pointer_assign) {
  op_comp->count();
  if (this->data_ == value) {
    op_pointer_comp->count(2);
    if (this->left_ == nullptr) { // replace the node by (not necessarily existing) right child
      op_pointer_comp->count(2);
      Node* rightChild = this->right_;
      if (parent == nullptr) {
        delete this;
        return rightChild;
      } else {
        op_pointer_comp->count();
        op_pointer_assign->count();
        if (parent->left_ == this) {
          parent->left_ = this->right_;
        } else {
          parent->right_ = this->right_;
        }
        delete this;
        return rightChild;
      }
    } else if (this->right_ == nullptr) { // replace node by left child
      op_pointer_comp->count(2);
      Node* leftChild = this->left_;
      if (parent == nullptr) {
        delete this;
        return leftChild;
      } else {
        op_pointer_comp->count();
        op_pointer_assign->count();
        if (parent->left_ == this) {
          parent->left_ = this->left_;
        } else {
          parent->right_ = this->left_;
        }
        delete this;
        return leftChild;
      }
    } else { // both children exist: replace node's data by successor's data
      op_pointer_comp->count();
      this->data_ = this->right_->DeleteMin(this, op_pointer_comp, op_pointer_assign);
      this->size_--;
      op_assign->count();
      return this;
    }
  } else {
    op_comp->count();
    if (this->data_ > value) {
      this->left_->Delete(value, this, op_comp, op_assign, op_pointer_comp, op_pointer_assign);
    } else {
      this->right_->Delete(value, this, op_comp, op_assign, op_pointer_comp, op_pointer_assign);
    }
    this->size_--;
    return this;
  }
}

int OSTree::Node::DeleteMin(Node* parent, Operation* op_pointer_comp,
                            Operation* op_pointer_assign) {
  op_pointer_comp->count();
  if (this->left_ == nullptr) {
    op_pointer_assign->count();
    op_pointer_comp->count();
    if (parent->left_ == this) {
      parent->left_ = this->right_;
    } else {
      parent->right_ = this->right_;
    }
    int data = this->data_;
    delete this;
    return data;
  } else {
    this->size_--;
    return this->left_->DeleteMin(this, op_pointer_comp,
                                  op_pointer_assign);
  }
}

int OSTree::Node::Select(int index, Operation* op_comp, Operation* op_assign) {
  int left_size;
  op_assign->count();
  if (this->left_ != nullptr) {
    left_size = this->left_->size_;
  } else {
    left_size = 0;
  }
  if (index == left_size + 1) {
    op_comp->count();
    return this->data_;
  } else if (index <= left_size) {
    op_comp->count(2);
    return this->left_->Select(index, op_comp, op_assign);
  } else {
    op_comp->count(2);
    return this->right_->Select(index - left_size - 1, op_comp, op_assign);
  }
}
