//
// Created by Bori on 10/6/2020.
//

#ifndef LAB1_SORTING_SORTEREVALUATOR_H
#define LAB1_SORTING_SORTEREVALUATOR_H


class SorterEvaluator {
public:
    SorterEvaluator();
    void evaluate();
    void addSorter(Sorter* sorter);

private:
    void evaluateBestCase();
    void evaluateWorstCase();
    void evaluateAvreageCase();
    void evaluateCase(int no_tests, int order);

    Sorter* sorters;
    static int NO_TESTS_AVERAGE_CASE = 5;
    static int MAX_NO_SORTERS = 10;
};


#endif //LAB1_SORTING_SORTEREVALUATOR_H
