#pragma once
#include <iostream>
#include <memory>


template<class T>
class Vector{
private:
  std::unique_ptr<T[]> entities; 
public:
  Vector(): entities(nullptr) {}
  bool empty();
 
};



template<class T>
bool Vector<T>::empty(){
  if(entities == nullptr)
    return true;
  return false;
}
