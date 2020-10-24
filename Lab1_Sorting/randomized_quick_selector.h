//
// Created by Bori on 10/25/2020.
//

#ifndef LAB1_SORTING__RANDOMIZED_QUICK_SELECTOR_H_
#define LAB1_SORTING__RANDOMIZED_QUICK_SELECTOR_H_

#include "Profiler.h"

class RandomizedQuickSelector {
 public:
  int select(int *v, int no_elements, int index);

 private:
  int RandomizedPartition(int *v, int no_elements);

  void Swap(int *v, int i, int j);
};

#endif //LAB1_SORTING__RANDOMIZED_QUICK_SELECTOR_H_
