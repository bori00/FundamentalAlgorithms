//
// Created by Bori on 10/6/2020.
//

#ifndef LAB1_SORTING_SORTEREVALUATOR_H
#define LAB1_SORTING_SORTEREVALUATOR_H


#include "Sorter.h"

class SorterEvaluator {
public:
    SorterEvaluator();
    void evaluate();
    void addSorter(Sorter* sorter);

private:
    void evaluateBestCase();
    void evaluateWorstCase();
    void evaluateAverageCase();
    void evaluateCase(int no_tests, int order);

    Sorter** sorters;
    int no_sorters;
    const static int NO_TESTS_AVERAGE_CASE = 5;
    const static int MAX_NO_SORTERS = 10;
};


#endif //LAB1_SORTING_SORTEREVALUATOR_H
