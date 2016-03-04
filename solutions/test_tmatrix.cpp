#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> m(2);
  m[0][0] = 1;
  m[1][1] = 1;
  
  // 1 0
  // 0 1

  TMatrix<int> w(m);
  
  EXPECT_EQ(m, w);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m(2);
  m[0][0] = 1;
  m[1][1] = 1;
  
  // 1 0
  // 0 1

  TMatrix<int> w(m);
  w[0][1] = -1;

  // 1 -1
  // 0  1

  EXPECT_NE(m, w);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> v(4);

  int k = 0;

  ASSERT_NO_THROW(k = v.GetSize());

  EXPECT_EQ(k, 4);
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m(2);

  ASSERT_NO_THROW(m[0][0] = 4);

  EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m(2);

  ASSERT_ANY_THROW(m[-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m(2);

  ASSERT_ANY_THROW(m[4]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3
  
  TMatrix<int> t(2);
  t[0][0] = 10;
  t[1][1] = 3;

  // 10 0 
  // 0  3

  ASSERT_NO_THROW(v = v);

  EXPECT_EQ(v, t);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3
  
  TMatrix<int> t(v);
  t[0][1] = -7;

  // 10 -7 
  // 0   3

  ASSERT_NO_THROW(v = t);

  EXPECT_EQ(v, t);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> t(3);
  TMatrix<int> r(4);

  ASSERT_NO_THROW(t = r);

  EXPECT_NE(t.GetSize(), 3);  
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3
  
  TMatrix<int> t(3);
  t[0][1] = -7;

  // 0 -7 0 
  // 0  0 0
  // 0  0 0

  ASSERT_NO_THROW(v = t);

  EXPECT_EQ(v, t);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3
  
  TMatrix<int> h(2);
  h[0][0] = 10;
  h[1][1] = 3;

  // 10 0 
  // 0  3

  EXPECT_EQ(v == h, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3

  EXPECT_EQ(v == v, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> v(2);
  TMatrix<int> h(3);

  EXPECT_NE(v, h);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3

  TMatrix<int> h(2);
  h[0][1] = -5;
  h[1][1] = 3;

  // 0 -5 
  // 0  3

  TMatrix<int> k(2);
  k[0][0] = 10;
  k[0][1] = -5;
  k[1][1] = 6;

  // 10 -5 
  // 0   6

  ASSERT_NO_THROW(v = v + h);

  EXPECT_EQ(v, k);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> v(2), h(3);

  ASSERT_ANY_THROW(v + h);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> v(2);
  v[0][0] = 10;
  v[1][1] = 3;

  // 10 0 
  // 0  3

  TMatrix<int> h(2);
  h[0][1] = -5;
  h[1][1] = 3;

  // 0 -5 
  // 0  3

  TMatrix<int> k(2);
  k[0][0] = 10;
  k[0][1] = 5;

  // 10 5 
  // 0  0

  ASSERT_NO_THROW(v = v - h);

  EXPECT_EQ(v, k);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> v(2), h(3);

  ASSERT_ANY_THROW(v - h);
}

