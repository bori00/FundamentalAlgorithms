//
// Created by Bori on 12/21/2020.
//

#include <iostream>
#include "demo_dfs.h"
#include "graph.h"

using namespace std;

void PrintDfsNodesData(vector<Graph::DFSNodeData> &node_data) {
  for (int i = 0; i < node_data.size(); i++) {
    cout << "Node " << i << ": discovery time: " << node_data[i].d_ << ", finishing time: " <<
      node_data[i].f_ << endl;
  }
}

void Demo_Dfs1(){
  cout << "DFS --- Demo 1" << endl;
  Graph* g = new Graph(8);
  g->AddEdge(4, 1);
  g->AddEdge(2, 0);
  g->AddEdge(2, 1);
  g->AddEdge(1, 3);
  g->AddEdge(1, 5);
  g->AddEdge(1, 7);
  g->AddEdge(0, 5);
  g->AddEdge(6, 0);
  g->AddEdge(6, 7);
  g->PrintAdjLists();
  vector<Graph::DFSNodeData> node_data = g->Dfs();
  PrintDfsNodesData(node_data);
}

void Demo_Dfs2() {
  cout << "DFS --- Demo 2" << endl;
  Graph* g = new Graph(5);
  g->AddEdge(0, 4);
  g->AddEdge(4, 1);
  g->AddEdge(4, 2);
  g->AddEdge(4, 3);
  g->AddEdge(3, 1);
  g->AddEdge(2, 0);
  g->AddEdge(2, 1);
  g->PrintAdjLists();
  vector<Graph::DFSNodeData> node_data = g->Dfs();
  PrintDfsNodesData(node_data);
}

void Demo_Dfs3() {
  cout << "DFS --- Demo 3" << endl;
  Graph* g = new Graph(6);
  g->AddEdge(1, 2);
  g->AddEdge(3, 5);
  g->AddEdge(0, 5);
  g->AddEdge(4, 2);
  g->AddEdge(4, 3);
  g->AddEdge(5, 1);
  g->AddEdge(5, 2);
  g->AddEdge(3, 5);
  g->PrintAdjLists();
  vector<Graph::DFSNodeData> node_data = g->Dfs();
  PrintDfsNodesData(node_data);
}