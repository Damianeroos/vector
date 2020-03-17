#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <type_traits>

template <class T>
class Vector {
 public:
  Vector() : m_size(0) {
    m_entities = std::make_unique<T[]>(4);
    m_real_size = 4;
  }
  Vector(const Vector<T> &arg) { *this = arg; }
  Vector(Vector<T> &&arg) noexcept { *this = std::move(arg); }
  Vector(std::initializer_list<T>);
  Vector(std::size_t);

  bool empty() const { return !m_size; }
  std::size_t size() const { return m_size; }
  T &at(std::size_t);
  const T &at(std::size_t) const;
  void push_back(const T &);
  void pop_back();
  T &back() { return (*this)[m_size - 1]; }
  const T &back() const { return (*this)[m_size - 1]; }
  T &front() { return (*this)[0]; }
  const T &front() const { return (*this)[0]; }

  T &operator[](std::size_t arg) { return m_entities[arg]; }
  const T &operator[](std::size_t arg) const { return m_entities[arg]; }
  bool operator==(const Vector<T> &) const;
  bool operator!=(const Vector<T> &arg) const { return !(*this == arg); }
  Vector<T> &operator=(const Vector<T> &);
  Vector<T> &operator=(Vector<T> &&) noexcept;

  T *begin() { return &m_entities[0]; }
  T *begin() const { return &m_entities[0]; }
  T *end() { return &m_entities[m_size]; }
  T *end() const { return &m_entities[m_size]; }

 private:
  size_t compute_pow(const size_t &size) const;
  std::unique_ptr<T[]> m_entities;
  std::size_t m_size;
  std::size_t m_real_size;
};

template <class T>
Vector<T>::Vector(std::initializer_list<T> list) {
  if (!list.size()) {
    return;
  }

  m_real_size = 1 << compute_pow(list.size());
  m_entities = std::make_unique<T[]>(m_real_size);
  std::copy(list.begin(), list.end(), begin());
  m_size = list.size();
}

template <class T>
Vector<T>::Vector(std::size_t arg) {
  m_real_size = 1 << compute_pow(arg);
  m_size = arg;
  m_entities = std::make_unique<T[]>(m_real_size);
  std::fill(begin(), end(), T{});
}

template <class T>
T &Vector<T>::at(std::size_t index) {
  if (index > m_size - 1) throw std::out_of_range("range_check");
  return m_entities[index];
}

template <class T>
const T &Vector<T>::at(std::size_t index) const {
  if (index > m_size - 1) throw std::out_of_range("range_check");
  return m_entities[index];
}

template <class T>
void Vector<T>::push_back(const T &arg) {
  if (m_real_size == m_size) {
    std::size_t temp_real_size = m_real_size * 2;

    auto temp_entities = std::make_unique<T[]>(temp_real_size);
    std::copy(begin(), end(), &temp_entities[0]);

    temp_entities[m_size] = arg;
    m_entities = std::move(temp_entities);
    ++m_size;
    m_real_size = temp_real_size;
  } else {
    m_entities[m_size] = arg;
    ++m_size;
  }
}

template <class T>
void Vector<T>::pop_back() {
  --m_size;
}

template <class T>
bool Vector<T>::operator==(const Vector<T> &arg) const {
  if (arg.size() != m_size) return false;

  return (std::equal(begin(), end(), arg.begin(), arg.end()));
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &arg) {
  if (&arg == this) return *this;

  size_t temp_real_size = 1 << compute_pow(arg.size());

  auto temp_entities = std::make_unique<T[]>(temp_real_size);
  std::copy(arg.begin(), arg.end(), &temp_entities[0]);

  m_entities = std::move(temp_entities);
  m_size = arg.size();
  m_real_size = temp_real_size;

  return *this;
}

template <class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&arg) noexcept {
  if (&arg == this) return *this;

  m_entities = std::move(arg.m_entities);
  m_size = arg.m_size;
  m_real_size = arg.m_real_size;

  return *this;
}

template <class T>
size_t Vector<T>::compute_pow(const size_t &size) const {
  int p = 0;
  int temp_size = static_cast<int>(size);
  while (temp_size >= (1 << p)) ++p;
  return p;
}
