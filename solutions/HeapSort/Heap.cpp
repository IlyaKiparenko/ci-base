#include "Heap.h"

Heap::Heap() {}

Heap::Heap(int size_, int d_) {
  m = new int[size_];
  max_size = size_;
  size = 0;
  d = d_;
}
void Heap::transp(int i, int j) {
  int t = m[i];
  m[i] = m[j];
  m[j] = t;
}
void Heap::vdown(int i) {
  if (i*d+1 < size) {
    int min;
    int imin;
    bool b;
    do {
      min = m[i*d + 1];
      imin = i*d + 1;
      b = false;
      for (int j = i*d + 2; (j <= i*d + d && j < size); j++) {
        if (m[j] < min) {
          imin = j;
          min = m[j];
        }
      }
      if (m[i] > min) {
        transp(i, imin);
        i = imin;
        b = true;
      }
    } while (i*d+1 < size && b);
  }
}

void Heap::vup(int i) {
  while (i > 0 && m[i] < m[(i - 1)/d]) {
    transp(i, (i - 1)/d);
    i = (i - 1)/d;
  }
}

int Heap::min_pop() {
  transp(0, size - 1);
  size--;
  vdown(0);
  return(m[size]);
}

void Heap::push(int i) {
  if (size - 1 < max_size) {
    m[size] = i;
    size++;
    vup(size - 1);
  }
}

Heap::~Heap() {
  delete[] m;
}

void Heap::HeapSort(int* ar, int size, int d) {
  Heap h;
  h.size = size;
  h.max_size = size;
  h.d = d;
  h.m = ar;
  for (int i = 0; i < size; i++) {
    h.vup(i);
  } 
  for (int i = 0; i < size; i++) {
    h.min_pop();
  } 
  h.m = new int[1];
}
