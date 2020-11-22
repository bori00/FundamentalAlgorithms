//
// Created by Bori on 11/17/2020.
//

#ifndef LAB7_DYNORDERSTATISTICS__OS_TREE_H_
#define LAB7_DYNORDERSTATISTICS__OS_TREE_H_

#include "Profiler.h"

class OSTree {
 public:
  /** Builds a perfectly balanced OS tree containing elements in the interval [1..n]. */
  explicit OSTree(int n);

  int Select(int index, Operation* op_comp, Operation* op_assign);

  void Delete(int value, Operation* op_comp, Operation* op_assign, Operation* op_pointer_comp,
      Operation* op_pointer_assign);

  void PrettyPrint();

 private:
  class Node {
   public:
    int data_;
    Node* left_;
    Node* right_;
    int size_;

    explicit Node(int data) {
      this->data_ = data;
      this->left_ = nullptr;
      this->right_ = nullptr;
      this->size_ = 0;
    }

    Node(int data, Node* left, Node* right) {
      this->data_ = data;
      this->left_ = left;
      this->right_ = right;
      this->ComputeSize();
    }

    void PrettyPrint(int level);

    int Select(int index, Operation* op_comp, Operation* op_assign);

    /**
     * Deletes the node with data = @param value from the tree rooted at this node.
     * @returns the new root of this subtree, needed in case the root of the entire tree was
     * deleted.
     */
    Node* Delete(int value, Node* parent, Operation* op_comp, Operation* op_assign, Operation* op_pointer_comp,
                 Operation* op_pointer_assign);

    /**
     * Deletes the minimum value of the tree rooted at this node and returns its value.
     * @param parent is required not to be nullptr.
     */
    int DeleteMin(Node* parent, Operation* op_pointer_comp,
                  Operation* op_pointer_assign);

   private:
    void ComputeSize();
  };

  /**
   * Builds a perfectly balanced OS tree containing elements in the interval [min..max], and
   * returns the root
   */
  Node* BuildTree(int min, int max);

  Node* root;
};

#endif //LAB7_DYNORDERSTATISTICS__OS_TREE_H_
