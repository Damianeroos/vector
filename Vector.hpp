#pragma once

#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <cstddef>
#include <algorithm>

template <class T> class Vector {
public:
  Vector() :  m_size(0) {}
  Vector(const Vector<T> &arg) { *this = arg; }
  Vector(std::initializer_list<T>);
  Vector(std::size_t);

  bool empty() { return !m_size; }
  bool empty()const { return !m_size; }
  const std::size_t size() const { return m_size; }
  T &at(std::size_t);
  const T &at(std::size_t) const;
  void push_back(const T&);
  void pop_back();
  T &back() { return (*this)[m_size - 1]; }
  const T &back() const { return (*this)[m_size - 1]; }
  T &front() { return (*this)[0]; }
  const T &front() const { return (*this)[0]; }

  T &operator[](std::size_t arg){ return m_entities[arg];}
  const T &operator[](std::size_t arg) const{ return m_entities[arg];}
  bool operator==(const Vector<T> &) const;
  bool operator!=(const Vector<T> &arg) const { return !(*this == arg); }
  Vector<T> &operator=(const Vector<T> &);

  private:
  std::unique_ptr<T[]> m_entities;
  std::size_t m_size;
  
};

template <class T> Vector<T>::Vector(std::initializer_list<T> list) {
  m_size = list.size();
  m_entities = std::make_unique<T[]>(m_size);

  int i = 0;
  for (auto it : list) {
    m_entities[i++] = it;
  }
}

template <class T> Vector<T>::Vector(std::size_t arg) {
  m_size = arg;
  m_entities = std::make_unique<T[]>(m_size);
  for (int i = 0; i < m_size; i++) {
    m_entities[i] = 0;
  }
}

template <class T> T &Vector<T>::at(std::size_t index) {
  if (index > m_size - 1)
    throw std::out_of_range("range_check");
  return m_entities[index];
}

template <class T> const T &Vector<T>::at(std::size_t index) const {
  if (index > m_size - 1)
    throw std::out_of_range("range_check");
  return m_entities[index];
}

template <class T> void Vector<T>::push_back(const T &arg) {

  std::unique_ptr<T[]> temp = std::make_unique<T[]>(m_size+1);
  for (int i = 0; i < m_size; i++) {
    temp[i] = m_entities[i];
  }
  temp[m_size]=arg;
  m_size++;

  m_entities = std::move(temp);
}

template <class T> void Vector<T>::pop_back() {
  if (m_size <= 1) {
    m_size = 0;
    m_entities = nullptr;
    return;
  }
  m_size--;
}


template <class T> bool Vector<T>::operator==(const Vector<T> &arg) const {
  if (arg.size() != m_size)
    return false;

  for (int i = 0; i < m_size; i++) {
    if (m_entities[i] != arg[i])
      return false;
  }
  return true;
  
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &arg) {
  m_size = arg.size();
  m_entities = std::make_unique<T[]>(m_size);
  for (int i = 0; i < arg.size(); i++) {
    m_entities[i] = arg[i];
  }
  return *this;
}
