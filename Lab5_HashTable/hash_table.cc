//
// Created by Bori on 11/3/2020.
//

#include <iostream>
#include "hash_table.h"

using namespace std;

template<class T>
HashTable<T>::HashTable() {
  for (int i = 0; i <kSize; i++) {
    v[i] = nullptr;
  }
}

template<class T>
bool HashTable<T>::search(T t) {
  bool found = false;
  // todo
  int hashcode = 3;
  for (int i = 0; i < kSize && !found; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] == t) {
      found = true;
    }
  }
  return found;
}

template<class T>
void HashTable<T>::insert(T t) {
  bool inserted = false;
  // todo
  int hashcode = 3;
  for (int i = 0; i < kSize && !inserted; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] == nullptr) {
      v[probe_index] = t;
      inserted = true;
    }
  }
  if (!inserted) {
    cerr << "Error: no empty slot left for element " << t << endl;
    exit(1);
  }
}

template<class T>
int HashTable<T>::hash(int h, int i) {
  return (h + kC1*i + kC2 *i) % kSize;
}

