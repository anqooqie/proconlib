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
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':question:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector3.hpp\"\n\n\n\n#include <array>\n#include <functional>\n\
    #include <utility>\n#include <cassert>\n#include <cstddef>\n#line 1 \"tools/detail/vector_static_common.hpp\"\
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
    \ *this;\\\n  }\\\n\\\n  class iterator {\\\n  private:\\\n    V* m_parent;\\\n\
    \    size_type m_i;\\\n\\\n  public:\\\n    using difference_type = ::std::ptrdiff_t;\\\
    \n    using value_type = T;\\\n    using reference = T&;\\\n    using pointer\
    \ = T*;\\\n    using iterator_category = ::std::random_access_iterator_tag;\\\n\
    \\\n    iterator(V * const parent, const size_type i) : m_parent(parent), m_i(i)\
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
    \n\n\n#include <type_traits>\n#line 7 \"tools/detail/vector_common.hpp\"\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iostream>\n#include <string>\n#line\
    \ 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const float\
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
    \n\n\n\n#line 5 \"tools/tuple_hash.hpp\"\n#include <tuple>\n#include <limits>\n\
    #line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\nnamespace tools {\n  long\
    \ long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
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
    \      }\n    }\n  };\n}\n\n\n#line 12 \"tools/vector3.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T>\n  class vector3 {\n  public:\n    T x;\n    T y;\n\
    \    T z;\n\n  private:\n    ::std::array<::std::reference_wrapper<T>, 3> m_refs;\n\
    \n  public:\n    vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z),\
    \ m_refs({::std::ref(this->x), ::std::ref(this->y), ::std::ref(this->z)}) {}\n\
    \    vector3() : vector3(T(), T(), T()) {}\n    vector3(const ::tools::vector3<T>&\
    \ other) : vector3(other.x, other.y, other.z) {}\n    ~vector3() = default;\n\n\
    \    TOOLS_DETAIL_VECTOR_STATIC_COMMON(::tools::vector3<T>)\n    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector3<T>)\n\
    \n  public:\n    ::tools::vector3<T> outer_product(const ::tools::vector3<T>&\
    \ other) const {\n      return ::tools::vector3<T>(this->y * other.z - this->z\
    \ * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y\
    \ * other.x);\n    }\n\n    template <typename T_ = T>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::array<::tools::vector3<T>, 3>> orthonormal_basis() const {\n      assert(*this\
    \ != ::tools::vector3<T>(0, 0, 0));\n\n      ::std::array<::tools::vector3<T>,\
    \ 3> v;\n      v[0] = *this;\n      v[1] = ::tools::vector3<T>(0, this->z, -this->y);\n\
    \      if (v[1] == ::tools::vector3<T>(0, 0, 0)) {\n        v[1] = ::tools::vector3<T>(-this->z,\
    \ 0, this->x);\n      }\n      v[1] -= v[0].inner_product(v[1]) / v[0].inner_product(v[0])\
    \ * v[0];\n\n      v[0] = v[0].normalized();\n      v[1] = v[1].normalized();\n\
    \      v[2] = v[0].outer_product(v[1]);\n\n      return v;\n    }\n  };\n}\n\n\
    namespace std {\n  template <typename T>\n  struct hash<::tools::vector3<T>> {\n\
    \    using result_type = ::std::size_t;\n    using argument_type = ::tools::vector3<T>;\n\
    \    ::std::size_t operator()(const ::tools::vector3<T>& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR3_HPP\n#define TOOLS_VECTOR3_HPP\n\n#include <array>\n\
    #include <functional>\n#include <utility>\n#include <cassert>\n#include <cstddef>\n\
    #include \"tools/detail/vector_static_common.hpp\"\n#include \"tools/detail/vector_common.hpp\"\
    \n#include \"tools/tuple_hash.hpp\"\n\nnamespace tools {\n  template <typename\
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
    \ key.y, key.z));\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/detail/vector_static_common.hpp
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/vector3.hpp
  requiredBy:
  - tools/quaternion.hpp
  timestamp: '2022-11-12 11:43:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
documentation_of: tools/vector3.hpp
layout: document
title: Three dimensional vector
---

It is a three-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::array&lt;T, 3&gt;
```cpp
vector3<T> v(const vector3<T>& u);
vector3<T>& v.operator=(const vector3<T>& u);

(vector3<T>::iterator or vector3<T>::const_iterator) v.begin();
(vector3<T>::iterator or vector3<T>::const_iterator) v.end();
vector3<T>::const_iterator v.cbegin();
vector3<T>::const_iterator v.cend();
(vector3<T>::reverse_iterator or vector3<T>::const_reverse_iterator) v.rbegin();
(vector3<T>::reverse_iterator or vector3<T>::const_reverse_iterator) v.rend();
vector3<T>::const_reverse_iterator v.crbegin();
vector3<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

void v.swap(vector3<T>& u);

bool operator==(vector3<T> v, vector3<T> u);
bool operator!=(vector3<T> v, vector3<T> u);
```

They are methods based on `std::array<T, 3>`.

### Constraints
- Same as ones of `std::array<T, 3>`.

### Time Complexity
- Same as ones of `std::array<T, 3>`.

## Constructor
```cpp
(1) vector3<T> v();
(2) vector3<T> v(T x, T y, T z);
```

- (1)
    - It creates a vector $(0, 0, 0)$.
- (2)
    - It creates a vector $(x, y, z)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## x
```cpp
T v.x;
```

It is identical to `v[0]`.

## y
```cpp
T v.y;
```

It is identical to `v[1]`.

## z
```cpp
T v.z;
```

It is identical to `v[2]`.

## Arithmetic operators
```cpp
(1) vector3<T> operator+(vector3<T> v);
(2) vector3<T> operator-(vector3<T> v);
(3) vector3<T>& v.operator+=(vector3<T> u);
(4) vector3<T> operator+(vector3<T> v, vector3<T> u);
(5) vector3<T>& v.operator-=(vector3<T> u);
(6) vector3<T> operator-(vector3<T> v, vector3<T> u);
(7) vector3<T>& v.operator*=(T c);
(8) vector3<T> operator*(T c, vector3<T> v);
(9) vector3<T> operator*(vector3<T> v, T c);
(10) vector3<T>& v.operator/=(T c);
(11) vector3<T> operator/(vector3<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(vector3<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## outer_product
```cpp
vector3<T> v.outer_product(vector3<T> u);
```

It returns $\overrightarrow{v} \times \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1 = \|x\| + \|y\| + \|z\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2 + z^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l2_norm
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2 = \sqrt{x^2 + y^2 + z^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector3<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## orthonormal_basis
```cpp
std::array<vector3<T>, 3> v.orthonormal_basis();
```

It returns three vectors $u_1, u_2, u_3$ which satisfy the following conditions.

$$\begin{align*}
\left\{\begin{array}{l}
u_1 = \frac{v}{|v|}\\
|u_2| = 1\\
u_1 \cdot u_2 = 0\\
u_3 = u_1 \times u_2
\end{array}\right.&
\end{align*}$$

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector3<T>& self);
```

It returns `is >> self.x >> self.y >> self.z`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector3<T>& self);
```

It returns `os << '(' << self.x << ", " << self.y << ", " << self.z << ')'`.

### Constraints
- None

### Time Complexity
- $O(1)$
