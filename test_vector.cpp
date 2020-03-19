#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include "Vector.hpp"

TEST(VectorTest, empty_vector) {
  // Given
  Vector<int> i;
  Vector<float> f;
  Vector<double> d;
  Vector<std::string> s;

  // When/Then
  EXPECT_TRUE(i.empty());
  EXPECT_TRUE(f.empty());
  EXPECT_TRUE(d.empty());
  EXPECT_TRUE(s.empty());
}

TEST(VectorTest, SizeCopyFnc) {
  // Given
  Vector<int> a = {1, 2, 3};
  Vector<int> copy;

  // When
  copy = a;

  // Then
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(copy.size(), 3);
}

TEST(VectorTest, size_constructor) {
  // Given
  Vector<int> b(3);

  // Then
  EXPECT_EQ(b.size(), 3);
}

TEST(VectorTest, subscript_operator) {
  // Given
  Vector<int> b(4);

  // When/Then
  EXPECT_EQ(b[0], 0);
  EXPECT_EQ(b[1], 0);
  EXPECT_EQ(b[2], 0);
  EXPECT_EQ(b[3], 0);
}

TEST(VectorTest, at_function) {
  // Given
  Vector<int> b(4);

  // When/Then
  EXPECT_EQ(b.at(0), 0);
  EXPECT_EQ(b.at(1), 0);
  EXPECT_EQ(b.at(2), 0);
  EXPECT_EQ(b.at(3), 0);
  EXPECT_THROW(b.at(4), std::out_of_range);
}

TEST(VectorTest, elemAdding) {
  // Given
  Vector<int> c = {1, 2, 3};

  // When
  c.push_back(99);

  // Then
  EXPECT_EQ(c.size(), 4);
}

TEST(VectorTest, back_function) {
  // Given
  Vector<int> c = {1, 2, 3};

  // When
  c.push_back(99);
  c.back()++;

  // Then
  EXPECT_EQ(c.back(), 100);
}

TEST(VectorTest, front_function) {
  // Given
  Vector<int> c = {665, 2, 3};

  // When
  c.front()++;

  // Then
  EXPECT_EQ(c.front(), 666);
}

TEST(VectorTest, pop_back_function) {
  // Given
  Vector<int> c = {1, 2, 3};

  // When
  c.pop_back();

  // Then
  EXPECT_EQ(c.back(), 2);
  EXPECT_EQ(c.size(), 2);
}

TEST(VectorTest, relational_operator) {
  // Given
  Vector<int> at = {100, 2, 3, 50};
  Vector<int> bt = {1, 2, 3};
  Vector<int> ct = {1, 2, 3};
  Vector<int> dt = {1, 2, 3};

  // When
  dt = at;

  // Then
  EXPECT_EQ(dt, at);
  EXPECT_NE(at, bt);
  EXPECT_EQ(bt, ct);
  EXPECT_EQ(at.front(), dt.front());
}

TEST(VectorTest, begin_iterator) {
  // Given
  Vector<int> a = {1, 2, 3};

  // When
  *a.begin() = 9;

  // Then
  EXPECT_EQ(a.front(), 9);
}

TEST(VectorTest, end_iterator) {
  // Given
  Vector<int> a;

  // When/Then
  EXPECT_EQ(*a.end(), 0);
}

TEST(VectorTest, move_semantics) {
  // Given
  Vector<int> a = {1, 2, 3};
  Vector<int> b = {1};
  Vector<int> c(std::move(b));

  // When
  b = std::move(a);

  // Then
  EXPECT_EQ(b.size(), 3);
  EXPECT_EQ(b[2], 3);
  EXPECT_EQ(c[0], 1);
}

TEST(VectorTest, swap_class_method) {
  // Given
  Vector<int> a = {1, 2, 3};
  Vector<int> b = {6, 6, 6, 6};
  Vector<int> c(a);

  // When
  b.swap(a);

  // Then
  EXPECT_EQ(c, b);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a[3], 6);
}

TEST(VectorTest, swap_fnc) {
  // Given
  Vector<int> a = {1, 2, 3};
  Vector<int> b = {6, 6, 6, 6};
  Vector<int> c(a);

  // When
  swap(a, b);

  // Then
  EXPECT_EQ(c, b);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a[3], 6);
}

TEST(VectorTest, make_swap){
  // Given
  Vector<int> a = {1 , 2 ,3};
  Vector<int> b = {88, 666, 1993,55};
  std::vector<int> aa = {9,8,7};
  std::vector<int> bb = {0 ,-4};

  // When
  call_swap(a, b);
  call_swap(aa, bb);

  // Them
  EXPECT_EQ(a.size(),4);
  EXPECT_EQ(b.back(),3);
  EXPECT_EQ(aa.back(),-4);
  EXPECT_EQ(bb.front(),9);
}
