//
// Created by Bori on 11/3/2020.
//

#include <iostream>
#include <assert.h>
#include "hash_table.h"

using namespace std;

template<class K, class V, class Hasher>
HashTable<K, V, Hasher>::HashTable() {
  for (int i = 0; i <kTableSize; i++) {
    v[i] = nullptr;
  }
}

template<class K, class V,  class Hasher>
bool HashTable<K, V, Hasher>::search(K key, int* no_probes) {
  bool found = false;
  int hashcode = hasher_(key);
  for (int i = 0; i < kTableSize; i++) {
    (*no_probes)++;
    int probe_index = hash(hashcode, i);
    if (v[probe_index] == nullptr) {
      return false;
    } else if (v[probe_index]->key == key) {
      return true;
    }
  }
  return false;
}

template<class K, class V, class Hasher>
V* HashTable<K, V, Hasher>::get(K key) {
  int hashcode = hasher_(key);
  for (int i = 0; i < kTableSize; i++) {
    int probe_index = hash(hashcode, i);
    if (v[probe_index] == nullptr) {
      return nullptr; // not found
    } else if (v[probe_index]->key == key) {
      return &v[probe_index]->value;
    }
  }
  return nullptr;
}


template<class K, class V, class Hasher>
void HashTable<K, V, Hasher>::insert(K key, V value) {
  bool inserted = false;
  int hashcode = hasher_(key);
  for (int i = 0; i < kTableSize && !inserted; i++) {
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
  return (abs(h) + kC1*i + kC2*i*i) % kTableSize;
}

template<class K, class V, class Hasher>
void HashTable<K, V, Hasher>::printContent() {
  for (int i = 0; i < kTableSize; i++) {
    if (v[i] != nullptr) {
      cout << i << ": " << *v[i] << endl;
    }
  }
}

template class HashTable<int, string, hash<int>>;
template class HashTable<string, int, hash<string>>;

