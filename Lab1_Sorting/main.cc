#include <iostream>
#include "selection_sorter.h"
#include "sorter_evaluator.h"
#include "gtest/gtest.h"
#include "bubble_sorter.h"
#include "insertion_sorter.h"

int main(int argc, char *argv[]) {
  SorterEvaluator sorterEvaluator;
  SelectionSorter selectionSorter;
  sorterEvaluator.AddSorter(&selectionSorter);
  BubbleSorter bubbleSorter;
  sorterEvaluator.AddSorter(&bubbleSorter);
  InsertionSorter insertionSorter;
  sorterEvaluator.AddSorter(&insertionSorter);
  sorterEvaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}