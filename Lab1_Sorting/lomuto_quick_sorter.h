//
// Created by Bori on 10/24/2020.
//

#ifndef LAB1_SORTING__LOMUTO_QUICK_SORTER_H_
#define LAB1_SORTING__LOMUTO_QUICK_SORTER_H_

#include "sorter.h"
class LomutoQuickSorter : public Sorter {
 public:
  void Sort(int *v, int no_elements, Profiler &p) override;

  const char *GetCompOpName() override;

  const char *GetAssignOpName() override;

  const char *GetSorterName() override;

 private:
  void SortHelper(int *v, int no_elements, Operation *op_comp, Operation *op_assign);

  int LomutoPartition(int *v, int no_elements, Operation *op_comp, Operation *op_assign);

  static const char *kAssignOpName;
  static const char *kCompOpName;
  static const char *kSorterName;
};

#endif //LAB1_SORTING__LOMUTO_QUICK_SORTER_H_
