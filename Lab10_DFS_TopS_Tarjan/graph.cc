//
// Created by Bori on 12/15/2020.
//

#include <unordered_map>
#include "graph.h"

class DFSNodeData;
void Graph::Node::addEdge(Graph::Node *node) {
  this->edges_.push_back(node);
}

Graph::Node::Node(int index) {
  this->index_ = index;
}

Graph::DFSNodeData::DFSNodeData() {
  this->d_ = -1;
  this->f_ = -1;
  this->color_ = Color::WHITE;
};

Graph::Graph(int noNodes) {
  this->nodes_.reserve(noNodes);
  for (int i = 0; i < noNodes; i++) {
    this->nodes_.emplace_back(i);
  }
}

vector<Graph::DFSNodeData> Graph::dfs() {
  vector<DFSNodeData> node_data;
  node_data.resize(this->nodes_.size());
  int time = 0;
  for (Node node: this->nodes_) {
    if (node_data[node.index_].color_ == DFSNodeData::Color::WHITE) {
      dfs_visit(&node, node_data, time);
    }
  }
  return node_data;
}

void Graph::dfs_visit(Node* node, vector<DFSNodeData> &node_data, int &time) {
  time++;
  node_data[node->index_].d_ = time;
  node_data[node->index_].color_ = DFSNodeData::Color::GRAY;
  for (Node* neighbor : node->edges_) {
    if (node_data[neighbor->index_].color_ == DFSNodeData::Color::WHITE) {
      dfs_visit(neighbor, node_data, time);
    }
  }
  time++;
  node_data[node->index_].f_ = time;
  node_data[node->index_].color_ = DFSNodeData::Color::BLACK;
}

void Graph::addEdge(int n1, int n2) {
  this->nodes_[n1].addEdge(&this->nodes_[n2]);
}

