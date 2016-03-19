#ifndef SOLUTIONS_HEAP_HEAP_H_
#define SOLUTIONS_HEAP_HEAP_H_



class Heap {
 public:
  int* m;
  int size;
  int max_size;
  int d;
  Heap();
  explicit Heap(int size, int d = 2);
  void transp(int i, int j);
  void vdown(int i);
  void vup(int i);
  int min_pop();
  void push(int i);
  void print();
  static void HeapSort(int* ar, int n, int d);
  ~Heap();
};

#endif  // SOLUTIONS_HEAP_HEAP_H_
