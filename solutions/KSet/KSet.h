#ifndef SOLUTIONS_KSET_KSET_H_
#define SOLUTIONS_KSET_KSET_H_



class KSet {
 public:
  int* m;
  int size;
  KSet();
  explicit KSet(int size_);
  void add(int i);
  int whereI(int i);
  void merge(int i, int j);
  void print();
  ~KSet();
};

#endif  // SOLUTIONS_KSET_KSET_H_
