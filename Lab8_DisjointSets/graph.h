//
// Created by Bori on 11/24/2020.
//

#ifndef LAB8_DISJOINTSETS__GRAPH_H_
#define LAB8_DISJOINTSETS__GRAPH_H_

#include <vector>
#include <iostream>
#include "Profiler.h"

using namespace std;

class Graph {
 public:
  explicit Graph(int n);

  static Graph GenerateRandomGraph(int n);

  class Edge {
   public:
    int n1_, n2_, w_;
    static const int kMaxWeight = 1000000;

    Edge(int n_1, int n_2, int w);

    friend bool operator == (const Edge &e1, const Edge &e2) {
      return e1.n1_ == e2.n2_ && e1.n2_ == e2.n2_;
    }

    static bool SmallerWeight(Edge e1, Edge e2) {
      return e1.w_ < e2.w_;
    }

    class EdgeHash{
     public:
      std::size_t operator()(const Edge &e) const {
        std::hash<int> hashVal;
        return hashVal(e.n1_) + hashVal(e.n2_);
      }
    };
  };

  vector<Edge> Kruskal(Operation* sort_op, Operation* make_set_op, Operation* find_set_op,
      Operation* union_set_op, Operation* other_op);

 private:
  int no_nodes_;
  vector<Edge> edges;

  void FillWithRandomTree(int n);

  void AddUniqueEdges(int no_edges);

 public:
  void AddEdge(Edge e);
};

#endif //LAB8_DISJOINTSETS__GRAPH_H_
