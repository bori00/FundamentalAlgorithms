#include <iostream>
#include "disjoint_set.h"
#include "graph.h"

using namespace std;

void disjoint_sets_demo1();
void disjoint_sets_demo2();
void disjoint_sets_demo3();
void kruskal_demo1();
void kruskal_demo2();
void kruskal_demo3();

int main() {
  disjoint_sets_demo1();
  disjoint_sets_demo2();
  disjoint_sets_demo3();
  kruskal_demo1();
  kruskal_demo2();
  kruskal_demo3();
  return 0;
}

void disjoint_sets_demo1() {
  cout << "---------Disjoint Sets: Demo 1---------" << endl;
  cout << "Sets with values from 0 to 9" << endl;
  DisjointSet disjoint_set;
  for (int i = 0; i < 10; i++) {
    disjoint_set.MakeSet(i);
  }
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "representative of set with value 4: " << disjoint_set.FindSet(4) << endl;
  cout << "union of 2 with 4" << endl;
  disjoint_set.Union(2, 4);
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "representative of set with value 4: " << disjoint_set.FindSet(4) << endl;
  cout << "union of 8 with 4" << endl;
  disjoint_set.Union(4, 8);
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "representative of set with value 4: " << disjoint_set.FindSet(4) << endl;
  cout << "representative of set with value 8: " << disjoint_set.FindSet(8) << endl;
  cout << "union of 1 with 6" << endl;
  disjoint_set.Union(1, 6);
  cout << "representative of set with value 1: " << disjoint_set.FindSet(1) << endl;
  cout << "representative of set with value 6: " << disjoint_set.FindSet(6) << endl;
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
}

void disjoint_sets_demo2() {
  cout << "---------Disjoint Sets: Demo 1---------" << endl;
  cout << "Sets with values from 0 to 8" << endl;
  DisjointSet disjoint_set;
  for (int i = 0; i < 9; i++) {
    disjoint_set.MakeSet(i);
  }
  cout << "representative of set with value 1: " << disjoint_set.FindSet(1) << endl;
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "union of 1 with 2" << endl;
  disjoint_set.Union(1, 2);
  cout << "representative of set with value 1: " << disjoint_set.FindSet(1) << endl;
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "union of 3 with 4" << endl;
  disjoint_set.Union(3, 4);
  cout << "representative of set with value 1: " << disjoint_set.FindSet(1) << endl;
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "representative of set with value 3: " << disjoint_set.FindSet(3) << endl;
  cout << "representative of set with value 4: " << disjoint_set.FindSet(4) << endl;
  cout << "union of 1 with 4" << endl;
  disjoint_set.Union(1, 4);
  cout << "representative of set with value 1: " << disjoint_set.FindSet(1) << endl;
  cout << "representative of set with value 2: " << disjoint_set.FindSet(2) << endl;
  cout << "representative of set with value 3: " << disjoint_set.FindSet(3) << endl;
  cout << "representative of set with value 4: " << disjoint_set.FindSet(4) << endl;
}

void disjoint_sets_demo3() {
  cout << "---------Disjoint Sets: Demo 3---------" << endl;
  cout << "Sets with values from 0 to 100" << endl;
  DisjointSet disjoint_set;
  for (int i = 0; i < 100; i++) {
    disjoint_set.MakeSet(i);
  }
  cout << "Unite all sets" << endl;
  for (int i = 1; i < 100; i++) {
    int set_value = rand() % i;
    disjoint_set.Union(i, set_value);
  }
  cout << "The representatives of sets in order: " << endl;
  for (int i = 0; i < 100; i++) {
    cout << disjoint_set.FindSet(i) << " ";
  }
  cout << endl;
}

void kruskal_demo1() {
  cout << "---------Kruskal: Demo 1---------" << endl;
  cout << "(see attached doc for drawing)" << endl;
  Graph g(8);
  g.AddEdge(Graph::Edge(0, 1, 15));
  g.AddEdge(Graph::Edge(0, 4, 12));
  g.AddEdge(Graph::Edge(0, 5, 20));
  g.AddEdge(Graph::Edge(0, 7, 10));
  g.AddEdge(Graph::Edge(1, 2, 12));
  g.AddEdge(Graph::Edge(1, 4, 10));
  g.AddEdge(Graph::Edge(2, 5, 15));
  g.AddEdge(Graph::Edge(3, 7, 3));
  g.AddEdge(Graph::Edge(4, 5, 18));
  g.AddEdge(Graph::Edge(5, 7, 8));
  g.AddEdge(Graph::Edge(6, 7, 5));
  vector<Graph::Edge> edges = g.Kruskal();
  cout << "Edges of Kruskal Tree: " << endl;
  for (Graph::Edge edge : edges) {
    cout << edge.n1_ << " " << edge.n2_ << " " << edge.w_ << endl;
  }
}

void kruskal_demo2() {
  cout << "---------Kruskal: Demo 2---------" << endl;
  cout << "(see attached doc for drawing)" << endl;
  Graph g(6);
  g.AddEdge(Graph::Edge(0, 2, 10));
  g.AddEdge(Graph::Edge(0, 3, 10));
  g.AddEdge(Graph::Edge(0, 5, 10));
  g.AddEdge(Graph::Edge(1, 3, 2));
  g.AddEdge(Graph::Edge(1, 4, 3));
  g.AddEdge(Graph::Edge(2, 3, 10));
  g.AddEdge(Graph::Edge(3, 4, 5));
  g.AddEdge(Graph::Edge(4, 5, 15));
  vector<Graph::Edge> edges = g.Kruskal();
  cout << "Edges of Kruskal Tree: " << endl;
  for (Graph::Edge edge : edges) {
    cout << edge.n1_ << " " << edge.n2_ << " " << edge.w_ << endl;
  }
}

void kruskal_demo3() {
  cout << "---------Kruskal: Demo 3---------" << endl;
  cout << "(see attached doc for drawing)" << endl;
  Graph g(5);
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      g.AddEdge(Graph::Edge(i, j, 1));
    }
  }
  vector<Graph::Edge> edges = g.Kruskal();
  cout << "Edges of Kruskal Tree: " << endl;
  for (Graph::Edge edge : edges) {
    cout << edge.n1_ << " " << edge.n2_ << " " << edge.w_ << endl;
  }
}