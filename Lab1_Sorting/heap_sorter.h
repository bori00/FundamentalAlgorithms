//
// Created by Bori on 10/10/2020.
//

#ifndef LAB1_SORTING__HEAP_SORTER_H_
#define LAB1_SORTING__HEAP_SORTER_H_

#include "Profiler.h"
#include "sorter.h"

class HeapSorter : public Sorter {
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

#endif //LAB1_SORTING__HEAP_SORTER_H_
