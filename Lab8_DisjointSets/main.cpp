#include <iostream>
#include "disjoint_set.h"
#include "graph.h"
#include "kruskal_evaluator.h"

using namespace std;

/**
 * @author Borbala Fazakas
 * @group 30422
 *
 * Task:
 * - implement the base operations(make_set, find_set, union_ for disjoint sets data structure
 * - implement Kruskal's algorithm using disjoint sets
 *
 * Solutions
 * 1. Disjoint Sets
 * Given that my set elements are only integer numbers in a bounded range [0, n], I used an array
 * as the underlying data structure. On position i the parent of node i in the fidjoint forest
 * representation and the rank of the tree rooted at i is stored.
 * -- a. make_set(n): initialises a new set, represented in the array on position n, with the
 * node's parent being itself and the rank being 1. This is a constant time operation.
 * -- b. find_set(n): returns the representative (the root of the tree) of the set containing n.
 * To do so, a traversal of the tree containing n from n to the root is done, due to each node
 * having a pointer to its parent. The root is recognised because its parent is itself.
 * More than that, to make the operations more efficient, we aim to make the trees' height
 * representing the sets as small as possible. To achieve this, during find_set a path
 * compression is performed, meaning that each node along the path from n to the root is set to
 * point to the overall root. Thus, after the operation they are all at level 1, closer to the
 * root than they were before, so later find_set operations will take less time.
 * The analysis of this operation is more complex, but based on published analysis we know that
 * its complexity can be described with a very slowly growing function, which is in practice
 * close to the constant funtion.
 * -- c. union(a, b): unites the sets containing elements a and b.
 * It first searches for the representatives of both sets, relying on find_set. Then, one of
 * the roots is set to point to the other one, thus making the sets united.
 * Again, in order to maximise efficiency, the rank is taken into account as this step so that we
 * can keep the trees as short as possible: always the shorter tree is attached as a child of the
 * other one, so that the height of the resulting tree is not larger than originally the height
 * of the larger tree. If the two trees have the same heights, then we have to increase the
 * height by 1.
 * Since the union itself is a constant time operation, the complexity of union is the same as
 * the one of find_set --> close to constant.
 *
 * 2. Kruskal
 * The Kruskal algorithm is a greedy algorithm for finding the minimum spanning tree of a
 * connected graph. It first sorts the edges of the graph by their weight, and then always tries
 * to add the smallest-weight edge to the Kruskal-tree, with the constraint that it can't close a
 * cycle (because it would violate the tree-property. Having a cycle is unnecessary, since our
 * goal is to span all the nodes with minimum sum of edge weights). The check whether an edge
 * closes a cycle or not is done using disjoint sets, each connected component of the tree being
 * represented by a set, and two sets being united if an edge connecting the two components is
 * added.
 * Kruskal searches for edges which don't close a cycle as long as the number of edges in the
 * Kruskal-tree is < no_nodes - 1, because a tree of n nodes must contain n-1 edges.
 * Complexity analysis:
 * - sorting is O(ElogE)
 * - initialising the sets is O(v), because make_set takes constant time
 * - at most E edges are checked if they can be inserted. Insertion takes time proportional to
 * disjoint_set.Union, check takes time proportional to disjoint_set.Find_set. These being close
 * to constant, the actual building of the tree is ~O(E)
 * All in all, the Kruskal's algoruthm is an O(ElogE) algorithm.
 *
 * Chart Analysis
 * The charts correspond to what we have computed before. In kruskal, the most expensive
 * operation is the sorting part, and it clearly defines the overall complexity of the entire
 * algorithm.
 * Othe than that, only the find_set operations have a significant impact, as expected. Based on
 * the chart, the number of operations performed grows approcimately linearly with respect to the
 * size of the graph, so indeed find_set is nearly constant: for a graph of size 10000, ~260000
 * operations are needed for find_set, meaning ~26 operations per node.
 * the number of operations required for make_set is constant per node and for the entire graph
 * it is equal to the number of nodes, and the number of operations required for union itself
 * and for other operations is close to constant per node, so linear per graph.
 */

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
  KruskalEvaluator::Evaluate();
  return 0;
}

Profiler ignore_p("ignore");
Operation ignore_op = ignore_p.createOperation("ignore", 0);

void disjoint_sets_demo1() {
  cout << "---------Disjoint Sets: Demo 1---------" << endl;
  cout << "Sets with values from 0 to 9" << endl;
  DisjointSet disjoint_set(&ignore_op, &ignore_op, &ignore_op);
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
  DisjointSet disjoint_set(&ignore_op, &ignore_op, &ignore_op);
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
  DisjointSet disjoint_set(&ignore_op, &ignore_op, &ignore_op);
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
  vector<Graph::Edge> edges = g.Kruskal(&ignore_op, &ignore_op, &ignore_op, &ignore_op, &ignore_op);
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
  vector<Graph::Edge> edges = g.Kruskal(&ignore_op, &ignore_op, &ignore_op, &ignore_op, &ignore_op);
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
  vector<Graph::Edge> edges = g.Kruskal(&ignore_op, &ignore_op, &ignore_op, &ignore_op, &ignore_op);
  cout << "Edges of Kruskal Tree: " << endl;
  for (Graph::Edge edge : edges) {
    cout << edge.n1_ << " " << edge.n2_ << " " << edge.w_ << endl;
  }
}