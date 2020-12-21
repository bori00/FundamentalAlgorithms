//
// Created by Bori on 12/21/2020.
//

#include <iostream>
#include "demo_topological_sort.h"
#include "graph.h"

using namespace std;

void PrintTopOrder(list<int> nodes) {
  for (int node_index : nodes) {
    cout << node_index << " ";
  }
  cout << endl;
}

void Demo_TopSort1() {
  cout << "Topological Sort --- Demo 1" << endl;
  Graph* g = new Graph(8);
  g->AddEdge(4, 1);
  g->AddEdge(2, 1);
  g->AddEdge(2, 0);
  g->AddEdge(1, 3);
  g->AddEdge(1, 5);
  g->AddEdge(1, 7);
  g->AddEdge(0, 5);
  g->AddEdge(6, 0);
  g->AddEdge(6, 7);
  g->PrintAdjLists();
  cout << "Topological order: ";
  bool valid = true;
  list<int> top_ordered_nodes = g->TopologicalSort(valid);
  if (valid) {
    PrintTopOrder(top_ordered_nodes);
  } else {
    cout << "does not exist, because graph contains a cycle" << endl;
  }
}

void Demo_TopSort2() {
  cout << "Topological Sort --- Demo 2" << endl;
  Graph* g = new Graph(8);
  g->AddEdge(2, 0);
  g->AddEdge(0, 1);
  g->AddEdge(1, 2);
  g->AddEdge(5, 2);
  g->AddEdge(3, 2);
  g->AddEdge(3, 1);
  g->AddEdge(3, 4);
  g->AddEdge(4, 3);
  g->AddEdge(4, 5);
  g->AddEdge(7, 4);
  g->AddEdge(7, 6);
  g->AddEdge(7, 7);
  g->AddEdge(5, 6);
  g->AddEdge(6, 5);
  g->PrintAdjLists();
  cout << "Topological order: ";
  bool valid = true;
  list<int> top_ordered_nodes = g->TopologicalSort(valid);
  if (valid) {
    PrintTopOrder(top_ordered_nodes);
  } else {
    cout << "does not exist, because graph contains a cycle" << endl;
  }
}

void Demo_TopSort3() {
  cout << "Topological Sort --- Demo 3" << endl;
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
  cout << "Topological order: ";
  bool valid = true;
  list<int> top_ordered_nodes = g->TopologicalSort(valid);
  if (valid) {
    PrintTopOrder(top_ordered_nodes);
  } else {
    cout << "does not exist, because graph contains a cycle" << endl;
  }
}