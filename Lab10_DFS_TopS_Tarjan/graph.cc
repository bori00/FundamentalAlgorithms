//
// Created by Bori on 12/15/2020.
//

#include <unordered_map>
#include "graph.h"

class DFSNodeData;
void Graph::Node::addEdge(Graph::Node *node) {
  this->edges_.push_back(node);
}

Graph::DFSNodeData::DFSNodeData() {
  this->d_ = -1;
  this->f_ = -1;
  this->color_ = Color::WHITE;
};

Graph::Graph(int noNodes) {
  this->nodes_.resize(noNodes);
}

vector<Graph::DFSNodeData> Graph::dfs() {
  unordered_map<Node*, DFSNodeData> node_to_data;
  for (Node node : this->nodes_) {
    node_to_data[&node] = DFSNodeData();
  }
  int time = 0;
  for (Node node: this->nodes_) {
    if (node_to_data[&node].color_ == DFSNodeData::Color::WHITE) {
      dfs_visit(&node, node_to_data, time);
    }
  }
  vector<Graph::DFSNodeData> result;
  result.reserve(this->nodes_.size());
  for (int i = 0; i < this->nodes_.size(); i++) {
    result.push_back(node_to_data[&this->nodes_[i]]);
  }
  return result;
}

void Graph::dfs_visit(Node* node, unordered_map<Node*, DFSNodeData> &node_to_data, int &time) {
  time++;
  node_to_data[node].d_ = time;
  node_to_data[node].color_ = DFSNodeData::Color::GRAY;
  for (Node* neighbor : node->edges_) {
    if (node_to_data[neighbor].color_ == DFSNodeData::Color::WHITE) {
      dfs_visit(neighbor, node_to_data, time);
    }
  }
  time++;
  node_to_data[node].f_ = time;
  node_to_data[node].color_ = DFSNodeData::Color::BLACK;
}

void Graph::addEdge(int n1, int n2) {
  this->nodes_[n1].addEdge(&this->nodes_[n2]);
}

