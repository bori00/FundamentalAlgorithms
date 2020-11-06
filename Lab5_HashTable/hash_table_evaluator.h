//
// Created by Bori on 11/5/2020.
//

#ifndef LAB5_HASHTABLE__HASH_TABLE_EVALUATOR_H_
#define LAB5_HASHTABLE__HASH_TABLE_EVALUATOR_H_

#include <string>
#include "hash_table.h"

using namespace std;

class HashTableEvaluator {
 public:
  void Evaluate();

 private:
  void EvaluateWithLoadFactor(float load_factor);

  void FillTable(int keys[],  int no_elements, HashTable<int, string, hash<int>>* hash_table);

  void printEvaluationResult(float load_factor, double avg_effort_found, int max_effort_found,
      double avg_effort_not_found, int max_effort_not_found);

  static const int kSearchedFoundElements = 1500;
  static const int kSearchedNotFoundElements = 1500;
  static const int kNoLoadFactors = 7;
  static const int kNoRepetitions = 5;
  const string kOutputFileName = "evaluation.csv";
  float kLoadFactors[kNoLoadFactors] = {0.6, 0.7, 0.8, 0.85, 0.9, 0.95, 0.99};
};

#endif //LAB5_HASHTABLE__HASH_TABLE_EVALUATOR_H_
