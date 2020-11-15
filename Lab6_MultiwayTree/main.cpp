#include <iostream>
#include "parent_array_multiway_tree.h"
#include "multiway_tree.h"
#include "binary_rep_multiway_tree.h"

using namespace std;

void demo(int parents[], int no_nodes);

int main() {
  int parents_1[9] = {2, 7, 5, 2, 7, 7, -1, 5, 2};
  cout << "--------------Tree 1--------------" << endl;
  demo(parents_1, 9);

  int parents_2[10] = {9, -1, 7, 2, 2, 7, 2, 2, 3, 2};
  cout << "--------------Tree 2--------------" << endl;
  demo(parents_2, 10);

  int parents_3[6] = {-1, 1, 2, 3, 4, 5};
  cout << "--------------Tree 3--------------" << endl;
  demo(parents_3, 6);

  int parents_4[5] = {3, 3, -1, 3, 3};
  cout << "--------------Tree 4--------------" << endl;
  demo(parents_4, 5);

  int parents_5[8] = {2, 3, 8, 5, 6, 8, 8, -1};
  cout << "--------------Tree 5--------------" << endl;
  demo(parents_5, 8);
  return 0;
}

void demo(int parents[], int no_nodes) {
  ParentArrayMultiwayTree p_tree(parents, no_nodes);
  cout << "---Parent array representation:" << endl;
  p_tree.Print();
  MultiwayTree m_tree(p_tree);
  cout << "---Multiway tree representation:" << endl;
  m_tree.PrettyPrint();
  BinaryRepMultiwayTree b_tree(m_tree);
  cout << "---Binary tree representation:" << endl;
  b_tree.PrettyPrint();
}