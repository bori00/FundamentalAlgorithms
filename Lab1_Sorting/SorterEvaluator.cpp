//
// Created by Bori on 10/6/2020.
//

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <assert.h>
#include "SorterEvaluator.h"

using namespace std;

SorterEvaluator::SorterEvaluator() : p("sorting"){
    no_sorters = 0;
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
    sorters[no_sorters] = sorter;
    no_sorters++;
}

void SorterEvaluator::evaluateWorstCase() {
    evaluateCase(NO_TESTS_AVERAGE_CASE, DESCENDING, "WorstCase");
}

void SorterEvaluator::evaluateBestCase() {
    evaluateCase(1, ASCENDING, "BestCase");
}

void SorterEvaluator::evaluateAverageCase() {
    evaluateCase(1, UNSORTED, "AverageCase");
}

void SorterEvaluator::evaluateCase(int no_tests, int order, char* title) {
    p.reset(title);
    int v[MAX_ARRAY_SIZE];
    int u[MAX_ARRAY_SIZE];
    for (int size = MIN_ARRAY_SIZE; size <= MAX_ARRAY_SIZE; size += STEP_SIZE) {
        for (int test = 0; test < no_tests; test++) {
            FillRandomArray(v, size, 1, 500000, false, order);
            for (int i = 0; i < no_sorters; i++) {
                // todo change to memcpy
                mempcpy(&u, &v, size * sizeof(v[0]));
                cout << "evauluate case " << order << " size " << size << ", test nr. " << test << " sorter nr. " << i << endl;
                sorters[i]->sort(u, size, p);
                assert(SorterEvaluator::isSorted(u, size));
            }
        }
    }
    for (int i = 0; i < no_sorters; i++) {
        p.divideValues(sorters[i]->getCompOpName(), no_tests);
        p.divideValues(sorters[i]->getAssignOpName(), no_tests);
        // p.addSeries("v" + i, sorters[i]->getCompOpName(), sorters[i]->getAssignOpName());
    }
    p.showReport();
}

bool SorterEvaluator::isSorted(int* v, int no_elements) {
    for (int i = 0; i < no_elements - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}
