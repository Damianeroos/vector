#include "Vector.hpp"


// #include <cassert>
// #include <stdexcept>
#include <string>
#include <gtest/gtest.h>


TEST(VectorTest, emptyFunction){
  Vector<int> i;
  Vector<float> f;
  Vector<double> d;
  Vector<std::string> s;
  EXPECT_TRUE(i.empty());
  EXPECT_TRUE(f.empty());
  EXPECT_TRUE(d.empty());
  EXPECT_TRUE(s.empty());

}

TEST(VectorTest, SizeCopyFnc){
  Vector<int> a = {1, 2, 3};
  assert(a.size() == 3);
  EXPECT_TRUE(a.size()==3);
  Vector<int> copy = a;
  EXPECT_TRUE(a.size() == 3);
  EXPECT_TRUE(copy.size() == 3);

}

TEST(VectorTest, accessOperators){
  Vector<int> b(3);
  EXPECT_TRUE(b.size() == 3);

  EXPECT_TRUE(b[0] == 0);
  EXPECT_TRUE(b[1] == 0);
  EXPECT_TRUE(b[2] == 0);

  EXPECT_TRUE(b.at(0) == 0);
  EXPECT_TRUE(b.at(1) == 0);
  EXPECT_TRUE(b.at(2) == 0);

  bool thrown = false;
  try {
    b.at(3);
  } catch (std::out_of_range &) {
    thrown = true;
  }
  EXPECT_TRUE(thrown);
}

TEST(VectorTest, elemAdding){
  Vector<int> c = {1, 2, 3};

  c.push_back(99);
  EXPECT_TRUE(c.size() == 4);
  EXPECT_TRUE(c.back() == 99);

  c.back() = 100;
  EXPECT_TRUE(c.back() == 100);
  c.back()++;
  EXPECT_TRUE(c.back() == 101);

  c.pop_back();
  EXPECT_TRUE(c.size() == 3);
  EXPECT_TRUE(c.back() == 3);
}

TEST(VectorTest, assignmentOperator){
  Vector<int> at = {100, 2, 3, 50};
  Vector<int> bt = {1, 2, 3};
  Vector<int> ct = {1, 2, 3};
  EXPECT_TRUE(at != bt);
  EXPECT_TRUE(bt == ct);

  at = bt;
  EXPECT_TRUE(at == bt);
  EXPECT_TRUE(at.front() == 1 && bt.front() == 1);
}

int main(int argc,char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}
