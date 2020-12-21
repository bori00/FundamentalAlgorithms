//
// Created by Bori on 12/15/2020.
//

#include <unordered_map>
#include <iostream>
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

list<int> Graph::topological_sort(int* valid) {
  *valid = true;
  vector<DFSNodeData> node_data;
  list<int> result;
  node_data.resize(this->nodes_.size());
  for (Node node: this->nodes_) {
    if (node_data[node.index_].color_ == DFSNodeData::Color::WHITE) {
      if (!top_sort_dfs_visit(&node, node_data, result)) {
        *valid = false;
        break;
      }
    }
  }
  return result;
}

bool Graph::top_sort_dfs_visit(Graph::Node *node,
                         vector<DFSNodeData> &node_data,
                         list<int> &sorted_nodes) {
  node_data[node->index_].color_ = DFSNodeData::Color::GRAY;
  for (Node* neighbor : node->edges_) {
    if (node_data[neighbor->index_].color_ == DFSNodeData::Color::WHITE) {
      if(!top_sort_dfs_visit(neighbor, node_data, sorted_nodes)) {
        return false;
      }
    }
    if (node_data[neighbor->index_].color_ == DFSNodeData::Color::GRAY) {
      return false;
    }
  }
  node_data[node->index_].color_ = DFSNodeData::Color::BLACK;
  sorted_nodes.push_front(node->index_);
  return true;
}

vector<vector<int>> Graph::Tarjan_SCC() {
  vector<TarjanNodeData> node_data;
  vector<vector<int>> sccs;
  stack<Node*> tarjan_stack;
  node_data.resize(this->nodes_.size());
  int d_time = 1;
  for (Node node : this->nodes_) {
    if (node_data[node.index_].d_ == -1) { //not visited yet
      TarjanDfs(&node, node_data, sccs, tarjan_stack, d_time);
    }
  }
  return sccs;
}
void Graph::TarjanDfs(Graph::Node *node,
                      vector<TarjanNodeData> &node_data,
                      vector<vector<int>> &sccs, stack<Node*> &stack,
                      int &d_time) {
  stack.push(node);
  node_data[node->index_].d_ = d_time;
  node_data[node->index_].low_ = d_time;
  node_data[node->index_].on_stack_ = true;
  d_time++;
  for (Node *neighbor : node->edges_) {
    if (node_data[neighbor->index_].d_ == -1) { //not yet visited --> successor of node. Tree edge.
      TarjanDfs(neighbor, node_data, sccs, stack, d_time);
      node_data[node->index_].low_ = min(
          node_data[node->index_].low_,
          node_data[neighbor->index_].low_);
    } else if (node_data[neighbor->index_].on_stack_) { // already visited. Ancestor. Back edge.
      node_data[node->index_].low_ = min(node_data[node->index_].low_,
                                         node_data[neighbor->index_].d_);
    }
  }
  if (node_data[node->index_].low_ == node_data[node->index_].d_) { // starts a new scc
    vector<int> nodes_in_scc;
    bool found_this = false;
    while (!found_this) {
      nodes_in_scc.push_back(stack.top()->index_);
      if (stack.top() == node) {
        found_this = true;
      }
      node_data[stack.top()->index_].on_stack_ = false;
      stack.pop();
    }
    sccs.push_back(nodes_in_scc);
  }
}

void Graph::PrintAdjLists() {
  for (Node node : this->nodes_) {
    cout << "Node " << node.index_ << "s neighbors: ";
    for (Node* neighbor : node.edges_) {
      cout << neighbor->index_ << " ";
    }
    cout << endl;
  }
}

Graph::TarjanNodeData::TarjanNodeData() {
  this->d_ = -1;
  this->low_ = -1;
  this->on_stack_ = false;
}
