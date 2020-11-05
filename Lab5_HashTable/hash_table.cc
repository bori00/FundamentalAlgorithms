//
// Created by Bori on 11/3/2020.
//

#include <iostream>
#include "hash_table.h"

using namespace std;

template<class K, class V, class Hasher>
HashTable<K, V, Hasher>::HashTable() {
  for (int i = 0; i <kSize; i++) {
    v[i] = nullptr;
  }
}

template<class K, class V,  class Hasher>
bool HashTable<K, V, Hasher>::search(K key) {
  bool found = false;
  int hashcode = hasher_(key);
  for (int i = 0; i < kSize && !found; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] != nullptr && v[probe_index]->key == key) {
      found = true;
    }
  }
  return found;
}

template<class K, class V, class Hasher>
void HashTable<K, V, Hasher>::insert(K key, V value) {
  bool inserted = false;
  int hashcode = hasher_(key);
  for (int i = 0; i < kSize && !inserted; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] == nullptr || v[probe_index]->key == key) {
      v[probe_index] = new Entry(key, value);
      inserted = true;
    }
  }
  if (!inserted) {
    cerr << "Error: no empty slot left for element " << key << " " << value << endl;
    exit(1);
  }
}

template<class K, class V, class Hasher>
int HashTable<K, V, Hasher>::hash(int h, int i) {
  return (h + kC1*i + kC2 *i) % kSize;
}

template class HashTable<int, string, hash<int>>;

