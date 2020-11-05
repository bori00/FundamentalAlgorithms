//
// Created by Bori on 11/3/2020.
//

#ifndef LAB5_HASHTABLE__HASH_TABLE_H_
#define LAB5_HASHTABLE__HASH_TABLE_H_

template<class T>
class HashTable {
 public:
  HashTable();

  void insert(T t);

  bool search(T t);

 private:
  int hash(int h, int i);

  static const int kC1 = 1;
  static const int kC2 = 1;
  static const int kSize = 9973;
  T v[kSize];
};
#endif //LAB5_HASHTABLE__HASH_TABLE_H_
