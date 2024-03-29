//
// Created by Bori on 11/3/2020.
//

#ifndef LAB5_HASHTABLE__HASH_TABLE_H_
#define LAB5_HASHTABLE__HASH_TABLE_H_

#include <iostream>

using namespace std;

template<class K, class V, class Hasher>
class HashTable {
 public:
  HashTable();

  void insert(K key, V value);

  bool search(K key, int* no_probes);

  V* get(K key);

  void printContent();

  static const int kTableSize = 10007;

 private:
  class Entry {
   public:
    K key;
    V value;

    Entry(K key, V value) : key(key), value(value) {}

    friend ostream & operator << (ostream &out, const Entry &e) {
      out << "(k = " << e.key << ", v = " << e.value << ")";
      return out;
    }
  };

  int hash(int h, int i);

  static const int kC1 = 13;
  static const int kC2 = 11;

  Hasher hasher_;
  Entry* v[kTableSize];
};
#endif //LAB5_HASHTABLE__HASH_TABLE_H_
