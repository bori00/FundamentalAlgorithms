#include <iostream>
#include "disjoint_set.h"
#include "graph.h"

using namespace std;

void disjoint_sets_demo1();
void disjoint_sets_demo2();
void disjoint_sets_demo3();

int main() {
  disjoint_sets_demo1();
  disjoint_sets_demo2();
  disjoint_sets_demo3();
  Graph g = Graph::GenerateRandomGraph(10);
  vector<Graph::Edge> kruskal_tree = g.Kruskal();
  return 0;
}

void disjoint_sets_demo1() {
  cout << "---------Demo 1---------" << endl;
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
  cout << "---------Demo 1---------" << endl;
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
  cout << "---------Demo 3---------" << endl;
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