//
// Created by Bori on 11/24/2020.
//

#include "graph.h"

Graph::Graph(int n) {
  this->no_nodes = n;
}

Graph::Edge::Edge(int n_1, int n_2, int w) : n1_(n_1), n2_(n_2), w_(w) {}
