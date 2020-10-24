//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_INSERTIONSORTER_H
#define LAB1_SORTING_CLION_INSERTIONSORTER_H

#include <string>
#include "sorter.h"

using namespace std;

class InsertionSorter : public Sorter {
 public:
  void Sort(int *v, int no_elements, Profiler &p) override;

  void Sort(int *v, int no_elements, Operation* op_comp, Operation* op_assign);

  const char *GetCompOpName() override;

  const char *GetAssignOpName() override;

  const char *GetSorterName() override;

 private:
  /** Defines where the new element should be inserted in the already sorted part of the array. */
  static int getInsertionIndex(const int *v, int value, int no_elements, Operation *op_comp);

  /**
   * Shift the elements [low_index .. high_index] to the right by one position,
   * to [low_index + 1 .. high_index + 1]. The value of v[low_index] remains the same.
   */
  static void shiftElementsToRight(int *v, int low_index, int high_index, Operation *op_assign);

  static const char *kAssignOpName;
  static const char *kCompOpName;
  static const char *kSorterName;
};

#endif //LAB1_SORTING_CLION_INSERTIONSORTER_H
