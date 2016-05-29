#include "HashTable.h"
#include <fstream>

template<class Key, class Data>
HashTable<Key, Data>::HashTable(int size_, int step_, HashFunc hash_) {
  size = size_;
  step = step_;
  hash = hash_;
  m = new HRecord<Key, Data>*[size];
  for (int i = 0; i < size; i++)
    m[i] = 0;
}

template<class Key, class Data>
int HashTable<Key, Data>::find1(Key key_) {
  int start = hash(key_, size);
  if (m[start] == 0) {
    return start;
  } else {
    int c = start;
    do {
      c = (c + step) % size;
    } while (m[c] != 0 && c != start);
    if (c == start)
      return -1;
    else
      return c;
  }
}

template<class Key, class Data>
int HashTable<Key, Data>::find2(Key key_) {
  int start = hash(key_, size);
  bool d = false;
  d = (m[start] == 0);
  if (!d)
    d = (m[start]->h_key == key_);
  if (d) {
    return start;
  } else {
      int c = start;
      do {
        c = (c + step) % size;
        d = (m[c] == 0);
        if (!d)
          d = (m[c]->h_key != key_);
      } while (d && c != start);
      if (c == start)
        return -1;
      else
        return c;
  }
}
template<class Key, class Data>
void HashTable<Key, Data>::add(Key key_, Data data_) {
  cout << "Add " << key_ << " " << data_ << endl;
  int place = find1(key_);
  if (place != -1) {
     m[place] = new HRecord<Key, Data>(key_, data_);
  } else {
    throw "Size Error!";
  }
}

template<class Key, class Data>
void HashTable<Key, Data>::del(Key key_) {
  cout << "Del [" << key_ <<"]"<< endl;
  int place = find2(key_);
  if (place != -1) {
     delete m[place];
     m[place] = 0;
  } else {
    throw "Not Found!";
  }
}

template<class Key, class Data>
void HashTable<Key, Data>::print(ostream* os) {
  for (int i = 0; i < size; i++) {
    if (m[i] == 0) {
      (*os) << "state=FREE     key=0      data=0\n";
    } else {
      (*os) << "state=BUSY\tkey=" << m[i]->h_key;
      (*os) << "\tdata=" << m[i]->h_data << "\n";
    }
  }
}

template<class Key, class Data>
inline void HashTable<Key, Data>::doOperationFile
                  (string in_file, string out_file) {
  ifstream f(in_file.c_str());
  char op[4];
  char s[80];
  Key key_;
  Data data_;
  f.getline(s, 80);
  while (!f.eof()) {
    f >> op;
    if (op[0] == 'A') {
      f >> key_ >> data_;
      add(key_, data_);
    } else {
      f >> key_;
      del(key_);
    }
  }
  f.close();
  ofstream out(out_file.c_str());
  print(&out);
  out.close();
}

template<class Key, class Data>
HashTable<Key, Data>::~HashTable() {
  for (int i = 0; i < size; i++)
    delete m[i];
  delete[] m;
}
