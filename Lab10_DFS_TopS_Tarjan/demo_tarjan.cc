//
// Created by Bori on 01/10/1010.
//

#include <iostream>
#include "graph.h"
#include "demo_tarjan.h"

using namespace std;

void print_sccs(vector<vector<int>> sccs) {
  for (const vector<int>& scc : sccs) {
    cout << "SCC: ";
    for (int nodeIndex : scc) {
      cout << nodeIndex << " ";
    }
    cout << endl;
  }
}

void Demo_Tarjan1() {
  cout << "Tarjan --- Demo 1" << endl;
  Graph* g = new Graph(8);
  g->addEdge(2, 0);
  g->addEdge(0, 1);
  g->addEdge(1, 2);
  g->addEdge(5, 2);
  g->addEdge(3, 2);
  g->addEdge(3, 1);
  g->addEdge(3, 4);
  g->addEdge(4, 3);
  g->addEdge(4, 5);
  g->addEdge(7, 4);
  g->addEdge(7, 6);
  g->addEdge(7, 7);
  g->addEdge(5, 6);
  g->addEdge(6, 5);
  g->PrintAdjLists();
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->Tarjan_SCC();
  print_sccs(sccs);
}

void Demo_Tarjan2() {
  cout << "Tarjan --- Demo 2" << endl;
  Graph* g = new Graph(5);
  g->addEdge(0, 4);
  g->addEdge(4, 3);
  g->addEdge(4, 1);
  g->addEdge(4, 2);
  g->addEdge(3, 1);
  g->addEdge(2, 1);
  g->addEdge(2, 0);
  g->PrintAdjLists();
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->Tarjan_SCC();
  print_sccs(sccs);
}

void Demo_Tarjan3() {
  cout << "Tarjan --- Demo 3" << endl;
  Graph* g = new Graph(9);
  g->addEdge(0, 4);
  g->addEdge(1, 0);
  g->addEdge(4, 2);
  g->addEdge(4, 1);
  g->addEdge(2, 5);
  g->addEdge(5, 3);
  g->addEdge(3, 6);
  g->addEdge(6, 6);
  g->addEdge(8, 3);
  g->addEdge(6, 5);
  g->addEdge(5, 8);
  g->addEdge(8, 7);
  g->addEdge(7, 5);
  g->PrintAdjLists();
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->Tarjan_SCC();
  print_sccs(sccs);
}


