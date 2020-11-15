//
// Created by Bori on 11/10/2020.
//

#ifndef LAB6_MULTIWAYTREE__PARENT_ARRAY_MULTIWAY_TREE_H_
#define LAB6_MULTIWAYTREE__PARENT_ARRAY_MULTIWAY_TREE_H_

class ParentArrayMultiwayTree {
 public:
  ParentArrayMultiwayTree(int* parents, int no_nodes);

  void Print();

 private:
  int no_nodes_;
  int* parents_;

  friend class MultiwayTree;
};

#endif //LAB6_MULTIWAYTREE__PARENT_ARRAY_MULTIWAY_TREE_H_
