//
// Created by Bori on 10/13/2020.
//

#ifndef LAB1_SORTING__HEAP_EVALUATOR_H_
#define LAB1_SORTING__HEAP_EVALUATOR_H_

#include "Profiler.h"

using namespace std;

class HeapEvaluator {
 public:
  HeapEvaluator();

  void Evaluate();

 private:
  void EvaluateAverageCase();

  void EvaluateWorstCase();

  void EvaluateCase(int no_tests, int order, const char *title);

  void EvaluateBottomUpHeapBuilding(int v[], int size);

  void EvaluateTopDownHeapBuilding(int v[], int size);

  static const int kAverageCaseNoTests = 5;
  static const int kMinArraySize = 100;
  static const int kMaxArraySize = 10000;
  static const int kStepSize = 100;
  static const char *kTopDownAssignmentName;
  static const char *kTopDownComparisonName;
  static const char *kBottomUpAssignmentName;
  static const char *kBottomUpComparisonName;
  static const char *kTopDownOperationName;
  static const char *kBottomUpOperationName;
  Profiler p_;

};

#endif //LAB1_SORTING__HEAP_EVALUATOR_H_
