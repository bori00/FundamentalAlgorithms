//
// Created by Bori on 11/10/2020.
//

#include <stdlib.h>
#include <iostream>
#include "parent_array_multiway_tree.h"

using namespace std;

ParentArrayMultiwayTree::ParentArrayMultiwayTree(int *parents, int no_nodes) {
  this->no_nodes_ = no_nodes;
  this->parents_ = (int*) malloc(sizeof(int) * no_nodes_);
  for (int i = 0; i < no_nodes_; i++) {
      this->parents_[i] = parents[i];
  }
}

void ParentArrayMultiwayTree::Print() {
  for (int i = 0; i < no_nodes_; i++) {
    if (parents_[i] >= 0) {
      cout << "Parent of node " << i << " is: " << parents_[i] << endl;
    } else {
      cout << "Node " << i << " is the root" << endl;
    }
  }
}
