#include "Heap.h"
#include <stdlib.h>
#include <ctime>

int main() {
  int size = 100;

  int* y = new int[size];
  srand(time(0));
  int sum = 0;

  for (int i = 0; i < size; i++) {
    y[i] = rand() % 255;
    printf("%4i ", y[i]);
  }
  printf("\n\n");

  Heap::HeapSort(y, size, 2);

  printf("%4i ", y[0]);
  for (int i = 1; i < size; i++) {
    if (y[i-1] >= y[i]) 
      sum++;
    else  
      printf("_");
    printf("%4i ", y[i]);
  }
  printf("\n");
  sum = sum == size - 1;
  printf("%i\n", sum);
  return 0;
}
