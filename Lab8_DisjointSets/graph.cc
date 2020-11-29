//
// Created by Bori on 11/24/2020.
//

#include <cstdlib>
#include <unordered_set>
#include "graph.h"

Graph::Graph(int n) {
  this->no_nodes_ = n;
}

Graph Graph::GenerateRandomGraph(int n) {
  Graph* g = new Graph(n);
  g->FillWithRandomTree(n);
  g->AddUniqueEdges(3*n);
  return *g;
}

void Graph::AddUniqueEdges(int no_edges) {
  unordered_set<Graph::Edge, Edge::EdgeHash> edge_set;
  for (Edge e : this->edges) {
    edge_set.insert(e);
  }
  int n1, n2, weight = 0;
  while (no_edges > 0) {
    n1 = rand() % no_nodes_;
    n2 = rand() % no_nodes_;
    if (n1 != n2 && edge_set.find(Edge(n1, n2, 0)) == edge_set.end()) {
      weight = rand() % Edge::kMaxWeight;
      // edge_set.insert(Edge(n1, n2, weight));
      this->edges.emplace_back(n1, n2, weight);
      no_edges--;
    }
  }
}

void Graph::AddEdge(Graph::Edge e) {
  this->edges.push_back(e);
}

void Graph::FillWithRandomTree(int n) {
  for (int n1 = 1; n1 < n; n1++) {
    int n2 = rand() % n1;
    int w = rand() % Graph::Edge::kMaxWeight;
    this->AddEdge(Edge(n1, n2, w));
  }
}

Graph::Edge::Edge(int n_1, int n_2, int w) : n1_(n_1), n2_(n_2), w_(w) {}
