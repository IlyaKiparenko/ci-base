#pragma once

#include "HRecord.h"
#include <iostream>

using namespace std;

template<class Key, class Data>
class HashTable {
public:
  HRecord<Key, Data>* m;
  int size;
  int step;
  HashTable(int size_, int step_);
  void add(Key key_, Data& data_);
  void add(HRecord<Key, Data>& t);
  void del(Key key_);
  void print(ostream& os);
  ~HashTable();
};

int HashFunc(int key, int size);
int HashFunc(char* key, int size);