//
// Created by Bori on 10/4/2020.
//

#include "sorter.h"

void Sorter::Swap(int *v, int i, int j, Operation *op_assign) {
  op_assign->count(3);
  int helper = v[i];
  v[i] = v[j];
  v[j] = helper;
}
