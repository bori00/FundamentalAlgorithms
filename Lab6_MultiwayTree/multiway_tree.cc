//
// Created by Bori on 11/10/2020.
//

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "multiway_tree.h"

using namespace std;

MultiwayTree::MultiwayTree(ParentArrayMultiwayTree parent_tree) {
  // instantiate
  vector<MultiWayNode*> nodes(parent_tree.no_nodes_);
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    nodes[i] = new MultiWayNode(i);
  }
  // count no children
  vector<int> no_inserted_children (parent_tree.no_nodes_, 0);
  int root_index = -1;
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    if (parent_tree.parents_[i] == -1) {
      if (root_index != -1) {
        cerr << "Error: Multiple roots in the tree";
        exit(1);
      }
      root_index = i;
    } else {
      nodes[parent_tree.parents_[i]]->no_children_++;
    }
  }
  // allocate the necessary space for children
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    nodes[i]->allocateDataFrorChildren();
  }
  // insert children
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    int parent = parent_tree.parents_[i];
    if (parent_tree.parents_[i] > -1) {
      nodes[parent]->children_[no_inserted_children[parent]] = nodes[i];
      no_inserted_children[parent]++;
    }
  }
  this->root_ = nodes[root_index];
}

void MultiwayTree::PrettyPrint() {
  PrettyPrintHelper(root_, 0);
}

void MultiwayTree::PrettyPrintHelper(MultiwayTree::MultiWayNode *node, int level) {
  for (int i = 0; i < level; i++) {
    cout << "  ";
  }
  cout << node->data_ + 1 << endl;
  for (int i = 0; i < node->no_children_; i++) {
    PrettyPrintHelper(node->children_[i], level + 1);
  }
}
