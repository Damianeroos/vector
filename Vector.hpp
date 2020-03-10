#pragma once


template<class T>
struct entity{
  T obj;
  entity *next_entity;
};

template<class T>
class Vector{
private:
  entity<T> * first_obj;
public:
  Vector();
  bool empty();
};

template<class T>
Vector<T>::Vector(){
  first_obj = nullptr;
}
template<class T>
bool Vector<T>::empty(){
  if(first_obj == nullptr)
    return true;
  return false;
}
