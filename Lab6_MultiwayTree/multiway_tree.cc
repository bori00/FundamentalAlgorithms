//
// Created by Bori on 11/10/2020.
//

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "multiway_tree.h"

using namespace std;

MultiwayTree::MultiwayTree(ParentArrayMultiwayTree parent_tree) {
  // count no children
  vector<int> no_inserted_children (parent_tree.no_nodes_, 0);
  vector<int> no_children(parent_tree.no_nodes_, 0);
  int root_index;
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    if (parent_tree.parents_[i] == -1) {
      root_index = i;
    } else {
      no_children[parent_tree.parents_[i]]++;
    }
  }
  // initialise nodes
  vector<MultiWayNode*> nodes(parent_tree.no_nodes_);
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    nodes[i] = new MultiWayNode(i, no_children[i]);
  }
  // insert children
  for (int i = 0; i < parent_tree.no_nodes_; i++) {
    int parent = parent_tree.parents_[i];
    if (parent_tree.parents_[i] > -1) {
      nodes[parent]->children[no_inserted_children[parent]] = nodes[i];
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
  cout << node->data + 1 << endl;
  for (int i = 0; i < node->no_children; i++) {
    PrettyPrintHelper(node->children[i], level + 1);
  }
}
