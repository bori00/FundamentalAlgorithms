//
// Created by Bori on 12/15/2020.
//

#ifndef LAB10_DFS_TOPS_TARJAN__GRAPH_H_
#define LAB10_DFS_TOPS_TARJAN__GRAPH_H_

#include <vector>

using namespace std;

class Graph {
 public:
  explicit Graph(int noNodes);

  void dfs();

 private:
  class Node {
    vector<Node*> edges_;

    void addEdge(Node* node);
  };

  class DFSNode {
   public:
    static enum class Color  {WHITE, GRAY, BLACK};

    Node* node_;
    int d_, f_;
    Color color_;

    explicit DFSNode (Node* node);
  };

  vector<Node> nodes_;
};

#endif //LAB10_DFS_TOPS_TARJAN__GRAPH_H_
