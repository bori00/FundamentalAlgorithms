//
// Created by Bori on 10/6/2020.
//

#include <cstdlib>
#include <string.h>
#include <iostream>
#include "SorterEvaluator.h"
#include "Profiler.h"

using namespace std;

SorterEvaluator::SorterEvaluator(){
    no_sorters = 0;
    sorters = (Sorter**) malloc(sizeof(Sorter*)*MAX_NO_SORTERS);
}

void SorterEvaluator::evaluate() {
    evaluateAverageCase();
    evaluateBestCase();
    evaluateWorstCase();
}

void SorterEvaluator::addSorter(Sorter *sorter) {
    if (no_sorters == MAX_NO_SORTERS) {
        cerr << "Max number of sorters exceeded";
        exit(1);
    }
    no_sorters++;
    sorters[no_sorters] = sorter;
}

void SorterEvaluator::evaluateWorstCase() {
    evaluateCase(NO_TESTS_AVERAGE_CASE, DESCENDING);
}

void SorterEvaluator::evaluateBestCase() {
    evaluateCase(1, ASCENDING);
}

void SorterEvaluator::evaluateAverageCase() {
    evaluateCase(1, UNSORTED);
}

void SorterEvaluator::evaluateCase(int no_tests, int order) {
    int v[MAX_ARRAY_SIZE];
    int u[MAX_ARRAY_SIZE];
    for (int size = MIN_ARRAY_SIZE; size <= MAX_ARRAY_SIZE; size += STEP_SIZE) {
        for (int test = 0; test < no_tests; test++) {
            FillRandomArray(v, size);
            for (int i = 0; i < no_sorters; i++) {
                // todo change to memcpy
                mempcpy(&u, &v, size * sizeof(v[0]));
                cout << "evauluate case " << order << ", test nr. " << test << " sorter nr. " << i << endl;
               // sorters[i]->sort(u, size);
            }
        }
    }
}
