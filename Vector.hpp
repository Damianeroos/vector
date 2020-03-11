#pragma once

//nie używać includów w headerach. jak to rozwiązać?
#include <iostream>
#include <memory>


template<class T>
class Vector{
private:
  std::unique_ptr<T[]> m_entities;
  size_t   m_size;
public:
  Vector(): m_entities(nullptr), m_size(0) {}
  Vector(std::initializer_list<T>);
  bool empty() {return !m_size;}
  size_t size(){return m_size;}
 
};

template<class T>
Vector<T>::Vector(std::initializer_list<T> list){
  m_size =  list.size();
  m_entities = std::make_unique<T[]>(m_size);

  int i = 0;
  for(auto it : list){
    m_entities[i++] = it; //na pewno jest bardziej elegancki sposób
  }
}

