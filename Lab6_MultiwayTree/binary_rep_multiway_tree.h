//
// Created by Bori on 11/10/2020.
//

#ifndef LAB6_MULTIWAYTREE__BINARY_REP_MULTIWAY_TREE_H_
#define LAB6_MULTIWAYTREE__BINARY_REP_MULTIWAY_TREE_H_

#include "multiway_tree.h"

class BinaryRepMultiwayTree {
 public:
  explicit BinaryRepMultiwayTree(MultiwayTree m_tree);

  void PrettyPrint();

 private:
  class BinaryNode {
   public:
    int data_;
    BinaryNode* first_child_;
    BinaryNode* first_sibling_;

    BinaryNode(int data, BinaryNode* first_child, BinaryNode* first_sibling) {
      this->data_ = data;
      this->first_child_ = first_child;
      this->first_sibling_ = first_sibling;
    }
  };

  BinaryNode* getBinaryRepSubtree(MultiwayTree::MultiWayNode* multiway_root, BinaryNode*
  first_sibling);

  static void PrettyPrintHelper(BinaryNode* node, int level);

  BinaryNode* root_;
};

#endif //LAB6_MULTIWAYTREE__BINARY_REP_MULTIWAY_TREE_H_
