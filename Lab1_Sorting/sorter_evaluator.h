//
// Created by Bori on 10/6/2020.
//

#ifndef LAB1_SORTING_SORTEREVALUATOR_H
#define LAB1_SORTING_SORTEREVALUATOR_H

#include "sorter.h"
#include "Profiler.h"

/**
 * SorterEvaluator is responsible for evaluating maximum @param  kMaxNoSorters implementations
 * of Sorter, in average, best and worst case, and draw a chart for the number of assignments and
 * comparisons needed for ach of them depending on the size of the array to be sorted.
 */
class SorterEvaluator {
 public:
  SorterEvaluator();

  void Evaluate();

  void AddSorter(Sorter *sorter);

 private:
  void EvaluateBestCase();

  void EvaluateWorstCase();

  void EvaluateAverageCase();

  void EvaluateCase(int no_tests, int order, const char *title);

  void CreateProfilerGroups();

  void CreateProfilerTotalGroup();

  void CreateProfilerAssignGroup();

  void CreateProfilerCompGroup();

  static const int kAverageCaseNoTests = 5;
  static const int kMaxNoSorters = 10;
  static const int kMinArraySize = 100;
  static const int kMaxArraySize = 10000;
  static const int kStepSize = 100;
  Sorter *sorters_[kMaxNoSorters];
  Profiler p_;
  int no_sorters_;
};

#endif //LAB1_SORTING_SORTEREVALUATOR_H
