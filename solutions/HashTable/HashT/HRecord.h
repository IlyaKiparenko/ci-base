#ifndef SOLUTIONS_HASHTABLE_HASHT_HRECORD_H_
#define SOLUTIONS_HASHTABLE_HASHT_HRECORD_H_

template<class Key, class Data>
class HRecord {
public:
  Key h_key;
  Data h_data;
  HRecord();
  HRecord(Key key_, Data& data);
  HRecord(const HRecord& t);
  ~HRecord();
};

#endif  // SOLUTIONS_HASHTABLE_HASHT_HRECORD_H_
