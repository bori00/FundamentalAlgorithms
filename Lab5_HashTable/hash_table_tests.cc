//
// Created by Bori on 11/7/2020.
//

#include "gtest/gtest.h"
#include "string"
#include "hash_table.h"

using namespace std;

TEST(HashTable, InsertIntStringElements) {
  int no_elements = 9;
  int keys[9] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  string values[9] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                                                                    "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
}

TEST(HashTable, InsertStringIntElements) {
  int no_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour, "
                                                                          "twohundredninetyeight"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
}

TEST(HashTable, SearchExistingIntStringElements) {
  int no_elements = 9;
  int keys[9] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  string values[9] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                      "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_elements; i++) {
    int no_probes = 0;
    EXPECT_TRUE(hash_table.search(keys[i], &no_probes));
  }
}

TEST(HashTable, SearchExistingStringIntElements) {
  int no_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour, "
                                                                        "twohundredninetyeight"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_elements; i++) {
    int no_probes = 0;
    EXPECT_TRUE(hash_table.search(keys[i], &no_probes));
  }
}

TEST(HashTable, SearchNotExistingIntStringElements) {
  int no_elements = 9, no_not_elements = 4;
  int keys[9] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  int not_keys[4] = {7, -387, 105, 20019};
  string values[9] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                      "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_not_elements; i++) {
    int no_probes = 0;
    EXPECT_FALSE(hash_table.search(not_keys[i], &no_probes));
  }
}

TEST(HashTable, SearchNotExistingStringIntElements) {
  int no_elements = 5, no_not_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour, "
                                                                        "twohundredninetyeight"};
  string not_keys[5] = {"a", "aa", "abc", "abcd", "ada"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_not_elements; i++) {
    int no_probes = 0;
    EXPECT_FALSE(hash_table.search(not_keys[i], &no_probes));
  }
}

TEST(HashTable, GetExistingIntStringElements) {
  int no_elements = 9;
  int keys[9] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  string values[9] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                      "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_elements; i++) {
    EXPECT_EQ(values[i], *hash_table.get(keys[i]));
  }
}

TEST(HashTable, GetExistingStringIntElements) {
  int no_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour, "
                                                                        "twohundredninetyeight"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_elements; i++) {
    EXPECT_EQ(values[i], *hash_table.get(keys[i]));
  }
}

TEST(HashTable, GetNotExistingIntStringElements) {
  int no_elements = 9, no_not_elements = 4;
  int keys[9] = {5, 101, 387, 1004, 298, 10012, -101, 10108};
  int not_keys[4] = {7, -387, 105, 20019};
  string values[9] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                      "twohundredninetyeight", "tenthousandtwelve", "minusonehundredone",
                      "tenthousandonehundredeight"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_not_elements; i++) {
    int no_probes = 0;
    EXPECT_EQ(nullptr, hash_table.get(not_keys[i]));
  }
}

TEST(HashTable, GetNotExistingStringIntElements) {
  int no_elements = 5, no_not_elements = 5;
  int values[5] = {5, 101, 387, 1004, 298};
  string keys[5] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour, "
                                                                        "twohundredninetyeight"};
  string not_keys[5] = {"a", "aa", "abc", "abcd", "ada"};
  HashTable<string, int, hash<string>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < no_not_elements; i++) {
    int no_probes = 0;
    EXPECT_EQ(nullptr, hash_table.get(not_keys[i]));
  }
}

TEST(HashTable, GetOverridenStringElements) {
  int no_elements = 6;
  int keys[6] = {5, 101, 387, 1004, 298, 101};
  string values[6] = {"five", "onehundredone", "threehundredeightyseven", "onethousandfour",
                                                                        "twohundredninetyeight",
                                                                        "overriden"};
  HashTable<int, string, hash<int>> hash_table;
  for (int i = 0; i < no_elements; i++) {
    hash_table.insert(keys[i], values[i]);
  }
  string expected_result = "overriden";
  EXPECT_EQ(expected_result, *hash_table.get(101));
}

