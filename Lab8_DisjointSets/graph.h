//
// Created by Bori on 11/24/2020.
//

#ifndef LAB8_DISJOINTSETS__GRAPH_H_
#define LAB8_DISJOINTSETS__GRAPH_H_

class Graph {
 public:
  explicit Graph(int n);

  static Graph GenerateRandomGraph(int n);

 private:
  class Edge {
    int n1_, n2_, w_;

   public:
    Edge(int n_1, int n_2, int w);
  };

  int no_nodes;
};

#endif //LAB8_DISJOINTSETS__GRAPH_H_
