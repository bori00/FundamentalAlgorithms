//
// Created by Bori on 11/3/2020.
//

#include "entry.h"
#include <cstring>
#include <algorithm>

using namespace std;

Entry::Entry(int id, char *name) {
  this->id_ = id;
  for (int i = 0; i < min(29, (int) strlen(name)); i++) {
    this->name_[i] = name[i];
  }
  this->name_[min(29, (int) strlen(name))] = '\0';
}

bool operator==(const Entry &e1, const Entry &e2) {
  return e1.id_ == e2.id_;
}

int Entry::getId() const {
  return this->id_;
}

char *Entry::getName() const {
  char* result = (char*) malloc(sizeof(char)*(strlen(this->name_)+1));
  for (int i = 0; i <= strlen(this->name_); i++) {
    result[i] = this->name_[i];
  }
  return result;
}
