//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_SORTER_H
#define LAB1_SORTING_CLION_SORTER_H

#include "Profiler.h"

using namespace std;

class Sorter {
 public:
  virtual void Sort(int *v, int no_elements, Profiler &p) = 0;

  virtual const char *GetCompOpName() = 0;

  virtual const char *GetAssignOpName() = 0;

  virtual const char *GetSorterName() = 0;
 protected:
  void swap(int *v, int i, int j, Operation* op_assign);
};

#endif //LAB1_SORTING_CLION_SORTER_H
