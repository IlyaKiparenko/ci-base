#ifndef SOLUTIONS_PHEAP_PHEAP_H_
#define SOLUTIONS_PHEAP_PHEAP_H_



class PHeap {
 public:
  int* m;
  int* index;
  int* re_index;
  int size;
  int max_size;
  int d;
  PHeap();
  explicit PHeap(int size, int d = 2);
  void transp(int i, int j);
  void vdown(int i);
  void vup(int i);
  int min_pop();
  int min_top();
  void chg_rank(int new_rank, int index_);
  int get_rank(int index_);
  void push(int rank, int index_);
  void print();
  ~PHeap();
};

#endif  // SOLUTIONS_PHEAP_PHEAP_H_
