//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_INSERTIONSORTER_H
#define LAB1_SORTING_CLION_INSERTIONSORTER_H

#include <string>
#include "Sorter.h"

using namespace std;

class InsertionSorter : public Sorter {
 public:
  void Sort(int *v, int no_elements, Profiler &p) override;

  const char *GetCompOpName() override;

  const char *GetAssignOpName() override;

  const char *GetSorterName() override;

 private:
  static const char *kAssignOpName;
  static const char *kCompOpName;
  static const char *kSorterName;
};

#endif //LAB1_SORTING_CLION_INSERTIONSORTER_H
