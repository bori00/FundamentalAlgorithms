//
// Created by Bori on 10/6/2020.
//

#ifndef LAB1_SORTING_SORTEREVALUATOR_H
#define LAB1_SORTING_SORTEREVALUATOR_H

#include "Sorter.h"
#include "Profiler.h"

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
  // todo change to 10000
  static const int kMaxArraySize = 1000;
  static const int kStepSize = 100;
  Sorter *sorters_[kMaxNoSorters];
  Profiler p_;
  int no_sorters_;
};

#endif //LAB1_SORTING_SORTEREVALUATOR_H
