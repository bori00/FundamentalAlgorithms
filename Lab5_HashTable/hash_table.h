//
// Created by Bori on 11/3/2020.
//

#ifndef LAB5_HASHTABLE__HASH_TABLE_H_
#define LAB5_HASHTABLE__HASH_TABLE_H_

template<class K, class V, class Hasher>
class HashTable {
 public:
  HashTable();

  void insert(K key, V value);

  bool search(K key, int* no_probes);

  static const int kTableSize = 9973;

 private:
  class Entry {
   public:
    K key;
    V value;

    Entry(K key, V value) : key(key), value(value) {}
  };

  int hash(int h, int i);

  static const int kC1 = 1;
  static const int kC2 = 1;

  Hasher hasher_;
  Entry* v[kTableSize];
};
#endif //LAB5_HASHTABLE__HASH_TABLE_H_
