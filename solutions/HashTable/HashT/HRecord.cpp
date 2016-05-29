#include "HRecord.h"
#include <stdio.h>

template<class Key, class Data>
HRecord<Key, Data>::HRecord(Key key_, const Data& data_) {
  h_key = key_;
  h_data = data_;
}

template<class Key, class Data>
HRecord<Key, Data>::HRecord() {
}

template<class Key, class Data>
HRecord<Key, Data>::HRecord(const HRecord<Key, Data>& t) {
  h_key = t.h_key;
  h_data = t.h_data;
}

template<class Key, class Data>
HRecord<Key, Data>::~HRecord() {
}
