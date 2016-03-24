#include "KSet.h"
#include <stdio.h>

KSet::KSet() { }

KSet::KSet(int size_) {
  size = size_;
  m = new int[size];
  for (int i = 0; i < size; i++)
    m[i] = -1;
}

void KSet::add(int i) {
  m[i] = i;
}

int KSet::whereI(int i) {
  return m[i];
}

void KSet::merge(int i, int j) {
  i = m[i];
  j = m[j];
  for (int k = 0; k < size; k++)
    if (m[k] == j) m[k] = i;
}

void KSet::print() {
  printf("Size = %i\n[", size);
  for (int k = 0; k < size; k++)
    printf("%i,", m[k]);
  printf("END]\n");
}

KSet::~KSet() {
  delete[] m;
}
