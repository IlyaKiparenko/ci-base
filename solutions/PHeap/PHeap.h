#ifndef SOLUTIONS_PHEAP_PHEAP_H_
#define SOLUTIONS_PHEAP_PHEAP_H_

#include "P_Queue.h"

class PHeap : public P_Queue {
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
  void changePriority(int new_rank, int index_);
  int getRank(int index_);
  void add(int rank, int index_);
  void print();
  ~PHeap();
};

#endif  // SOLUTIONS_PHEAP_PHEAP_H_
