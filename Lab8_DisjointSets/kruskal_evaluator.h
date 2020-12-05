//
// Created by Bori on 12/5/2020.
//

#ifndef LAB8_DISJOINTSETS__KRUSKAL_EVALUATOR_H_
#define LAB8_DISJOINTSETS__KRUSKAL_EVALUATOR_H_

#include "Profiler.h"
class KruskalEvaluator {
 public:
  static void Evaluate();

 private:
  static const int kMinGraphSize = 100;
  static const int kMaxGraphSize = 10000;
  static const int kStepSize = 100;
  static const int kNoRepetitions = 5;
  static const char* sort_op_name;
  static const char* make_set_op_name;
  static const char* find_set_op_name;
  static const char* union_op_name;
  static const char* other_op_name;

};

#endif //LAB8_DISJOINTSETS__KRUSKAL_EVALUATOR_H_
