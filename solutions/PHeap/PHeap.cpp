#include "PHeap.h"
#include <stdio.h>
#include <exception>

PHeap::PHeap() {}

PHeap::PHeap(int size_, int d_) {
  m = new int[size_];
  index = new int[size_];
  re_index = new int[size_];
  max_size = size_;
  size = 0;
  d = d_;
}
void PHeap::transp(int i, int j) {
  int t = m[i];
  m[i] = m[j];
  m[j] = t;
  t = index[i];
  index[i] = index[j];
  index[j] = t;
  re_index[index[i]] = i;
  re_index[index[j]] = j;
}
void PHeap::vdown(int i) {
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

void PHeap::vup(int i) {
  while (i > 0 && m[i] < m[(i - 1)/d]) {
    transp(i, (i - 1)/d);
    i = (i - 1)/d;
  }
}

int PHeap::min_pop() {
  transp(0, size - 1);
  size--;
  vdown(0);
  return(index[size]);
}

int PHeap::min_top() {
  return(index[0]);
}

int PHeap::get_rank(int index_) {
  return m[re_index[index_]];
}

void PHeap::chg_rank(int new_rank, int index_) {
  int u = re_index[index_];
  if (m[u] > new_rank) {
    m[u] = new_rank;
    vup(u);
  } else {
    m[u] = new_rank;
    vdown(u);
  }
}

void PHeap::push(int rank, int index_) {
  if (size < max_size) {
    m[size] = rank;
    index[size]= index_;
    re_index[index_] = size;
    size++;
    vup(size - 1);
  } else {
    throw new std::exception();
  }
}

PHeap::~PHeap() {
  delete[] m;
}

void PHeap::print() {
  for (int i = 0; i < size; i++) {
    printf("%4i ", m[i]);
  }
  printf("\n");
}
