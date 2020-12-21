//
// Created by Bori on 12/15/2020.
//

#ifndef LAB10_DFS_TOPS_TARJAN__GRAPH_H_
#define LAB10_DFS_TOPS_TARJAN__GRAPH_H_

#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

class Graph {
 public:
  explicit Graph(int noNodes);

  void AddEdge(int n1, int n2);

  void PrintAdjLists();

  class DFSNodeData {
   public:
    enum class Color  {WHITE, GRAY, BLACK};
    int d_, f_;
    Color color_;

    explicit DFSNodeData ();
  };

  class TarjanNodeData {
   public:
    int d_, low_;
    bool on_stack_;

    explicit TarjanNodeData ();
  };

 private:
  class Node {
   public:
    explicit Node(int index);
    void AddEdge(Node* node);
    vector<Node*> edges_;
    int index_;


  };

  vector<Node> nodes_;

  static void DfsVisit(Node* node, vector<DFSNodeData> &node_data, int &time);

  /** Returns true if no cycle was detected. */
  static bool TopSortDfsVisit(Node* node, vector<DFSNodeData> &node_data, list<int>
      &sorted_nodes);

  static void TarjanDfs(Node* node, vector<TarjanNodeData> &node_data, vector<vector<int>> &sccs,
      stack<Node*> &stack, int &d_time);

 public:
  vector<DFSNodeData> Dfs();

  list<int> TopologicalSort(int* valid);

  vector<vector<int>> TarjanSCC();
};

#endif //LAB10_DFS_TOPS_TARJAN__GRAPH_H_
