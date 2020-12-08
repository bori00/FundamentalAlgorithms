//
// Created by Bori on 11/10/2020.
//

#ifndef LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
#define LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_

#include <stdlib.h>
#include <vector>

#include "bfs.h"
#include "parent_array_multiway_tree.h"

using namespace std;

class MultiwayTree {
 public:
  explicit MultiwayTree(ParentArrayMultiwayTree parent_tree);

  void PrettyPrint();

  void PrettyPrint(Point* repr);

 private:
  static class MultiWayNode {
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

  bool ValidTree(int no_expected_nodes);

  /** Returns false if tree is invalid. */
  bool DFS(MultiWayNode* root, vector<bool>& visited);

  static void PrettyPrintHelper(MultiWayNode* node, int level);

  static void PrettyPrintHelper(MultiWayNode* node, int level, Point* repr);

  MultiWayNode* root_;

  friend class BinaryRepMultiwayTree;
};

#endif //LAB6_MULTIWAYTREE__MULTIWAY_TREE_H_
