#ifndef UTILS_HEAPSORT_HEAP_H_
#define UTILS_HEAPSORT_HEAP_H_

#include <stdio.h>

class Heap {
 public:
  int* m;
  int size;
  int max_size;
  int d;
  Heap();
  Heap(int size, int d = 2);
  void transp(int i, int j);
  void vdown(int i);
  void vup(int i);
  int min_pop();
  void push(int i);
  void print() {
    for (int i = 0; i < size; i++) {
      printf("%4i ", m[i]);
    }
    printf("\n");
  }
  static void HeapSort(int* ar, int n, int d);
  ~Heap();
};

#endif //UTILS_HEAPSORT_HEAP_H_