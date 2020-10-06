//
// Created by Bori on 10/6/2020.
//

#include <stdlib.h>
#include <iostream>
#include "SorterEvaluator.h"

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
