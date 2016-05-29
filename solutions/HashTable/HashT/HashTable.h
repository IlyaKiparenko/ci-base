#ifndef SOLUTIONS_HASHTABLE_HASHT_HASHTABLE_H_
#define SOLUTIONS_HASHTABLE_HASHT_HASHTABLE_H_

#include "HRecord.h"
#include "HRecord.cpp"
#include <iostream>
#include <sstream>

using namespace std;

template<class Key, class Data>
class HashTable {
public:
  typedef int (*HashFunc) (Key&, int);
  HashFunc hash;
  HRecord<Key, Data>** m;
  int size;
  int step;
  HashTable(int size_, int step_, HashFunc hash_);
  void add(Key key_, Data data_);
  void add(HRecord<Key, Data>& t);
  int find1(Key key_);
  int find2(Key key_);
  void del(Key key_);
  void print(ostream& os);
  void doOperationFile(string in_file, string out_file);
  ~HashTable();
};

#endif  // SOLUTIONS_HASHTABLE_HASHT_HASHTABLE_H_
