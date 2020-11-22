//
// Created by Bori on 11/22/2020.
//

#ifndef LAB7_DYNORDERSTATISTICS__OS_TREE_EVALUATOR_H_
#define LAB7_DYNORDERSTATISTICS__OS_TREE_EVALUATOR_H_

#include "Profiler.h"

class OSTreeEvaluator {
 public:
  static void Evaluate();

 private:
  static const int kMinSize = 100, kMaxSize = 10000;
  static const int kStepSize = 100;
  static const int kNoTests = 5;
};

#endif //LAB7_DYNORDERSTATISTICS__OS_TREE_EVALUATOR_H_
