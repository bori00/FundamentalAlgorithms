#include <iostream>
#include "SelectionSorter.h"
#include "SorterEvaluator.h"
#include "gtest/gtest.h"
#include "BubbleSorter.h"
#include "InsertionSorter.h"

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