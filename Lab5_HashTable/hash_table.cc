//
// Created by Bori on 11/3/2020.
//

#include <iostream>
#include "hash_table.h"
#include "entry.h"

using namespace std;

template<class T, class Hasher>
HashTable<T, Hasher>::HashTable() {
  for (int i = 0; i <kSize; i++) {
    v[i] = nullptr;
  }
}

template<class T, class Hasher>
bool HashTable<T, Hasher>::search(T* t) {
  bool found = false;
  int hashcode = hasher_(*t);
  for (int i = 0; i < kSize && !found; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] != nullptr && *v[probe_index] == *t) {
      found = true;
    }
  }
  return found;
}

template<class T, class Hasher>
void HashTable<T, Hasher>::insert(T* t) {
  bool inserted = false;
  int hashcode = hasher_(*t);
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

template<class T, class Hasher>
int HashTable<T, Hasher>::hash(int h, int i) {
  return (h + kC1*i + kC2 *i) % kSize;
}

template class HashTable<Entry, EntryHasher>;

