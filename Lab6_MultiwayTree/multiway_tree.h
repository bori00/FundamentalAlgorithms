//
// Created by Bori on 11/10/2020.
//

#ifndef LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
#define LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_

#include <stdlib.h>
#include "parent_array_multiway_tree.h"
class MultiwayTree {
 public:
  explicit MultiwayTree(ParentArrayMultiwayTree parent_tree);

  void PrettyPrint();

 private:
  class MultiWayNode {
   public:
    int data_;
    int no_children_ = 0;
    MultiWayNode** children_;

    MultiWayNode(int data) {
      this->data_ = data;
      this->no_children_ = 0;
    }

    void allocateDataFrorChildren() {
      this->children_ = (MultiWayNode**) malloc(sizeof(MultiWayNode*)*no_children_);
    }
  };

  static void PrettyPrintHelper(MultiWayNode* node, int level);

  MultiWayNode* root_;

  friend class BinaryRepMultiwayTree;
};

#endif //LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
