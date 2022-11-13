---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':question:'
    path: tools/detail/vector_static_common.hpp
    title: tools/detail/vector_static_common.hpp
  - icon: ':heavy_check_mark:'
    path: tools/exp.hpp
    title: std::exp(x) extended for my library
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/log.hpp
    title: std::log(x) extended for my library
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':question:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':heavy_check_mark:'
    path: tools/vector3.hpp
    title: Three dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector4.hpp
    title: Four dimensional vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
  bundledCode: "#line 1 \"tests/quaternion/look_rotation.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B\"\n\n#include <iostream>\n\
    #include <array>\n#include <algorithm>\n#include <iterator>\n#line 1 \"tools/quaternion.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <cmath>\n#line 7 \"tools/quaternion.hpp\"\
    \n#include <cassert>\n#include <sstream>\n#include <random>\n#line 1 \"tools/exp.hpp\"\
    \n\n\n\n#line 5 \"tools/exp.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  auto exp(const T x) {\n    return ::std::exp(x);\n  }\n}\n\n\n#line 1 \"tools/log.hpp\"\
    \n\n\n\n#line 5 \"tools/log.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  auto log(const T x) {\n    return ::std::log(x);\n  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\
    \n\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 5 \"tools/monoid.hpp\"\n#include\
    \ <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid {\n  \
    \  template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n   \
    \ struct max {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n\
    \    struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5\
    \ \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  typename\
    \ M::T square(const typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template\
    \ <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 1 \"tools/vector4.hpp\"\n\n\n\n#line 5 \"tools/vector4.hpp\"\
    \n#include <functional>\n#include <utility>\n#include <cstddef>\n#line 1 \"tools/detail/vector_static_common.hpp\"\
    \n\n\n\n#line 7 \"tools/detail/vector_static_common.hpp\"\n\n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V)\
    \ \\\n  using reference = T&;\\\n  using const_reference = const T&;\\\n  using\
    \ size_type = ::std::size_t;\\\n  using difference_type = ::std::ptrdiff_t;\\\n\
    \  using pointer = T*;\\\n  using const_pointer = const T*;\\\n  using value_type\
    \ = T;\\\n\\\n  constexpr size_type size() const {\\\n    return this->m_refs.size();\\\
    \n  }\\\n  reference operator[](const size_type n) {\\\n    return this->m_refs[n].get();\\\
    \n  }\\\n  const_reference operator[](const size_type n) const {\\\n    return\
    \ this->m_refs[n].get();\\\n  }\\\n\\\n  V& operator=(const V& other) {\\\n  \
    \  for (size_type i = 0; i < this->size(); ++i) {\\\n      (*this)[i] = other[i];\\\
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
    \ other[i]);\\\n    }\\\n  }\n\n\n#line 1 \"tools/detail/vector_common.hpp\"\n\
    \n\n\n#line 10 \"tools/detail/vector_common.hpp\"\n#include <string>\n#line 1\
    \ \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const float\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\n\n\
    #define TOOLS_DETAIL_VECTOR_COMMON(V) \\\n  private:\\\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
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
    \ * ::tools::log(base));\n  }\n}\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace\
    \ tools {\n\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\
    \n  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 10 \"tests/quaternion/look_rotation.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const std::array<tools::vector3<double>, 6> six_directions = {\n    tools::vector3<double>(0,\
    \ 1, 0),\n    tools::vector3<double>(0, 0, 1),\n    tools::vector3<double>(1,\
    \ 0, 0),\n    tools::vector3<double>(-1, 0, 0),\n    tools::vector3<double>(0,\
    \ 0, -1),\n    tools::vector3<double>(0, -1, 0)\n  };\n\n  std::array<int, 6>\
    \ faces;\n  for (auto& f : faces) std::cin >> f;\n  int Q;\n  std::cin >> Q;\n\
    \  for (int i = 0; i < Q; ++i) {\n    int top_face, front_face;\n    std::cin\
    \ >> top_face >> front_face;\n    const auto top_direction = six_directions[std::distance(faces.begin(),\
    \ std::find(faces.begin(), faces.end(), top_face))];\n    const auto front_direction\
    \ = six_directions[std::distance(faces.begin(), std::find(faces.begin(), faces.end(),\
    \ front_face))];\n    const auto q = ::tools::quaternion<double>::look_rotation(front_direction,\
    \ top_direction);\n    const auto answer_with_error = q * tools::vector3<double>(1,\
    \ 0, 0);\n\n    std::cout << faces[std::distance(six_directions.begin(), std::min_element(six_directions.begin(),\
    \ six_directions.end(), tools::less_by([&](const auto& possible_answer) {\n  \
    \    return (possible_answer - answer_with_error).squared_l2_norm();\n    })))]\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B\"\n\
    \n#include <iostream>\n#include <array>\n#include <algorithm>\n#include <iterator>\n\
    #include \"tools/quaternion.hpp\"\n#include \"tools/vector3.hpp\"\n#include \"\
    tools/less_by.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const std::array<tools::vector3<double>, 6> six_directions = {\n    tools::vector3<double>(0,\
    \ 1, 0),\n    tools::vector3<double>(0, 0, 1),\n    tools::vector3<double>(1,\
    \ 0, 0),\n    tools::vector3<double>(-1, 0, 0),\n    tools::vector3<double>(0,\
    \ 0, -1),\n    tools::vector3<double>(0, -1, 0)\n  };\n\n  std::array<int, 6>\
    \ faces;\n  for (auto& f : faces) std::cin >> f;\n  int Q;\n  std::cin >> Q;\n\
    \  for (int i = 0; i < Q; ++i) {\n    int top_face, front_face;\n    std::cin\
    \ >> top_face >> front_face;\n    const auto top_direction = six_directions[std::distance(faces.begin(),\
    \ std::find(faces.begin(), faces.end(), top_face))];\n    const auto front_direction\
    \ = six_directions[std::distance(faces.begin(), std::find(faces.begin(), faces.end(),\
    \ front_face))];\n    const auto q = ::tools::quaternion<double>::look_rotation(front_direction,\
    \ top_direction);\n    const auto answer_with_error = q * tools::vector3<double>(1,\
    \ 0, 0);\n\n    std::cout << faces[std::distance(six_directions.begin(), std::min_element(six_directions.begin(),\
    \ six_directions.end(), tools::less_by([&](const auto& possible_answer) {\n  \
    \    return (possible_answer - answer_with_error).squared_l2_norm();\n    })))]\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/quaternion.hpp
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
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/quaternion/look_rotation.test.cpp
  requiredBy: []
  timestamp: '2022-11-12 13:21:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/quaternion/look_rotation.test.cpp
layout: document
redirect_from:
- /verify/tests/quaternion/look_rotation.test.cpp
- /verify/tests/quaternion/look_rotation.test.cpp.html
title: tests/quaternion/look_rotation.test.cpp
---
