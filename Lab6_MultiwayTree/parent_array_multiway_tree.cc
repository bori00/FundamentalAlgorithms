//
// Created by Bori on 11/10/2020.
//

#include <stdlib.h>
#include "parent_array_multiway_tree.h"

ParentArrayMultiwayTree::ParentArrayMultiwayTree(int *parents, int no_nodes) {
  this->no_nodes_ = no_nodes;
  this->parents_ = (int*) malloc(sizeof(int) * no_nodes_);
  for (int i = 0; i < no_nodes_; i++) {
    if (parents[i] >= 0) {
      this->parents_[i] = parents[i] - 1;
    } else {
      this->parents_[i] = -1;
    }
  }
}
