#include <iostream>
#include "SelectionSorter.h"
#include "SorterEvaluator.h"
#include "gtest/gtest.h"
#include "BubbleSorter.h"
#include "InsertionSorter.h"

int main(int argc, char* argv[]) {
    SorterEvaluator sorterEvaluator;
    SelectionSorter selectionSorter;
    sorterEvaluator.addSorter(&selectionSorter);
    BubbleSorter bubbleSorter;
    sorterEvaluator.addSorter(&bubbleSorter);
    InsertionSorter insertionSorter;
    sorterEvaluator.addSorter(&insertionSorter);
    sorterEvaluator.evaluate();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}