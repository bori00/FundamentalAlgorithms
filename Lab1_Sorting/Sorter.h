//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_SORTER_H
#define LAB1_SORTING_CLION_SORTER_H

#include "Profiler.h"

using namespace std;

class Sorter {
 public:
  virtual void sort(int *v, int no_elements, Profiler &p) = 0;

  virtual const char *getCompOpName() = 0;

  virtual const char *getAssignOpName() = 0;

  virtual const char *getSorterName() = 0;
};

#endif //LAB1_SORTING_CLION_SORTER_H
