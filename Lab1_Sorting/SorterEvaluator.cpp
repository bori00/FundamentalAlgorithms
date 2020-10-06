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
    // todo: remove testing
    cout << "Initialised: " + sorters[no_sorters]->message << endl;
    cout << "First: " + sorters[0]->message << endl;
    int v[5] = {1, 4, 2, 6, 4};
    sorters[no_sorters]->sort(v, 5);
    cout << "test sort done" << endl;
    for(int i = 0; i < no_sorters; i++)
        sorters[i]->sort(v, 5);
    no_sorters++;
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
                cout << "evauluate case " << order << ", test nr. " << test << " sorter nr. " << i << " with assign op: " << sorters[i]->message << endl;
                sorters[i]->sort(u, size);
            }
        }
    }
}
