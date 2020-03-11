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
  T& operator[](size_t);
  const  T& operator[](size_t) const;
  T& at(size_t);
  const T& at(size_t) const;
  void push_back(T);
  void pop_back(void);
  T& back(void){return (*this)[m_size-1];}
  const T& back(void) const{return (*this)[m_size-1];}
  bool operator ==(const Vector<T> &) const;
  bool operator !=(const Vector<T> &arg) const {return !(*this==arg);}
  T& front(void){return (*this)[0];}
  const T& front(void) const{return (*this)[0];}
  
};


template<class T>
bool Vector<T>::operator ==(const Vector<T> &arg) const{
  if(arg.size()!=m_size)
    return false;

  for(int i=0; i<m_size; i++){
    if(m_entities[i]!=arg[i])
      return false;
  }
  return true;
}

template<class T>
void Vector<T>::pop_back(void){
  if(m_size <= 1){
    m_size = 0;
    m_entities = nullptr;
    return;
  }
  
  std::unique_ptr<T[]> temp = std::make_unique<T[]>(m_size);
  //mało wydajne, może powinienem użyć shared_ptr zamiast unique_ptr
  for(int i=0;i<m_size;i++){ 
    temp[i]=m_entities[i];
  }
  m_size--;
  m_entities = std::make_unique<T[]>(m_size);
  for(int i=0;i<m_size;i++){ 
    m_entities[i]=temp[i];
  }
}
  
template<class T>
void Vector<T>::push_back(T arg){
  std::unique_ptr<T[]> temp = std::make_unique<T[]>(m_size);
  for(int i=0;i<m_size;i++){ 
    temp[i]=m_entities[i];
  }
  m_size++;
  m_entities = std::make_unique<T[]>(m_size);
  for(int i=0;i<m_size-1;i++){ 
    m_entities[i]=temp[i];
  }
  m_entities[m_size-1]= arg;
}

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
