
#include "Heap.h"

#include <gtest.h>

TEST(Heap, rere) {
	int size = 10;

	int* y = new int[size];
	srand(time(0));
	int sum = 0;
  printf("input array:\n");
	for (int i = 0; i < size; i++) {
	  y[i] = rand() % 255;
	  printf("%4i ", y[i]);
	}
	printf("\n");

	Heap::HeapSort(y, size, 2);
  printf("sorted array:\n");

	printf("%4i ", y[0]);
	for (int i = 1; i < size; i++) {
	  if (y[i - 1] >= y[i])
		  sum++;
	  else 
      printf("_");
	  printf("%4i ", y[i]);
	}
	printf("\n");
	sum = sum == size - 1;
  if (sum)
    printf("Sorted.\n");
  else
    printf("Unsorted.\n");

  EXPECT_EQ(sum, 1);
}