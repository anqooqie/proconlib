#ifndef TOOLS_DETAIL_VECTOR_STATIC_COMMON_HPP
#define TOOLS_DETAIL_VECTOR_STATIC_COMMON_HPP

#include <cstddef>
#include <utility>
#include <iterator>

#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V) \
  using reference = T&;\
  using const_reference = const T&;\
  using size_type = ::std::size_t;\
  using difference_type = ::std::ptrdiff_t;\
  using pointer = T*;\
  using const_pointer = const T*;\
  using value_type = T;\
\
  constexpr size_type size() const {\
    return this->m_refs.size();\
  }\
  reference operator[](const size_type n) {\
    return this->m_refs[n].get();\
  }\
  const_reference operator[](const size_type n) const {\
    return this->m_refs[n].get();\
  }\
\
  V& operator=(const V& other) {\
    for (size_type i = 0; i < this->size(); ++i) {\
      (*this)[i] = other[i];\
    }\
    return *this;\
  }\
  V& operator=(V&& other) {\
    for (size_type i = 0; i < this->size(); ++i) {\
      (*this)[i] = ::std::move(other[i]);\
    }\
    return *this;\
  }\
\
  class iterator {\
  private:\
    V* m_parent;\
    size_type m_i;\
\
  public:\
    using difference_type = ::std::ptrdiff_t;\
    using value_type = T;\
    using reference = T&;\
    using pointer = T*;\
    using iterator_category = ::std::random_access_iterator_tag;\
\
    iterator(V * const parent, const size_type i) : m_parent(parent), m_i(i) {}\
\
    iterator() = default;\
    iterator(const iterator&) = default;\
    iterator(iterator&&) = default;\
    ~iterator() = default;\
    iterator& operator=(const iterator&) = default;\
    iterator& operator=(iterator&&) = default;\
\
    iterator& operator++() {\
      ++this->m_i;\
      return *this;\
    }\
    iterator operator++(int) {\
      const iterator self = *this;\
      ++*this;\
      return self;\
    }\
\
    iterator& operator--() {\
      --this->m_i;\
      return *this;\
    }\
    iterator operator--(int) {\
      const iterator self = *this;\
      --*this;\
      return self;\
    }\
\
    iterator& operator+=(const difference_type n) {\
      this->m_i += n;\
      return *this;\
    }\
    friend iterator operator+(const iterator& self, const difference_type n) {\
      return iterator(self) += n;\
    }\
    friend iterator operator+(const difference_type n, const iterator& self) {\
      return iterator(self) += n;\
    }\
\
    iterator& operator-=(const difference_type n) {\
      this->m_i -= n;\
      return *this;\
    }\
    friend iterator operator-(const iterator& self, const difference_type n) {\
      return iterator(self) -= n;\
    }\
    friend difference_type operator-(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return rhs.m_i - lhs.m_i;\
    }\
\
    reference operator*() const {\
      return (*this->m_parent)[this->m_i];\
    }\
    reference operator[](const difference_type n) const {\
      return (*this->m_parent)[this->m_i + n];\
    }\
\
    friend bool operator<(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i < rhs.m_i;\
    }\
    friend bool operator<=(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i <= rhs.m_i;\
    }\
    friend bool operator>(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i > rhs.m_i;\
    }\
    friend bool operator>=(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i >= rhs.m_i;\
    }\
    friend bool operator==(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i == rhs.m_i;\
    }\
    friend bool operator!=(const iterator& lhs, const iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i != rhs.m_i;\
    }\
  };\
\
  class const_iterator {\
  private:\
    const V* m_parent;\
    size_type m_i;\
\
  public:\
    using difference_type = ::std::ptrdiff_t;\
    using value_type = const T;\
    using reference = const T&;\
    using pointer = const T*;\
    using iterator_category = ::std::random_access_iterator_tag;\
\
    const_iterator(const V * const parent, const size_type i) : m_parent(parent), m_i(i) {}\
\
    const_iterator() = default;\
    const_iterator(const const_iterator&) = default;\
    const_iterator(const_iterator&&) = default;\
    ~const_iterator() = default;\
    const_iterator& operator=(const const_iterator&) = default;\
    const_iterator& operator=(const_iterator&&) = default;\
\
    const_iterator& operator++() {\
      ++this->m_i;\
      return *this;\
    }\
    const_iterator operator++(int) {\
      const const_iterator self = *this;\
      ++*this;\
      return self;\
    }\
\
    const_iterator& operator--() {\
      --this->m_i;\
      return *this;\
    }\
    const_iterator operator--(int) {\
      const const_iterator self = *this;\
      --*this;\
      return self;\
    }\
\
    const_iterator& operator+=(const difference_type n) {\
      this->m_i += n;\
      return *this;\
    }\
    friend const_iterator operator+(const const_iterator& self, const difference_type n) {\
      return const_iterator(self) += n;\
    }\
    friend const_iterator operator+(const difference_type n, const const_iterator& self) {\
      return const_iterator(self) += n;\
    }\
\
    const_iterator& operator-=(const difference_type n) {\
      this->m_i -= n;\
      return *this;\
    }\
    friend const_iterator operator-(const const_iterator& self, const difference_type n) {\
      return const_iterator(self) -= n;\
    }\
    friend difference_type operator-(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return rhs.m_i - lhs.m_i;\
    }\
\
    reference operator*() const {\
      return (*this->m_parent)[this->m_i];\
    }\
    reference operator[](const difference_type n) const {\
      return (*this->m_parent)[this->m_i + n];\
    }\
\
    friend bool operator<(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i < rhs.m_i;\
    }\
    friend bool operator<=(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i <= rhs.m_i;\
    }\
    friend bool operator>(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i > rhs.m_i;\
    }\
    friend bool operator>=(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i >= rhs.m_i;\
    }\
    friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i == rhs.m_i;\
    }\
    friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {\
      assert(lhs.m_parent == rhs.m_parent);\
      return lhs.m_i != rhs.m_i;\
    }\
  };\
\
  using reverse_iterator = ::std::reverse_iterator<iterator>;\
  using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;\
\
  iterator begin() {\
    return iterator(this, 0);\
  }\
  const_iterator begin() const {\
    return const_iterator(this, 0);\
  }\
  iterator end() {\
    return iterator(this, this->size());\
  }\
  const_iterator end() const {\
    return const_iterator(this, this->size());\
  }\
  const_iterator cbegin() const {\
    return const_iterator(this, 0);\
  }\
  const_iterator cend() const {\
    return const_iterator(this, this->size());\
  }\
  reverse_iterator rbegin() {\
    return ::std::make_reverse_iterator(this->end());\
  }\
  const_reverse_iterator rbegin() const {\
    return ::std::make_reverse_iterator(this->end());\
  }\
  const_reverse_iterator crbegin() const {\
    return ::std::make_reverse_iterator(this->cend());\
  }\
  reverse_iterator rend() {\
    return ::std::make_reverse_iterator(this->begin());\
  }\
  const_reverse_iterator rend() const {\
    return ::std::make_reverse_iterator(this->begin());\
  }\
  const_reverse_iterator crend() const {\
    return ::std::make_reverse_iterator(this->cbegin());\
  }\
\
  reference front() {\
    return *this->begin();\
  }\
  const_reference front() const {\
    return *this->begin();\
  }\
  reference back() {\
    return *this->rbegin();\
  }\
  const_reference back() const {\
    return *this->rbegin();\
  }\
\
  constexpr bool empty() const {\
    return this->m_refs.empty();\
  }\
\
  void swap(V& other) {\
    for (size_type i = 0; i < this->size(); ++i) {\
      ::std::swap((*this)[i], other[i]);\
    }\
  }

#endif
