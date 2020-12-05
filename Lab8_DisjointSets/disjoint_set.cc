//
// Created by Bori on 11/24/2020.
//

#include "disjoint_set.h"

void DisjointSet::MakeSet(int value) {
  make_set_op->count();
  sets[value] = new Node(value);
}

int DisjointSet::FindSet(int value) {
  // with path compression
  find_set_op->count();
  if (sets[value]->parent_ != value) {
    find_set_op->count();
    sets[value]->parent_ = FindSet(sets[value]->parent_);
  }
  return sets[value]->parent_;
}

void DisjointSet::Union(int value1, int value2) {
  int root1 = FindSet(value1);
  int root2 = FindSet(value2);
  union_op->count(3);
  // by rank
  if (root1 != root2) {
    union_op->count(2);
    if (sets[root1]->rank_ > sets[root2]->rank_) {
      sets[root2]->parent_ = root1;
    } else if (sets[root1]->rank_ < sets[root2]->rank_) {
      union_op->count();
      sets[root1]->parent_= root2;
    } else {
      union_op->count(2);
      sets[root2]->parent_ = root1;
      sets[root1]->increaseRank();
    }
  }
}

DisjointSet::DisjointSet(Operation* make_set_op, Operation *find_set_op, Operation *union_op){
  for (auto & set : sets) {
    set = nullptr;
  }
  this->find_set_op = find_set_op;
  this->make_set_op = make_set_op;
  this->union_op = union_op;
}
