---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':heavy_check_mark:'
    path: tools/vector.hpp
    title: Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/matrix/determinant.test.cpp
    title: tests/matrix/determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/inv.test.cpp
    title: tests/matrix/inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/multiplies.test.cpp
    title: tests/matrix/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/rank.test.cpp
    title: tests/matrix/rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/solve.test.cpp
    title: tests/matrix/solve.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/static.test.cpp
    title: tests/matrix/static.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/online_cumsum.test.cpp
    title: tests/online_cumsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/matrix.hpp\"\n\n\n\n#include <cstddef>\n#include <array>\n\
    #include <limits>\n#include <vector>\n#include <type_traits>\n#include <initializer_list>\n\
    #include <cassert>\n#include <algorithm>\n#include <iostream>\n#include <string>\n\
    #include <utility>\n#include <optional>\n#line 1 \"tools/vector.hpp\"\n\n\n\n\
    #line 11 \"tools/vector.hpp\"\n#include <iterator>\n#line 14 \"tools/vector.hpp\"\
    \n#include <cmath>\n#line 17 \"tools/vector.hpp\"\n#include <functional>\n#include\
    \ <tuple>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float\
    \ abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const\
    \ long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const\
    \ int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned\
    \ int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned long\
    \ x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 1 \"tools/tuple_hash.hpp\"\n\
    \n\n\n#line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\nnamespace tools {\n\
    \  inline long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
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
    \ V& other) {\n      if constexpr (has_aliases) {\n        ::std::copy(other.begin(),\
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
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n#line 17 \"tools/matrix.hpp\"\n\n\
    namespace tools {\n  namespace detail {\n    namespace matrix {\n      template\
    \ <typename T, ::std::size_t N, ::std::size_t M>\n      class members {\n    \
    \  protected:\n        constexpr static bool variable_sized = false;\n       \
    \ ::std::array<T, N * M> m_values;\n        members() : m_values() {}\n      };\n\
    \      template <typename T>\n      class members<T, ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::numeric_limits<::std::size_t>::max()> {\n      protected:\n        constexpr\
    \ static bool variable_sized = true;\n        ::std::vector<T> m_values;\n   \
    \     ::std::size_t m_rows;\n        ::std::size_t m_cols;\n        members()\
    \ = default;\n        members(const ::std::size_t rows, const ::std::size_t cols)\
    \ : m_values(rows * cols), m_rows(rows), m_cols(cols) {}\n        members(const\
    \ ::std::size_t rows, const ::std::size_t cols, const T& value) : m_values(rows\
    \ * cols, value), m_rows(rows), m_cols(cols) {}\n      };\n    }\n  }\n\n  template\
    \ <typename T, ::std::size_t N = ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::size_t M = ::std::numeric_limits<::std::size_t>::max()>\n  class matrix\
    \ : ::tools::detail::matrix::members<T, N, M> {\n  private:\n    template <typename,\
    \ ::std::size_t, ::std::size_t>\n    friend class ::tools::matrix;\n    using\
    \ Mat = ::tools::matrix<T, N, M>;\n    using Base = ::tools::detail::matrix::members<T,\
    \ N, M>;\n    constexpr static bool variable_sized = Base::variable_sized;\n\n\
    \  public:\n    matrix() = default;\n    template <bool SFINAE = variable_sized,\
    \ ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    matrix(const ::std::size_t\
    \ rows, const ::std::size_t cols) : Base(rows, cols) {}\n    template <bool SFINAE\
    \ = variable_sized, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n\
    \    matrix(const ::std::size_t rows, const ::std::size_t cols, const T& value)\
    \ : Base(rows, cols, value) {}\n    template <bool SFINAE = !variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    matrix(const ::std::initializer_list<::std::initializer_list<T>>\
    \ il) {\n      assert(il.size() == this->rows());\n      assert(::std::all_of(il.begin(),\
    \ il.end(), [&](const auto& row) { return row.size() == this->cols(); }));\n \
    \     for (::std::size_t r = 0; r < this->rows(); ++r) {\n        ::std::copy(il.begin()[r].begin(),\
    \ il.begin()[r].end(), (*this)[r]);\n      }\n    }\n    template <bool SFINAE\
    \ = variable_sized, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr, ::std::nullptr_t\
    \ = nullptr>\n    matrix(const ::std::initializer_list<::std::initializer_list<T>>\
    \ il) : Base(il.size(), il.empty() ? 0 : il.begin()->size()) {\n      assert(il.empty()\
    \ || ::std::all_of(il.begin(), il.end(), [&](const auto& row) { return row.size()\
    \ == this->cols(); }));\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        ::std::copy(il.begin()[r].begin(), il.begin()[r].end(), (*this)[r]);\n\
    \      }\n    }\n    auto operator[](const ::std::size_t r) {\n      assert(r\
    \ < this->rows());\n      return this->m_values.begin() + r * this->cols();\n\
    \    }\n    auto operator[](const ::std::size_t r) const {\n      assert(r < this->rows());\n\
    \      return this->m_values.begin() + r * this->cols();\n    }\n\n    ::std::size_t\
    \ rows() const {\n      if constexpr (variable_sized) {\n        return this->m_rows;\n\
    \      } else {\n        return N;\n      }\n    }\n    ::std::size_t cols() const\
    \ {\n      if constexpr (variable_sized) {\n        return this->m_cols;\n   \
    \   } else {\n        return M;\n      }\n    }\n\n    Mat operator+() const {\n\
    \      return *this;\n    }\n    Mat operator-() const {\n      return Mat(*this)\
    \ *= T(-1);\n    }\n    friend Mat operator+(const Mat& lhs, const Mat& rhs) {\n\
    \      return Mat(lhs) += rhs;\n    }\n    friend Mat operator-(const Mat& lhs,\
    \ const Mat& rhs) {\n      return Mat(lhs) -= rhs;\n    }\n    template <::std::size_t\
    \ K, ::std::enable_if_t<!Mat::variable_sized || K == ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::nullptr_t> = nullptr>\n    friend ::tools::matrix<T, N, K> operator*(const\
    \ Mat& lhs, const ::tools::matrix<T, M, K>& rhs) {\n      assert(lhs.cols() ==\
    \ rhs.rows());\n      auto result = [&]() {\n        if constexpr (Mat::variable_sized)\
    \ {\n          return ::tools::matrix<T>(lhs.rows(), rhs.cols());\n        } else\
    \ {\n          return ::tools::matrix<T, N, K>();\n        }\n      }();\n   \
    \   for (::std::size_t i = 0; i < lhs.rows(); ++i) {\n        for (::std::size_t\
    \ k = 0; k < lhs.cols(); ++k) {\n          for (::std::size_t j = 0; j < rhs.cols();\
    \ ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n          }\n  \
    \      }\n      }\n      return result;\n    }\n    friend ::tools::vector<T,\
    \ N> operator*(const Mat& lhs, const ::tools::vector<T, M>& rhs) {\n      assert(lhs.cols()\
    \ == rhs.size());\n      auto result = [&]() {\n        if constexpr (Mat::variable_sized)\
    \ {\n          return ::tools::vector<T>(lhs.rows());\n        } else {\n    \
    \      return ::tools::vector<T, N>();\n        }\n      }();\n      for (::std::size_t\
    \ i = 0; i < lhs.rows(); ++i) {\n        for (::std::size_t j = 0; j < lhs.cols();\
    \ ++j) {\n          result[i] += lhs[i][j] * rhs[j];\n        }\n      }\n   \
    \   return result;\n    }\n    friend Mat operator*(const Mat& lhs, const T& rhs)\
    \ {\n      return Mat(lhs) *= rhs;\n    }\n    friend Mat operator/(const Mat&\
    \ lhs, const ::tools::matrix<T, M, M>& rhs) {\n      const auto inv = rhs.inv();\n\
    \      assert(inv);\n      return lhs * *inv;\n    }\n    friend Mat operator/(const\
    \ Mat& lhs, const T& rhs) {\n      return Mat(lhs) /= rhs;\n    }\n    Mat& operator+=(const\
    \ Mat& other) {\n      assert(this->rows() == other.rows());\n      assert(this->cols()\
    \ == other.cols());\n      for (::std::size_t i = 0; i < this->m_values.size();\
    \ ++i) {\n        this->m_values[i] += other.m_values[i];\n      }\n      return\
    \ *this;\n    }\n    Mat& operator-=(const Mat& other) {\n      assert(this->rows()\
    \ == other.rows());\n      assert(this->cols() == other.cols());\n      for (::std::size_t\
    \ i = 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] -= other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    Mat& operator*=(const ::tools::matrix<T,\
    \ M, M>& other) {\n      return *this = *this * other;\n    }\n    Mat& operator*=(const\
    \ T& c) {\n      for (auto& v : this->m_values) v *= c;\n      return *this;\n\
    \    }\n    Mat& operator/=(const ::tools::matrix<T, M, M>& other) {\n      return\
    \ *this = *this / other;\n    }\n    Mat& operator/=(const T& c) {\n      return\
    \ *this *= T(1) / c;\n    }\n    friend bool operator==(const Mat& lhs, const\
    \ Mat& rhs) {\n      if constexpr (variable_sized) {\n        if (lhs.rows() !=\
    \ rhs.rows()) return false;\n        if (lhs.cols() != rhs.cols()) return false;\n\
    \      }\n      return lhs.m_values == rhs.m_values;\n    }\n    friend bool operator!=(const\
    \ Mat& lhs, const Mat& rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend\
    \ ::std::istream& operator>>(::std::istream& is, Mat& self) {\n      for (auto&\
    \ v : self.m_values) is >> v;\n      return is;\n    }\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const Mat& self) {\n      for (::std::size_t\
    \ r = 0; r < self.rows(); ++r) {\n        os << '[';\n        ::std::string delimiter\
    \ = \"\";\n        for (::std::size_t c = 0; c < self.cols(); ++c) {\n       \
    \   os << delimiter << self[r][c];\n          delimiter = \", \";\n        }\n\
    \        os << ']' << '\\n';\n      }\n      return os;\n    }\n\n  private:\n\
    \    ::std::pair<::std::size_t, T> internal_gauss_jordan() {\n      ::std::size_t\
    \ rank = 0;\n      T coeff(1);\n\n      for (::std::size_t c = 0; c < this->cols();\
    \ ++c) {\n        ::std::size_t pivot;\n        for (pivot = rank; pivot < this->rows()\
    \ && (*this)[pivot][c] == T(0); ++pivot);\n        if (pivot == this->rows())\
    \ continue;\n\n        if (pivot != rank) {\n          for (::std::size_t cc =\
    \ c; cc < this->cols(); ++cc) {\n            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);\n\
    \          }\n          coeff *= T(-1);\n        }\n\n        {\n          const\
    \ T scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c;\
    \ cc < this->cols(); ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n  \
    \        }\n          coeff *= scale_inv;\n        }\n\n        for (::std::size_t\
    \ r = 0; r < this->rows(); ++r) {\n          if (r == rank) continue;\n      \
    \    const T scale = (*this)[r][c];\n          if (scale == T(0)) continue;\n\
    \          for (::std::size_t cc = c; cc < this->cols(); ++cc) {\n           \
    \ (*this)[r][cc] -= (*this)[rank][cc] * scale;\n          }\n        }\n\n   \
    \     ++rank;\n      }\n\n      return ::std::make_pair(rank, coeff);\n    }\n\
    \n  public:\n    ::std::size_t gauss_jordan() {\n      return this->internal_gauss_jordan().first;\n\
    \    }\n\n    ::std::size_t rank() const {\n      return (this->rows() < this->cols()\
    \ ? this->transposed() : Mat(*this)).gauss_jordan();\n    }\n\n    ::tools::matrix<T>\
    \ solve(const ::tools::vector<T, N>& b) const {\n      assert(this->rows() ==\
    \ b.size());\n      assert(this->cols() >= 1);\n      auto Ab = [&]() {\n    \
    \    if constexpr (variable_sized) {\n          return Mat(this->rows(), this->cols()\
    \ + 1);\n        } else {\n          return ::tools::matrix<T, N, M + 1>();\n\
    \        }\n      }();\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols(); ++c) {\n          Ab[r][c]\
    \ = (*this)[r][c];\n        }\n        Ab[r][this->cols()] = b[r];\n      }\n\n\
    \      Ab.internal_gauss_jordan();\n\n      ::std::vector<::std::size_t> ranks(Ab.cols());\n\
    \      for (::std::size_t r = 0, cl = 0, cr = 0; r <= Ab.rows(); ++r, cl = cr)\
    \ {\n        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr] == T(0)); ++cr);\n\
    \        for (::std::size_t c = cl; c < cr; ++c) {\n          ranks[c] = r;\n\
    \        }\n      }\n\n      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1])\
    \ {\n        return ::tools::matrix<T>(this->rows(), 0);\n      }\n\n      ::std::vector<::tools::vector<T>>\
    \ answers(this->cols());\n      ::std::size_t free = this->cols() - ranks.back()\
    \ - 1;\n\n      for (::std::size_t l = this->cols(), r = this->cols(); r > 0;\
    \ r = l) {\n        for (; l > 0 && ranks[l - 1] == ranks[r - 1]; --l);\n    \
    \    for (::std::size_t c = r - 1; c > l; --c) {\n          answers[c] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[c][free] = T(1);\n          --free;\n\
    \        }\n        if (ranks[l] > 0) {\n          answers[l] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[l][this->cols() - ranks.back()]\
    \ = Ab[ranks[l] - 1][Ab.cols() - 1];\n          for (::std::size_t c = l + 1;\
    \ c < Ab.cols() - 1; ++c) {\n            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];\n\
    \          }\n        } else {\n          answers[l] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[l][free] = T(1);\n          --free;\n\
    \        }\n      }\n\n      ::tools::matrix<T> answer(this->cols(), this->cols()\
    \ - ranks.back() + 1);\n      for (::std::size_t r = 0; r < this->cols(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols() - ranks.back() + 1; ++c)\
    \ {\n          answer[r][c] = answers[r][c];\n        }\n      }\n\n      return\
    \ answer;\n    }\n\n    T determinant() const {\n      assert(this->rows() ==\
    \ this->cols());\n\n      auto A = *this;\n      const auto [rank, coeff] = A.internal_gauss_jordan();\n\
    \n      return rank == A.rows() ? T(1) / coeff : T(0);\n    }\n\n    template\
    \ <bool SFINAE = !variable_sized && N == M, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    static Mat e() {\n      Mat result{};\n      for (::std::size_t\
    \ i = 0; i < N; ++i) {\n        result[i][i] = T(1);\n      }\n      return result;\n\
    \    }\n    template <bool SFINAE = variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    static Mat e(const ::std::size_t n) {\n  \
    \    Mat result(n, n, T(0));\n      for (::std::size_t i = 0; i < n; ++i) {\n\
    \        result[i][i] = T(1);\n      }\n      return result;\n    }\n\n    template\
    \ <bool SFINAE = variable_sized || N == M, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::optional<Mat> inv() const {\n      assert(this->rows()\
    \ == this->cols());\n\n      auto AI = [&]() {\n        if constexpr (variable_sized)\
    \ {\n          return Mat(this->rows(), this->cols() * 2);\n        } else {\n\
    \          return ::tools::matrix<T, N, M * 2>();\n        }\n      }();\n   \
    \   for (::std::size_t r = 0; r < this->rows(); ++r) {\n        for (::std::size_t\
    \ c = 0; c < this->cols(); ++c) {\n          AI[r][c] = (*this)[r][c];\n     \
    \   }\n        for (::std::size_t c = this->cols(); c < AI.cols(); ++c) {\n  \
    \        AI[r][c] = T(0);\n        }\n        AI[r][this->cols() + r] = T(1);\n\
    \      }\n\n      AI.internal_gauss_jordan();\n      for (::std::size_t i = 0;\
    \ i < this->rows(); ++i) {\n        if (AI[i][i] != T(1)) return ::std::nullopt;\n\
    \      }\n\n      auto B = [&]() {\n        if constexpr (variable_sized) {\n\
    \          return Mat(this->rows(), this->cols());\n        } else {\n       \
    \   return Mat();\n        }\n      }();\n      for (::std::size_t r = 0; r <\
    \ this->rows(); ++r) {\n        for (::std::size_t c = 0; c < this->cols(); ++c)\
    \ {\n          B[r][c] = AI[r][this->cols() + c];\n        }\n      }\n      return\
    \ B;\n    }\n\n    ::tools::matrix<T, M, N> transposed() const {\n      auto A_T\
    \ = [&]() {\n        if constexpr (variable_sized) {\n          return Mat(this->cols(),\
    \ this->rows());\n        } else {\n          return ::tools::matrix<T, M, N>();\n\
    \        }\n      }();\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols(); ++c) {\n          A_T[c][r]\
    \ = (*this)[r][c];\n        }\n      }\n      return A_T;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MATRIX_HPP\n#define TOOLS_MATRIX_HPP\n\n#include <cstddef>\n\
    #include <array>\n#include <limits>\n#include <vector>\n#include <type_traits>\n\
    #include <initializer_list>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <iostream>\n#include <string>\n#include <utility>\n#include <optional>\n#include\
    \ \"tools/vector.hpp\"\n\nnamespace tools {\n  namespace detail {\n    namespace\
    \ matrix {\n      template <typename T, ::std::size_t N, ::std::size_t M>\n  \
    \    class members {\n      protected:\n        constexpr static bool variable_sized\
    \ = false;\n        ::std::array<T, N * M> m_values;\n        members() : m_values()\
    \ {}\n      };\n      template <typename T>\n      class members<T, ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::numeric_limits<::std::size_t>::max()> {\n      protected:\n        constexpr\
    \ static bool variable_sized = true;\n        ::std::vector<T> m_values;\n   \
    \     ::std::size_t m_rows;\n        ::std::size_t m_cols;\n        members()\
    \ = default;\n        members(const ::std::size_t rows, const ::std::size_t cols)\
    \ : m_values(rows * cols), m_rows(rows), m_cols(cols) {}\n        members(const\
    \ ::std::size_t rows, const ::std::size_t cols, const T& value) : m_values(rows\
    \ * cols, value), m_rows(rows), m_cols(cols) {}\n      };\n    }\n  }\n\n  template\
    \ <typename T, ::std::size_t N = ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::size_t M = ::std::numeric_limits<::std::size_t>::max()>\n  class matrix\
    \ : ::tools::detail::matrix::members<T, N, M> {\n  private:\n    template <typename,\
    \ ::std::size_t, ::std::size_t>\n    friend class ::tools::matrix;\n    using\
    \ Mat = ::tools::matrix<T, N, M>;\n    using Base = ::tools::detail::matrix::members<T,\
    \ N, M>;\n    constexpr static bool variable_sized = Base::variable_sized;\n\n\
    \  public:\n    matrix() = default;\n    template <bool SFINAE = variable_sized,\
    \ ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    matrix(const ::std::size_t\
    \ rows, const ::std::size_t cols) : Base(rows, cols) {}\n    template <bool SFINAE\
    \ = variable_sized, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n\
    \    matrix(const ::std::size_t rows, const ::std::size_t cols, const T& value)\
    \ : Base(rows, cols, value) {}\n    template <bool SFINAE = !variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    matrix(const ::std::initializer_list<::std::initializer_list<T>>\
    \ il) {\n      assert(il.size() == this->rows());\n      assert(::std::all_of(il.begin(),\
    \ il.end(), [&](const auto& row) { return row.size() == this->cols(); }));\n \
    \     for (::std::size_t r = 0; r < this->rows(); ++r) {\n        ::std::copy(il.begin()[r].begin(),\
    \ il.begin()[r].end(), (*this)[r]);\n      }\n    }\n    template <bool SFINAE\
    \ = variable_sized, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr, ::std::nullptr_t\
    \ = nullptr>\n    matrix(const ::std::initializer_list<::std::initializer_list<T>>\
    \ il) : Base(il.size(), il.empty() ? 0 : il.begin()->size()) {\n      assert(il.empty()\
    \ || ::std::all_of(il.begin(), il.end(), [&](const auto& row) { return row.size()\
    \ == this->cols(); }));\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        ::std::copy(il.begin()[r].begin(), il.begin()[r].end(), (*this)[r]);\n\
    \      }\n    }\n    auto operator[](const ::std::size_t r) {\n      assert(r\
    \ < this->rows());\n      return this->m_values.begin() + r * this->cols();\n\
    \    }\n    auto operator[](const ::std::size_t r) const {\n      assert(r < this->rows());\n\
    \      return this->m_values.begin() + r * this->cols();\n    }\n\n    ::std::size_t\
    \ rows() const {\n      if constexpr (variable_sized) {\n        return this->m_rows;\n\
    \      } else {\n        return N;\n      }\n    }\n    ::std::size_t cols() const\
    \ {\n      if constexpr (variable_sized) {\n        return this->m_cols;\n   \
    \   } else {\n        return M;\n      }\n    }\n\n    Mat operator+() const {\n\
    \      return *this;\n    }\n    Mat operator-() const {\n      return Mat(*this)\
    \ *= T(-1);\n    }\n    friend Mat operator+(const Mat& lhs, const Mat& rhs) {\n\
    \      return Mat(lhs) += rhs;\n    }\n    friend Mat operator-(const Mat& lhs,\
    \ const Mat& rhs) {\n      return Mat(lhs) -= rhs;\n    }\n    template <::std::size_t\
    \ K, ::std::enable_if_t<!Mat::variable_sized || K == ::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::nullptr_t> = nullptr>\n    friend ::tools::matrix<T, N, K> operator*(const\
    \ Mat& lhs, const ::tools::matrix<T, M, K>& rhs) {\n      assert(lhs.cols() ==\
    \ rhs.rows());\n      auto result = [&]() {\n        if constexpr (Mat::variable_sized)\
    \ {\n          return ::tools::matrix<T>(lhs.rows(), rhs.cols());\n        } else\
    \ {\n          return ::tools::matrix<T, N, K>();\n        }\n      }();\n   \
    \   for (::std::size_t i = 0; i < lhs.rows(); ++i) {\n        for (::std::size_t\
    \ k = 0; k < lhs.cols(); ++k) {\n          for (::std::size_t j = 0; j < rhs.cols();\
    \ ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n          }\n  \
    \      }\n      }\n      return result;\n    }\n    friend ::tools::vector<T,\
    \ N> operator*(const Mat& lhs, const ::tools::vector<T, M>& rhs) {\n      assert(lhs.cols()\
    \ == rhs.size());\n      auto result = [&]() {\n        if constexpr (Mat::variable_sized)\
    \ {\n          return ::tools::vector<T>(lhs.rows());\n        } else {\n    \
    \      return ::tools::vector<T, N>();\n        }\n      }();\n      for (::std::size_t\
    \ i = 0; i < lhs.rows(); ++i) {\n        for (::std::size_t j = 0; j < lhs.cols();\
    \ ++j) {\n          result[i] += lhs[i][j] * rhs[j];\n        }\n      }\n   \
    \   return result;\n    }\n    friend Mat operator*(const Mat& lhs, const T& rhs)\
    \ {\n      return Mat(lhs) *= rhs;\n    }\n    friend Mat operator/(const Mat&\
    \ lhs, const ::tools::matrix<T, M, M>& rhs) {\n      const auto inv = rhs.inv();\n\
    \      assert(inv);\n      return lhs * *inv;\n    }\n    friend Mat operator/(const\
    \ Mat& lhs, const T& rhs) {\n      return Mat(lhs) /= rhs;\n    }\n    Mat& operator+=(const\
    \ Mat& other) {\n      assert(this->rows() == other.rows());\n      assert(this->cols()\
    \ == other.cols());\n      for (::std::size_t i = 0; i < this->m_values.size();\
    \ ++i) {\n        this->m_values[i] += other.m_values[i];\n      }\n      return\
    \ *this;\n    }\n    Mat& operator-=(const Mat& other) {\n      assert(this->rows()\
    \ == other.rows());\n      assert(this->cols() == other.cols());\n      for (::std::size_t\
    \ i = 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] -= other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    Mat& operator*=(const ::tools::matrix<T,\
    \ M, M>& other) {\n      return *this = *this * other;\n    }\n    Mat& operator*=(const\
    \ T& c) {\n      for (auto& v : this->m_values) v *= c;\n      return *this;\n\
    \    }\n    Mat& operator/=(const ::tools::matrix<T, M, M>& other) {\n      return\
    \ *this = *this / other;\n    }\n    Mat& operator/=(const T& c) {\n      return\
    \ *this *= T(1) / c;\n    }\n    friend bool operator==(const Mat& lhs, const\
    \ Mat& rhs) {\n      if constexpr (variable_sized) {\n        if (lhs.rows() !=\
    \ rhs.rows()) return false;\n        if (lhs.cols() != rhs.cols()) return false;\n\
    \      }\n      return lhs.m_values == rhs.m_values;\n    }\n    friend bool operator!=(const\
    \ Mat& lhs, const Mat& rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend\
    \ ::std::istream& operator>>(::std::istream& is, Mat& self) {\n      for (auto&\
    \ v : self.m_values) is >> v;\n      return is;\n    }\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const Mat& self) {\n      for (::std::size_t\
    \ r = 0; r < self.rows(); ++r) {\n        os << '[';\n        ::std::string delimiter\
    \ = \"\";\n        for (::std::size_t c = 0; c < self.cols(); ++c) {\n       \
    \   os << delimiter << self[r][c];\n          delimiter = \", \";\n        }\n\
    \        os << ']' << '\\n';\n      }\n      return os;\n    }\n\n  private:\n\
    \    ::std::pair<::std::size_t, T> internal_gauss_jordan() {\n      ::std::size_t\
    \ rank = 0;\n      T coeff(1);\n\n      for (::std::size_t c = 0; c < this->cols();\
    \ ++c) {\n        ::std::size_t pivot;\n        for (pivot = rank; pivot < this->rows()\
    \ && (*this)[pivot][c] == T(0); ++pivot);\n        if (pivot == this->rows())\
    \ continue;\n\n        if (pivot != rank) {\n          for (::std::size_t cc =\
    \ c; cc < this->cols(); ++cc) {\n            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);\n\
    \          }\n          coeff *= T(-1);\n        }\n\n        {\n          const\
    \ T scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c;\
    \ cc < this->cols(); ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n  \
    \        }\n          coeff *= scale_inv;\n        }\n\n        for (::std::size_t\
    \ r = 0; r < this->rows(); ++r) {\n          if (r == rank) continue;\n      \
    \    const T scale = (*this)[r][c];\n          if (scale == T(0)) continue;\n\
    \          for (::std::size_t cc = c; cc < this->cols(); ++cc) {\n           \
    \ (*this)[r][cc] -= (*this)[rank][cc] * scale;\n          }\n        }\n\n   \
    \     ++rank;\n      }\n\n      return ::std::make_pair(rank, coeff);\n    }\n\
    \n  public:\n    ::std::size_t gauss_jordan() {\n      return this->internal_gauss_jordan().first;\n\
    \    }\n\n    ::std::size_t rank() const {\n      return (this->rows() < this->cols()\
    \ ? this->transposed() : Mat(*this)).gauss_jordan();\n    }\n\n    ::tools::matrix<T>\
    \ solve(const ::tools::vector<T, N>& b) const {\n      assert(this->rows() ==\
    \ b.size());\n      assert(this->cols() >= 1);\n      auto Ab = [&]() {\n    \
    \    if constexpr (variable_sized) {\n          return Mat(this->rows(), this->cols()\
    \ + 1);\n        } else {\n          return ::tools::matrix<T, N, M + 1>();\n\
    \        }\n      }();\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols(); ++c) {\n          Ab[r][c]\
    \ = (*this)[r][c];\n        }\n        Ab[r][this->cols()] = b[r];\n      }\n\n\
    \      Ab.internal_gauss_jordan();\n\n      ::std::vector<::std::size_t> ranks(Ab.cols());\n\
    \      for (::std::size_t r = 0, cl = 0, cr = 0; r <= Ab.rows(); ++r, cl = cr)\
    \ {\n        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr] == T(0)); ++cr);\n\
    \        for (::std::size_t c = cl; c < cr; ++c) {\n          ranks[c] = r;\n\
    \        }\n      }\n\n      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1])\
    \ {\n        return ::tools::matrix<T>(this->rows(), 0);\n      }\n\n      ::std::vector<::tools::vector<T>>\
    \ answers(this->cols());\n      ::std::size_t free = this->cols() - ranks.back()\
    \ - 1;\n\n      for (::std::size_t l = this->cols(), r = this->cols(); r > 0;\
    \ r = l) {\n        for (; l > 0 && ranks[l - 1] == ranks[r - 1]; --l);\n    \
    \    for (::std::size_t c = r - 1; c > l; --c) {\n          answers[c] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[c][free] = T(1);\n          --free;\n\
    \        }\n        if (ranks[l] > 0) {\n          answers[l] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[l][this->cols() - ranks.back()]\
    \ = Ab[ranks[l] - 1][Ab.cols() - 1];\n          for (::std::size_t c = l + 1;\
    \ c < Ab.cols() - 1; ++c) {\n            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];\n\
    \          }\n        } else {\n          answers[l] = ::tools::vector<T>(this->cols()\
    \ - ranks.back() + 1, T(0));\n          answers[l][free] = T(1);\n          --free;\n\
    \        }\n      }\n\n      ::tools::matrix<T> answer(this->cols(), this->cols()\
    \ - ranks.back() + 1);\n      for (::std::size_t r = 0; r < this->cols(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols() - ranks.back() + 1; ++c)\
    \ {\n          answer[r][c] = answers[r][c];\n        }\n      }\n\n      return\
    \ answer;\n    }\n\n    T determinant() const {\n      assert(this->rows() ==\
    \ this->cols());\n\n      auto A = *this;\n      const auto [rank, coeff] = A.internal_gauss_jordan();\n\
    \n      return rank == A.rows() ? T(1) / coeff : T(0);\n    }\n\n    template\
    \ <bool SFINAE = !variable_sized && N == M, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    static Mat e() {\n      Mat result{};\n      for (::std::size_t\
    \ i = 0; i < N; ++i) {\n        result[i][i] = T(1);\n      }\n      return result;\n\
    \    }\n    template <bool SFINAE = variable_sized, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    static Mat e(const ::std::size_t n) {\n  \
    \    Mat result(n, n, T(0));\n      for (::std::size_t i = 0; i < n; ++i) {\n\
    \        result[i][i] = T(1);\n      }\n      return result;\n    }\n\n    template\
    \ <bool SFINAE = variable_sized || N == M, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::optional<Mat> inv() const {\n      assert(this->rows()\
    \ == this->cols());\n\n      auto AI = [&]() {\n        if constexpr (variable_sized)\
    \ {\n          return Mat(this->rows(), this->cols() * 2);\n        } else {\n\
    \          return ::tools::matrix<T, N, M * 2>();\n        }\n      }();\n   \
    \   for (::std::size_t r = 0; r < this->rows(); ++r) {\n        for (::std::size_t\
    \ c = 0; c < this->cols(); ++c) {\n          AI[r][c] = (*this)[r][c];\n     \
    \   }\n        for (::std::size_t c = this->cols(); c < AI.cols(); ++c) {\n  \
    \        AI[r][c] = T(0);\n        }\n        AI[r][this->cols() + r] = T(1);\n\
    \      }\n\n      AI.internal_gauss_jordan();\n      for (::std::size_t i = 0;\
    \ i < this->rows(); ++i) {\n        if (AI[i][i] != T(1)) return ::std::nullopt;\n\
    \      }\n\n      auto B = [&]() {\n        if constexpr (variable_sized) {\n\
    \          return Mat(this->rows(), this->cols());\n        } else {\n       \
    \   return Mat();\n        }\n      }();\n      for (::std::size_t r = 0; r <\
    \ this->rows(); ++r) {\n        for (::std::size_t c = 0; c < this->cols(); ++c)\
    \ {\n          B[r][c] = AI[r][this->cols() + c];\n        }\n      }\n      return\
    \ B;\n    }\n\n    ::tools::matrix<T, M, N> transposed() const {\n      auto A_T\
    \ = [&]() {\n        if constexpr (variable_sized) {\n          return Mat(this->cols(),\
    \ this->rows());\n        } else {\n          return ::tools::matrix<T, M, N>();\n\
    \        }\n      }();\n      for (::std::size_t r = 0; r < this->rows(); ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->cols(); ++c) {\n          A_T[c][r]\
    \ = (*this)[r][c];\n        }\n      }\n      return A_T;\n    }\n  };\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/vector.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/matrix.hpp
  requiredBy: []
  timestamp: '2024-03-23 15:55:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/matrix/multiplies.test.cpp
  - tests/matrix/rank.test.cpp
  - tests/matrix/inv.test.cpp
  - tests/matrix/static.test.cpp
  - tests/matrix/determinant.test.cpp
  - tests/matrix/solve.test.cpp
  - tests/online_cumsum.test.cpp
documentation_of: tools/matrix.hpp
layout: document
title: Matrix
---

It is a $n \times m$-dimensional matrix.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) matrix<T, n, m> A();
(2) matrix<T, n, m> A(std::initializer_list<std::initializer_list<T>> il);
(3) matrix<T> A(std::size_t n, std::size_t m);
(4) matrix<T> A(std::size_t n, std::size_t m, T x);
(5) matrix<T> A(std::initializer_list<std::initializer_list<T>> il);
```

- (1), (3)
    - It creates a $n \times m$-dimensional matrix.
- (2)
    - It creates a $n \times m$-dimensional matrix where $A_{r, c}$ is `il.begin()[r].begin()[c]`.
- (4)
    - It creates a $n \times m$-dimensional matrix filled with $x$.
- (5)
    - It creates a $n \times m$-dimensional matrix where $n$ is `il.size()`, $m$ is `il.empty() ? 0 : il.begin()->size()` and $A_{r, c}$ is `il.begin()[r].begin()[c]`.

The type parameter `<T>` represents the type of the elements.

### Constraints
- (2)
    - `il.size()` is equal to $n$.
    - For all $0 \leq r < n$, `il.begin()[r].size()` is equal to $m$.
- (5)
    - For all $0 \leq r < $`il.size()`, `il.begin()[r].size()` is equal to `il.begin()->size()`.

### Time Complexity
- $O(nm)$

## operator[]
```cpp
T& A[i][j];
```

It is the $(i, j)$-th element of the matrix.

### Constraints
- $0 \leq i < n$
- $0 \leq j < m$

### Time Complexity
- $O(1)$

## rows
```cpp
std::size_t A.rows();
```

It returns $n$, the number of rows of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## cols
```cpp
std::size_t A.cols();
```

It returns $m$, the number of columns of the matrix.

### Constraints
- None

### Time Complexity
- $O(1)$

## gauss_jordan
```cpp
std::size_t A.gauss_jordan();
```

It transforms $A$ to the reduced row echelon form, and returns the rank of $A$.

### Constraints
- None

### Time Complexity
- $O(n m^2)$

## rank
```cpp
std::size_t A.rank();
```

It returns the rank of $A$.

### Constraints
- None

### Time Complexity
- $O(nm \min(n, m))$

## solve
```cpp
(1) matrix<T> A.solve(vector<T, n> b);
(2) matrix<T> A.solve(vector<T> b);
```

It solves $A\overrightarrow{x} = \overrightarrow{b}$.
If the answers exist, the answers can be denoted as follows where $B$ is another $m \times (m - \mathrm{rank}(A) + 1)$-dimensional matrix and $c_i$ are free variables.

$$\begin{align*}
\overrightarrow{x} &= B\left(\begin{array}{c}
c_1\\
c_2\\
\vdots\\
c_{m - \mathrm{rank}(A)}\\
1
\end{array}\right)
\end{align*}$$

If the answers exist, it returns $B$.
Otherwise, it returns a $m \times 0$-dimensional matrix.

### Constraints
- (1)
    - `A` is `matrix<T, n, m>`.
    - $m \geq 1$
- (2)
    - `A` is `matrix<T>`.
    - $n = \mathrm{dim}(b)$
    - $m \geq 1$

### Time Complexity
- $O(n m^2)$

## determinant
```cpp
T A.determinant();
```

It returns $\|A\|$.

### Constraints
- $n = m$

### Time Complexity
- $O(n^3)$

## Unary plus operator
```cpp
(1) matrix<T, n, m> operator+(matrix<T, n, m> A);
(2) matrix<T> operator+(matrix<T> A);
```

It returns the copy of $A$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## Unary negation operator
```cpp
(1) matrix<T, n, m> operator-(matrix<T, n, m> A);
(2) matrix<T> operator-(matrix<T> A);
```

It returns $-A$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## Addition operators
```cpp
(1) matrix<T, n, m> operator+(matrix<T, n, m> A, matrix<T, n, m> B);
(2) matrix<T, n, m>& operator+=(matrix<T, n, m>& A, matrix<T, n, m> B);
(3) matrix<T> operator+(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator+=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $A + B$.
- (2), (4)
    - It updates $A$ to $A + B$, and returns the new $A$.

### Constraints
- (3), (4)
    - The number of rows of $A$ is equal to the number of rows of $B$.
    - The number of columns of $A$ is equal to the number of columns of $B$.

### Time Complexity
- $O(nm)$

## Subtraction operators
```cpp
(1) matrix<T, n, m> operator-(matrix<T, n, m> A, matrix<T, n, m> B);
(2) matrix<T, n, m>& operator-=(matrix<T, n, m>& A, matrix<T, n, m> B);
(3) matrix<T> operator-(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator-=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $A - B$.
- (2), (4)
    - It updates $A$ to $A - B$, and returns the new $A$.

### Constraints
- (3), (4)
    - The number of rows of $A$ is equal to the number of rows of $B$.
    - The number of columns of $A$ is equal to the number of columns of $B$.

### Time Complexity
- $O(nm)$

## Multiplication operators for a matrix
```cpp
(1) matrix<T, n, k> operator*(matrix<T, n, m> A, matrix<T, m, k> B);
(2) matrix<T, n, m>& operator*=(matrix<T, n, m>& A, matrix<T, m, m> B);
(3) matrix<T> operator*(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator*=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $AB$.
- (2), (4)
    - It updates $A$ to $AB$, and returns the new $A$.

### Constraints
- (3)
    - The number of columns of $A$ is equal to the number of rows of $B$.
- (4)
    - The number of columns of $A$ is equal to the number of rows of $B$.
    - The number of rows of $B$ is equal to the number of columns of $B$.

### Time Complexity
- (1), (3)
    - $O(nmk)$
- (2), (4)
    - $O(nm^2)$

## Multiplication operators for a vector
```cpp
(1) vector<T, n> operator*(matrix<T, n, m> A, vector<T, m> v);
(2) vector<T> operator*(matrix<T> A, vector<T> v);
```

It returns $Av$.

### Constraints
- (2)
    - The number of columns of $A$ is equal to $\mathrm{dim}(v)$.

### Time Complexity
- $O(nm)$

## Multiplication operators for a scholar value
```cpp
(1) matrix<T, n, m> operator*(matrix<T, n, m> A, T c);
(2) matrix<T, n, m>& operator*=(matrix<T, n, m>& A, T c);
(3) matrix<T> operator*(matrix<T> A, T c);
(4) matrix<T>& operator*=(matrix<T>& A, T c);
```

- (1), (3)
    - It returns $cA$.
- (2), (4)
    - It updates $A$ to $cA$, and returns the new $A$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## Division operators for a matrix
```cpp
(1) matrix<T, n, m> operator/(matrix<T, n, m> A, matrix<T, m, m> B);
(2) matrix<T, n, m>& operator/=(matrix<T, n, m>& A, matrix<T, m, m> B);
(3) matrix<T> operator/(matrix<T> A, matrix<T> B);
(4) matrix<T>& operator/=(matrix<T>& A, matrix<T> B);
```

- (1), (3)
    - It returns $AB^{-1}$.
- (2), (4)
    - It updates $A$ to $AB^{-1}$, and returns the new $A$.

### Constraints
- (1), (2)
    - $B^{-1}$ exists.
- (3), (4)
    - The number of columns of $A$ is equal to the number of rows of $B$.
    - $B^{-1}$ exists.

### Time Complexity
- $O((n + m) m^2)$

## Division operators for a scholar value
```cpp
(1) matrix<T, n, m> operator/(matrix<T, n, m> A, T c);
(2) matrix<T, n, m>& operator/=(matrix<T, n, m>& A, T c);
(3) matrix<T> operator/(matrix<T> A, T c);
(4) matrix<T>& operator/=(matrix<T>& A, T c);
```

- (1), (3)
    - It returns $c^{-1} A$.
- (2), (4)
    - It updates $A$ to $c^{-1} A$, and returns the new $A$.

### Constraints
- $c \neq 0$

### Time Complexity
- $O(nm)$

## Comparison operations
```cpp
(1) bool operator==(matrix<T, n, m> A, matrix<T, n, m> B);
(2) bool operator!=(matrix<T, n, m> A, matrix<T, n, m> B);
(3) bool operator==(matrix<T> A, matrix<T> B);
(4) bool operator!=(matrix<T> A, matrix<T> B);
```

- (1), (3)
    - It returns whether $A = B$.
- (2), (4)
    - It returns whether $A \neq B$.

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator&gt;&gt;
```cpp
(1) std::istream& operator>>(std::istream& is, matrix<T, n, m>& self);
(2) std::istream& operator>>(std::istream& is, matrix<T>& self);
```

It is equivalent to the following code.

```cpp
for (std::size_t r = 0; r < self.rows(); ++r) {
  for (std::size_t c = 0; c < self.cols(); ++c) {
    is >> self[r][c];
  }
}
return is;
```

### Constraints
- None

### Time Complexity
- $O(nm)$

## operator&lt;&lt;
```cpp
(1) std::ostream& operator<<(std::ostream& os, matrix<T, n, m> self);
(2) std::ostream& operator<<(std::ostream& os, matrix<T> self);
```

It is equivalent to the following code.

```cpp
for (std::size_t r = 0; r < self.rows(); ++r) {
  os << '[';
  for (std::size_t c = 0; c < self.cols(); ++c) {
    if (c > 0) os << ", ";
    os << self[r][c];
  }
  os << ']' << '\n';
}
return os;
```

### Constraints
- None

### Time Complexity
- $O(nm)$

## e
```cpp
(1) matrix<T, n, n> matrix<T, n, n>::e();
(2) matrix<T> matrix<T>::e(std::size_t n);
```

It returns $n \times n$-dimensional identity matrix.

### Constraints
- None

### Time Complexity
- $O(n^2)$

## inv
```cpp
(1) std::optional<matrix<T, n, n>> A.inv();
(2) std::optional<matrix<T>> A.inv();
```

If $A^{-1}$ exists, it returns $A^{-1}$.
Otherwise, it returns `std::nullopt`.

### Constraints
- (1)
    - $A$ is `matrix<T, n, n>`.
- (2)
    - $A$ is `matrix<T>`.
    - $n = m$

### Time Complexity
- $O(n^3)$

## transposed
```cpp
(1) matrix<T, m, n> A.transposed();
(2) matrix<T> A.transposed();
```

It returns $A^\top$.

### Constraints
- (1)
    - $A$ is `matrix<T, n, m>`.
- (2)
    - $A$ is `matrix<T>`.

### Time Complexity
- $O(nm)$
