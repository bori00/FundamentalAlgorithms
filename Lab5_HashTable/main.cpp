#include <iostream>
#include "hash_table.h"
#include "hash_table_evaluator.h"
#include "gtest/gtest.h"

using namespace std;

void demo1();

void demo2();

int main(int argc, char *argv[]) {
  demo1();
  demo2();
  HashTableEvaluator hash_table_evaluator;
  hash_table_evaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void demo1() {
  int no_elements = 8;
  int keys[8] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  string values[8] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                      "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  cout << "------------ Demo1: ------------" << endl;
  hash_table.printContent();
}

void demo2() {
  int no_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                                                                        "twohundredninetyeight"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  cout << "------------ Demo2: ------------" << endl;
  hash_table.printContent();
}