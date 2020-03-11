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
  Vector(const Vector<T> &);
  bool empty() {return !m_size;}
  size_t size()const {return m_size;}
  Vector<T>& operator= (const Vector<T>&);
  T& operator[](size_t index){return m_entities[index];}
  const  T& operator[](size_t index) const {return m_entities[index];}
 
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
//do operatora = trzeba dopisać konstruktor Vector(Vector<T>)
template<class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& arg){
  m_size =  arg.size();
  m_entities = std::make_unique<T[]>(m_size);
  for(int i=0;i<arg.size();i++){
    m_entities[i] = arg[i];
  }
  return *this;
}

template <class T>
Vector<T>::Vector(const Vector<T> & arg){
  *this = arg;
}
