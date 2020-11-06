//
// Created by Bori on 11/5/2020.
//

#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>
#include "hash_table_evaluator.h"
#include "hash_table.h"
#include "Profiler.h"

using namespace std;

void HashTableEvaluator::Evaluate() {
  ofstream g(kOutputFileName);
  // g << "1, 2, 3, 4, 5, 6" << "\n";
  for (float kLoadFactor : kLoadFactors) {
    EvaluateWithLoadFactor(kLoadFactor);
  }
}

void HashTableEvaluator::EvaluateWithLoadFactor(float load_factor) {
  int no_elements = ceil((float) HashTable<int, string, hash<int>>::kTableSize * load_factor);
  int total_probes_found = 0, max_probes_found = 0, total_probes_not_found = 0,
    max_probes_not_found = 0;
  for (int i = 1; i <= kNoRepetitions; i++) {
    HashTable<int, string, hash<int>> hash_table;
    int keys[no_elements + kSearchedNotFoundElements];
    FillRandomArray(keys, no_elements + kSearchedNotFoundElements, -1000000, 1000000, true);
    FillTable(keys, no_elements, &hash_table);
    int found_indexes[kSearchedFoundElements];
    FillRandomArray(found_indexes, kSearchedFoundElements, 0, no_elements - 1, true);
    // search for present elements
    for (int found_index : found_indexes) {
      int probes = 0;
      bool found = hash_table.search(keys[found_index], &probes);
      assert(found);
      total_probes_found += probes;
      max_probes_found = max(probes, max_probes_found);
    }
    // search for elements not present in the table
    for (int i = no_elements; i < no_elements + kSearchedNotFoundElements; i++) {
      int probes = 0;
      bool found = hash_table.search(keys[i], &probes);
      assert(!found);
      total_probes_not_found += probes;
      max_probes_not_found = max(probes, max_probes_not_found);
    }
  }
  double avg_probes_found = (double) total_probes_found / (kSearchedFoundElements * kNoRepetitions);
  double avg_probes_not_found = (double) total_probes_not_found / (kSearchedNotFoundElements *
      kNoRepetitions);
  printEvaluationResult(load_factor, avg_probes_found, max_probes_found, avg_probes_not_found,
      max_probes_not_found);
}

void HashTableEvaluator::FillTable(int *keys,
                                   int no_elements,
                                   HashTable<int, string, hash<int>> *hash_table) {
  for (int i = 0; i < no_elements; i++) {
    hash_table->insert(keys[i], "");
  }
}
void HashTableEvaluator::printEvaluationResult(float load_factor,
                                               double avg_effort_found,
                                               int max_effort_found,
                                               double avg_effort_not_found,
                                               int max_effort_not_found) {
  ofstream g(kOutputFileName, fstream::app);
  g << load_factor << "," << avg_effort_found << "," << max_effort_found << "," <<
    avg_effort_not_found << "," << max_effort_not_found << endl;
}

