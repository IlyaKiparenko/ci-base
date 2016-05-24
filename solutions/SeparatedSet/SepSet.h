#ifndef SOLUTIONS_SEPARATEDSET_SEPSET_H_
#define SOLUTIONS_SEPARATEDSET_SEPSET_H_

class SepSet {
 public:
  int* sets;
  int* h;
  int size;
  SepSet();
  explicit SepSet(int size_);
  void add(int i);
  void merge(int i, int j);
  int whereI(int i);
  bool isAdded(int i);
  void print();
  void clear();
  ~SepSet();
};

#endif  // SOLUTIONS_SEPARATEDSET_SEPSET_H_
