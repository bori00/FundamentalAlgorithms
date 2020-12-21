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
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->TarjanSCC();
  print_sccs(sccs);
}

void Demo_Tarjan2() {
  cout << "Tarjan --- Demo 2" << endl;
  Graph* g = new Graph(5);
  g->AddEdge(0, 4);
  g->AddEdge(4, 3);
  g->AddEdge(4, 1);
  g->AddEdge(4, 2);
  g->AddEdge(3, 1);
  g->AddEdge(2, 1);
  g->AddEdge(2, 0);
  g->PrintAdjLists();
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->TarjanSCC();
  print_sccs(sccs);
}

void Demo_Tarjan3() {
  cout << "Tarjan --- Demo 3" << endl;
  Graph* g = new Graph(9);
  g->AddEdge(0, 4);
  g->AddEdge(1, 0);
  g->AddEdge(4, 2);
  g->AddEdge(4, 1);
  g->AddEdge(2, 5);
  g->AddEdge(5, 3);
  g->AddEdge(3, 6);
  g->AddEdge(6, 6);
  g->AddEdge(8, 3);
  g->AddEdge(6, 5);
  g->AddEdge(5, 8);
  g->AddEdge(8, 7);
  g->AddEdge(7, 5);
  g->PrintAdjLists();
  cout << "Strongly connected components: " << endl;
  vector<vector<int>> sccs = g->TarjanSCC();
  print_sccs(sccs);
}


