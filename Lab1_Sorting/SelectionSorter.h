//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_SELECTIONSORTER_H
#define LAB1_SORTING_CLION_SELECTIONSORTER_H

#include <string>
#include "Sorter.h"

using namespace std;

class SelectionSorter : public Sorter {
 public:
  void sort(int *v, int no_elements, Profiler &p) override;

  const char *getCompOpName() override;

  const char *getAssignOpName() override;

  const char *getSorterName() override;

 private:
  static const char *ASSIGN_OP_NAME;
  static const char *COMP_OP_NAME;
  static const char *SORTER_NAME;
};

#endif //LAB1_SORTING_CLION_SELECTIONSORTER_H
