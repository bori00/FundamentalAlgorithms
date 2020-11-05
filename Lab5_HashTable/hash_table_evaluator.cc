//
// Created by Bori on 11/5/2020.
//

#include <iostream>
#include <cmath>
#include <cassert>
#include "hash_table_evaluator.h"
#include "hash_table.h"
#include "Profiler.h"

using namespace std;

void HashTableEvaluator::Evaluate() {
  for (float kLoadFactor : kLoadFactors) {
    EvaluateWithLoadFactor(kLoadFactor);
  }
}

void HashTableEvaluator::EvaluateWithLoadFactor(float load_factor) {
  HashTable<int, string, hash<int>>  hash_table;
  int no_elements = ceil((float)HashTable<int, string, hash<int>>::kTableSize * load_factor);
  int keys[no_elements+kSearchedNotFoundElements];
  FillRandomArray(keys, no_elements+kSearchedNotFoundElements, -100000, 100000, true);
  FillTable(keys, no_elements, &hash_table);
  int found_indexes[kSearchFoundElements];
  FillRandomArray(found_indexes, kSearchFoundElements, 0, no_elements - 1, true);
  int total_probes = 0, max_probes = 0;
  for (int found_index : found_indexes) {
    int probes = 0;
    bool found = hash_table.search(keys[found_index], &probes);
    assert(found);
    total_probes += probes;
    max_probes = max(probes, max_probes);
  }
  for (int i = no_elements; i < no_elements + kSearchedNotFoundElements; i++) {
    int probes = 0;
    bool found = hash_table.search(keys[i], &probes);
    assert(!found);
    total_probes += probes;
    max_probes = max(probes, max_probes);
  }
  float avg_probes = (float ) total_probes / (kSearchFoundElements + kSearchedNotFoundElements);
  cout << "Load factor " << load_factor << " " << " no_elements " << no_elements << " " <<
  avg_probes <<
  " " <<
  max_probes <<
  endl;
}

void HashTableEvaluator::FillTable(int *keys,
                                   int no_elements,
                                   HashTable<int, string, hash<int>> *hash_table) {
  for (int i = 0; i < no_elements; i++) {
    hash_table->insert(keys[i], "");
  }
}


