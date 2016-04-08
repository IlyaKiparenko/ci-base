#include "HRecord.h"

template<class Key, class Data>
HRecord::HRecord(Key key_, Data& data_):h_key(key_), h_data(data_) {};

template<class Key, class Data>
HRecord::HRecord(const HRecord<Key, Data>& t) {
  h_key = t.h_key;
  h_data = t.h_data;
}

template<class Key, class Data>
HRecord::~HRecord() { }
