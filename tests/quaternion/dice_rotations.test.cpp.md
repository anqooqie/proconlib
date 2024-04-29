---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/exp.hpp
    title: std::exp(x) extended for my library
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
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
  - icon: ':question:'
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
  - icon: ':question:'
    path: tools/vector.hpp
    title: Vector
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C
  bundledCode: "#line 1 \"tests/quaternion/dice_rotations.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C\"\n\n#include <iostream>\n\
    #include <array>\n#include <cstddef>\n#include <iterator>\n#include <algorithm>\n\
    #line 1 \"tools/vector3.hpp\"\n\n\n\n#line 1 \"tools/vector.hpp\"\n\n\n\n#line\
    \ 6 \"tools/vector.hpp\"\n#include <initializer_list>\n#include <cassert>\n#include\
    \ <limits>\n#include <vector>\n#include <type_traits>\n#line 13 \"tools/vector.hpp\"\
    \n#include <utility>\n#include <cmath>\n#line 16 \"tools/vector.hpp\"\n#include\
    \ <string>\n#include <functional>\n#include <tuple>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n   \
    \ return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n \
    \   return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n \
    \   return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 1 \"tools/tuple_hash.hpp\"\n\n\n\n#line\
    \ 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline\
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
    \      }\n    }\n  };\n}\n\n\n#line 21 \"tools/vector.hpp\"\n\nnamespace tools\
    \ {\n  namespace detail {\n    namespace vector {\n      template <typename T,\
    \ ::std::size_t N>\n      class members {\n      protected:\n        constexpr\
    \ static bool variable_sized = false;\n        constexpr static bool has_aliases\
    \ = false;\n        ::std::array<T, N> m_values;\n        members() : m_values()\
    \ {}\n        members(const ::std::initializer_list<T> il) : m_values(il) {\n\
    \          assert(il.size() == N);\n        }\n      };\n\n      template <typename\
    \ T>\n      class members<T, 2> {\n      protected:\n        constexpr static\
    \ bool variable_sized = false;\n        constexpr static bool has_aliases = true;\n\
    \        ::std::array<T*, 2> m_values;\n        members() : m_values{&this->x,\
    \ &this->y} {}\n        members(const T& x, const T& y) : m_values{&this->x, &this->y},\
    \ x(x), y(y) {}\n        members(const ::std::initializer_list<T> il) : m_values{&this->x,\
    \ &this->y}, x(il.begin()[0]), y(il.begin()[1]) {\n          assert(il.size()\
    \ == 2);\n        }\n\n      public:\n        T x;\n        T y;\n      };\n\n\
    \      template <typename T>\n      class members<T, 3> {\n      protected:\n\
    \        constexpr static bool variable_sized = false;\n        constexpr static\
    \ bool has_aliases = true;\n        ::std::array<T*, 3> m_values;\n        members()\
    \ : m_values{&this->x, &this->y, &this->z} {}\n        members(const T& x, const\
    \ T& y, const T& z) : m_values{&this->x, &this->y, &this->z}, x(x), y(y), z(z)\
    \ {}\n        members(const ::std::initializer_list<T> il) : m_values{&this->x,\
    \ &this->y, &this->z}, x(il.begin()[0]), y(il.begin()[1]), z(il.begin()[2]) {\n\
    \          assert(il.size() == 3);\n        }\n\n      public:\n        T x;\n\
    \        T y;\n        T z;\n      };\n\n      template <typename T>\n      class\
    \ members<T, 4> {\n      protected:\n        constexpr static bool variable_sized\
    \ = false;\n        constexpr static bool has_aliases = true;\n        ::std::array<T*,\
    \ 4> m_values;\n        members() : m_values{&this->x, &this->y, &this->z, &this->w}\
    \ {}\n        members(const T& x, const T& y, const T& z, const T& w) : m_values{&this->x,\
    \ &this->y, &this->z, &this->w}, x(x), y(y), z(z), w(w) {}\n        members(const\
    \ ::std::initializer_list<T> il) : m_values{&this->x, &this->y, &this->z, &this->w},\
    \ x(il.begin()[0]), y(il.begin()[1]), z(il.begin()[2]), w(il.begin()[3]) {\n \
    \         assert(il.size() == 4);\n        }\n\n      public:\n        T x;\n\
    \        T y;\n        T z;\n        T w;\n      };\n\n      template <typename\
    \ T>\n      class members<T, ::std::numeric_limits<::std::size_t>::max()> {\n\
    \      protected:\n        constexpr static bool variable_sized = true;\n    \
    \    constexpr static bool has_aliases = false;\n        ::std::vector<T> m_values;\n\
    \        members() = default;\n        members(const ::std::size_t n) : m_values(n)\
    \ {}\n        members(const ::std::size_t n, const T& value) : m_values(n, value)\
    \ {}\n        template <typename InputIter>\n        members(const InputIter first,\
    \ const InputIter last) : m_values(first, last) {}\n        members(const ::std::initializer_list<T>\
    \ il) : m_values(il) {}\n      };\n    }\n  }\n\n  template <typename T, ::std::size_t\
    \ N = ::std::numeric_limits<::std::size_t>::max()>\n  class vector : public ::tools::detail::vector::members<T,\
    \ N> {\n  private:\n    using Base = ::tools::detail::vector::members<T, N>;\n\
    \    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\n\
    \    using V = ::tools::vector<T, N>;\n    constexpr static bool variable_sized\
    \ = Base::variable_sized;\n    constexpr static bool has_aliases = Base::has_aliases;\n\
    \n  public:\n    using reference = T&;\n    using const_reference = const T&;\n\
    \    using size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using pointer = T*;\n    using const_pointer = const T*;\n    using value_type\
    \ = T;\n    class iterator {\n    private:\n      V* m_parent;\n      size_type\
    \ m_i;\n\n    public:\n      using difference_type = ::std::ptrdiff_t;\n     \
    \ using value_type = T;\n      using reference = T&;\n      using pointer = T*;\n\
    \      using iterator_category = ::std::random_access_iterator_tag;\n\n      iterator()\
    \ = default;\n      iterator(const iterator&) = default;\n      iterator(iterator&&)\
    \ = default;\n      ~iterator() = default;\n      iterator& operator=(const iterator&)\
    \ = default;\n      iterator& operator=(iterator&&) = default;\n\n      iterator(V\
    \ * const parent, const size_type i) : m_parent(parent), m_i(i) {}\n\n      reference\
    \ operator*() const {\n        return (*this->m_parent)[this->m_i];\n      }\n\
    \      pointer operator->() const {\n        return &(*(*this));\n      }\n\n\
    \      iterator& operator++() {\n        ++this->m_i;\n        return *this;\n\
    \      }\n      iterator operator++(int) {\n        const auto self = *this;\n\
    \        ++*this;\n        return self;\n      }\n      iterator& operator--()\
    \ {\n        --this->m_i;\n        return *this;\n      }\n      iterator operator--(int)\
    \ {\n        const auto self = *this;\n        --*this;\n        return self;\n\
    \      }\n      iterator& operator+=(const difference_type n) {\n        this->m_i\
    \ += n;\n        return *this;\n      }\n      iterator& operator-=(const difference_type\
    \ n) {\n        this->m_i -= n;\n        return *this;\n      }\n      friend\
    \ iterator operator+(const iterator& self, const difference_type n) {\n      \
    \  return iterator(self) += n;\n      }\n      friend iterator operator+(const\
    \ difference_type n, const iterator& self) {\n        return iterator(self) +=\
    \ n;\n      }\n      friend iterator operator-(const iterator& self, const difference_type\
    \ n) {\n        return iterator(self) -= n;\n      }\n      friend difference_type\
    \ operator-(const iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);\n\
    \      }\n      reference operator[](const difference_type n) const {\n      \
    \  return *(*this + n);\n      }\n\n      friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i == rhs.m_i;\n      }\n      friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i != rhs.m_i;\n      }\n      friend bool operator<(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i < rhs.m_i;\n      }\n      friend bool operator<=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i <= rhs.m_i;\n      }\n      friend bool operator>(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i > rhs.m_i;\n      }\n      friend bool operator>=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i >= rhs.m_i;\n      }\n    };\n    class const_iterator\
    \ {\n    private:\n      const V *m_parent;\n      size_type m_i;\n\n    public:\n\
    \      using difference_type = ::std::ptrdiff_t;\n      using value_type = T;\n\
    \      using reference = const T&;\n      using pointer = const T*;\n      using\
    \ iterator_category = ::std::random_access_iterator_tag;\n\n      const_iterator()\
    \ = default;\n      const_iterator(const const_iterator&) = default;\n      const_iterator(const_iterator&&)\
    \ = default;\n      ~const_iterator() = default;\n      const_iterator& operator=(const\
    \ const_iterator&) = default;\n      const_iterator& operator=(const_iterator&&)\
    \ = default;\n\n      const_iterator(const V * const parent, const size_type i)\
    \ : m_parent(parent), m_i(i) {}\n\n      reference operator*() const {\n     \
    \   return (*this->m_parent)[this->m_i];\n      }\n      pointer operator->()\
    \ const {\n        return &(*(*this));\n      }\n\n      const_iterator& operator++()\
    \ {\n        ++this->m_i;\n        return *this;\n      }\n      const_iterator\
    \ operator++(int) {\n        const auto self = *this;\n        ++*this;\n    \
    \    return self;\n      }\n      const_iterator& operator--() {\n        --this->m_i;\n\
    \        return *this;\n      }\n      const_iterator operator--(int) {\n    \
    \    const auto self = *this;\n        --*this;\n        return self;\n      }\n\
    \      const_iterator& operator+=(const difference_type n) {\n        this->m_i\
    \ += n;\n        return *this;\n      }\n      const_iterator& operator-=(const\
    \ difference_type n) {\n        this->m_i -= n;\n        return *this;\n     \
    \ }\n      friend const_iterator operator+(const const_iterator& self, const difference_type\
    \ n) {\n        return const_iterator(self) += n;\n      }\n      friend const_iterator\
    \ operator+(const difference_type n, const const_iterator& self) {\n        return\
    \ const_iterator(self) += n;\n      }\n      friend const_iterator operator-(const\
    \ const_iterator& self, const difference_type n) {\n        return const_iterator(self)\
    \ -= n;\n      }\n      friend difference_type operator-(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);\n\
    \      }\n      reference operator[](const difference_type n) const {\n      \
    \  return *(*this + n);\n      }\n\n      friend bool operator==(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i == rhs.m_i;\n      }\n      friend bool operator!=(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i != rhs.m_i;\n      }\n      friend\
    \ bool operator<(const const_iterator& lhs, const const_iterator& rhs) {\n   \
    \     assert(lhs.m_parent == rhs.m_parent);\n        return lhs.m_i < rhs.m_i;\n\
    \      }\n      friend bool operator<=(const const_iterator& lhs, const const_iterator&\
    \ rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n        return lhs.m_i\
    \ <= rhs.m_i;\n      }\n      friend bool operator>(const const_iterator& lhs,\
    \ const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i > rhs.m_i;\n      }\n      friend bool operator>=(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i >= rhs.m_i;\n      }\n    };\n   \
    \ using reverse_iterator = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator\
    \ = ::std::reverse_iterator<const_iterator>;\n\n    vector() = default;\n    vector(const\
    \ V& other) : Base() {\n      if constexpr (has_aliases) {\n        ::std::copy(other.begin(),\
    \ other.end(), this->begin());\n      } else {\n        this->m_values = other.m_values;\n\
    \      }\n    }\n    vector(V&& other) noexcept {\n      if constexpr (has_aliases)\
    \ {\n        ::std::copy(other.begin(), other.end(), this->begin());\n      }\
    \ else {\n        this->m_values = ::std::move(other.m_values);\n      }\n   \
    \ }\n    ~vector() = default;\n    V& operator=(const V& other) {\n      if constexpr\
    \ (has_aliases) {\n        ::std::copy(other.begin(), other.end(), this->begin());\n\
    \      } else {\n        this->m_values = other.m_values;\n      }\n      return\
    \ *this;\n    }\n    V& operator=(V&& other) noexcept {\n      if constexpr (has_aliases)\
    \ {\n        ::std::copy(other.begin(), other.end(), this->begin());\n      }\
    \ else {\n        this->m_values = ::std::move(other.m_values);\n      }\n   \
    \   return *this;\n    }\n\n    template <bool SFINAE = variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    explicit vector(size_type n) : Base(n) {}\n\
    \    template <bool SFINAE = variable_sized, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    vector(size_type n, const_reference value) : Base(n, value)\
    \ {}\n    template <typename InputIter, bool SFINAE = variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    vector(const InputIter first, const InputIter\
    \ last) : Base(first, last) {}\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    vector(const T& x, const T& y) : Base(x, y)\
    \ {}\n    template <bool SFINAE = N == 3, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    vector(const T& x, const T& y, const T& z) : Base(x, y, z) {}\n\
    \    template <bool SFINAE = N == 4, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    vector(const T& x, const T& y, const T& z, const T& w) : Base(x,\
    \ y, z, w) {}\n    vector(const ::std::initializer_list<T> il) : Base(il) {}\n\
    \n    iterator begin() noexcept { return iterator(this, 0); }\n    const_iterator\
    \ begin() const noexcept { return const_iterator(this, 0); }\n    const_iterator\
    \ cbegin() const noexcept { return const_iterator(this, 0); }\n    iterator end()\
    \ noexcept { return iterator(this, this->size()); }\n    const_iterator end()\
    \ const noexcept { return const_iterator(this, this->size()); }\n    const_iterator\
    \ cend() const noexcept { return const_iterator(this, this->size()); }\n    reverse_iterator\
    \ rbegin() noexcept { return ::std::make_reverse_iterator(this->end()); }\n  \
    \  const_reverse_iterator rbegin() const noexcept { return ::std::make_reverse_iterator(this->end());\
    \ }\n    const_reverse_iterator crbegin() const noexcept { return ::std::make_reverse_iterator(this->cend());\
    \ }\n    reverse_iterator rend() noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator rend() const noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator crend() const noexcept { return ::std::make_reverse_iterator(this->cbegin());\
    \ }\n\n    size_type size() const noexcept { return this->m_values.size(); }\n\
    \    bool empty() const noexcept { return this->m_values.empty(); }\n\n    reference\
    \ operator[](const size_type n) {\n      if constexpr (has_aliases) {\n      \
    \  return *this->m_values[n];\n      } else {\n        return this->m_values[n];\n\
    \      }\n    }\n    const_reference operator[](const size_type n) const {\n \
    \     if constexpr (has_aliases) {\n        return *this->m_values[n];\n     \
    \ } else {\n        return this->m_values[n];\n      }\n    }\n    reference front()\
    \ { return *this->begin(); }\n    const_reference front() const { return *this->begin();\
    \ }\n    reference back() { return *this->rbegin(); }\n    const_reference back()\
    \ const { return *this->rbegin(); }\n\n    V operator+() const {\n      return\
    \ *this;\n    }\n    V operator-() const {\n      V res = *this;\n      for (auto&\
    \ v : res) v = -v;\n      return res;\n    }\n    V& operator+=(const V& other)\
    \ {\n      assert(this->size() == other.size());\n      for (::std::size_t i =\
    \ 0; i < this->size(); ++i) {\n        (*this)[i] += other[i];\n      }\n    \
    \  return *this;\n    }\n    friend V operator+(const V& lhs, const V& rhs) {\n\
    \      return V(lhs) += rhs;\n    }\n    V& operator-=(const V& other) {\n   \
    \   assert(this->size() == other.size());\n      for (::std::size_t i = 0; i <\
    \ this->size(); ++i) {\n        (*this)[i] -= other[i];\n      }\n      return\
    \ *this;\n    }\n    friend V operator-(const V& lhs, const V& rhs) {\n      return\
    \ V(lhs) -= rhs;\n    }\n    V& operator*=(const T& c) {\n      for (auto& v :\
    \ *this) v *= c;\n      return *this;\n    }\n    friend V operator*(const T&\
    \ lhs, const V& rhs) {\n      return V(rhs) *= lhs;\n    }\n    friend V operator*(const\
    \ V& lhs, const T& rhs) {\n      return V(lhs) *= rhs;\n    }\n    V& operator/=(const\
    \ T& c) {\n      for (auto& v : *this) v /= c;\n      return *this;\n    }\n \
    \   friend V operator/(const V& lhs, const T& rhs) {\n      return V(lhs) /= rhs;\n\
    \    }\n\n    friend bool operator==(const V& lhs, const V& rhs) {\n      return\
    \ ::std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());\n    }\n    friend\
    \ bool operator!=(const V& lhs, const V& rhs) {\n      return !(lhs == rhs);\n\
    \    }\n\n    T inner_product(const V& other) const {\n      assert(this->size()\
    \ == other.size());\n      T res{};\n      for (::std::size_t i = 0; i < this->size();\
    \ ++i) {\n        res += (*this)[i] * other[i];\n      }\n      return res;\n\
    \    }\n    T l1_norm() const {\n      T res{};\n      for (const auto& v : *this)\
    \ {\n        res += ::tools::abs(v);\n      }\n      return res;\n    }\n    T\
    \ squared_l2_norm() const {\n      return this->inner_product(*this);\n    }\n\
    \    F l2_norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\n\
    \    }\n    template <bool SFINAE = ::std::is_floating_point_v<T>, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    V normalized() const {\n      return *this\
    \ / this->l2_norm();\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const V& self) {\n      os << '(';\n      ::std::string delimiter = \"\"\
    ;\n      for (const auto& v : self) {\n        os << delimiter << v;\n       \
    \ delimiter = \", \";\n      }\n      return os << ')';\n    }\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, V& self) {\n      for (auto& v : self) {\n  \
    \      is >> v;\n      }\n      return is;\n    }\n\n    template <bool SFINAE\
    \ = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    T outer_product(const\
    \ V& other) const {\n      return this->x * other.y - this->y * other.x;\n   \
    \ }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    V turned90() const {\n      return V{-this->y, this->x};\n \
    \   }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    V turned270() const {\n      return V{this->y, -this->x};\n\
    \    }\n\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    static const ::std::array<V, 4>& four_directions() {\n     \
    \ static const ::std::array<V, 4> res = {\n        V{T(1), T(0)},\n        V{T(0),\
    \ T(1)},\n        V{T(-1), T(0)},\n        V{T(0), T(-1)}\n      };\n      return\
    \ res;\n    }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    static const ::std::array<V, 8>& eight_directions()\
    \ {\n      static const ::std::array<V, 8> res = {\n        V{T(1), T(0)},\n \
    \       V{T(1), T(1)},\n        V{T(0), T(1)},\n        V{T(-1), T(1)},\n    \
    \    V{T(-1), T(0)},\n        V{T(-1), T(-1)},\n        V{T(0), T(-1)},\n    \
    \    V{T(1), T(-1)}\n      };\n      return res;\n    }\n\n    template <bool\
    \ SFINAE = N == 3, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n \
    \   V outer_product(const V& other) const {\n      return V{this->y * other.z\
    \ - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y\
    \ - this->y * other.x};\n    }\n    template <bool SFINAE = N == 3 && ::std::is_floating_point_v<T>,\
    \ ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    ::std::array<V,\
    \ 3> orthonormal_basis() const {\n      assert((*this != V{0, 0, 0}));\n\n   \
    \   ::std::array<V, 3> v;\n      v[0] = *this;\n      v[1] = V{0, this->z, -this->y};\n\
    \      if (v[1] == V{0, 0, 0}) {\n        v[1] = V{-this->z, 0, this->x};\n  \
    \    }\n      v[1] -= v[0].inner_product(v[1]) / v[0].inner_product(v[0]) * v[0];\n\
    \n      v[0] = v[0].normalized();\n      v[1] = v[1].normalized();\n      v[2]\
    \ = v[0].outer_product(v[1]);\n\n      return v;\n    }\n  };\n}\n\nnamespace\
    \ std {\n  template <typename T>\n  struct hash<::tools::vector<T, 2>> {\n   \
    \ using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 2>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y));\n    }\n  };\n  template <typename T>\n  struct hash<::tools::vector<T,\
    \ 3>> {\n    using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 3>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z));\n    }\n  };\n  template <typename T>\n  struct hash<::tools::vector<T,\
    \ 4>> {\n    using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 4>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n#line 5 \"tools/vector3.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  using vector3 = ::tools::vector<T,\
    \ 3>;\n}\n\n\n#line 1 \"tools/quaternion.hpp\"\n\n\n\n#line 8 \"tools/quaternion.hpp\"\
    \n#include <sstream>\n#include <random>\n#line 1 \"tools/exp.hpp\"\n\n\n\n#line\
    \ 5 \"tools/exp.hpp\"\n\nnamespace tools {\n  template <typename T>\n  auto exp(const\
    \ T x) {\n    return ::std::exp(x);\n  }\n}\n\n\n#line 1 \"tools/log.hpp\"\n\n\
    \n\n#line 5 \"tools/log.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  auto log(const T x) {\n    return ::std::log(x);\n  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\
    \n\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 6 \"tools/monoid.hpp\"\n#include\
    \ <numeric>\n\nnamespace tools {\n  namespace monoid {\n    template <typename\
    \ M, M E = ::std::numeric_limits<M>::lowest()>\n    struct max {\n      using\
    \ T = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::max(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename M, M E = ::std::numeric_limits<M>::max()>\n    struct\
    \ min {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n       \
    \ return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/is_monoid.hpp\"\
    \n\n\n\n#line 6 \"tools/is_monoid.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename = void>\n  struct is_monoid : ::std::false_type {};\n\n  template\
    \ <typename M>\n  struct is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ M::T, decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename\
    \ M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n  , void>>\
    \ : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr bool is_monoid_v\
    \ = ::tools::is_monoid<M>::value;\n}\n\n\n#line 6 \"tools/square.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M>\n  ::std::enable_if_t<::tools::is_monoid_v<M>,\
    \ typename M::T> square(const typename M::T& x) {\n    return M::op(x, x);\n \
    \ }\n\n  template <typename T>\n  ::std::enable_if_t<!::tools::is_monoid_v<T>,\
    \ T> square(const T& x) {\n    return x * x;\n  }\n}\n\n\n#line 9 \"tools/pow.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ typename M::T> pow(const typename M::T& base, const E exponent) {\n    assert(exponent\
    \ >= 0);\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n\
    \        ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        :\
    \ M::op(::tools::pow<M>(base, exponent - 1), base);\n  }\n\n  template <typename\
    \ T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, T> pow(const T&\
    \ base, const E exponent) {\n    assert(exponent >= 0);\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n\n  template <typename T, typename E>\n  auto pow(const T base,\
    \ const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>, decltype(::std::pow(base,\
    \ exponent))> {\n    return ::std::pow(base, exponent);\n  }\n}\n\n\n#line 1 \"\
    tools/vector4.hpp\"\n\n\n\n#line 5 \"tools/vector4.hpp\"\n\nnamespace tools {\n\
    \  template <typename T>\n  using vector4 = ::tools::vector<T, 4>;\n}\n\n\n#line\
    \ 15 \"tools/quaternion.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  class quaternion;\n\n  template <typename T>\n  ::tools::quaternion<T> exp(const\
    \ ::tools::quaternion<T>& q);\n  template <typename T>\n  ::tools::quaternion<T>\
    \ log(const ::tools::quaternion<T>& q);\n  template <typename T>\n  ::tools::quaternion<T>\
    \ pow(const ::tools::quaternion<T>& base, T exponent);\n\n  template <typename\
    \ T>\n  class quaternion {\n    static_assert(::std::is_floating_point_v<T>);\n\
    \n  private:\n    static constexpr T eps = 1e-5;\n    static constexpr T pi =\
    \ 3.14159265358979323846264338327950288419716939937510L;\n\n  public:\n    T x;\n\
    \    T y;\n    T z;\n    T w;\n\n    quaternion() = default;\n    quaternion(const\
    \ ::tools::quaternion<T>&) = default;\n    quaternion(::tools::quaternion<T>&&)\
    \ = default;\n    ~quaternion() = default;\n    ::tools::quaternion<T>& operator=(const\
    \ ::tools::quaternion<T>&) = default;\n    ::tools::quaternion<T>& operator=(::tools::quaternion<T>&&)\
    \ = default;\n\n    quaternion(const T x, const T y, const T z, const T w) : x(x),\
    \ y(y), z(z), w(w) {}\n\n    T real() const {\n      return this->w;\n    }\n\
    \    void real(const T val) {\n      this->w = val;\n    }\n    ::tools::vector3<T>\
    \ imag() const {\n      return ::tools::vector3<T>(this->x, this->y, this->z);\n\
    \    }\n    void imag(const ::tools::vector3<T>& val) {\n      this->x = val.x;\n\
    \      this->y = val.y;\n      this->z = val.z;\n    }\n\n    T abs() const {\n\
    \      return ::tools::vector4<T>(this->x, this->y, this->z, this->w).l2_norm();\n\
    \    }\n    T norm() const {\n      return ::tools::vector4<T>(this->x, this->y,\
    \ this->z, this->w).squared_l2_norm();\n    }\n    ::tools::quaternion<T> conj()\
    \ const {\n      return ::tools::quaternion<T>(-this->x, -this->y, -this->z, this->w);\n\
    \    }\n\n    T angle() const {\n      assert(::std::abs(this->norm() - 1) <=\
    \ eps);\n      return ::std::acos(::std::clamp<T>(this->real(), -1, 1)) * 2;\n\
    \    }\n    ::tools::vector3<T> axis() const {\n      assert(::std::abs(this->norm()\
    \ - 1) <= eps);\n      return ::std::abs(this->real()) >= 1.0 ? ::tools::vector3<T>(1,\
    \ 0, 0) : this->imag().normalized();\n    }\n\n    ::tools::quaternion<T> operator+()\
    \ const {\n      return *this;\n    }\n    ::tools::quaternion<T> operator-()\
    \ const {\n      return ::tools::quaternion<T>(-this->x, -this->y, -this->z, -this->w);\n\
    \    }\n\n    ::tools::quaternion<T>& operator+=(const ::tools::quaternion<T>&\
    \ other) {\n      this->x += other.x;\n      this->y += other.y;\n      this->z\
    \ += other.z;\n      this->w += other.w;\n      return *this;\n    }\n    friend\
    \ ::tools::quaternion<T> operator+(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>&\
    \ rhs) {\n      return ::tools::quaternion<T>(lhs) += rhs;\n    }\n\n    ::tools::quaternion<T>&\
    \ operator-=(const ::tools::quaternion<T>& other) {\n      this->x -= other.x;\n\
    \      this->y -= other.y;\n      this->z -= other.z;\n      this->w -= other.w;\n\
    \      return *this;\n    }\n    friend ::tools::quaternion<T> operator-(const\
    \ ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {\n      return\
    \ ::tools::quaternion<T>(lhs) -= rhs;\n    }\n\n    ::tools::quaternion<T>& operator*=(const\
    \ T c) {\n      this->x *= c;\n      this->y *= c;\n      this->z *= c;\n    \
    \  this->w *= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T>\
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
    \ {\n      this->x /= c;\n      this->y /= c;\n      this->z /= c;\n      this->w\
    \ /= c;\n      return *this;\n    }\n    friend ::tools::quaternion<T> operator/(const\
    \ ::tools::quaternion<T>& self, const T c) {\n      return ::tools::quaternion<T>(self)\
    \ /= c;\n    }\n\n    ::tools::quaternion<T> inv() const {\n      const auto norm\
    \ = this->norm();\n      assert(norm != 0);\n      return this->conj() / norm;\n\
    \    }\n    friend ::tools::quaternion<T> operator/(const ::tools::quaternion<T>&\
    \ lhs, const ::tools::quaternion<T>& rhs) {\n      return lhs * rhs.inv();\n \
    \   }\n    ::tools::quaternion<T>& operator/=(const ::tools::quaternion<T>& other)\
    \ {\n      return *this = *this / other;\n    }\n\n    friend bool operator==(const\
    \ ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {\n      return\
    \ lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;\n    }\n\
    \    friend bool operator!=(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>&\
    \ rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::quaternion<T>& self) {\n      ::std::ostringstream s;\n \
    \     s.flags(os.flags());\n      s.imbue(os.getloc());\n      s.precision(os.precision());\n\
    \      s << '(' << self.x << ',' << self.y << ',' << self.z << ',' << self.w <<\
    \ ')';\n      return os << s.str();\n    }\n\n    static ::tools::quaternion<T>\
    \ angle_axis(const T angle, const ::tools::vector3<T>& axis) {\n      assert(axis\
    \ != ::tools::vector3<T>(0, 0, 0));\n      const auto real = ::std::cos(angle\
    \ / 2);\n      const auto imag = ::std::sin(angle / 2) * axis.normalized();\n\
    \      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);\n    }\n\n\
    \    static ::tools::quaternion<T> from_to_rotation(::tools::vector3<T> from_direction,\
    \ ::tools::vector3<T> to_direction) {\n      assert(from_direction != ::tools::vector3<T>(0,\
    \ 0, 0));\n      assert(to_direction != ::tools::vector3<T>(0, 0, 0));\n     \
    \ from_direction = from_direction.normalized();\n      to_direction = to_direction.normalized();\n\
    \      if (from_direction.inner_product(to_direction) <= -1 + eps) {\n       \
    \ return ::tools::quaternion<T>::angle_axis(pi, from_direction.orthonormal_basis()[1]);\n\
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
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 11 \"tests/quaternion/dice_rotations.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const std::array<tools::vector3<double>, 6> six_directions = {\n    tools::vector3<double>(0,\
    \ 1, 0),\n    tools::vector3<double>(0, 0, 1),\n    tools::vector3<double>(1,\
    \ 0, 0),\n    tools::vector3<double>(-1, 0, 0),\n    tools::vector3<double>(0,\
    \ 0, -1),\n    tools::vector3<double>(0, -1, 0)\n  };\n\n  std::array<int, 6>\
    \ faces1, faces2;\n  for (auto& f : faces1) std::cin >> f;\n  for (auto& f : faces2)\
    \ std::cin >> f;\n\n  std::cout << ([&]() {\n    for (const auto& q : tools::quaternion<double>::dice_rotations())\
    \ {\n      if ([&]() {\n        for (std::size_t i = 0; i < six_directions.size();\
    \ ++i) {\n          const auto& v1 = six_directions[i];\n          const auto\
    \ v2_with_error = q * v1;\n          const auto j = std::distance(six_directions.begin(),\
    \ std::min_element(six_directions.begin(), six_directions.end(), tools::less_by([&](const\
    \ auto& v2) { return (v2_with_error - v2).squared_l2_norm(); })));\n         \
    \ if (faces1[i] != faces2[j]) return false;\n        }\n        return true;\n\
    \      }()) {\n        return true;\n      }\n    }\n    return false;\n  }()\
    \ ? \"Yes\" : \"No\") << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C\"\n\
    \n#include <iostream>\n#include <array>\n#include <cstddef>\n#include <iterator>\n\
    #include <algorithm>\n#include \"tools/vector3.hpp\"\n#include \"tools/quaternion.hpp\"\
    \n#include \"tools/less_by.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  const std::array<tools::vector3<double>,\
    \ 6> six_directions = {\n    tools::vector3<double>(0, 1, 0),\n    tools::vector3<double>(0,\
    \ 0, 1),\n    tools::vector3<double>(1, 0, 0),\n    tools::vector3<double>(-1,\
    \ 0, 0),\n    tools::vector3<double>(0, 0, -1),\n    tools::vector3<double>(0,\
    \ -1, 0)\n  };\n\n  std::array<int, 6> faces1, faces2;\n  for (auto& f : faces1)\
    \ std::cin >> f;\n  for (auto& f : faces2) std::cin >> f;\n\n  std::cout << ([&]()\
    \ {\n    for (const auto& q : tools::quaternion<double>::dice_rotations()) {\n\
    \      if ([&]() {\n        for (std::size_t i = 0; i < six_directions.size();\
    \ ++i) {\n          const auto& v1 = six_directions[i];\n          const auto\
    \ v2_with_error = q * v1;\n          const auto j = std::distance(six_directions.begin(),\
    \ std::min_element(six_directions.begin(), six_directions.end(), tools::less_by([&](const\
    \ auto& v2) { return (v2_with_error - v2).squared_l2_norm(); })));\n         \
    \ if (faces1[i] != faces2[j]) return false;\n        }\n        return true;\n\
    \      }()) {\n        return true;\n      }\n    }\n    return false;\n  }()\
    \ ? \"Yes\" : \"No\") << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/vector3.hpp
  - tools/vector.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  - tools/quaternion.hpp
  - tools/exp.hpp
  - tools/log.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  - tools/is_monoid.hpp
  - tools/vector4.hpp
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/quaternion/dice_rotations.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 13:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/quaternion/dice_rotations.test.cpp
layout: document
redirect_from:
- /verify/tests/quaternion/dice_rotations.test.cpp
- /verify/tests/quaternion/dice_rotations.test.cpp.html
title: tests/quaternion/dice_rotations.test.cpp
---
