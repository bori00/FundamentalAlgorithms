//
// Created by Bori on 12/15/2020.
//

#include "graph.h"

void Graph::Node::addEdge(Graph::Node *node) {
  this->edges_.push_back(node);
}

Graph::DFSNode::DFSNode(Graph::Node *node) {
  this->node_ = node;
  this->d_ = -1;
  this->f_ = -1;
  this->color_ = Color::WHITE;
};

Graph::Graph(int noNodes) {
  this->nodes_.resize(noNodes);
}
