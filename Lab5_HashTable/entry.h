//
// Created by Bori on 11/3/2020.
//

#ifndef LAB5_HASHTABLE__ENTRY_H_
#define LAB5_HASHTABLE__ENTRY_H_

#include <stdlib.h>
#include <functional>

class Entry {
 public:
  Entry(int id, char* name);

  friend bool operator ==(const Entry& e1, const Entry& e2);

  int getId() const;

  char* getName() const;

 private:
  int id_;
  char name_[30];
};

class EntryHasher
{
 public:
  std::size_t operator()(const Entry e) const
  {
    using std::size_t;
    using std::hash;

    return (hash<std::string>()(e.getName()));
  }
};


#endif //LAB5_HASHTABLE__ENTRY_H_
