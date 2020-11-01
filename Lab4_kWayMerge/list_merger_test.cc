//
// Created by Bori on 11/1/2020.
//

#include "list_merger_test.h"
#include "Profiler.h"

using namespace std;

List<int>* ListMergerTest::GetList(int index) {
  switch(index) {
    case 1: return new List<int>(array1, array1_size);
    case 2: return new List<int>(array2, array2_size);
    case 3: return new List<int>(array3, array3_size);
    case 4: return new List<int>(array4, array4_size);
    case 5: return new List<int>(array5, array5_size);
    default: cerr << "Invalid test array index";
  }
  return new List<int>();
}

List<int>* ListMergerTest::GetRandomList() {
  int size = rand() % kMaxSize;
  int v[kMaxSize];
  FillRandomArray(v, size, -10000, 10000, false, ASCENDING);
  return new List<int>(v, size);
}

bool ListMergerTest::IsSorted(List<int> l) {
  if (l.IsEmpty()) {
    return true;
  }
  int prev_value = l.PopFrontValue();
  int value;
  while (!l.IsEmpty()) {
    value = l.PopFrontValue();
    if (value < prev_value) {
      return false;
    }
    prev_value = value;
  }
  return true;
}
