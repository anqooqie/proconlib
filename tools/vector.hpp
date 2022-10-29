#ifndef TOOLS_VECTOR_HPP
#define TOOLS_VECTOR_HPP

#include <vector>
#include <cstddef>
#include <initializer_list>
#include "tools/detail/vector_common.hpp"

namespace tools {
  template <typename T>
  class vector {
  private:
    ::std::vector<T> m_values;

  public:
    using reference = T&;
    using const_reference = const T&;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using value_type = T;
    using iterator = typename ::std::vector<T>::iterator;
    using const_iterator = typename ::std::vector<T>::const_iterator;
    using reverse_iterator = typename ::std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<T>::const_reverse_iterator;

    vector() = default;
    vector(const ::tools::vector<T>&) = default;
    vector(::tools::vector<T>&&) = default;
    ~vector() = default;
    ::tools::vector<T>& operator=(const ::tools::vector<T>&) = default;
    ::tools::vector<T>& operator=(::tools::vector<T>&&) = default;

    explicit vector(size_type n) : m_values(n) {}
    vector(size_type n, const_reference value) : m_values(n, value) {}
    template <typename InputIter> vector(const InputIter first, const InputIter last) : m_values(first, last) {}
    vector(const ::std::initializer_list<T> il) : m_values(il) {}

    iterator begin() { return this->m_values.begin(); }
    const_iterator begin() const { return this->m_values.begin(); }
    iterator end() { return this->m_values.end(); }
    const_iterator end() const { return this->m_values.end(); }
    const_iterator cbegin() const { return this->m_values.cbegin(); }
    const_iterator cend() const { return this->m_values.cend(); }
    reverse_iterator rbegin() { return this->m_values.rbegin(); }
    const_reverse_iterator rbegin() const { return this->m_values.rbegin(); }
    const_reverse_iterator crbegin() const { return this->m_values.crbegin(); }
    reverse_iterator rend() { return this->m_values.rend(); }
    const_reverse_iterator rend() const { return this->m_values.rend(); }
    const_reverse_iterator crend() const { return this->m_values.crend(); }

    size_type size() const { return this->m_values.size(); }
    bool empty() const { return this->m_values.empty(); }

    reference operator[](const size_type n) { return this->m_values[n]; }
    const_reference operator[](const size_type n) const { return this->m_values[n]; }
    reference front() { return *this->begin(); }
    const_reference front() const { return *this->begin(); }
    reference back() { return *this->rbegin(); }
    const_reference back() const { return *this->rbegin(); }

    void swap(::tools::vector<T>& other) { this->m_values.swap(other.m_values); }

    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector<T>)
  };
}

#endif
