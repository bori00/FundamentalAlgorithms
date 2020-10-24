//
// Created by Bori on 10/25/2020.
//

#include "randomized_quick_selector.h"

int RandomizedQuickSelector::select(int *v, int no_elements, int index) {
  if (no_elements > 0) {
    int q = RandomizedPartition(v, no_elements);
    if (index < q) {
      select(v, q, index);
    } else if (q < index) {
      select(v + q + 1, no_elements - q - 1, index - q - 1);
    }
  }
  return v[index];
}

int RandomizedQuickSelector::RandomizedPartition(int *v, int no_elements) {
  int pivot_index = rand() % no_elements;
  Swap(v, pivot_index, no_elements-1);
  int i = 0;
  for (int j = 0; j < no_elements - 1; j++) {
    if (v[j] <= v[no_elements - 1]) {
      Swap(v, i, j);
      i++;
    }
  }
  Swap(v, i, no_elements - 1);
  return i;
}

void RandomizedQuickSelector::Swap(int *v, int i, int j) {
  if (i != j) {
    int helper = v[i];
    v[i] = v[j];
    v[j] = helper;
  }
}