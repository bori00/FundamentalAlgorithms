//
// Created by Bori on 11/24/2020.
//

#ifndef LAB8_DISJOINTSETS__DISJOINT_SET_H_
#define LAB8_DISJOINTSETS__DISJOINT_SET_H_

class DisjointSet {
 public:
  void MakeSet(int value);

  int FindSet(int value);

  void Union(int value1, int value2);

 private:
  class Node {
   public:
    int parent_;
    int rank_;

    explicit Node(int index) {
      this->parent_ = index;
      this->rank_ = 1;
    }

    void increaseRank() {
      rank_++;
    }
  };

  static const int kMaxSize = 10001;
  Node* sets[kMaxSize];
};

#endif //LAB8_DISJOINTSETS__DISJOINT_SET_H_
