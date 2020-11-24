//
// Created by Bori on 11/24/2020.
//

#include "disjoint_set.h"

void DisjointSet::MakeSet(int value) {
  sets[value] = new Node(value);
}

int DisjointSet::FindSet(int value) {
  // with path compression
  if (sets[value]->parent_ != value) {
    sets[value]->parent_ = FindSet(sets[value]->parent_);
  }
  return sets[value]->parent_;
}

void DisjointSet::Union(int value1, int value2) {
  int root1 = FindSet(value1);
  int root2 = FindSet(value2);
  // by rank
  if (root1 != root2) {
    if (sets[root1]->rank_ > sets[root2]->rank_) {
      sets[root2]->parent_ = root1;
    } else if (sets[root1]->rank_ < sets[root2]->rank_) {
      sets[root1]->parent_= root2;
    } else {
      sets[root2]->parent_ = root1;
      sets[root1]->increaseRank();
    }
  }
}
