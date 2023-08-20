---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':question:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':question:'
    path: tools/detail/vector_static_common.hpp
    title: tools/detail/vector_static_common.hpp
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':question:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':question:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A
  bundledCode: "#line 1 \"tests/convex_hull.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <iterator>\n#include <algorithm>\n\
    #include <utility>\n#line 1 \"tools/vector2.hpp\"\n\n\n\n#include <array>\n#include\
    \ <functional>\n#line 7 \"tools/vector2.hpp\"\n#include <cstddef>\n#line 1 \"\
    tools/detail/vector_static_common.hpp\"\n\n\n\n#line 7 \"tools/detail/vector_static_common.hpp\"\
    \n\n#define TOOLS_DETAIL_VECTOR_STATIC_COMMON(V) \\\n  using reference = T&;\\\
    \n  using const_reference = const T&;\\\n  using size_type = ::std::size_t;\\\n\
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
    \n\n\n#include <type_traits>\n#include <cassert>\n#line 8 \"tools/detail/vector_common.hpp\"\
    \n#include <cmath>\n#line 10 \"tools/detail/vector_common.hpp\"\n#include <string>\n\
    #line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const\
    \ float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\
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
    \n\n\n\n#line 5 \"tools/tuple_hash.hpp\"\n#include <tuple>\n#include <limits>\n\
    #line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline\
    \ long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
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
    \      }\n    }\n  };\n}\n\n\n#line 11 \"tools/vector2.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T>\n  class vector2 {\n  public:\n    T x;\n    T y;\n\
    \n  private:\n    ::std::array<::std::reference_wrapper<T>, 2> m_refs;\n\n  public:\n\
    \    vector2(const T& x, const T& y) : x(x), y(y), m_refs({::std::ref(this->x),\
    \ ::std::ref(this->y)}) {}\n    vector2() : vector2(T(), T()) {}\n    vector2(const\
    \ ::tools::vector2<T>& other) : vector2(other.x, other.y) {}\n    ~vector2() =\
    \ default;\n\n    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector2<T>)\n   \
    \ TOOLS_DETAIL_VECTOR_COMMON(::tools::vector2<T>)\n\n  public:\n    T outer_product(const\
    \ ::tools::vector2<T>& other) const {\n      return this->x * other.y - this->y\
    \ * other.x;\n    }\n\n    ::tools::vector2<T> turned90() const {\n      return\
    \ ::tools::vector2<T>(-this->y, this->x);\n    }\n\n    ::tools::vector2<T> turned270()\
    \ const {\n      return ::tools::vector2<T>(this->y, -this->x);\n    }\n\n   \
    \ static ::std::array<::tools::vector2<T>, 4> four_directions() {\n      return\
    \ ::std::array<::tools::vector2<T>, 4>({\n        ::tools::vector2<T>(T(1), T(0)),\n\
    \        ::tools::vector2<T>(T(0), T(1)),\n        ::tools::vector2<T>(T(-1),\
    \ T(0)),\n        ::tools::vector2<T>(T(0), T(-1))\n      });\n    }\n\n    static\
    \ ::std::array<::tools::vector2<T>, 8> eight_directions() {\n      return ::std::array<::tools::vector2<T>,\
    \ 8>({\n        ::tools::vector2<T>(T(1), T(0)),\n        ::tools::vector2<T>(T(1),\
    \ T(1)),\n        ::tools::vector2<T>(T(0), T(1)),\n        ::tools::vector2<T>(T(-1),\
    \ T(1)),\n        ::tools::vector2<T>(T(-1), T(0)),\n        ::tools::vector2<T>(T(-1),\
    \ T(-1)),\n        ::tools::vector2<T>(T(0), T(-1)),\n        ::tools::vector2<T>(T(1),\
    \ T(-1))\n      });\n    }\n  };\n}\n\nnamespace std {\n  template <typename T>\n\
    \  struct hash<::tools::vector2<T>> {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::tools::vector2<T>;\n    ::std::size_t operator()(const\
    \ ::tools::vector2<T>& key) const {\n      static const ::tools::tuple_hash<T,\
    \ T> hasher;\n      return hasher(::std::make_tuple(key.x, key.y));\n    }\n \
    \ };\n}\n\n\n#line 1 \"tools/convex_hull.hpp\"\n\n\n\n#line 7 \"tools/convex_hull.hpp\"\
    \n#include <numeric>\n#line 11 \"tools/convex_hull.hpp\"\n#include <stack>\n#line\
    \ 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n \
    \ class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/ccw.hpp\"\n\n\n\n#line 5 \"tools/ccw.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  int ccw(const ::tools::vector2<T>&\
    \ a, ::tools::vector2<T> b, ::tools::vector2<T> c) {\n    b -= a;\n    c -= a;\n\
    \    if (b.outer_product(c) > T(0)) return +1;\n    if (b.outer_product(c) < T(0))\
    \ return -1;\n    if (b.inner_product(c) < T(0)) return +2;\n    if (b.squared_l2_norm()\
    \ < c.squared_l2_norm()) return -2;\n    return 0;\n  }\n}\n\n\n#line 15 \"tools/convex_hull.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void convex_hull(const InputIterator begin, const InputIterator end, bool minimum,\
    \ OutputIterator result) {\n    using T = ::std::decay_t<decltype(begin->x)>;\n\
    \n    const ::std::vector<::tools::vector2<T>> v(begin, end);\n    ::std::vector<::std::size_t>\
    \ a(v.size());\n    ::std::iota(a.begin(), a.end(), 0);\n    ::std::sort(a.begin(),\
    \ a.end(), ::tools::less_by([&](const ::std::size_t i) {\n      return ::std::make_pair(v[i].x,\
    \ v[i].y);\n    }));\n    ::std::vector<::std::vector<::std::size_t>> duplicates;\n\
    \n    if (minimum) {\n      ::std::size_t vl = 0;\n      for (::std::size_t vr\
    \ = 0, al = 0, ar = 0; al < a.size(); vl = vr, al = ar) {\n        for (; ar <\
    \ a.size() && v[a[al]].x == v[a[ar]].x; ++vr, ++ar);\n        if (vl < al) ::std::move(::std::next(a.begin(),\
    \ al), ::std::next(a.begin(), ar), ::std::next(a.begin(), vl));\n        if (v[a[vl]].y\
    \ == v[a[vr - 1]].y) {\n          vr -= vr - vl - 1;\n          duplicates.emplace_back();\n\
    \          duplicates.back().push_back(a[vl]);\n        } else {\n          ::std::swap(a[vl\
    \ + 1], a[vr - 1]);\n          vr -= vr - vl - 2;\n          duplicates.emplace_back();\n\
    \          duplicates.back().push_back(a[vl]);\n          duplicates.emplace_back();\n\
    \          duplicates.back().push_back(a[vl + 1]);\n        }\n      }\n     \
    \ a.erase(::std::next(a.begin(), vl), a.end());\n    } else {\n      ::std::size_t\
    \ vl = 0;\n      for (::std::size_t vr = 0, al = 0, ar = 0; al < a.size(); vl\
    \ = vr, al = ar) {\n        for (; ar < a.size() && v[a[al]] == v[a[ar]]; ++vr,\
    \ ++ar);\n        if (vl < al) ::std::move(::std::next(a.begin(), al), ::std::next(a.begin(),\
    \ ar), ::std::next(a.begin(), vl));\n        duplicates.emplace_back();\n    \
    \    for (::std::size_t i = vl; i < vr; ++i) {\n          duplicates.back().push_back(a[i]);\n\
    \        }\n        vr -= vr - vl - 1;\n      }\n      a.erase(::std::next(a.begin(),\
    \ vl), a.end());\n    }\n\n    ::std::vector<::std::size_t> convex_hull;\n   \
    \ if (a.size() >= 3) {\n\n      convex_hull.push_back(0);\n      convex_hull.push_back(1);\n\
    \      for (::std::size_t p3 = 2; p3 < a.size(); ++p3) {\n        while (convex_hull.size()\
    \ >= 2) {\n          const int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]],\
    \ v[a[convex_hull.back()]], v[a[p3]]);\n          if (ccw == 1 || (!minimum &&\
    \ ccw == -2)) {\n            break;\n          }\n          convex_hull.pop_back();\n\
    \        }\n        convex_hull.push_back(p3);\n      }\n\n      const ::std::size_t\
    \ threshold = convex_hull.size() + 1;\n      for (::std::size_t p3 = convex_hull.back();\
    \ p3 --> 0;) {\n        while (convex_hull.size() >= threshold) {\n          const\
    \ int ccw = ::tools::ccw(v[a[convex_hull.rbegin()[1]]], v[a[convex_hull.back()]],\
    \ v[a[p3]]);\n          if (ccw == 1 || (!minimum && ccw == -2)) {\n         \
    \   break;\n          }\n          convex_hull.pop_back();\n        }\n      \
    \  convex_hull.push_back(p3);\n      }\n      convex_hull.pop_back();\n\n    }\
    \ else {\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n        convex_hull.push_back(i);\n\
    \      }\n    }\n\n    for (const ::std::size_t& c : convex_hull) {\n      for\
    \ (const ::std::size_t& i : duplicates[c]) {\n        if constexpr (::std::is_assignable_v<OutputIterator,\
    \ ::std::size_t>) {\n          *result = i;\n        } else {\n          *result\
    \ = v[i];\n        }\n        ++result;\n      }\n    }\n  }\n}\n\n\n#line 11\
    \ \"tests/convex_hull.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll n;\n  std::cin >> n;\n  std::vector<tools::vector2<ll>>\
    \ v(n);\n  for (ll i = 0; i < n; ++i) {\n    std::cin >> v[i].x >> v[i].y;\n \
    \ }\n\n  std::vector<ll> convex_hull;\n  tools::convex_hull(v.begin(), v.end(),\
    \ false, std::back_inserter(convex_hull));\n\n  std::rotate(\n    convex_hull.begin(),\n\
    \    std::min_element(convex_hull.begin(), convex_hull.end(), tools::less_by([&](const\
    \ ll& i) { return std::make_pair(v[i].y, v[i].x); })),\n    convex_hull.end()\n\
    \  );\n\n  std::cout << convex_hull.size() << '\\n';\n  for (const ll& i : convex_hull)\
    \ {\n    std::cout << v[i].x << ' ' << v[i].y << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <iterator>\n#include <algorithm>\n\
    #include <utility>\n#include \"tools/vector2.hpp\"\n#include \"tools/convex_hull.hpp\"\
    \n#include \"tools/less_by.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll n;\n  std::cin >> n;\n  std::vector<tools::vector2<ll>>\
    \ v(n);\n  for (ll i = 0; i < n; ++i) {\n    std::cin >> v[i].x >> v[i].y;\n \
    \ }\n\n  std::vector<ll> convex_hull;\n  tools::convex_hull(v.begin(), v.end(),\
    \ false, std::back_inserter(convex_hull));\n\n  std::rotate(\n    convex_hull.begin(),\n\
    \    std::min_element(convex_hull.begin(), convex_hull.end(), tools::less_by([&](const\
    \ ll& i) { return std::make_pair(v[i].y, v[i].x); })),\n    convex_hull.end()\n\
    \  );\n\n  std::cout << convex_hull.size() << '\\n';\n  for (const ll& i : convex_hull)\
    \ {\n    std::cout << v[i].x << ' ' << v[i].y << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/detail/vector_static_common.hpp
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  - tools/convex_hull.hpp
  - tools/less_by.hpp
  - tools/ccw.hpp
  isVerificationFile: true
  path: tests/convex_hull.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 13:03:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/convex_hull.test.cpp
layout: document
redirect_from:
- /verify/tests/convex_hull.test.cpp
- /verify/tests/convex_hull.test.cpp.html
title: tests/convex_hull.test.cpp
---
