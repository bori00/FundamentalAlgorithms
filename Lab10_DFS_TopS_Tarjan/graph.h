//
// Created by Bori on 12/15/2020.
//

#ifndef LAB10_DFS_TOPS_TARJAN__GRAPH_H_
#define LAB10_DFS_TOPS_TARJAN__GRAPH_H_

#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
 public:
  explicit Graph(int noNodes);

  void addEdge(int n1, int n2);

  class DFSNodeData {
   public:
    enum class Color  {WHITE, GRAY, BLACK};
    int d_, f_;
    Color color_;

    explicit DFSNodeData ();
  };

 private:
  class Node {
   public:
    void addEdge(Node* node);
    vector<Node*> edges_;
  };

  vector<Node> nodes_;

  static void dfs_visit(Node* node, unordered_map<Node*, DFSNodeData> &node_to_data, int &time);

 public:
  vector<DFSNodeData> dfs();
};

#endif //LAB10_DFS_TOPS_TARJAN__GRAPH_H_
