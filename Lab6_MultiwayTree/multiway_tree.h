//
// Created by Bori on 11/10/2020.
//

#ifndef LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
#define LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_

#include <stdlib.h>
#include "parent_array_multiway_tree.h"
class MultiwayTree {
 public:
  MultiwayTree(ParentArrayMultiwayTree parent_tree);

  void PrettyPrint();

 private:
  class MultiWayNode {
   public:
    int data;
    int no_children = 0;
    MultiWayNode** children;

    MultiWayNode(int data) {
      this->data = data;
    }

    MultiWayNode(int data, int no_children) {
      this->data = data;
      this->no_children = no_children;
      this->children = (MultiWayNode**) malloc(sizeof(MultiWayNode*)*no_children);
    }
  };

  static void PrettyPrintHelper(MultiWayNode* node, int level);

  MultiWayNode* root_;

  friend class BinaryRepMultiwayTree;
};

#endif //LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
