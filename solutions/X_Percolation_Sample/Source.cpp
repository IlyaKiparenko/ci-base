#include "SepSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <random>

typedef std::mersenne_twister_engine<int,
  32, 624, 397, 31, 0x9908b0df, 11,
  0xffffffff, 7, 0x9d2c5680, 15,
  0xefc60000, 18, 1812433253>
  mt19937;

int main(int argc, char *argv[]) {
  time_t start_time = time(0);
  mt19937 mt;
  int EXP_SIZE;
  int n;
  int m;
  if (argc > 1) {
    EXP_SIZE = 4000;
    n = 300;
    m = 300;
  } else {
    EXP_SIZE = 10;
    n = 20;
    m = 20;
  }
  int size = n*m + 2*n;
  SepSet set(size);
  int count;
  int coord;
  bool f;
  srand(time(0));
  double result = 0;
  int x;
  int y;
  for (int cc = 0; cc < EXP_SIZE; cc++) {
    set.clear();
    f = false;
    count = 0;
    for (int i = 0; i < n; i++) {
      set.add(i);
      set.add(size - i - 1);
    }
    for (int i = 1; i < n; i++) {
      set.merge(0, i);
      set.merge(size - 1, size - i - 1);
    }
    while (!f && count < n*m) {
      do {
        x = mt() % n;
        y = mt() % m;
      } while (set.isAdded(x + (y + 1)*n));
      count++;
      coord = x + (y + 1)*n;
      set.add(coord);
      if (x > 0)
        if (set.isAdded(coord - 1))
          set.merge(coord, coord - 1);
      if (set.isAdded(coord - n))
        set.merge(coord, coord - n);
      if (x < n - 1)
        if (set.isAdded(coord + 1))
          set.merge(coord, coord + 1);
      if (set.isAdded(coord + n))
        set.merge(coord, coord + n);
      f = (set.whereI(0) == set.whereI(size - 1));
    }
    result += count*1.0/(n*m);
  }
  printf("percentage = %f\n", result/EXP_SIZE);
  printf("time = %i sec\n", time(0) - start_time);
  std::cin >> count;
}
