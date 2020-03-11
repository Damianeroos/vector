#pragma once


#include <iostream>
#include <memory>
#include <stdexcept>


template<class T>
class Vector{
private:
  std::unique_ptr<T[]> m_entities;
  size_t   m_size;
public:
  Vector(): m_entities(nullptr), m_size(0) {}
  Vector(std::initializer_list<T>);
  Vector(const Vector<T> &);
  Vector(size_t);
  bool empty() {return !m_size;}
  size_t size()const {return m_size;}
  Vector<T>& operator= (const Vector<T>&);
  T& operator[](size_t index);
  const  T& operator[](size_t index) const;
  T& at(size_t index);
  const T& at(size_t index) const;
  
 
};

template<class T>
T& Vector<T>::operator[](size_t index){
  if(index > m_size-1)
    throw std::out_of_range ("range_check");
  return m_entities[index];
}

template<class T>
const  T& Vector<T>::operator[](size_t index) const {
  if(index > m_size-1)
    throw std::out_of_range ("range_check");
  return m_entities[index];
}

template<class T>
T& Vector<T>::at(size_t index){
  if(index > m_size-1)
    throw std::out_of_range ("range_check");
  return m_entities[index];
}

template<class T>
const T& Vector<T>::at(size_t index) const {
  if(index > m_size-1)
    throw std::out_of_range ("range_check");
  return m_entities[index];
}  


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

template <class T>
Vector<T>::Vector(size_t arg){
  m_size =  arg;
  m_entities = std::make_unique<T[]>(m_size);
  for(int i=0;i<m_size;i++){
    m_entities[i] = 0;
  }
}
