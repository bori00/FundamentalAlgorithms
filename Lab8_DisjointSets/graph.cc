//
// Created by Bori on 11/24/2020.
//

#include <cstdlib>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include "graph.h"
#include "disjoint_set.h"

using namespace std;

Graph::Graph(int n) {
  this->no_nodes_ = n;
}

Graph Graph::GenerateRandomGraph(int n) {
  Graph* g = new Graph(n);
  g->FillWithRandomTree(n);
  g->AddUniqueEdges(3 * n + 1);
  return *g;
}

void Graph::AddUniqueEdges(int no_edges) {
  unordered_set<Graph::Edge, Edge::EdgeHash> edge_set;
  for (Edge e : this->edges) {
    edge_set.insert(e);
  }
  int n1, n2, weight = 0, no_inserted_edges = 0;
  while (no_edges > no_inserted_edges) {
    n1 = rand() % no_nodes_;
    n2 = rand() % no_nodes_;
    if (n1 != n2 && edge_set.find(Edge(n1, n2, 0)) == edge_set.end()) {
      weight = rand() % Edge::kMaxWeight;
      edge_set.insert(Edge(n1, n2, weight));
      this->edges.emplace_back(n1, n2, weight);
      no_inserted_edges++;
    }
  }
  assert(edge_set.size() == 4*this->no_nodes_);
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

vector<Graph::Edge> Graph::Kruskal(Operation* sort_op, Operation* make_set_op, Operation* find_set_op,
                                   Operation* union_set_op, Operation* other_op) {
  vector<Edge> kruskal_tree;
  sort(this->edges.begin(), this->edges.end(), Graph::Edge::SmallerWeight);
  sort_op->count(this->edges.size()*log2(this->edges.size()));
  DisjointSet disjoint_set(make_set_op, find_set_op, union_set_op);
  for (int i = 0; i < this->no_nodes_; i++) {
    disjoint_set.MakeSet(i);
  }
  int edge_index = 0, no_tree_edges = 0;
  while (no_tree_edges < this->no_nodes_ - 1) {
    other_op->count();
    if (disjoint_set.FindSet(edges.at(edge_index).n1_) != disjoint_set.FindSet(edges.at
    (edge_index).n2_)) {
      disjoint_set.Union(edges.at(edge_index).n1_, edges.at(edge_index).n2_);
      kruskal_tree.push_back(edges.at(edge_index));
      no_tree_edges++;
    }
    edge_index++;
  }
  return kruskal_tree;
}

Graph::Edge::Edge(int n_1, int n_2, int w) : n1_(n_1), n2_(n_2), w_(w) {}
