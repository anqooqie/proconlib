---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':heavy_check_mark:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_arg.hpp
    title: std::greater by the argument
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_arg_total.hpp
    title: std::greater by the argument (total order)
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg.hpp
    title: std::less by the argument
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg_total.hpp
    title: std::less by the argument (total order)
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ccw.test.cpp
    title: tests/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/intersection_to_circle.test.cpp
    title: tests/circle_2d/intersection_to_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/intersection_to_line.test.cpp
    title: tests/circle_2d/intersection_to_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/with_radius.test.cpp
    title: tests/circle_2d/where/with_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/without_radius.test.cpp
    title: tests/circle_2d/where/without_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convex_hull.test.cpp
    title: tests/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/greater_by_arg.test.cpp
    title: tests/greater_by_arg.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/greater_by_arg_total.test.cpp
    title: tests/greater_by_arg_total.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/less_by_arg.test.cpp
    title: tests/less_by_arg.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/less_by_arg_total.test.cpp
    title: tests/less_by_arg_total.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/detail/vector_static_common.hpp\"\n\n\n\n#include\
    \ <cstddef>\n#include <utility>\n#include <iterator>\n\n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V)\
    \ \\\n  using reference = T&;\\\n  using const_reference = const T&;\\\n  using\
    \ size_type = ::std::size_t;\\\n  using difference_type = ::std::ptrdiff_t;\\\n\
    \  using pointer = T*;\\\n  using const_pointer = const T*;\\\n  using value_type\
    \ = T;\\\n\\\n  constexpr size_type size() const {\\\n    return this->m_refs.size();\\\
    \n  }\\\n  reference operator[](const size_type n) {\\\n    return this->m_refs[n].get();\\\
    \n  }\\\n  const_reference operator[](const size_type n) const {\\\n    return\
    \ this->m_refs[n].get();\\\n  }\\\n\\\n  V& operator=(const V& other) {\\\n  \
    \  for (size_type i = 0; i < this->size(); ++i) {\\\n      (*this)[i] = other[i];\\\
    \n    }\\\n    return *this;\\\n  }\\\n  V& operator=(V&& other) {\\\n    for\
    \ (size_type i = 0; i < this->size(); ++i) {\\\n      (*this)[i] = ::std::move(other[i]);\\\
    \n    }\\\n    return *this;\\\n  }\\\n\\\n  class iterator {\\\n  private:\\\n\
    \    V* m_parent;\\\n    size_type m_i;\\\n\\\n  public:\\\n    using difference_type\
    \ = ::std::ptrdiff_t;\\\n    using value_type = T;\\\n    using reference = T&;\\\
    \n    using pointer = T*;\\\n    using iterator_category = ::std::random_access_iterator_tag;\\\
    \n\\\n    iterator(V * const parent, const size_type i) : m_parent(parent), m_i(i)\
    \ {}\\\n\\\n    iterator() = default;\\\n    iterator(const iterator&) = default;\\\
    \n    iterator(iterator&&) = default;\\\n    ~iterator() = default;\\\n    iterator&\
    \ operator=(const iterator&) = default;\\\n    iterator& operator=(iterator&&)\
    \ = default;\\\n\\\n    iterator& operator++() {\\\n      ++this->m_i;\\\n   \
    \   return *this;\\\n    }\\\n    iterator operator++(int) {\\\n      const iterator\
    \ self = *this;\\\n      ++*this;\\\n      return self;\\\n    }\\\n\\\n    iterator&\
    \ operator--() {\\\n      --this->m_i;\\\n      return *this;\\\n    }\\\n   \
    \ iterator operator--(int) {\\\n      const iterator self = *this;\\\n      --*this;\\\
    \n      return self;\\\n    }\\\n\\\n    iterator& operator+=(const difference_type\
    \ n) {\\\n      this->m_i += n;\\\n      return *this;\\\n    }\\\n    friend\
    \ iterator operator+(const iterator& self, const difference_type n) {\\\n    \
    \  return iterator(self) += n;\\\n    }\\\n    friend iterator operator+(const\
    \ difference_type n, const iterator& self) {\\\n      return iterator(self) +=\
    \ n;\\\n    }\\\n\\\n    iterator& operator-=(const difference_type n) {\\\n \
    \     this->m_i -= n;\\\n      return *this;\\\n    }\\\n    friend iterator operator-(const\
    \ iterator& self, const difference_type n) {\\\n      return iterator(self) -=\
    \ n;\\\n    }\\\n    friend difference_type operator-(const iterator& lhs, const\
    \ iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return\
    \ rhs.m_i - lhs.m_i;\\\n    }\\\n\\\n    reference operator*() const {\\\n   \
    \   return (*this->m_parent)[this->m_i];\\\n    }\\\n    reference operator[](const\
    \ difference_type n) const {\\\n      return (*this->m_parent)[this->m_i + n];\\\
    \n    }\\\n\\\n    friend bool operator<(const iterator& lhs, const iterator&\
    \ rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i\
    \ < rhs.m_i;\\\n    }\\\n    friend bool operator<=(const iterator& lhs, const\
    \ iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return\
    \ lhs.m_i <= rhs.m_i;\\\n    }\\\n    friend bool operator>(const iterator& lhs,\
    \ const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n  \
    \    return lhs.m_i > rhs.m_i;\\\n    }\\\n    friend bool operator>=(const iterator&\
    \ lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i >= rhs.m_i;\\\n    }\\\n    friend bool operator==(const\
    \ iterator& lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i == rhs.m_i;\\\n    }\\\n    friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i != rhs.m_i;\\\n    }\\\n  };\\\n\\\n  class const_iterator\
    \ {\\\n  private:\\\n    const V* m_parent;\\\n    size_type m_i;\\\n\\\n  public:\\\
    \n    using difference_type = ::std::ptrdiff_t;\\\n    using value_type = const\
    \ T;\\\n    using reference = const T&;\\\n    using pointer = const T*;\\\n \
    \   using iterator_category = ::std::random_access_iterator_tag;\\\n\\\n    const_iterator(const\
    \ V * const parent, const size_type i) : m_parent(parent), m_i(i) {}\\\n\\\n \
    \   const_iterator() = default;\\\n    const_iterator(const const_iterator&) =\
    \ default;\\\n    const_iterator(const_iterator&&) = default;\\\n    ~const_iterator()\
    \ = default;\\\n    const_iterator& operator=(const const_iterator&) = default;\\\
    \n    const_iterator& operator=(const_iterator&&) = default;\\\n\\\n    const_iterator&\
    \ operator++() {\\\n      ++this->m_i;\\\n      return *this;\\\n    }\\\n   \
    \ const_iterator operator++(int) {\\\n      const const_iterator self = *this;\\\
    \n      ++*this;\\\n      return self;\\\n    }\\\n\\\n    const_iterator& operator--()\
    \ {\\\n      --this->m_i;\\\n      return *this;\\\n    }\\\n    const_iterator\
    \ operator--(int) {\\\n      const const_iterator self = *this;\\\n      --*this;\\\
    \n      return self;\\\n    }\\\n\\\n    const_iterator& operator+=(const difference_type\
    \ n) {\\\n      this->m_i += n;\\\n      return *this;\\\n    }\\\n    friend\
    \ const_iterator operator+(const const_iterator& self, const difference_type n)\
    \ {\\\n      return const_iterator(self) += n;\\\n    }\\\n    friend const_iterator\
    \ operator+(const difference_type n, const const_iterator& self) {\\\n      return\
    \ const_iterator(self) += n;\\\n    }\\\n\\\n    const_iterator& operator-=(const\
    \ difference_type n) {\\\n      this->m_i -= n;\\\n      return *this;\\\n   \
    \ }\\\n    friend const_iterator operator-(const const_iterator& self, const difference_type\
    \ n) {\\\n      return const_iterator(self) -= n;\\\n    }\\\n    friend difference_type\
    \ operator-(const const_iterator& lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent\
    \ == rhs.m_parent);\\\n      return rhs.m_i - lhs.m_i;\\\n    }\\\n\\\n    reference\
    \ operator*() const {\\\n      return (*this->m_parent)[this->m_i];\\\n    }\\\
    \n    reference operator[](const difference_type n) const {\\\n      return (*this->m_parent)[this->m_i\
    \ + n];\\\n    }\\\n\\\n    friend bool operator<(const const_iterator& lhs, const\
    \ const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n  \
    \    return lhs.m_i < rhs.m_i;\\\n    }\\\n    friend bool operator<=(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i <= rhs.m_i;\\\n    }\\\n    friend bool operator>(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent\
    \ == rhs.m_parent);\\\n      return lhs.m_i > rhs.m_i;\\\n    }\\\n    friend\
    \ bool operator>=(const const_iterator& lhs, const const_iterator& rhs) {\\\n\
    \      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i >= rhs.m_i;\\\
    \n    }\\\n    friend bool operator==(const const_iterator& lhs, const const_iterator&\
    \ rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i\
    \ == rhs.m_i;\\\n    }\\\n    friend bool operator!=(const const_iterator& lhs,\
    \ const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i != rhs.m_i;\\\n    }\\\n  };\\\n\\\n  using reverse_iterator\
    \ = ::std::reverse_iterator<iterator>;\\\n  using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;\\\
    \n\\\n  iterator begin() {\\\n    return iterator(this, 0);\\\n  }\\\n  const_iterator\
    \ begin() const {\\\n    return const_iterator(this, 0);\\\n  }\\\n  iterator\
    \ end() {\\\n    return iterator(this, this->size());\\\n  }\\\n  const_iterator\
    \ end() const {\\\n    return const_iterator(this, this->size());\\\n  }\\\n \
    \ const_iterator cbegin() const {\\\n    return const_iterator(this, 0);\\\n \
    \ }\\\n  const_iterator cend() const {\\\n    return const_iterator(this, this->size());\\\
    \n  }\\\n  reverse_iterator rbegin() {\\\n    return ::std::make_reverse_iterator(this->end());\\\
    \n  }\\\n  const_reverse_iterator rbegin() const {\\\n    return ::std::make_reverse_iterator(this->end());\\\
    \n  }\\\n  const_reverse_iterator crbegin() const {\\\n    return ::std::make_reverse_iterator(this->cend());\\\
    \n  }\\\n  reverse_iterator rend() {\\\n    return ::std::make_reverse_iterator(this->begin());\\\
    \n  }\\\n  const_reverse_iterator rend() const {\\\n    return ::std::make_reverse_iterator(this->begin());\\\
    \n  }\\\n  const_reverse_iterator crend() const {\\\n    return ::std::make_reverse_iterator(this->cbegin());\\\
    \n  }\\\n\\\n  reference front() {\\\n    return *this->begin();\\\n  }\\\n  const_reference\
    \ front() const {\\\n    return *this->begin();\\\n  }\\\n  reference back() {\\\
    \n    return *this->rbegin();\\\n  }\\\n  const_reference back() const {\\\n \
    \   return *this->rbegin();\\\n  }\\\n\\\n  constexpr bool empty() const {\\\n\
    \    return this->m_refs.empty();\\\n  }\\\n\\\n  void swap(V& other) {\\\n  \
    \  for (size_type i = 0; i < this->size(); ++i) {\\\n      ::std::swap((*this)[i],\
    \ other[i]);\\\n    }\\\n  }\n\n\n"
  code: "#ifndef TOOLS_DETAIL_VECTOR_STATIC_COMMON_HPP\n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON_HPP\n\
    \n#include <cstddef>\n#include <utility>\n#include <iterator>\n\n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V)\
    \ \\\n  using reference = T&;\\\n  using const_reference = const T&;\\\n  using\
    \ size_type = ::std::size_t;\\\n  using difference_type = ::std::ptrdiff_t;\\\n\
    \  using pointer = T*;\\\n  using const_pointer = const T*;\\\n  using value_type\
    \ = T;\\\n\\\n  constexpr size_type size() const {\\\n    return this->m_refs.size();\\\
    \n  }\\\n  reference operator[](const size_type n) {\\\n    return this->m_refs[n].get();\\\
    \n  }\\\n  const_reference operator[](const size_type n) const {\\\n    return\
    \ this->m_refs[n].get();\\\n  }\\\n\\\n  V& operator=(const V& other) {\\\n  \
    \  for (size_type i = 0; i < this->size(); ++i) {\\\n      (*this)[i] = other[i];\\\
    \n    }\\\n    return *this;\\\n  }\\\n  V& operator=(V&& other) {\\\n    for\
    \ (size_type i = 0; i < this->size(); ++i) {\\\n      (*this)[i] = ::std::move(other[i]);\\\
    \n    }\\\n    return *this;\\\n  }\\\n\\\n  class iterator {\\\n  private:\\\n\
    \    V* m_parent;\\\n    size_type m_i;\\\n\\\n  public:\\\n    using difference_type\
    \ = ::std::ptrdiff_t;\\\n    using value_type = T;\\\n    using reference = T&;\\\
    \n    using pointer = T*;\\\n    using iterator_category = ::std::random_access_iterator_tag;\\\
    \n\\\n    iterator(V * const parent, const size_type i) : m_parent(parent), m_i(i)\
    \ {}\\\n\\\n    iterator() = default;\\\n    iterator(const iterator&) = default;\\\
    \n    iterator(iterator&&) = default;\\\n    ~iterator() = default;\\\n    iterator&\
    \ operator=(const iterator&) = default;\\\n    iterator& operator=(iterator&&)\
    \ = default;\\\n\\\n    iterator& operator++() {\\\n      ++this->m_i;\\\n   \
    \   return *this;\\\n    }\\\n    iterator operator++(int) {\\\n      const iterator\
    \ self = *this;\\\n      ++*this;\\\n      return self;\\\n    }\\\n\\\n    iterator&\
    \ operator--() {\\\n      --this->m_i;\\\n      return *this;\\\n    }\\\n   \
    \ iterator operator--(int) {\\\n      const iterator self = *this;\\\n      --*this;\\\
    \n      return self;\\\n    }\\\n\\\n    iterator& operator+=(const difference_type\
    \ n) {\\\n      this->m_i += n;\\\n      return *this;\\\n    }\\\n    friend\
    \ iterator operator+(const iterator& self, const difference_type n) {\\\n    \
    \  return iterator(self) += n;\\\n    }\\\n    friend iterator operator+(const\
    \ difference_type n, const iterator& self) {\\\n      return iterator(self) +=\
    \ n;\\\n    }\\\n\\\n    iterator& operator-=(const difference_type n) {\\\n \
    \     this->m_i -= n;\\\n      return *this;\\\n    }\\\n    friend iterator operator-(const\
    \ iterator& self, const difference_type n) {\\\n      return iterator(self) -=\
    \ n;\\\n    }\\\n    friend difference_type operator-(const iterator& lhs, const\
    \ iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return\
    \ rhs.m_i - lhs.m_i;\\\n    }\\\n\\\n    reference operator*() const {\\\n   \
    \   return (*this->m_parent)[this->m_i];\\\n    }\\\n    reference operator[](const\
    \ difference_type n) const {\\\n      return (*this->m_parent)[this->m_i + n];\\\
    \n    }\\\n\\\n    friend bool operator<(const iterator& lhs, const iterator&\
    \ rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i\
    \ < rhs.m_i;\\\n    }\\\n    friend bool operator<=(const iterator& lhs, const\
    \ iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return\
    \ lhs.m_i <= rhs.m_i;\\\n    }\\\n    friend bool operator>(const iterator& lhs,\
    \ const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n  \
    \    return lhs.m_i > rhs.m_i;\\\n    }\\\n    friend bool operator>=(const iterator&\
    \ lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i >= rhs.m_i;\\\n    }\\\n    friend bool operator==(const\
    \ iterator& lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i == rhs.m_i;\\\n    }\\\n    friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i != rhs.m_i;\\\n    }\\\n  };\\\n\\\n  class const_iterator\
    \ {\\\n  private:\\\n    const V* m_parent;\\\n    size_type m_i;\\\n\\\n  public:\\\
    \n    using difference_type = ::std::ptrdiff_t;\\\n    using value_type = const\
    \ T;\\\n    using reference = const T&;\\\n    using pointer = const T*;\\\n \
    \   using iterator_category = ::std::random_access_iterator_tag;\\\n\\\n    const_iterator(const\
    \ V * const parent, const size_type i) : m_parent(parent), m_i(i) {}\\\n\\\n \
    \   const_iterator() = default;\\\n    const_iterator(const const_iterator&) =\
    \ default;\\\n    const_iterator(const_iterator&&) = default;\\\n    ~const_iterator()\
    \ = default;\\\n    const_iterator& operator=(const const_iterator&) = default;\\\
    \n    const_iterator& operator=(const_iterator&&) = default;\\\n\\\n    const_iterator&\
    \ operator++() {\\\n      ++this->m_i;\\\n      return *this;\\\n    }\\\n   \
    \ const_iterator operator++(int) {\\\n      const const_iterator self = *this;\\\
    \n      ++*this;\\\n      return self;\\\n    }\\\n\\\n    const_iterator& operator--()\
    \ {\\\n      --this->m_i;\\\n      return *this;\\\n    }\\\n    const_iterator\
    \ operator--(int) {\\\n      const const_iterator self = *this;\\\n      --*this;\\\
    \n      return self;\\\n    }\\\n\\\n    const_iterator& operator+=(const difference_type\
    \ n) {\\\n      this->m_i += n;\\\n      return *this;\\\n    }\\\n    friend\
    \ const_iterator operator+(const const_iterator& self, const difference_type n)\
    \ {\\\n      return const_iterator(self) += n;\\\n    }\\\n    friend const_iterator\
    \ operator+(const difference_type n, const const_iterator& self) {\\\n      return\
    \ const_iterator(self) += n;\\\n    }\\\n\\\n    const_iterator& operator-=(const\
    \ difference_type n) {\\\n      this->m_i -= n;\\\n      return *this;\\\n   \
    \ }\\\n    friend const_iterator operator-(const const_iterator& self, const difference_type\
    \ n) {\\\n      return const_iterator(self) -= n;\\\n    }\\\n    friend difference_type\
    \ operator-(const const_iterator& lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent\
    \ == rhs.m_parent);\\\n      return rhs.m_i - lhs.m_i;\\\n    }\\\n\\\n    reference\
    \ operator*() const {\\\n      return (*this->m_parent)[this->m_i];\\\n    }\\\
    \n    reference operator[](const difference_type n) const {\\\n      return (*this->m_parent)[this->m_i\
    \ + n];\\\n    }\\\n\\\n    friend bool operator<(const const_iterator& lhs, const\
    \ const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n  \
    \    return lhs.m_i < rhs.m_i;\\\n    }\\\n    friend bool operator<=(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i <= rhs.m_i;\\\n    }\\\n    friend bool operator>(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent\
    \ == rhs.m_parent);\\\n      return lhs.m_i > rhs.m_i;\\\n    }\\\n    friend\
    \ bool operator>=(const const_iterator& lhs, const const_iterator& rhs) {\\\n\
    \      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i >= rhs.m_i;\\\
    \n    }\\\n    friend bool operator==(const const_iterator& lhs, const const_iterator&\
    \ rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i\
    \ == rhs.m_i;\\\n    }\\\n    friend bool operator!=(const const_iterator& lhs,\
    \ const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i != rhs.m_i;\\\n    }\\\n  };\\\n\\\n  using reverse_iterator\
    \ = ::std::reverse_iterator<iterator>;\\\n  using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;\\\
    \n\\\n  iterator begin() {\\\n    return iterator(this, 0);\\\n  }\\\n  const_iterator\
    \ begin() const {\\\n    return const_iterator(this, 0);\\\n  }\\\n  iterator\
    \ end() {\\\n    return iterator(this, this->size());\\\n  }\\\n  const_iterator\
    \ end() const {\\\n    return const_iterator(this, this->size());\\\n  }\\\n \
    \ const_iterator cbegin() const {\\\n    return const_iterator(this, 0);\\\n \
    \ }\\\n  const_iterator cend() const {\\\n    return const_iterator(this, this->size());\\\
    \n  }\\\n  reverse_iterator rbegin() {\\\n    return ::std::make_reverse_iterator(this->end());\\\
    \n  }\\\n  const_reverse_iterator rbegin() const {\\\n    return ::std::make_reverse_iterator(this->end());\\\
    \n  }\\\n  const_reverse_iterator crbegin() const {\\\n    return ::std::make_reverse_iterator(this->cend());\\\
    \n  }\\\n  reverse_iterator rend() {\\\n    return ::std::make_reverse_iterator(this->begin());\\\
    \n  }\\\n  const_reverse_iterator rend() const {\\\n    return ::std::make_reverse_iterator(this->begin());\\\
    \n  }\\\n  const_reverse_iterator crend() const {\\\n    return ::std::make_reverse_iterator(this->cbegin());\\\
    \n  }\\\n\\\n  reference front() {\\\n    return *this->begin();\\\n  }\\\n  const_reference\
    \ front() const {\\\n    return *this->begin();\\\n  }\\\n  reference back() {\\\
    \n    return *this->rbegin();\\\n  }\\\n  const_reference back() const {\\\n \
    \   return *this->rbegin();\\\n  }\\\n\\\n  constexpr bool empty() const {\\\n\
    \    return this->m_refs.empty();\\\n  }\\\n\\\n  void swap(V& other) {\\\n  \
    \  for (size_type i = 0; i < this->size(); ++i) {\\\n      ::std::swap((*this)[i],\
    \ other[i]);\\\n    }\\\n  }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/detail/vector_static_common.hpp
  requiredBy:
  - tools/triangle_2d.hpp
  - tools/greater_by_arg.hpp
  - tools/detail/geometry_2d.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/ccw.hpp
  - tools/vector2.hpp
  - tools/line_2d.hpp
  - tools/half_line_2d.hpp
  - tools/greater_by_arg_total.hpp
  - tools/polygon_2d.hpp
  - tools/convex_hull.hpp
  - tools/less_by_arg_total.hpp
  - tools/circle_2d.hpp
  - tools/less_by_arg.hpp
  timestamp: '2022-10-29 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/less_by_arg_total.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/greater_by_arg.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/greater_by_arg_total.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/ccw.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/convex_hull.test.cpp
documentation_of: tools/detail/vector_static_common.hpp
layout: document
redirect_from:
- /library/tools/detail/vector_static_common.hpp
- /library/tools/detail/vector_static_common.hpp.html
title: tools/detail/vector_static_common.hpp
---
