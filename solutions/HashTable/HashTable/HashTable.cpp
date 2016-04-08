#include "HashTable.h"


template<class Key, class Data>
HashTable::HashTable(int size_) {
  size = size_;
  step = step_;
  m = new HRecord<Key, Data>[size];
}

template<class Key, class Data>
void HashTable::add(Key key_, Data& data_) {
  int u = HashFunc(key_, size);
  if (m[u] != 0)
    m[u] = new HRecord<Key, Data>(key_, data_);
  else {
    int y = u;
    do { 
      u = (u + step) % size;
      y += step;
    } while (m[u] == 0 && y !=u);
    if (y != u)
      m[u] = new HRecord<Key, Data>(key_, data_);
  }
}

template<class Key, class Data>
void HashTable::del(Key key_) {
  int u = HashFunc(key_, size);
  if (m[u] != 0)
    m[u] = 0;
  else {
    int y = u;
    do { 
      u = (u + step) % size;
      y += step;
    } while (m[u] == 0 && y !=u);
    if (y != u)
      m[u] = 0;
  }
}

template<class Key,class Data>
void HashTable::print(ostream& os) {
  for (int i = 0; i < size; i++) {
    if (m[i] == 0)
      cout << "state=FREE     key=0      data=0\n";
    else
      cout << "state=BUSY     key=" << m[i].h_key << "      data=" << m[i].h_data << "\n";
  }
}
template<class Key, class Data>
HashTable::~HashTable() {
  delete[] m;
}

int HashFunc(int key_, int size_) {
  return key_ % size_;
}

int HashFunc(char* key_, int size_) {
  int l = 0;
  while(key_[l] != 0)
    l++;
  return l % size_;
}