#include "gtest/gtest.h"
#include "list_merger_evaluator.h"

using namespace std;

int main(int argc, char *argv[]) {
  ListMergerEvaluator list_merger_evaluator;
  list_merger_evaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}