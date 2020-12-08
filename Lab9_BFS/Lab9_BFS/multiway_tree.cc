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
        cerr << "Error: Multiple roots in the tree" << endl;
        exit(1);
      }
      root_index = i;
    } else {
      nodes[parent_tree.parents_[i]]->no_children_++;
    }
  }
  if (root_index == -1) {
    cerr << "Error: No root in the tree" << endl;
    exit(2);
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
  if (!ValidTree(parent_tree.no_nodes_)) {
    cerr << "Error: not a valid tree, it contains a circle." << endl;
    exit(3);
  }
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

bool MultiwayTree::ValidTree(int no_expected_nodes) {
  vector<bool> visited(no_expected_nodes, false);
  if (!DFS(root_, visited)) {
    return false;
  }
  for (int i = 0; i < no_expected_nodes; i++) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

bool MultiwayTree::DFS(MultiwayTree::MultiWayNode* root, vector<bool> &visited) {
  if (visited.at(root->data_)) {
    return false; // invalid tree
  }
  visited.at(root->data_) = true;
  bool valid;
  for (int i = 0; i < root->no_children_; i++) {
    valid = DFS (root->children_[i], visited);
    if (!valid) {
      return false;
    }
  }
  return true;
}
