//
// Created by Bori on 11/17/2020.
//

#ifndef LAB7_DYNORDERSTATISTICS__OS_TREE_H_
#define LAB7_DYNORDERSTATISTICS__OS_TREE_H_

class OSTree {
 public:
  /** Builds a perfectly balanced OS tree containing elements in the interval [1..n]. */
  explicit OSTree(int n);

  int Select(int index);

  void Delete(int value);

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

    int Select(int index);

    void Delete(int value);

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
