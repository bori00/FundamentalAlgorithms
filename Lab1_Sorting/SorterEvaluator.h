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

  void evaluate();

  void addSorter(Sorter *sorter);

 private:
  void evaluateBestCase();

  void evaluateWorstCase();

  void evaluateAverageCase();

  void evaluateCase(int no_tests, int order, char *title);

  static bool isSorted(int *v, int no_elements);

  void createProfilerGroups();

  void createProfilerTotalGroup();

  void createProfilerAssignGroup();

  void createProfilerCompGroup();

  int no_sorters;
  const static int NO_TESTS_AVERAGE_CASE = 5;
  const static int MAX_NO_SORTERS = 10;
  const static int MIN_ARRAY_SIZE = 100;
  // todo change to 10000
  const static int MAX_ARRAY_SIZE = 1000;
  const static int STEP_SIZE = 100;
  Sorter *sorters[MAX_NO_SORTERS];
  Profiler p;
};

#endif //LAB1_SORTING_SORTEREVALUATOR_H