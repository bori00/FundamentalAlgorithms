#include <iostream>
#include "os_tree.h"

using namespace std;

void demo11();

int main() {
  demo11();
  return 0;
}

void demo11() {
  OSTree os_tree(11);
  cout << "------Original Tree" << endl;
  os_tree.PrettyPrint();
  cout << "------ Selected the 2nd element: " << os_tree.Select(2) << endl;
  cout << "------Delete 2 (leaf)" << endl;
  os_tree.Delete(2);
  os_tree.PrettyPrint();
  cout << "------ Selected the 1st element: " << os_tree.Select(1) << endl;
  cout << "------Delete 1 (one single child)" << endl;
  os_tree.Delete(1);
  os_tree.PrettyPrint();
  cout << "------ Selected the 7th element: " << os_tree.Select(7) << endl;
  cout << "------Delete 9 (two children)" << endl;
  os_tree.Delete(9);
  os_tree.PrettyPrint();
  cout << "------ Selected the 4th element: " << os_tree.Select(4) << endl;
  cout << "------Delete 6 (root)" << endl;
  os_tree.Delete(6);
  os_tree.PrettyPrint();
}