//
// Created by Bori on 11/1/2020.
//

#ifndef LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_
#define LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_

#include "list.h"
class ListMergerEvaluator {
 public:
  void EvaluateConstantK(int k);

  void EvaluateConstantN();

 private:
  static List<int>** GenerateLists(int n, int k, Operation* op_assign, Operation*
  op_pointer_assign);

  int kConstN = 10000;
  int kMinK = 10;
  int kMaxK = 500;
  int kIncrementK = 10;

  int kMinN = 100;
  int kMaxN = 10000;
  int kIncrementN = 100;

  int kNoMeasurements = 5;
};

#endif //LAB4_KWAYMERGE__LIST_MERGER_EVALUATOR_H_
