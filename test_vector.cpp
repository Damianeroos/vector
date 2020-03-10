#include "Vector.hpp"

//#include <vector>
#include <cassert>
#include <stdexcept>
#include <string>

//template <typename T>
//using Vector = std::vector<T>;

int main() {
  {
	Vector<int> i;
	Vector<float> f;
	Vector<double> d;
	Vector<std::string> s;

	assert(i.empty());
	assert(f.empty());
	assert(d.empty());
	assert(s.empty());
  }

  // {
  //   Vector<int> a = {1, 2, 3};
  //   assert(a.size() == 3);

  //   Vector<int> copy = a;
  //   assert(a.size() == 3);
  //   assert(copy.size() == 3);
  // }

  // {
  //   Vector<int> a(3);
  //   assert(a.size() == 3);

  //   assert(a[0] == 0);
  //   assert(a[1] == 0);
  //   assert(a[2] == 0);

  //   assert(a.at(0) == 0);
  //   assert(a.at(1) == 0);
  //   assert(a.at(2) == 0);

  //   bool thrown = false;
  //   try {
  //     a.at(3);
  //   } catch (std::out_of_range&) {
  //     thrown = true;
  //   }
  //   assert(thrown);
  // }

  // {
  // 	Vector<int> a = {1, 2, 3};

  // 	a.push_back(99);
  // 	assert(a.size() == 4);
  //   assert(a.back() == 99);

  //   a.back() = 100;
  //   assert(a.back() == 100);
  //   a.back()++;
  //   assert(a.back() == 101);

  //   a.pop_back();
  //   assert(a.size() == 3);
  //   assert(a.back() == 3);
  // }

  // {
  // 	Vector<int> a = {100, 2, 3};
  // 	Vector<int> b = {1, 2, 3};
  // 	Vector<int> c = {1, 2, 3};
  // 	assert(a != b);
  // 	assert(b == c);

  // 	a = b;
  // 	assert(a == b);
  // 	assert(a.front() == 1 && b.front() == 1);
  // }
}
