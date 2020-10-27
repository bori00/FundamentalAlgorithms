#include <iostream>
#include "list.h"
#include "heap.h"
#include "list_merger.h"

using namespace std;

Profiler p("ignoreP");
Operation op_count = p.createOperation("count1", 10);
Operation op_count1 = p.createOperation("count2", 20);

int main() {
  auto* myList1 = new List<int>();
  myList1->PushBack(10);
  myList1->PushBack(30);
  myList1->PushBack(50);

  auto* myList2 = new List<int>();
  myList2->PushBack(5);
  myList2->PushBack(60);
  myList2->PushBack(70);

  ListMerger<int> list_merger;
  list_merger.AddList(myList1);
  list_merger.AddList(myList2);
  List<int> result = list_merger.merge(&op_count1, &op_count);

  int a = 3;
  //todo free memory
  return 0;
}