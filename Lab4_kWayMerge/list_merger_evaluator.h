//
// Created by Bori on 11/1/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_
#define LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_

#include "list.h"
#include "Profiler.h"

class ListMergerEvaluator {
 public:
  ListMergerEvaluator();

  void Evaluate();

 private:
  void EvaluateConstantK(int k);

  void EvaluateConstantN();

  char* GetOpName(char* op_name, int k);

  static List<int>** GenerateLists(int n, int k, Operation* op_assign, Operation*
  op_pointer_assign);

  static const int kConstN = 10000;
  static const int kMinK = 10;
  static const int kMaxK = 500;
  static const int kIncrementK = 10;

  static const int kMinN = 100;
  static const int kMaxN = 10000;
  static const int kIncrementN = 100;
  static const int k1 = 5, k2 = 10, k3 = 100;

  static const int kNoMeasurements = 5;

  Profiler p_;
};

#endif //LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_
