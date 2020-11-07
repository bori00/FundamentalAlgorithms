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

/**
 * Task:
 * Implement the insert and search operations in a hash table using open addressing and quadratic
 * probing.
 *
 * Solution:
 * -- General considerations for the implementation
 * For the implementation I used the well-known algorithm of open-addressing, with a hashfunction
 * depending both on the hash code of the inserted key and on the index of the probe(i).
 * For the underlying table I used an array of size 10007, empty slots are marked with nullptr.
 * The generic quadratic hashfunction looks as:
 * h(hashcode, i) = (hashcode + k1*i + k2 *i^2) mod 10007,
 * where k1 and k2 are constants. In an ideal case the permutation of h(hashcode, i) for i = 0.
 * .10006 we should get a permutation of the indexes 0...10006. In practice, I tried out many
 * different k1 and k2 constants, and chose the ones with the lowest average number of probes
 * required for searching.
 * In the table I stored objects of type Entry, which contains both the key and the value.
 * The HashTable is generic, meaning that the keys and the values can be of any type, but the
 * client has to define the function for computing the hashcode of the keys. This must be a
 * class/struct which overrides operator(). For primitives, hash<type> can be used.
 *
 * -- The algorithm
 * 1. Insertion
 * The new (key, value) pair is inserted in the table for the first still empty slot in the
 * underlying table defined by the probe sequence by the hashfunction for the hashcode of the key,
 * and for i (= probe index) increasing from 0 to 10006. Remark that the table allows for
 * overriding previous values, if the same key is inserted with a different key.
 * 2. Searching
 * Every slot defined by the probe sequence is tried. If the element on that slot has the key
 * equal to the searched one, than the element is found, the function returns true. If an empty
 * slot is found, it means that the key is not present in the table, so false is returned.
 * Note that the probe sequence is the same as for inserting.
 * 3. Find: returns the value corresponding to a key
 * Exploits the same idea as searching, but if the key is found, than its value is returned.
 * Othwerise, a nullptr is returned.
 *
 * -- Evaluation
 * The HashTableEvaluator evaluates the performance of searching, measured as the number of
 * probes required for finding an element(if present)/required for deciding that the element is
 * not present in the table, if that is the case.
 * The keys used for the evaluation are integers in range [-1 million, 1 million], all unique and
 * randomly generated. Except 1500 keys, all are inserted into the table.
 * The remaining 1500 keys are then used to evaluate searching for a key which is not present in
 * the table. Since the elements were all uniwue, these keya are for sure not present in the table.
 * For evaluating search for keys present in the table, I generated a new sequence of random
 * indexes between 0 and the number of elements inserted in the key. The keys on these indexes
 * are used to evaluate searching for existing keys. --> the keys are uniformly
 * distributed in the array of inserted keys.
 * The evaluation is performed five times on different load factors.
 *
 * -- Interpretation
 * Based on the results we can draw the conclusion that
 * a) for elements present on the array, the average number of probes for searching is nearly
 * constant. Even for load factor of 99%, i.e. for ~10000 elements inserted into an array of size
 * 10007, the average number of probes is <= 5, and this number seems to grow really slowly.
 * These values correspond to the ones deduced in the textbook:
 * -> for load factor a=0.8 = 4/5, we expect avg number of probes = 1/a * ln (1/(1-a)) = 5/4 * ln
 * 5 = 2.9, whereas my results show 2.03
 * -> for load factor a=0.99 = 99/100 we expect 1/a * ln (1/(1-a)) = 100/99 * ln 100 = 6.7,
 * whereas my results show 4.51
 * The maximum number of probes reaches ~400, but if the searches are frequent, then we don't
 * really care about the maximum, the average is much more significant.
 * b) for unsuccesful search operations, both the average and the maximum number of probes is
 * much higher than for succesful searches. For a load factor of 99%, the average is ~100,
 * compared to ~5.5 for load factor 0.8. We can remark, that the number of probes grows much
 * faster than for successful searches.
 * Moreover, the values correspond to the ones expected bases on the formula in the textbook.
 * -> for a=0.8, 5.5 ~= 1/1-a = 1/(1/5) = 5
 * -> for a=0.99, 100 ~= 1/1-a = 1/(1/100) = 100
 *
 * All in all I would say that the conclusions we draw about all operations for the hash table
 * having a constant amortized complexity is true, but we should be really careful with chosing
 * an appropriate load factor. Based on the average number of probes for unsuccesful searches I
 * would strongly recommend against using a load factor above 0.85-0.9, because the number of
 * probes seems to be growing faster than linear above this value. Moreover, above a load factor
 * of 0.9 we can anyway expect the hash table to be completely filled, so we can't avoid resizing.
 */

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