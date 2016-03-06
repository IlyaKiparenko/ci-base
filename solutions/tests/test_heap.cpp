
#include "Heap.h"

#include <gtest.h>

TEST(Heap, cant_push_element_when_heap_is_full) {
  Heap t(2, 2);
  t.push(1);
  t.push(2);
  EXPECT_ANY_THROW(t.push(3));
}

TEST(Heap, can_pop_min_element) {
  Heap t(2, 2);
  t.push(2);
  t.push(1);
  EXPECT_EQ(1,t.min_pop());
}

TEST(Heap, can_up_element) {
  Heap t(3, 2);
  t.m[0] = 3;
  t.m[1] = 2;
  t.m[2] = 1;
  t.size = 3;
  t.vup(2);
  EXPECT_EQ(1, t.min_pop());
}

TEST(Heap, can_down_element) {
  Heap t(3, 2);
  t.m[0] = 3;
  t.m[1] = 2;
  t.m[2] = 1;
  t.size = 3;
  t.vdown(0);
  EXPECT_EQ(1, t.min_pop());
}

TEST(Heap, can_sort) {
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
