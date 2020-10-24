//
// Created by Bori on 10/20/2020.
//

#ifndef LAB1_SORTING__RANDOMIZED_QUICK_SORTER_H_
#define LAB1_SORTING__RANDOMIZED_QUICK_SORTER_H_

#include "sorter.h"
class RandomizedQuickSorter : public Sorter {
 public:
  void Sort(int *v, int no_elements, Profiler &p) override;

  const char *GetCompOpName() override;

  const char *GetAssignOpName() override;

  const char *GetSorterName() override;

 private:
  void SortHelper(int *v, int no_elements, Operation *op_comp, Operation *op_assign);

  int RandomizedPartition(int *v, int no_elements, Operation* op_comp, Operation* op_assign);

  void RandomizedQuickSelect(int *v, int no_elements, int index, Operation *op_comp, Operation
  *op_assign);

  static const char *kAssignOpName;
  static const char *kCompOpName;
  static const char *kSorterName;
};

#endif //LAB1_SORTING__RANDOMIZED_QUICK_SORTER_H_
