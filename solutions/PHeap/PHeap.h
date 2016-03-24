#ifndef SOLUTIONS_PHEAP_PHEAP_H_
#define SOLUTIONS_PHEAP_PHEAP_H_



class PHeap {
 public:
  int* m;
  int* index;
  int size;
  int max_size;
  int d;
  PHeap();
  explicit PHeap(int size, int d = 2);
  void transp(int i, int j);
  void vdown(int i);
  void vup(int i);
  int min_pop();
  void push(int rank, int index_);
  void print();
  ~PHeap();
};

#endif  // SOLUTIONS_PHEAP_PHEAP_H_
