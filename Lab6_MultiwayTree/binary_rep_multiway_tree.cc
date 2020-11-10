//
// Created by Bori on 11/10/2020.
//

#include "binary_rep_multiway_tree.h"

BinaryRepMultiwayTree::BinaryRepMultiwayTree(MultiwayTree m_tree) {
  MultiwayTree::MultiWayNode* root = m_tree.root_;
  this->root_ = getBinaryRepSubtree(root, nullptr);
}
BinaryRepMultiwayTree::BinaryNode *BinaryRepMultiwayTree::getBinaryRepSubtree
(MultiwayTree::MultiWayNode *multiway_root, BinaryNode* first_sibling) {
  BinaryNode* prev_child = nullptr, *curr_child;
  for (int i = multiway_root->no_children - 1; i >= 0; i--) {
    curr_child = getBinaryRepSubtree(multiway_root->children[i], prev_child);
    prev_child = curr_child;
  }
  return new BinaryNode(multiway_root->data, curr_child, first_sibling);
}
