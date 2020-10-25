//
// Created by Bori on 10/18/2020.
//

#ifndef LAB1_SORTING__AKL_QUICK_SORTER_H_
#define LAB1_SORTING__AKL_QUICK_SORTER_H_

#include "sorter.h"

class AklQuickSorter : public Sorter {
 public:
  void Sort(int *v, int no_elements, Profiler &p) override;

  const char *GetCompOpName() override;

  const char *GetAssignOpName() override;

  const char *GetSorterName() override;

 private:
  void SortHelper(int *v, int no_elements, Operation *op_comp, Operation *op_assign);

  int partition(int *v, int no_elements, int pivot, Operation *op_comp, Operation *op_assign);

  void AklSelect(int *v, int no_elements, int index, Operation *op_comp, Operation *op_assign);

  static const char *kAssignOpName;
  static const char *kCompOpName;
  static const char *kSorterName;
};

#endif //LAB1_SORTING__AKL_QUICK_SORTER_H_
