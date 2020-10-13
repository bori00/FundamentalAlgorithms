//
// Created by Bori on 10/10/2020.
//

#include "heap_test.h"

int HeapTest::average_array_[] = {3, -7, 2, 10, -5, 9, 4, 12, 10, 10};
int HeapTest::sorted_array_[] = {-10, 0, 3, 7, 10, 23, 101, 103, 1000, 1500};
int HeapTest::inv_sorted_array_[] = {1002, 987, 540, 10, -24, -105, -900, -901, -901, -1000};

int *HeapTest::GetArrayWithContent(const int content[]) {
  int *result = (int *) malloc(sizeof(int) * kArrayLength);
  for (int i = 0; i < kArrayLength; i++) {
    result[i] = content[i];
  }
  return result;
}

bool HeapTest::isHeap(Heap h) {
  int *v = h.GetContent();
  int size = h.size();
  if (h.GetHeapType() == Heap::HeapType::kMaxHeap) {
    for (int i = size / 2 - 1; i >= 0; i--) {
      if (v[i] < v[2 * i + 1] || (2 * i + 2 < size && v[i] < v[2 * i + 2])) {
        return false;
      }
    }
    return true;
  } else {
    for (int i = size / 2 - 1; i >= 0; i--) {
      if (v[i] > v[2 * i + 1] || (2 * i + 2 < size && v[i] > v[2 * i + 2])) {
        return false;
      }
    }
    return true;
  }
}