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

  {
    Vector<int> a = {1, 2, 3};
    assert(a.size() == 3);
    Vector<int> copy = a;
    assert(a.size() == 3);
    assert(copy.size() == 3);
  }

  {
  Vector<int> b(3);
  assert(b.size() == 3);

  assert(b[0] == 0);
  assert(b[1] == 0);
  assert(b[2] == 0);

  assert(b.at(0) == 0);
  assert(b.at(1) == 0);
  assert(b.at(2) == 0);

    bool thrown = false;
    try {
      b.at(3);
    } catch (std::out_of_range&) {
      thrown = true;
    }
    assert(thrown);
  }

  {
    Vector<int> c = {1, 2, 3};

    c.push_back(99);
    assert(c.size() == 4);
    assert(c.back() == 99);

    c.back() = 100;
    assert(c.back() == 100);
    c.back()++;
    assert(c.back() == 101);

    c.pop_back();
    assert(c.size() == 3);
    assert(c.back() == 3);
  }

  {
    Vector<int> at = {100, 2, 3,50};
  	Vector<int> bt = {1, 2, 3};
  	Vector<int> ct = {1, 2, 3};
  	assert(at != bt);
  	assert(bt == ct);

  	at = bt;
  	assert(at == bt);
  	assert(at.front() == 1 && bt.front() == 1);
  }
}
