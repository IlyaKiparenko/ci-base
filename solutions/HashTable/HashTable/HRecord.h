#pragma once

template<class Key, class Data>
class HRecord {
public:
  Key h_key;
  Data h_data;
  HRecord(Key key_, Data& data);
  HRecord(const HRecord& t);
  ~HRecord();
};