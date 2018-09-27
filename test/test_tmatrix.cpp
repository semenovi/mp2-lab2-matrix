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
	TMatrix<int> v(2);
	TMatrix<int> b(v);

	EXPECT_EQ(v, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(2);
	TMatrix<int> b(v);
	v[1][1] = 1;

	EXPECT_NE(v[1][1], b[1][1]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(2);

	EXPECT_EQ(2, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[2][3] = 4;

	EXPECT_EQ(4, v[2][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[-1][-1] = 2);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);

	ASSERT_ANY_THROW(v[0][6] = 2);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(2);
	v[0][0] = 1;
	v[0][1] = 2;
	v = v;

	EXPECT_EQ(v, v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(2), b(2);
	v[0][0] = 1;
	v[0][1] = 2;
	b = v;

	EXPECT_EQ(v, b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v(3), b(2);
	v[0][0] = 1;
	v[0][1] = 2;
	v[0][2] = 3;
	b = v;

	EXPECT_EQ(3, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(3), b(2);
	v[0][0] = 1;
	v[0][1] = 2;
	v[0][2] = 3;
	b = v;

	EXPECT_EQ(v, b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(2), b(2);
	v[0][0] = 1;
	v[0][1] = 2;
	b[0][0] = 1;
	b[0][1] = 2;

	EXPECT_EQ(v, b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(2);

	EXPECT_EQ(v, v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(2), b(4);

	EXPECT_NE(v, b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(2), b(2), c(2);
	v[0][0] = 1;
	b[0][0] = 2;
	v[0][1] = 3;
	b[0][1] = 3;
	v = v + b;
	c[0][0] = 3;
	c[0][1] = 6;

	EXPECT_EQ(c, v);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(2), b(3);

	ASSERT_ANY_THROW(v = v + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(2), b(2), c(2);
	v[0][0] = 1;
	b[0][0] = 2;
	v[0][1] = 3;
	b[0][1] = 3;
	v = v - b;
	c[0][0] = -1;
	c[0][1] = 0;

	EXPECT_EQ(c, v);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(2), b(3);

	ASSERT_ANY_THROW(v = v - b);
}

