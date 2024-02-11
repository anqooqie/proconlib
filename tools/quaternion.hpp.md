---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/vector_static_common.hpp
    title: tools/detail/vector_static_common.hpp
  - icon: ':heavy_check_mark:'
    path: tools/exp.hpp
    title: std::exp(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/log.hpp
    title: std::log(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':heavy_check_mark:'
    path: tools/vector3.hpp
    title: Three dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector4.hpp
    title: Four dimensional vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/quaternion.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cmath>\n#include <algorithm>\n#include <cassert>\n#include <sstream>\n#include\
    \ <random>\n#line 1 \"tools/exp.hpp\"\n\n\n\n#line 5 \"tools/exp.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  auto exp(const T x) {\n    return ::std::exp(x);\n\
    \  }\n}\n\n\n#line 1 \"tools/log.hpp\"\n\n\n\n#line 5 \"tools/log.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  auto log(const T x) {\n    return ::std::log(x);\n\
    \  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\
    \n\n#line 5 \"tools/monoid.hpp\"\n#include <limits>\n#include <numeric>\n\nnamespace\
    \ tools {\n  namespace monoid {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n\
    \    struct max {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5 \"tools/square.hpp\"\n\
    \nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const typename\
    \ M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n  T square(const\
    \ T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n  }\n\
    }\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 1 \"tools/vector4.hpp\"\n\n\n\n#include <array>\n#include <functional>\n\
    #include <utility>\n#include <cstddef>\n#line 1 \"tools/detail/vector_static_common.hpp\"\
    \n\n\n\n#line 6 \"tools/detail/vector_static_common.hpp\"\n#include <iterator>\n\
    \n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V) \\\n  using reference = T&;\\\n\
    \  using const_reference = const T&;\\\n  using size_type = ::std::size_t;\\\n\
    \  using difference_type = ::std::ptrdiff_t;\\\n  using pointer = T*;\\\n  using\
    \ const_pointer = const T*;\\\n  using value_type = T;\\\n\\\n  constexpr size_type\
    \ size() const {\\\n    return this->m_refs.size();\\\n  }\\\n  reference operator[](const\
    \ size_type n) {\\\n    return this->m_refs[n].get();\\\n  }\\\n  const_reference\
    \ operator[](const size_type n) const {\\\n    return this->m_refs[n].get();\\\
    \n  }\\\n\\\n  V& operator=(const V& other) {\\\n    for (size_type i = 0; i <\
    \ this->size(); ++i) {\\\n      (*this)[i] = other[i];\\\n    }\\\n    return\
    \ *this;\\\n  }\\\n\\\n  class const_iterator;\\\n\\\n  class iterator {\\\n \
    \ private:\\\n    V* m_parent;\\\n    size_type m_i;\\\n\\\n  public:\\\n    using\
    \ difference_type = ::std::ptrdiff_t;\\\n    using value_type = T;\\\n    using\
    \ reference = T&;\\\n    using pointer = T*;\\\n    using iterator_category =\
    \ ::std::random_access_iterator_tag;\\\n\\\n    iterator(V * const parent, const\
    \ size_type i) : m_parent(parent), m_i(i) {}\\\n\\\n    iterator() = default;\\\
    \n    iterator(const iterator&) = default;\\\n    iterator(iterator&&) = default;\\\
    \n    ~iterator() = default;\\\n    iterator& operator=(const iterator&) = default;\\\
    \n    iterator& operator=(iterator&&) = default;\\\n\\\n    iterator& operator++()\
    \ {\\\n      ++this->m_i;\\\n      return *this;\\\n    }\\\n    iterator operator++(int)\
    \ {\\\n      const iterator self = *this;\\\n      ++*this;\\\n      return self;\\\
    \n    }\\\n\\\n    iterator& operator--() {\\\n      --this->m_i;\\\n      return\
    \ *this;\\\n    }\\\n    iterator operator--(int) {\\\n      const iterator self\
    \ = *this;\\\n      --*this;\\\n      return self;\\\n    }\\\n\\\n    iterator&\
    \ operator+=(const difference_type n) {\\\n      this->m_i += n;\\\n      return\
    \ *this;\\\n    }\\\n    friend iterator operator+(const iterator& self, const\
    \ difference_type n) {\\\n      return iterator(self) += n;\\\n    }\\\n    friend\
    \ iterator operator+(const difference_type n, const iterator& self) {\\\n    \
    \  return iterator(self) += n;\\\n    }\\\n\\\n    iterator& operator-=(const\
    \ difference_type n) {\\\n      this->m_i -= n;\\\n      return *this;\\\n   \
    \ }\\\n    friend iterator operator-(const iterator& self, const difference_type\
    \ n) {\\\n      return iterator(self) -= n;\\\n    }\\\n    friend difference_type\
    \ operator-(const iterator& lhs, const iterator& rhs) {\\\n      assert(lhs.m_parent\
    \ == rhs.m_parent);\\\n      return lhs.m_i - rhs.m_i;\\\n    }\\\n\\\n    reference\
    \ operator*() const {\\\n      return (*this->m_parent)[this->m_i];\\\n    }\\\
    \n    reference operator[](const difference_type n) const {\\\n      return (*this->m_parent)[this->m_i\
    \ + n];\\\n    }\\\n\\\n    friend bool operator<(const iterator& lhs, const iterator&\
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
    \n      return lhs.m_i != rhs.m_i;\\\n    }\\\n\\\n    friend const_iterator;\\\
    \n  };\\\n\\\n  class const_iterator {\\\n  private:\\\n    const V* m_parent;\\\
    \n    size_type m_i;\\\n\\\n  public:\\\n    using difference_type = ::std::ptrdiff_t;\\\
    \n    using value_type = const T;\\\n    using reference = const T&;\\\n    using\
    \ pointer = const T*;\\\n    using iterator_category = ::std::random_access_iterator_tag;\\\
    \n\\\n    const_iterator(const V * const parent, const size_type i) : m_parent(parent),\
    \ m_i(i) {}\\\n\\\n    const_iterator() = default;\\\n    const_iterator(const\
    \ const_iterator&) = default;\\\n    const_iterator(const_iterator&&) = default;\\\
    \n    ~const_iterator() = default;\\\n    const_iterator& operator=(const const_iterator&)\
    \ = default;\\\n    const_iterator& operator=(const_iterator&&) = default;\\\n\
    \\\n    const_iterator(const iterator it) : m_parent(it.m_parent), m_i(it.m_i)\
    \ {}\\\n\\\n    const_iterator& operator++() {\\\n      ++this->m_i;\\\n     \
    \ return *this;\\\n    }\\\n    const_iterator operator++(int) {\\\n      const\
    \ const_iterator self = *this;\\\n      ++*this;\\\n      return self;\\\n   \
    \ }\\\n\\\n    const_iterator& operator--() {\\\n      --this->m_i;\\\n      return\
    \ *this;\\\n    }\\\n    const_iterator operator--(int) {\\\n      const const_iterator\
    \ self = *this;\\\n      --*this;\\\n      return self;\\\n    }\\\n\\\n    const_iterator&\
    \ operator+=(const difference_type n) {\\\n      this->m_i += n;\\\n      return\
    \ *this;\\\n    }\\\n    friend const_iterator operator+(const const_iterator&\
    \ self, const difference_type n) {\\\n      return const_iterator(self) += n;\\\
    \n    }\\\n    friend const_iterator operator+(const difference_type n, const\
    \ const_iterator& self) {\\\n      return const_iterator(self) += n;\\\n    }\\\
    \n\\\n    const_iterator& operator-=(const difference_type n) {\\\n      this->m_i\
    \ -= n;\\\n      return *this;\\\n    }\\\n    friend const_iterator operator-(const\
    \ const_iterator& self, const difference_type n) {\\\n      return const_iterator(self)\
    \ -= n;\\\n    }\\\n    friend difference_type operator-(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
    \n      return lhs.m_i - rhs.m_i;\\\n    }\\\n\\\n    reference operator*() const\
    \ {\\\n      return (*this->m_parent)[this->m_i];\\\n    }\\\n    reference operator[](const\
    \ difference_type n) const {\\\n      return (*this->m_parent)[this->m_i + n];\\\
    \n    }\\\n\\\n    friend bool operator<(const const_iterator& lhs, const const_iterator&\
    \ rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\n      return lhs.m_i\
    \ < rhs.m_i;\\\n    }\\\n    friend bool operator<=(const const_iterator& lhs,\
    \ const const_iterator& rhs) {\\\n      assert(lhs.m_parent == rhs.m_parent);\\\
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
    \ other[i]);\\\n    }\\\n  }\n\n\n#line 1 \"tools/detail/vector_common.hpp\"\n\
    \n\n\n#line 9 \"tools/detail/vector_common.hpp\"\n#include <iostream>\n#include\
    \ <string>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float\
    \ abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const\
    \ long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const\
    \ int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned\
    \ int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned long\
    \ x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\
    \n\n#define TOOLS_DETAIL_VECTOR_COMMON(V) \\\n  private:\\\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double>;\\\n\\\n  public:\\\n    V operator+() const {\\\n      return *this;\\\
    \n    }\\\n\\\n    V operator-() const {\\\n      V res = *this;\\\n      for\
    \ (auto& v : res) {\\\n        v = -v;\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    V& operator+=(const V& other) {\\\n      assert(this->size() ==\
    \ other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\
    \n        (*this)[i] += other[i];\\\n      }\\\n      return *this;\\\n    }\\\
    \n    friend V operator+(const V& lhs, const V& rhs) {\\\n      return V(lhs)\
    \ += rhs;\\\n    }\\\n\\\n    V& operator-=(const V& other) {\\\n      assert(this->size()\
    \ == other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i)\
    \ {\\\n        (*this)[i] -= other[i];\\\n      }\\\n      return *this;\\\n \
    \   }\\\n    friend V operator-(const V& lhs, const V& rhs) {\\\n      return\
    \ V(lhs) -= rhs;\\\n    }\\\n\\\n    V& operator*=(const T& c) {\\\n      for\
    \ (auto& v : *this) {\\\n        v *= c;\\\n      }\\\n      return *this;\\\n\
    \    }\\\n    friend V operator*(const T& lhs, const V& rhs) {\\\n      return\
    \ V(rhs) *= lhs;\\\n    }\\\n    friend V operator*(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) *= rhs;\\\n    }\\\n\\\n    V& operator/=(const T&\
    \ c) {\\\n      for (auto& v : *this) {\\\n        v /= c;\\\n      }\\\n    \
    \  return *this;\\\n    }\\\n    friend V operator/(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) /= rhs;\\\n    }\\\n\\\n    friend bool operator==(const\
    \ V& lhs, const V& rhs) {\\\n      return ::std::equal(lhs.begin(), lhs.end(),\
    \ rhs.begin());\\\n    }\\\n    friend bool operator!=(const V& lhs, const V&\
    \ rhs) {\\\n      return !(lhs == rhs);\\\n    }\\\n\\\n    T inner_product(const\
    \ V& other) const {\\\n      assert(this->size() == other.size());\\\n      T\
    \ res(0);\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\n    \
    \    res += (*this)[i] * other[i];\\\n      }\\\n      return res;\\\n    }\\\n\
    \\\n    T l1_norm() const {\\\n      T res(0);\\\n      for (const auto& v : *this)\
    \ {\\\n        res += ::tools::abs(v);\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    T squared_l2_norm() const {\\\n      return this->inner_product(*this);\\\
    \n    }\\\n\\\n    F l2_norm() const {\\\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\\\
    \n    }\\\n\\\n    template <typename T_ = T>\\\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ V> normalized() const {\\\n      return *this / this->l2_norm();\\\n    }\\\n\
    \\\n    friend ::std::ostream& operator<<(::std::ostream& os, const V& self) {\\\
    \n      os << '(';\\\n      ::std::string delimiter = \"\";\\\n      for (const\
    \ auto& v : self) {\\\n        os << delimiter << v;\\\n        delimiter = \"\
    , \";\\\n      }\\\n      return os << ')';\\\n    }\\\n\\\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, V& self) {\\\n      for (auto& v : self) {\\\n\
    \        is >> v;\\\n      }\\\n      return is;\\\n    }\n\n\n#line 1 \"tools/tuple_hash.hpp\"\
    \n\n\n\n#line 5 \"tools/tuple_hash.hpp\"\n#include <tuple>\n#line 1 \"tools/now.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline long long now() {\n \
    \   return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 1 \"tools/hash_combine.hpp\"\n\n\n\n#line 6 \"tools/hash_combine.hpp\"\
    \n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
    // License: MIT\n// Author: Google Inc.\n\n// Copyright (c) 2011 Google, Inc.\n\
    //\n// Permission is hereby granted, free of charge, to any person obtaining a\
    \ copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n//\n// The\
    \ above copyright notice and this permission notice shall be included in\n// all\
    \ copies or substantial portions of the Software.\n//\n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n// THE SOFTWARE.\n\nnamespace\
    \ tools {\n  template <typename T>\n  void hash_combine(::std::size_t& seed, const\
    \ T& v) {\n    static const ::std::hash<T> hasher;\n    static constexpr ::std::size_t\
    \ k_mul = 0x9ddfea08eb382d69ULL;\n    ::std::size_t a = (hasher(v) ^ seed) * k_mul;\n\
    \    a ^= (a >> 47);\n    ::std::size_t b = (seed ^ a) * k_mul;\n    b ^= (b >>\
    \ 47);\n    seed = b * k_mul;\n  }\n}\n\n\n#line 11 \"tools/tuple_hash.hpp\"\n\
    \nnamespace tools {\n  template <typename... Ts>\n  struct tuple_hash {\n    template\
    \ <::std::size_t I = sizeof...(Ts) - 1>\n    ::std::size_t operator()(const ::std::tuple<Ts...>&\
    \ key) const {\n      if constexpr (I == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        static const ::std::size_t seed = ::tools::now();\n        return\
    \ seed;\n      } else {\n        ::std::size_t seed = this->operator()<I - 1>(key);\n\
    \        ::tools::hash_combine(seed, ::std::get<I>(key));\n        return seed;\n\
    \      }\n    }\n  };\n}\n\n\n#line 11 \"tools/vector4.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T>\n  class vector4 {\n  public:\n    T x;\n    T y;\n\
    \    T z;\n    T w;\n\n  private:\n    ::std::array<::std::reference_wrapper<T>,\
    \ 4> m_refs;\n\n  public:\n    vector4(const T& x, const T& y, const T& z, const\
    \ T& w) : x(x), y(y), z(z), w(w), m_refs({::std::ref(this->x), ::std::ref(this->y),\
    \ ::std::ref(this->z), ::std::ref(this->w)}) {}\n    vector4() : vector4(T(),\
    \ T(), T(), T()) {}\n    vector4(const ::tools::vector4<T>& other) : vector4(other.x,\
    \ other.y, other.z, other.w) {}\n    ~vector4() = default;\n\n    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector4<T>)\n\
    \    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector4<T>)\n  };\n}\n\nnamespace std\
    \ {\n  template <typename T>\n  struct hash<::tools::vector4<T>> {\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::tools::vector4<T>;\n\
    \    ::std::size_t operator()(const ::tools::vector4<T>& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n#line 1 \"tools/vector3.hpp\"\n\n\
    \n\n#line 12 \"tools/vector3.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class vector3 {\n  public:\n    T x;\n    T y;\n    T z;\n\n  private:\n\
    \    ::std::array<::std::reference_wrapper<T>, 3> m_refs;\n\n  public:\n    vector3(const\
    \ T& x, const T& y, const T& z) : x(x), y(y), z(z), m_refs({::std::ref(this->x),\
    \ ::std::ref(this->y), ::std::ref(this->z)}) {}\n    vector3() : vector3(T(),\
    \ T(), T()) {}\n    vector3(const ::tools::vector3<T>& other) : vector3(other.x,\
    \ other.y, other.z) {}\n    ~vector3() = default;\n\n    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector3<T>)\n\
    \    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector3<T>)\n\n  public:\n    ::tools::vector3<T>\
    \ outer_product(const ::tools::vector3<T>& other) const {\n      return ::tools::vector3<T>(this->y\
    \ * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x\
    \ * other.y - this->y * other.x);\n    }\n\n    template <typename T_ = T>\n \
    \   ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::array<::tools::vector3<T>,\
    \ 3>> orthonormal_basis() const {\n      assert(*this != ::tools::vector3<T>(0,\
    \ 0, 0));\n\n      ::std::array<::tools::vector3<T>, 3> v;\n      v[0] = *this;\n\
    \      v[1] = ::tools::vector3<T>(0, this->z, -this->y);\n      if (v[1] == ::tools::vector3<T>(0,\
    \ 0, 0)) {\n        v[1] = ::tools::vector3<T>(-this->z, 0, this->x);\n      }\n\
    \      v[1] -= v[0].inner_product(v[1]) / v[0].inner_product(v[0]) * v[0];\n\n\
    \      v[0] = v[0].normalized();\n      v[1] = v[1].normalized();\n      v[2]\
    \ = v[0].outer_product(v[1]);\n\n      return v;\n    }\n  };\n}\n\nnamespace\
    \ std {\n  template <typename T>\n  struct hash<::tools::vector3<T>> {\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::tools::vector3<T>;\n\
    \    ::std::size_t operator()(const ::tools::vector3<T>& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z));\n    }\n  };\n}\n\n\n#line 15 \"tools/quaternion.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  class quaternion;\n\n  template <typename\
    \ T>\n  ::tools::quaternion<T> exp(const ::tools::quaternion<T>& q);\n  template\
    \ <typename T>\n  ::tools::quaternion<T> log(const ::tools::quaternion<T>& q);\n\
    \  template <typename T>\n  ::tools::quaternion<T> pow(const ::tools::quaternion<T>&\
    \ base, T exponent);\n\n  template <typename T>\n  class quaternion {\n    static_assert(::std::is_floating_point_v<T>);\n\
    \n  private:\n    ::tools::vector4<T> m_vector;\n    static constexpr T eps =\
    \ 1e-5;\n    static constexpr T pi = 3.14159265358979323846264338327950288419716939937510L;\n\
    \n  public:\n    quaternion() = default;\n    quaternion(const ::tools::quaternion<T>&)\
    \ = default;\n    quaternion(::tools::quaternion<T>&&) = default;\n    ~quaternion()\
    \ = default;\n    ::tools::quaternion<T>& operator=(const ::tools::quaternion<T>&)\
    \ = default;\n    ::tools::quaternion<T>& operator=(::tools::quaternion<T>&&)\
    \ = default;\n\n    quaternion(const T x, const T y, const T z, const T w) : m_vector(x,\
    \ y, z, w) {}\n\n    T x() const {\n      return this->m_vector.x;\n    }\n  \
    \  void x(const T val) {\n      return this->m_vector.x = val;\n    }\n    T y()\
    \ const {\n      return this->m_vector.y;\n    }\n    void y(const T val) {\n\
    \      return this->m_vector.y = val;\n    }\n    T z() const {\n      return\
    \ this->m_vector.z;\n    }\n    void z(const T val) {\n      return this->m_vector.z\
    \ = val;\n    }\n    T w() const {\n      return this->m_vector.w;\n    }\n  \
    \  void w(const T val) {\n      return this->m_vector.w = val;\n    }\n\n    T\
    \ real() const {\n      return this->w();\n    }\n    void real(const T val) {\n\
    \      this->w(val);\n    }\n    ::tools::vector3<T> imag() const {\n      return\
    \ ::tools::vector3<T>(this->x(), this->y(), this->z());\n    }\n    void imag(const\
    \ ::tools::vector3<T>& val) {\n      this->x(val.x);\n      this->y(val.y);\n\
    \      this->z(val.z);\n    }\n\n    T abs() const {\n      return this->m_vector.l2_norm();\n\
    \    }\n    T norm() const {\n      return this->m_vector.squared_l2_norm();\n\
    \    }\n    ::tools::quaternion<T> conj() const {\n      return ::tools::quaternion<T>(-this->x(),\
    \ -this->y(), -this->z(), this->w());\n    }\n\n    T angle() const {\n      assert(::std::abs(this->norm()\
    \ - 1) <= eps);\n      return ::std::acos(::std::clamp<T>(this->real(), -1, 1))\
    \ * 2;\n    }\n    ::tools::vector3<T> axis() const {\n      assert(::std::abs(this->norm()\
    \ - 1) <= eps);\n      return ::std::abs(this->real()) >= 1.0 ? ::tools::vector3<T>(1,\
    \ 0, 0) : this->imag().normalized();\n    }\n\n    ::tools::quaternion<T> operator+()\
    \ const {\n      return *this;\n    }\n    ::tools::quaternion<T> operator-()\
    \ const {\n      return ::tools::quaternion<T>(-this->x(), -this->y(), -this->z(),\
    \ -this->w());\n    }\n\n    ::tools::quaternion<T>& operator+=(const ::tools::quaternion<T>&\
    \ other) {\n      this->m_vector += other.m_vector;\n      return *this;\n   \
    \ }\n    friend ::tools::quaternion<T> operator+(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return ::tools::quaternion<T>(lhs)\
    \ += rhs;\n    }\n\n    ::tools::quaternion<T>& operator-=(const ::tools::quaternion<T>&\
    \ other) {\n      this->m_vector -= other.m_vector;\n      return *this;\n   \
    \ }\n    friend ::tools::quaternion<T> operator-(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return ::tools::quaternion<T>(lhs)\
    \ -= rhs;\n    }\n\n    ::tools::quaternion<T>& operator*=(const T c) {\n    \
    \  this->m_vector *= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T>\
    \ operator*(const ::tools::quaternion<T>& self, const T c) {\n      return ::tools::quaternion<T>(self)\
    \ *= c;\n    }\n    friend ::tools::quaternion<T> operator*(const T c, const ::tools::quaternion<T>&\
    \ self) {\n      return ::tools::quaternion<T>(self) *= c;\n    }\n\n    friend\
    \ ::tools::quaternion<T> operator*(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>&\
    \ rhs) {\n      const auto real = lhs.real() * rhs.real() - lhs.imag().inner_product(rhs.imag());\n\
    \      const auto imag = lhs.real() * rhs.imag() + rhs.real() * lhs.imag() + lhs.imag().outer_product(rhs.imag());\n\
    \      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);\n    }\n \
    \   ::tools::quaternion<T>& operator*=(const ::tools::quaternion<T>& other) {\n\
    \      return *this = *this * other;\n    }\n    friend ::tools::vector3<T> operator*(const\
    \ ::tools::quaternion<T>& q, const ::tools::vector3<T>& v) {\n      assert(::std::abs(q.norm()\
    \ - 1) <= eps);\n      return (q * ::tools::quaternion<T>(v.x, v.y, v.z, 0) *\
    \ q.conj()).imag();\n    }\n\n    ::tools::quaternion<T>& operator/=(const T c)\
    \ {\n      this->m_vector /= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T>\
    \ operator/(const ::tools::quaternion<T>& self, const T c) {\n      return ::tools::quaternion<T>(self)\
    \ /= c;\n    }\n\n    ::tools::quaternion<T> inv() const {\n      const auto norm\
    \ = this->norm();\n      assert(norm != 0);\n      return this->conj() / norm;\n\
    \    }\n    friend ::tools::quaternion<T> operator/(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return lhs * rhs.inv();\n \
    \   }\n    ::tools::quaternion<T>& operator/=(const ::tools::quaternion<T>& other)\
    \ {\n      return *this = *this / other;\n    }\n\n    friend bool operator==(const\
    \ ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {\n      return\
    \ lhs.m_vector == rhs.m_vector;\n    }\n    friend bool operator!=(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return !(lhs == rhs);\n   \
    \ }\n\n    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::quaternion<T>&\
    \ self) {\n      ::std::ostringstream s;\n      s.flags(os.flags());\n      s.imbue(os.getloc());\n\
    \      s.precision(os.precision());\n      s << '(' << self.x() << ',' << self.y()\
    \ << ',' << self.z() << ',' << self.w() << ')';\n      return os << s.str();\n\
    \    }\n\n    static ::tools::quaternion<T> angle_axis(const T angle, const ::tools::vector3<T>&\
    \ axis) {\n      assert(axis != ::tools::vector3<T>(0, 0, 0));\n      const auto\
    \ real = ::std::cos(angle / 2);\n      const auto imag = ::std::sin(angle / 2)\
    \ * axis.normalized();\n      return ::tools::quaternion<T>(imag.x, imag.y, imag.z,\
    \ real);\n    }\n\n    static ::tools::quaternion<T> from_to_rotation(::tools::vector3<T>\
    \ from_direction, ::tools::vector3<T> to_direction) {\n      assert(from_direction\
    \ != ::tools::vector3<T>(0, 0, 0));\n      assert(to_direction != ::tools::vector3<T>(0,\
    \ 0, 0));\n      from_direction = from_direction.normalized();\n      to_direction\
    \ = to_direction.normalized();\n      if (from_direction.inner_product(to_direction)\
    \ <= -1 + eps) {\n        return ::tools::quaternion<T>::angle_axis(pi, from_direction.orthonormal_basis()[1]);\n\
    \      }\n      const auto bisect = (from_direction + to_direction).normalized();\n\
    \      const auto real = from_direction.inner_product(bisect);\n      const auto\
    \ imag = from_direction.outer_product(bisect);\n      return ::tools::quaternion<T>(imag.x,\
    \ imag.y, imag.z, real);\n    }\n\n    static ::tools::quaternion<T> look_rotation(::tools::vector3<T>\
    \ forward, ::tools::vector3<T> upwards = ::tools::vector3<T>(0, 1, 0)) {\n   \
    \   assert(forward != ::tools::vector3<T>(0, 0, 0));\n      assert(upwards !=\
    \ ::tools::vector3<T>(0, 0, 0));\n\n      auto side = upwards.outer_product(forward);\n\
    \      if (side == ::tools::vector3<T>(0, 0, 0)) {\n        upwards = ::tools::vector3<T>(0,\
    \ 1, 0);\n        side = upwards.outer_product(forward);\n      }\n      if (side\
    \ == ::tools::vector3<T>(0, 0, 0)) {\n        side = forward.orthonormal_basis()[1];\n\
    \      }\n      upwards = forward.outer_product(side);\n\n      forward = forward.normalized();\n\
    \      upwards = upwards.normalized();\n\n      const auto q1 = ::tools::quaternion<T>::from_to_rotation(::tools::vector3<T>(0,\
    \ 0, 1), forward);\n      const auto theta = ::std::atan2((q1 * ::tools::vector3<T>(0,\
    \ 1, 0)).outer_product(upwards).inner_product(forward), (q1 * ::tools::vector3<T>(0,\
    \ 1, 0)).inner_product(upwards));\n      const auto q2 = ::tools::quaternion<T>::angle_axis(theta,\
    \ forward);\n      return q2 * q1;\n    }\n\n    static ::tools::quaternion<T>\
    \ slerp(const ::tools::quaternion<T>& q0, const ::tools::quaternion<T>& q1, const\
    \ T t) {\n      return q0 * ::tools::pow(q0.inv() * q1, t);\n    }\n\n    static\
    \ ::tools::quaternion<T> identity() {\n      return ::tools::quaternion<T>(0,\
    \ 0, 0, 1);\n    }\n\n    template <typename R>\n    static ::tools::quaternion<T>\
    \ random(R& engine) {\n      static ::std::uniform_real_distribution<T> dist(0,\
    \ 1);\n      const auto u1 = dist(engine);\n      const auto u2 = dist(engine);\n\
    \      const auto u3 = dist(engine);\n      return ::tools::quaternion<T>(\n \
    \       ::std::sqrt(1 - u1) * ::std::sin(2 * pi * u2),\n        ::std::sqrt(1\
    \ - u1) * ::std::cos(2 * pi * u2),\n        ::std::sqrt(u1) * ::std::sin(2 * pi\
    \ * u3),\n        ::std::sqrt(u1) * ::std::cos(2 * pi * u3)\n      );\n    }\n\
    \n    static ::std::array<::tools::quaternion<T>, 24> dice_rotations() {\n   \
    \   return ::std::array<::tools::quaternion<T>, 24>({\n        ::tools::quaternion<double>::identity(),\n\
    \        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(-1,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(-1,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 1, 0))\n      });\n    }\n  };\n\n  template <typename T>\n  ::tools::quaternion<T>\
    \ exp(const ::tools::quaternion<T>& q) {\n    const auto inorm = q.imag().l2_norm();\n\
    \    if (inorm == 0) {\n      return ::tools::quaternion<T>(0, 0, 0, ::std::exp(q.real()));\n\
    \    }\n\n    const auto rexp = ::std::exp(q.real());\n    const auto real = rexp\
    \ * ::std::cos(inorm);\n    const auto imag = rexp * ::std::sin(inorm) / inorm\
    \ * q.imag();\n    return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);\n\
    \  }\n\n  template <typename T>\n  ::tools::quaternion<T> log(const ::tools::quaternion<T>&\
    \ q) {\n    assert(q != ::tools::quaternion<T>(0, 0, 0, 0));\n    const auto inorm\
    \ = q.imag().l2_norm();\n    const auto uimag = inorm == 0 ? ::tools::vector3<T>(1,\
    \ 0, 0) : q.imag() / inorm;\n    const auto real = ::std::log(q.abs());\n    const\
    \ auto imag = ::std::atan2(inorm, q.real()) * uimag;\n    return ::tools::quaternion<T>(imag.x,\
    \ imag.y, imag.z, real);\n  }\n\n  template <typename T>\n  ::tools::quaternion<T>\
    \ pow(const ::tools::quaternion<T>& base, const T exponent) {\n    const auto\
    \ norm = base.norm();\n    if (norm == 0) {\n      assert(exponent != 0);\n  \
    \    return ::tools::quaternion<T>(0, 0, 0, 0);\n    }\n\n    return ::tools::exp(exponent\
    \ * ::tools::log(base));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_QUATERNION_HPP\n#define TOOLS_QUATERNION_HPP\n\n#include <type_traits>\n\
    #include <cmath>\n#include <algorithm>\n#include <cassert>\n#include <sstream>\n\
    #include <random>\n#include \"tools/exp.hpp\"\n#include \"tools/log.hpp\"\n#include\
    \ \"tools/pow.hpp\"\n#include \"tools/vector4.hpp\"\n#include \"tools/vector3.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class quaternion;\n\n  template\
    \ <typename T>\n  ::tools::quaternion<T> exp(const ::tools::quaternion<T>& q);\n\
    \  template <typename T>\n  ::tools::quaternion<T> log(const ::tools::quaternion<T>&\
    \ q);\n  template <typename T>\n  ::tools::quaternion<T> pow(const ::tools::quaternion<T>&\
    \ base, T exponent);\n\n  template <typename T>\n  class quaternion {\n    static_assert(::std::is_floating_point_v<T>);\n\
    \n  private:\n    ::tools::vector4<T> m_vector;\n    static constexpr T eps =\
    \ 1e-5;\n    static constexpr T pi = 3.14159265358979323846264338327950288419716939937510L;\n\
    \n  public:\n    quaternion() = default;\n    quaternion(const ::tools::quaternion<T>&)\
    \ = default;\n    quaternion(::tools::quaternion<T>&&) = default;\n    ~quaternion()\
    \ = default;\n    ::tools::quaternion<T>& operator=(const ::tools::quaternion<T>&)\
    \ = default;\n    ::tools::quaternion<T>& operator=(::tools::quaternion<T>&&)\
    \ = default;\n\n    quaternion(const T x, const T y, const T z, const T w) : m_vector(x,\
    \ y, z, w) {}\n\n    T x() const {\n      return this->m_vector.x;\n    }\n  \
    \  void x(const T val) {\n      return this->m_vector.x = val;\n    }\n    T y()\
    \ const {\n      return this->m_vector.y;\n    }\n    void y(const T val) {\n\
    \      return this->m_vector.y = val;\n    }\n    T z() const {\n      return\
    \ this->m_vector.z;\n    }\n    void z(const T val) {\n      return this->m_vector.z\
    \ = val;\n    }\n    T w() const {\n      return this->m_vector.w;\n    }\n  \
    \  void w(const T val) {\n      return this->m_vector.w = val;\n    }\n\n    T\
    \ real() const {\n      return this->w();\n    }\n    void real(const T val) {\n\
    \      this->w(val);\n    }\n    ::tools::vector3<T> imag() const {\n      return\
    \ ::tools::vector3<T>(this->x(), this->y(), this->z());\n    }\n    void imag(const\
    \ ::tools::vector3<T>& val) {\n      this->x(val.x);\n      this->y(val.y);\n\
    \      this->z(val.z);\n    }\n\n    T abs() const {\n      return this->m_vector.l2_norm();\n\
    \    }\n    T norm() const {\n      return this->m_vector.squared_l2_norm();\n\
    \    }\n    ::tools::quaternion<T> conj() const {\n      return ::tools::quaternion<T>(-this->x(),\
    \ -this->y(), -this->z(), this->w());\n    }\n\n    T angle() const {\n      assert(::std::abs(this->norm()\
    \ - 1) <= eps);\n      return ::std::acos(::std::clamp<T>(this->real(), -1, 1))\
    \ * 2;\n    }\n    ::tools::vector3<T> axis() const {\n      assert(::std::abs(this->norm()\
    \ - 1) <= eps);\n      return ::std::abs(this->real()) >= 1.0 ? ::tools::vector3<T>(1,\
    \ 0, 0) : this->imag().normalized();\n    }\n\n    ::tools::quaternion<T> operator+()\
    \ const {\n      return *this;\n    }\n    ::tools::quaternion<T> operator-()\
    \ const {\n      return ::tools::quaternion<T>(-this->x(), -this->y(), -this->z(),\
    \ -this->w());\n    }\n\n    ::tools::quaternion<T>& operator+=(const ::tools::quaternion<T>&\
    \ other) {\n      this->m_vector += other.m_vector;\n      return *this;\n   \
    \ }\n    friend ::tools::quaternion<T> operator+(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return ::tools::quaternion<T>(lhs)\
    \ += rhs;\n    }\n\n    ::tools::quaternion<T>& operator-=(const ::tools::quaternion<T>&\
    \ other) {\n      this->m_vector -= other.m_vector;\n      return *this;\n   \
    \ }\n    friend ::tools::quaternion<T> operator-(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return ::tools::quaternion<T>(lhs)\
    \ -= rhs;\n    }\n\n    ::tools::quaternion<T>& operator*=(const T c) {\n    \
    \  this->m_vector *= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T>\
    \ operator*(const ::tools::quaternion<T>& self, const T c) {\n      return ::tools::quaternion<T>(self)\
    \ *= c;\n    }\n    friend ::tools::quaternion<T> operator*(const T c, const ::tools::quaternion<T>&\
    \ self) {\n      return ::tools::quaternion<T>(self) *= c;\n    }\n\n    friend\
    \ ::tools::quaternion<T> operator*(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>&\
    \ rhs) {\n      const auto real = lhs.real() * rhs.real() - lhs.imag().inner_product(rhs.imag());\n\
    \      const auto imag = lhs.real() * rhs.imag() + rhs.real() * lhs.imag() + lhs.imag().outer_product(rhs.imag());\n\
    \      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);\n    }\n \
    \   ::tools::quaternion<T>& operator*=(const ::tools::quaternion<T>& other) {\n\
    \      return *this = *this * other;\n    }\n    friend ::tools::vector3<T> operator*(const\
    \ ::tools::quaternion<T>& q, const ::tools::vector3<T>& v) {\n      assert(::std::abs(q.norm()\
    \ - 1) <= eps);\n      return (q * ::tools::quaternion<T>(v.x, v.y, v.z, 0) *\
    \ q.conj()).imag();\n    }\n\n    ::tools::quaternion<T>& operator/=(const T c)\
    \ {\n      this->m_vector /= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T>\
    \ operator/(const ::tools::quaternion<T>& self, const T c) {\n      return ::tools::quaternion<T>(self)\
    \ /= c;\n    }\n\n    ::tools::quaternion<T> inv() const {\n      const auto norm\
    \ = this->norm();\n      assert(norm != 0);\n      return this->conj() / norm;\n\
    \    }\n    friend ::tools::quaternion<T> operator/(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return lhs * rhs.inv();\n \
    \   }\n    ::tools::quaternion<T>& operator/=(const ::tools::quaternion<T>& other)\
    \ {\n      return *this = *this / other;\n    }\n\n    friend bool operator==(const\
    \ ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {\n      return\
    \ lhs.m_vector == rhs.m_vector;\n    }\n    friend bool operator!=(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return !(lhs == rhs);\n   \
    \ }\n\n    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::quaternion<T>&\
    \ self) {\n      ::std::ostringstream s;\n      s.flags(os.flags());\n      s.imbue(os.getloc());\n\
    \      s.precision(os.precision());\n      s << '(' << self.x() << ',' << self.y()\
    \ << ',' << self.z() << ',' << self.w() << ')';\n      return os << s.str();\n\
    \    }\n\n    static ::tools::quaternion<T> angle_axis(const T angle, const ::tools::vector3<T>&\
    \ axis) {\n      assert(axis != ::tools::vector3<T>(0, 0, 0));\n      const auto\
    \ real = ::std::cos(angle / 2);\n      const auto imag = ::std::sin(angle / 2)\
    \ * axis.normalized();\n      return ::tools::quaternion<T>(imag.x, imag.y, imag.z,\
    \ real);\n    }\n\n    static ::tools::quaternion<T> from_to_rotation(::tools::vector3<T>\
    \ from_direction, ::tools::vector3<T> to_direction) {\n      assert(from_direction\
    \ != ::tools::vector3<T>(0, 0, 0));\n      assert(to_direction != ::tools::vector3<T>(0,\
    \ 0, 0));\n      from_direction = from_direction.normalized();\n      to_direction\
    \ = to_direction.normalized();\n      if (from_direction.inner_product(to_direction)\
    \ <= -1 + eps) {\n        return ::tools::quaternion<T>::angle_axis(pi, from_direction.orthonormal_basis()[1]);\n\
    \      }\n      const auto bisect = (from_direction + to_direction).normalized();\n\
    \      const auto real = from_direction.inner_product(bisect);\n      const auto\
    \ imag = from_direction.outer_product(bisect);\n      return ::tools::quaternion<T>(imag.x,\
    \ imag.y, imag.z, real);\n    }\n\n    static ::tools::quaternion<T> look_rotation(::tools::vector3<T>\
    \ forward, ::tools::vector3<T> upwards = ::tools::vector3<T>(0, 1, 0)) {\n   \
    \   assert(forward != ::tools::vector3<T>(0, 0, 0));\n      assert(upwards !=\
    \ ::tools::vector3<T>(0, 0, 0));\n\n      auto side = upwards.outer_product(forward);\n\
    \      if (side == ::tools::vector3<T>(0, 0, 0)) {\n        upwards = ::tools::vector3<T>(0,\
    \ 1, 0);\n        side = upwards.outer_product(forward);\n      }\n      if (side\
    \ == ::tools::vector3<T>(0, 0, 0)) {\n        side = forward.orthonormal_basis()[1];\n\
    \      }\n      upwards = forward.outer_product(side);\n\n      forward = forward.normalized();\n\
    \      upwards = upwards.normalized();\n\n      const auto q1 = ::tools::quaternion<T>::from_to_rotation(::tools::vector3<T>(0,\
    \ 0, 1), forward);\n      const auto theta = ::std::atan2((q1 * ::tools::vector3<T>(0,\
    \ 1, 0)).outer_product(upwards).inner_product(forward), (q1 * ::tools::vector3<T>(0,\
    \ 1, 0)).inner_product(upwards));\n      const auto q2 = ::tools::quaternion<T>::angle_axis(theta,\
    \ forward);\n      return q2 * q1;\n    }\n\n    static ::tools::quaternion<T>\
    \ slerp(const ::tools::quaternion<T>& q0, const ::tools::quaternion<T>& q1, const\
    \ T t) {\n      return q0 * ::tools::pow(q0.inv() * q1, t);\n    }\n\n    static\
    \ ::tools::quaternion<T> identity() {\n      return ::tools::quaternion<T>(0,\
    \ 0, 0, 1);\n    }\n\n    template <typename R>\n    static ::tools::quaternion<T>\
    \ random(R& engine) {\n      static ::std::uniform_real_distribution<T> dist(0,\
    \ 1);\n      const auto u1 = dist(engine);\n      const auto u2 = dist(engine);\n\
    \      const auto u3 = dist(engine);\n      return ::tools::quaternion<T>(\n \
    \       ::std::sqrt(1 - u1) * ::std::sin(2 * pi * u2),\n        ::std::sqrt(1\
    \ - u1) * ::std::cos(2 * pi * u2),\n        ::std::sqrt(u1) * ::std::sin(2 * pi\
    \ * u3),\n        ::std::sqrt(u1) * ::std::cos(2 * pi * u3)\n      );\n    }\n\
    \n    static ::std::array<::tools::quaternion<T>, 24> dice_rotations() {\n   \
    \   return ::std::array<::tools::quaternion<T>, 24>({\n        ::tools::quaternion<double>::identity(),\n\
    \        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 0, 0)),\n        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(-0.5 * pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(0.5 * pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(-1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, ::tools::vector3<double>(1,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ -1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(0,\
    \ 1, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(-1,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 0, 1)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(-1,\
    \ 1, 0)),\n        ::tools::quaternion<double>::angle_axis(pi, ::tools::vector3<double>(1,\
    \ 1, 0))\n      });\n    }\n  };\n\n  template <typename T>\n  ::tools::quaternion<T>\
    \ exp(const ::tools::quaternion<T>& q) {\n    const auto inorm = q.imag().l2_norm();\n\
    \    if (inorm == 0) {\n      return ::tools::quaternion<T>(0, 0, 0, ::std::exp(q.real()));\n\
    \    }\n\n    const auto rexp = ::std::exp(q.real());\n    const auto real = rexp\
    \ * ::std::cos(inorm);\n    const auto imag = rexp * ::std::sin(inorm) / inorm\
    \ * q.imag();\n    return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);\n\
    \  }\n\n  template <typename T>\n  ::tools::quaternion<T> log(const ::tools::quaternion<T>&\
    \ q) {\n    assert(q != ::tools::quaternion<T>(0, 0, 0, 0));\n    const auto inorm\
    \ = q.imag().l2_norm();\n    const auto uimag = inorm == 0 ? ::tools::vector3<T>(1,\
    \ 0, 0) : q.imag() / inorm;\n    const auto real = ::std::log(q.abs());\n    const\
    \ auto imag = ::std::atan2(inorm, q.real()) * uimag;\n    return ::tools::quaternion<T>(imag.x,\
    \ imag.y, imag.z, real);\n  }\n\n  template <typename T>\n  ::tools::quaternion<T>\
    \ pow(const ::tools::quaternion<T>& base, const T exponent) {\n    const auto\
    \ norm = base.norm();\n    if (norm == 0) {\n      assert(exponent != 0);\n  \
    \    return ::tools::quaternion<T>(0, 0, 0, 0);\n    }\n\n    return ::tools::exp(exponent\
    \ * ::tools::log(base));\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/exp.hpp
  - tools/log.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  - tools/vector4.hpp
  - tools/detail/vector_static_common.hpp
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  - tools/vector3.hpp
  isVerificationFile: false
  path: tools/quaternion.hpp
  requiredBy: []
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
documentation_of: tools/quaternion.hpp
layout: document
title: Quaternion
---

It is a quaternion.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) quaternion<T> q();
(2) quaternion<T> q(T x, T y, T z, T w);
```

- (1)
    - It creates a quaternion $0$.
- (2)
    - It creates a quaternion $w + xi + yj + zk$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## x
```cpp
(1) T q.x();
(2) void q.x(T val);
```

- (1)
    - It returns the X component of $q$.
- (2)
    - It updates the X component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## y
```cpp
(1) T q.y();
(2) void q.y(T val);
```

- (1)
    - It returns the Y component of $q$.
- (2)
    - It updates the Y component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## z
```cpp
(1) T q.z();
(2) void q.z(T val);
```

- (1)
    - It returns the Z component of $q$.
- (2)
    - It updates the Z component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## w
```cpp
(1) T q.w();
(2) void q.w(T val);
```

- (1)
    - It returns the W component of $q$.
- (2)
    - It updates the W component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## real
```cpp
(1) T q.real();
(2) void q.real(T val);
```

- (1)
    - It returns the W component of $q$.
- (2)
    - It updates the W component of $q$ to `val`.

### Constraints
- None

### Time Complexity
- $O(1)$

## imag
```cpp
(1) tools::vector3<T> q.imag();
(2) void q.imag(tools::vector3<T> val);
```

- (1)
    - It returns the X component, the Y component and the Z component of $q$.
- (2)
    - It updates the X component of $q$ to `val.x`, the Y component of $q$ to `val.y` and the Z component of $q$ to `val.z`.

### Constraints
- None

### Time Complexity
- $O(1)$

## abs
```cpp
T q.abs();
```

It returns $\|q\| = \sqrt{w^2 + x^2 + y^2 + z^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## norm
```cpp
T q.norm();
```

It returns $q q^\ast = w^2 + x^2 + y^2 + z^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## conj
```cpp
quaternion<T> q.conj();
```

It returns $q^\ast = w - xi - yj - zk$.

### Constraints
- None

### Time Complexity
- $O(1)$

## inv
```cpp
quaternion<T> q.inv();
```

It returns $q^{-1} = \frac{q^\ast}{\|q\|^2}$.

### Constraints
- $q \neq 0$

### Time Complexity
- $O(1)$

## angle
```cpp
T q.angle();
```

It returns the angle of the rotation which $q$ represents in radians.
In other words, it returns $2 \cos^{-1}(w)$.

### Constraints
- $\|q\| \approx 1$

### Time Complexity
- $O(1)$

## axis
```cpp
tools::vector3<T> q.axis();
```

It returns the axis of the rotation which $q$ represents.
In other words, it returns the following unit vector where $\mathbb{v} = (x, y, z)$.

$$\begin{align*}
\left\{\begin{array}{ll}
\frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
(1, 0, 0) & \text{(if $|\mathbb{v}| = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $\|q\| \approx 1$

### Time Complexity
- $O(1)$

## Unary plus operator
```cpp
quaternion<T> q.operator+();
```

It returns the copy of $q$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Unary negation operator
```cpp
quaternion<T> q.operator-();
```

It returns $-w - xi - yj - zk$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Addition operators
```cpp
(1) quaternion<T>& q1.operator+=(quaternion<T> q2);
(2) quaternion<T> operator+(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q_1$ to $(w_1 + w_2) + (x_1 + x_2)i + (y_1 + y_2)j + (z_1 + z_2)k$, and returns $q_1$.
- (2)
    - It returns $(w_1 + w_2) + (x_1 + x_2)i + (y_1 + y_2)j + (z_1 + z_2)k$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Subtraction operators
```cpp
(1) quaternion<T>& q1.operator-=(quaternion<T> q2);
(2) quaternion<T> operator-(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q_1$ to $(w_1 - w_2) + (x_1 - x_2)i + (y_1 - y_2)j + (z_1 - z_2)k$, and returns $q_1$.
- (2)
    - It returns $(w_1 - w_2) + (x_1 - x_2)i + (y_1 - y_2)j + (z_1 - z_2)k$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Multiplication operators
```cpp
(1) quaternion<T>& q.operator*=(T c);
(2) quaternion<T> operator*(quaternion<T> q, T c);
(3) quaternion<T> operator*(T c, quaternion<T> q);
(4) quaternion<T>& q1.operator*=(quaternion<T> q2);
(5) quaternion<T> operator*(quaternion<T> q1, quaternion<T> q2);
(6) tools::vector3<T> operator*(quaternion<T> q, tools::vector3<T> p);
```

- (1)
    - It updates $q$ to $cw + cxi + cyj + czk$, and returns $q$.
- (2), (3)
    - It returns $cw + cxi + cyj + czk$.
- (4)
    - It updates $q_1$ to $(w_1 w_2 - \mathbb{v}_1 \cdot \mathbb{v}_2) + (w_1 \mathbb{v}_2 + w_2 \mathbb{v}_1 + \mathbb{v}_1 \times \mathbb{v}_2)$ where $\mathbb{v}_1 = (x_1, y_1, z_1)$ and $\mathbb{v}_2 = (x_2, y_2, z_2)$, and returns $q_1$.
- (5)
    - It returns $(w_1 w_2 - \mathbb{v}_1 \cdot \mathbb{v}_2) + (w_1 \mathbb{v}_2 + w_2 \mathbb{v}_1 + \mathbb{v}_1 \times \mathbb{v}_2)$ where $\mathbb{v}_1 = (x_1, y_1, z_1)$ and $\mathbb{v}_2 = (x_2, y_2, z_2)$.
- (6)
    - It applies the rotation which $q$ represents to $\mathbb{p}$. In other words, it returns the imaginary part of $q (\mathbb{p}_x i + \mathbb{p}_y j + \mathbb{p}_z k) q^\ast$, that is $(\cos \theta) \mathbb{p} + (1 - \cos \theta) (\hat{\mathbb{v}} \cdot \mathbb{p}) \hat{\mathbb{v}} + \sin \theta (\hat{\mathbb{v}} \times \mathbb{p})$ where $\theta$ = `q.angle()` and $\hat{\mathbb{v}}$ = `q.axis()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Division operators
```cpp
(1) quaternion<T>& q.operator/=(T c);
(2) quaternion<T> operator/(quaternion<T> q, T c);
(3) quaternion<T>& q1.operator/=(quaternion<T> q2);
(4) quaternion<T> operator/(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It updates $q$ to $\frac{w}{c} + \frac{x}{c}i + \frac{y}{c}j + \frac{z}{c}k$, and returns $q$.
- (2)
    - It returns $\frac{w}{c} + \frac{x}{c}i + \frac{y}{c}j + \frac{z}{c}k$.
- (3)
    - It updates $q_1$ to $q_1 q_2^{-1}$, and returns $q_1$.
- (4)
    - It returns $q_1 q_2^{-1}$.

### Constraints
- (1), (2)
    - $c \neq 0$
- (3), (4)
    - $q_2 \neq 0$

### Time Complexity
- $O(1)$

## Comparison operators
```cpp
(1) bool operator==(quaternion<T> q1, quaternion<T> q2);
(2) bool operator!=(quaternion<T> q1, quaternion<T> q2);
```

- (1)
    - It returns whether $w_1 = w_2 \land x_1 = x_2 \land y_1 = y_2 \land z_1 = z_2$.
- (2)
    - It returns whether $w_1 \neq w_2 \lor x_1 \neq x_2 \lor y_1 \neq y_2 \lor z_1 \neq z_2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const quaternion<T>& self);
```

It is equivalent to the following code.

```cpp
std::ostringstream s;
s.flags(os.flags());
s.imbue(os.getloc());
s.precision(os.precision());
s << '(' << self.x() << ',' << self.y() << ',' << self.z() << ',' << self.w() << ')';
return os << s.str();
```

### Constraints
- None

### Time Complexity
- $O(1)$

## angle_axis
```cpp
quaternion<T> quaternion<T>::angle_axis(T theta, tools::vector3<T> v);
```

It returns a rotation which rotates $\theta$ radians around $\mathbb{v}$.
In other words, it returns $\cos\left(\frac{\theta}{2}\right) + \sin\left(\frac{\theta}{2}\right) \frac{\mathbb{v}}{\|\mathbb{v}\|}$.

### Constraints
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## from_to_rotation
```cpp
quaternion<T> quaternion<T>::from_to_rotation(tools::vector3<T> u, tools::vector3<T> v);
```

It returns a rotation which rotates from $\mathbb{u}$ to $\mathbb{v}$.

### Constraints
- $\mathbb{u} \neq (0, 0, 0)$
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## look_rotation
```cpp
quaternion<T> quaternion<T>::look_rotation(tools::vector3<T> f, tools::vector3<T> u);
```

It returns a rotation with the specified forward direction $\mathbb{f}$ and upwards direction $\mathbb{u}$.
Z axis will be aligned with $\mathbb{f}$, X axis aligned with $\mathbb{f} \times \mathbb{u}$, and Y axis aligned with cross product between Z and X.

### Constraints
- $\mathbb{u} \neq (0, 0, 0)$
- $\mathbb{v} \neq (0, 0, 0)$

### Time Complexity
- $O(1)$

## slerp
```cpp
quaternion<T> quaternion<T>::slerp(quaternion<T> q0, quaternion<T> q1, T t);
```

It spherically interpolates between quaternions $q_0$ and $q_1$ by ratio $t$.
In other words, it returns $q_0 \left(q_0^{-1} q_1\right)^t$.

### Constraints
- $\mathbb{q_0} \neq 0$

### Time Complexity
- $O(1)$

## identity
```cpp
quaternion<T> quaternion<T>::identity();
```

It returns $1$.

### Constraints
- None

### Time Complexity
- $O(1)$

## random
```cpp
template <typename R>
quaternion<T> quaternion<T>::random(R& engine);
```

It returns a random rotation.

### Constraints
- `engine` is a pseudorandom number generator.

### Time Complexity
- $O(1)$

## dice_rotations
```cpp
std::array<quaternion<T>, 24> quaternion<T>::dice_rotations();
```

It returns all the states which a dice can have..

### Constraints
- None

### Time Complexity
- $O(1)$

## tools::exp
```cpp
quaternion<T> tools::exp(quaternion<T> q);
```

It returns $e^q = \sum_{n = 0}^\infty \frac{q^n}{n!}$.

### Note
$e^q$ is equal to the following quaternion where $\mathbb{v} = xi + yj + zk$.

$$\begin{align*}
\left\{\begin{array}{ll}
e^w \left(\cos|\mathbb{v}| + \sin|\mathbb{v}| \frac{\mathbb{v}}{|\mathbb{v}|}\right) & \text{(if $|\mathbb{v}| > 0$)}\\
e^w & \text{(if $|\mathbb{v}| = 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

## tools::log
```cpp
quaternion<T> tools::log(quaternion<T> q);
```

It returns $\mathrm{Log}(q)$.
$\mathrm{Log}(q)$ is defined as follows where $\mathbb{v} = xi + yj + zk$.

$$\begin{align*}
\mathrm{Log}(q) &=
\left\{\begin{array}{ll}
\log |q| + \mathrm{atan2}(|\mathbb{v}|, w) \frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
\log |q| + \mathrm{atan2}(|\mathbb{v}|, w) i  & \text{(if $|\mathbb{v}| = 0$ and $w \neq 0$)}
\end{array}\right.&
\end{align*}$$

### Note
$\mathrm{Log}(q)$ is one of the quaternions $q'$ such that $e^{q'} = q$ holds.
All the quaternions $q'$ such that $e^{q'} = q$ holds can be written in the following form for any unit three-dimensional vector $\hat{\mathbb{u}}$ and any integer $k$.

$$\begin{align*}
\left\{\begin{array}{ll}
\log |q| + (\mathrm{atan2}(|\mathbb{v}|, w) + 2k \pi) \frac{\mathbb{v}}{|\mathbb{v}|} & \text{(if $|\mathbb{v}| > 0$)}\\
\log |q| + (\mathrm{atan2}(|\mathbb{v}|, w) + 2k \pi) \hat{\mathbb{u}} & \text{(if $|\mathbb{v}| = 0$ and $w \neq 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $q \neq 0$

### Time Complexity
- $O(1)$

## tools::pow
```cpp
quaternion<T> tools::pow(quaternion<T> q, T t);
```

It returns $q^t$.
$q^t$ is defined as $e^{t \mathrm{Log}(q)}$.

### Constraints
- $q \neq 0$ or $t \neq 0$

### Time Complexity
- $O(1)$
