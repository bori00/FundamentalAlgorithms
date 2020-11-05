//
// Created by Bori on 11/3/2020.
//

#ifndef LAB5_HASHTABLE__HASH_TABLE_H_
#define LAB5_HASHTABLE__HASH_TABLE_H_

template<class K, class V, class Hasher>
class HashTable {
 public:
  HashTable();

  void insert(K k, V v);

  bool search(K k);

 private:
  class Entry {
   public:
    K key;
    V value;
  };

  int hash(int h, int i);

  static const int kC1 = 1;
  static const int kC2 = 1;
  static const int kSize = 9973;

  Hasher hasher_;
  Entry* v[kSize];
};
#endif //LAB5_HASHTABLE__HASH_TABLE_H_
