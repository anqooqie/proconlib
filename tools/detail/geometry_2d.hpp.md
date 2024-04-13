---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  - icon: ':heavy_check_mark:'
    path: tools/is_rational.hpp
    title: Check whether T is tools::rational
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/signum.hpp
    title: Sign function
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':heavy_check_mark:'
    path: tools/vector.hpp
    title: Vector
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
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
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/detail/geometry_2d.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <cmath>\n#include <cstddef>\n#include\
    \ <initializer_list>\n#include <limits>\n#include <optional>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n#include <variant>\n#include <vector>\n\
    #line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const\
    \ float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned\
    \ int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned long\
    \ x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 1 \"tools/is_rational.hpp\"\
    \n\n\n\n#line 5 \"tools/is_rational.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  struct is_rational : std::false_type {};\n\n  template <typename T>\n\
    \  inline constexpr bool is_rational_v = ::tools::is_rational<T>::value;\n}\n\n\
    \n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/signum.hpp\"\n\n\n\n#line 5 \"tools/signum.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  constexpr int signum(const\
    \ T x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0)\
    \ < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\n\
    #line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/is_monoid.hpp\"\n\n\n\n#line\
    \ 6 \"tools/is_monoid.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ = void>\n  struct is_monoid : ::std::false_type {};\n\n  template <typename\
    \ M>\n  struct is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ M::T, decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename\
    \ M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n  , void>>\
    \ : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr bool is_monoid_v\
    \ = ::tools::is_monoid<M>::value;\n}\n\n\n#line 6 \"tools/square.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M>\n  ::std::enable_if_t<::tools::is_monoid_v<M>,\
    \ typename M::T> square(const typename M::T& x) {\n    return M::op(x, x);\n \
    \ }\n\n  template <typename T>\n  ::std::enable_if_t<!::tools::is_monoid_v<T>,\
    \ T> square(const T& x) {\n    return x * x;\n  }\n}\n\n\n#line 1 \"tools/vector2.hpp\"\
    \n\n\n\n#line 1 \"tools/vector.hpp\"\n\n\n\n#line 11 \"tools/vector.hpp\"\n#include\
    \ <iterator>\n#line 15 \"tools/vector.hpp\"\n#include <iostream>\n#include <string>\n\
    #include <functional>\n#line 1 \"tools/tuple_hash.hpp\"\n\n\n\n#line 1 \"tools/now.hpp\"\
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
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n#line 5 \"tools/vector2.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  using vector2 = ::tools::vector<T,\
    \ 2>;\n}\n\n\n#line 23 \"tools/detail/geometry_2d.hpp\"\n\nnamespace tools {\n\
    \  template <typename T, bool Filled, bool HasRadius = true>\n  class circle_2d;\n\
    \n  template <typename T>\n  class directed_line_segment_2d;\n\n  template <typename\
    \ T>\n  class half_line_2d;\n\n  template <typename T>\n  class line_2d;\n\n \
    \ template <typename T, bool Filled>\n  class polygon_2d;\n\n  template <typename\
    \ T, bool Filled>\n  class triangle_2d;\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  class circle_2d {\n  private:\n    ::tools::vector2<T> m_center;\n\
    \    T m_radius;\n    T m_squared_radius;\n\n  public:\n    circle_2d() = default;\n\
    \    circle_2d(const ::tools::circle_2d<T, Filled, HasRadius>&) = default;\n \
    \   circle_2d(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n    ~circle_2d()\
    \ = default;\n    ::tools::circle_2d<T, Filled, HasRadius>& operator=(const ::tools::circle_2d<T,\
    \ Filled, HasRadius>&) = default;\n    ::tools::circle_2d<T, Filled, HasRadius>&\
    \ operator=(::tools::circle_2d<T, Filled, HasRadius>&&) = default;\n\n    circle_2d(const\
    \ ::tools::vector2<T>& center, const T& radius_or_squared_radius);\n\n    template\
    \ <typename T_ = T, bool Filled_ = Filled>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>\
    \ && Filled_, T> area() const;\n    ::tools::vector2<T> center() const;\n    template\
    \ <bool HasRadius_ = HasRadius>\n    ::std::enable_if_t<HasRadius_, T> radius()\
    \ const;\n    T squared_radius() const;\n    ::std::pair<int, int> where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const;\n    int where(const\
    \ ::tools::vector2<T>& p) const;\n\n    template <typename T_, bool HasRadius_>\n\
    \    friend ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::circle_2d<T_,\
    \ false, HasRadius_>, ::std::vector<::tools::vector2<T_>>>>>\n    operator&(const\
    \ ::tools::circle_2d<T_, false, HasRadius_>& lhs, const ::tools::circle_2d<T_,\
    \ false, HasRadius_>& rhs);\n    template <typename T_, bool HasRadius_>\n   \
    \ friend ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::vector<::tools::vector2<T_>>>\n\
    \    operator&(const ::tools::circle_2d<T_, false, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::circle_2d<T_, true, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n\
    \    friend bool operator==(const ::tools::circle_2d<T_, Filled_, HasRadius1>&\
    \ lhs, const ::tools::circle_2d<T_, Filled_, HasRadius2>& rhs);\n    template\
    \ <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n    friend bool\
    \ operator!=(const ::tools::circle_2d<T_, Filled_, HasRadius1>& lhs, const ::tools::circle_2d<T_,\
    \ Filled_, HasRadius2>& rhs);\n  };\n\n  template <typename T>\n  class directed_line_segment_2d\
    \ {\n  private:\n    ::tools::vector2<T> m_p1;\n    ::tools::vector2<T> m_p2;\n\
    \n  public:\n    directed_line_segment_2d() = default;\n    directed_line_segment_2d(const\
    \ ::tools::directed_line_segment_2d<T>&) = default;\n    directed_line_segment_2d(::tools::directed_line_segment_2d<T>&&)\
    \ = default;\n    ~directed_line_segment_2d() = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(const ::tools::directed_line_segment_2d<T>&) = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(::tools::directed_line_segment_2d<T>&&) = default;\n\n    directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);\n\n    bool contains(const\
    \ ::tools::vector2<T>& p) const;\n    ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> length() const; \n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    midpoint() const;\n\
    \    const ::tools::vector2<T>& p1() const;\n    const ::tools::vector2<T>& p2()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    T squared_length() const;\n    ::tools::half_line_2d<T> to_half_line()\
    \ const;\n    ::tools::line_2d<T> to_line() const;\n    ::tools::vector2<T> to_vector()\
    \ const;\n\n    ::tools::directed_line_segment_2d<T> operator+() const;\n    ::tools::directed_line_segment_2d<T>\
    \ operator-() const;\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n  };\n\n  template\
    \ <typename T>\n  class half_line_2d {\n  private:\n    ::tools::vector2<T> m_a;\n\
    \    ::tools::vector2<T> m_d;\n\n  public:\n    half_line_2d() = default;\n  \
    \  half_line_2d(const ::tools::half_line_2d<T>&) = default;\n    half_line_2d(::tools::half_line_2d<T>&&)\
    \ = default;\n    ~half_line_2d() = default;\n    ::tools::half_line_2d<T>& operator=(const\
    \ ::tools::half_line_2d<T>&) = default;\n    ::tools::half_line_2d<T>& operator=(::tools::half_line_2d<T>&&)\
    \ = default;\n\n    half_line_2d(const ::tools::vector2<T>& a, const ::tools::vector2<T>&\
    \ d);\n\n    const ::tools::vector2<T>& a() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    const ::tools::vector2<T>& d() const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>& other)\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    ::tools::line_2d<T> to_line() const;\n\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>, ::tools::half_line_2d<T_>>>>\n    operator&(const\
    \ ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);\n   \
    \ template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::half_line_2d<T_>>>>\n    operator&(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::half_line_2d<T_>& rhs);\n  };\n\n  template <typename T>\n\
    \  class line_2d {\n  private:\n    T m_a;\n    T m_b;\n    T m_c;\n\n  public:\n\
    \    line_2d() = default;\n    line_2d(const ::tools::line_2d<T>&) = default;\n\
    \    line_2d(::tools::line_2d<T>&&) = default;\n    ~line_2d() = default;\n  \
    \  ::tools::line_2d<T>& operator=(const ::tools::line_2d<T>&) = default;\n   \
    \ ::tools::line_2d<T>& operator=(::tools::line_2d<T>&&) = default;\n\n    line_2d(const\
    \ T& a, const T& b, const T& c);\n\n    const T& a() const;\n    const T& b()\
    \ const;\n    const T& c() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    bool crosses(const ::tools::line_2d<T>& other) const;\n \
    \   bool is_parallel_to(const ::tools::line_2d<T>& other) const;\n    ::tools::vector2<T>\
    \ normal() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    projection(const\
    \ ::tools::vector2<T>& p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::vector<::tools::vector2<T_>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::circle_2d<T_, false, HasRadius_>& rhs);\n    template <typename\
    \ T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::circle_2d<T_, true,\
    \ HasRadius_>& rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::half_line_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::line_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>& lhs, const\
    \ ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend bool operator==(const\
    \ ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend bool operator!=(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n\n    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1,\
    \ const ::tools::vector2<T>& p2);\n  };\n\n  template <typename T, bool Filled>\n\
    \  class polygon_2d {\n  protected:\n    ::std::vector<::tools::vector2<T>> m_points;\n\
    \    T doubled_signed_area() const;\n\n  public:\n    polygon_2d() = default;\n\
    \    polygon_2d(const ::tools::polygon_2d<T, Filled>&) = default;\n    polygon_2d(::tools::polygon_2d<T,\
    \ Filled>&&) = default;\n    ~polygon_2d() = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(const ::tools::polygon_2d<T, Filled>&) = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(::tools::polygon_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    polygon_2d(const InputIterator& begin, const InputIterator&\
    \ end);\n    polygon_2d(::std::initializer_list<::tools::vector2<T>> init);\n\n\
    \    template <typename T_ = T, bool Filled_ = Filled>\n    ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> area() const;\n    template\
    \ <bool Filled_ = Filled>\n    ::std::enable_if_t<Filled_, T> doubled_area() const;\n\
    \    bool is_counterclockwise() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle()\
    \ const;\n    int where(const ::tools::vector2<T>& p) const;\n  };\n\n  template\
    \ <typename T, bool Filled>\n  class triangle_2d : public polygon_2d<T, Filled>\
    \ {\n  private:\n    template <typename OutputIterator>\n    void sorted_edges(OutputIterator\
    \ result) const;\n\n  public:\n    triangle_2d() = default;\n    triangle_2d(const\
    \ ::tools::triangle_2d<T, Filled>&) = default;\n    triangle_2d(::tools::triangle_2d<T,\
    \ Filled>&&) = default;\n    ~triangle_2d() = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(const ::tools::triangle_2d<T, Filled>&) = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(::tools::triangle_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    triangle_2d(const InputIterator& begin, const\
    \ InputIterator& end);\n    triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init);\n\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> circumcircle()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> incircle() const;\n    template <typename T_\
    \ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle() const;\n   \
    \ int type() const;\n  };\n\n  template <typename T, bool Filled, bool HasRadius>\n\
    \  circle_2d<T, Filled, HasRadius>::circle_2d(const ::tools::vector2<T>& center,\
    \ const T& radius_or_squared_radius) : m_center(center) {\n    assert(radius_or_squared_radius\
    \ > T(0));\n    if constexpr (HasRadius) {\n      this->m_radius = radius_or_squared_radius;\n\
    \      this->m_squared_radius = ::tools::square(this->m_radius);\n    } else {\n\
    \      this->m_squared_radius = radius_or_squared_radius;\n    }\n  }\n\n  template\
    \ <typename T, bool Filled, bool HasRadius> template <typename T_, bool Filled_>\n\
    \  ::std::enable_if_t<::std::is_floating_point_v<T_> && Filled_, T> circle_2d<T,\
    \ Filled, HasRadius>::area() const {\n    return ::std::acos(T(-1)) * this->m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  ::tools::vector2<T>\
    \ circle_2d<T, Filled, HasRadius>::center() const {\n    return this->m_center;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius> template <bool HasRadius_>\n\
    \  ::std::enable_if_t<HasRadius_, T> circle_2d<T, Filled, HasRadius>::radius()\
    \ const {\n    return this->m_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  T circle_2d<T, Filled, HasRadius>::squared_radius() const\
    \ {\n    return this->m_squared_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  ::std::pair<int, int> circle_2d<T, Filled, HasRadius>::where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const {\n    return ::std::make_pair([&]()\
    \ {\n      if (*this == other) {\n        return ::std::numeric_limits<int>::max();\n\
    \      }\n      if constexpr (HasRadius) {\n        const auto d2 = (this->m_center\
    \ - other.m_center).squared_l2_norm();\n        const auto& a_r = this->m_radius;\n\
    \        const auto& b_r = other.m_radius;\n        const ::std::array<T, 2> threshold\
    \ = {::tools::square(a_r - b_r), ::tools::square(a_r + b_r)};\n        if (d2\
    \ < threshold[0]) {\n          return 0;\n        } else if (d2 == threshold[0])\
    \ {\n          return 1;\n        } else if (d2 == threshold[1]) {\n         \
    \ return 3;\n        } else if (threshold[1] < d2) {\n          return 4;\n  \
    \      } else {\n          return 2;\n        }\n      } else {\n        const\
    \ auto d2 = (this->m_center - other.m_center).squared_l2_norm();\n        const\
    \ auto& a_r2 = this->m_squared_radius;\n        const auto& b_r2 = other.m_squared_radius;\n\
    \        const auto threshold = a_r2 + b_r2 - d2;\n        const auto squared_threshold\
    \ = ::tools::square(threshold);\n        const auto v = T(4) * a_r2 * b_r2;\n\
    \        if (threshold > T(0) && v < squared_threshold) {\n          return 0;\n\
    \        } else if (threshold > T(0) && v == squared_threshold) {\n          return\
    \ 1;\n        } else if (threshold < T(0) && v == squared_threshold) {\n     \
    \     return 3;\n        } else if (threshold < T(0) && v < squared_threshold)\
    \ {\n          return 4;\n        } else {\n          return 2;\n        }\n \
    \     }\n    }(), ::tools::signum(this->m_squared_radius - other.m_squared_radius));\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  int circle_2d<T,\
    \ Filled, HasRadius>::where(const ::tools::vector2<T>& p) const {\n    return\
    \ ::tools::signum(this->m_squared_radius - (p - this->m_center).squared_l2_norm());\n\
    \  }\n\n  template <typename T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::circle_2d<T, false, HasRadius>, ::std::vector<::tools::vector2<T>>>>>\n\
    \  operator&(const ::tools::circle_2d<T, false, HasRadius>& lhs, const ::tools::circle_2d<T,\
    \ false, HasRadius>& rhs) {\n    using variant_t = ::std::variant<::tools::circle_2d<T,\
    \ false, HasRadius>, ::std::vector<::tools::vector2<T>>>;\n    using result_t\
    \ = ::std::optional<variant_t>;\n\n    const auto t = lhs.where(rhs).first;\n\
    \    if (t == ::std::numeric_limits<int>::max()) return result_t(variant_t(lhs));\n\
    \    if (t == 0 || t == 4) return ::std::nullopt;\n\n    const auto& x1 = lhs.m_center.x;\n\
    \    const auto& y1 = lhs.m_center.y;\n    const auto& x2 = rhs.m_center.x;\n\
    \    const auto& y2 = rhs.m_center.y;\n    const ::tools::line_2d<T> l(2 * (x2\
    \ - x1), 2 * (y2 - y1), (x1 + x2) * (x1 - x2) + (y1 + y2) * (y1 - y2) + rhs.m_squared_radius\
    \ - lhs.m_squared_radius);\n\n    return result_t(variant_t(lhs & l));\n  }\n\n\
    \  template <typename T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ ::std::vector<::tools::vector2<T>>>\n  operator&(const ::tools::circle_2d<T,\
    \ false, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using result_t\
    \ = ::std::vector<::tools::vector2<T>>;\n    if (const auto intersection = ::tools::circle_2d<T,\
    \ true, HasRadius>(lhs.m_center, HasRadius ? lhs.m_radius : lhs.m_squared_radius)\
    \ & rhs; intersection) {\n      struct {\n        result_t operator()(const ::tools::vector2<T>&\
    \ v) {\n          return result_t({v});\n        }\n        result_t operator()(const\
    \ ::tools::directed_line_segment_2d<T>& s) {\n          return result_t({s.p1(),\
    \ s.p2()});\n        }\n      } visitor;\n      return ::std::visit(visitor, *intersection);\n\
    \    } else {\n      return result_t();\n    }\n  }\n\n  template <typename T,\
    \ bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::circle_2d<T,\
    \ true, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n\n    const auto [a, b, c]\
    \ = (rhs.projection(lhs.m_center) - lhs.m_center).inner_product(rhs.normal())\
    \ >= T(0) ? ::std::make_tuple(rhs.a(), rhs.b(), rhs.c()) : ::std::make_tuple(-rhs.a(),\
    \ -rhs.b(), -rhs.c());\n    const auto& x = lhs.m_center.x;\n    const auto& y\
    \ = lhs.m_center.y;\n    const auto r = HasRadius ? lhs.m_radius : ::std::sqrt(lhs.m_squared_radius);\n\
    \    const auto& r2 = lhs.m_squared_radius;\n    const auto d2 = rhs.squared_distance(lhs.m_center);\n\
    \n    if (d2 < r2) {\n      const auto D = ::std::abs(a * x + b * y + c);\n  \
    \    return result_t(variant_t(::tools::directed_line_segment_2d<T>(\n       \
    \ ::tools::vector2<T>((a * D - b * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + x, (b * D + a * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + y),\n        ::tools::vector2<T>((a * D + b * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + x, (b * D - a * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + y)\n      )));\n    } else if\
    \ (d2 == r2) {\n      return result_t(variant_t(::tools::vector2<T>(a * r / ::std::sqrt(a\
    \ * a + b * b) + x, b * r / ::std::sqrt(a * a + b * b) + y)));\n    } else {\n\
    \      return ::std::nullopt;\n    }\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius1, bool HasRadius2>\n  bool operator==(const ::tools::circle_2d<T,\
    \ Filled, HasRadius1>& lhs, const ::tools::circle_2d<T, Filled, HasRadius2>& rhs)\
    \ {\n    return lhs.m_center == rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n\
    \  bool operator!=(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const\
    \ ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {\n    return !(lhs == rhs);\n\
    \  }\n\n  template <typename T>\n  directed_line_segment_2d<T>::directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) :\n    m_p1(p1),\n \
    \   m_p2(p2) {\n    assert(p1 != p2);\n  }\n\n  template <typename T>\n  bool\
    \ directed_line_segment_2d<T>::contains(const ::tools::vector2<T>& p) const {\n\
    \    if (p == this->m_p1 || p == this->m_p2) return true;\n    const ::tools::line_2d<T>\
    \ l = this->to_line();\n    if (!l.contains(p)) return false;\n    const T d =\
    \ (p - this->m_p1).inner_product(this->to_vector());\n    return T(0) <= d &&\
    \ d <= this->squared_length();\n  }\n\n  template <typename T> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return result_t();\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> directed_line_segment_2d<T>::length() const {\n    return this->to_vector().l2_norm();\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n  directed_line_segment_2d<T>::midpoint()\
    \ const {\n    return (this->m_p1 + this->m_p2) / T(2);\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& directed_line_segment_2d<T>::p1() const {\n\
    \    return this->m_p1;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ directed_line_segment_2d<T>::p2() const {\n    return this->m_p2;\n  }\n\n \
    \ template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    if (*this & other)\
    \ {\n      return T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2),\n      this->squared_distance(other.m_p1),\n\
    \      this->squared_distance(other.m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    const auto x = this->to_line().projection(p);\n\
    \    const auto d = this->to_vector().inner_product(x - this->m_p1);\n    return\
    \ (p - (d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x)).squared_l2_norm();\n\
    \  }\n\n  template <typename T>\n  T directed_line_segment_2d<T>::squared_length()\
    \ const {\n    return this->to_vector().squared_l2_norm();\n  }\n\n  template\
    \ <typename T>\n  ::tools::half_line_2d<T> directed_line_segment_2d<T>::to_half_line()\
    \ const {\n    return ::tools::half_line_2d<T>(this->m_p1, this->m_p2 - this->m_p1);\n\
    \  }\n\n  template <typename T>\n  ::tools::line_2d<T> directed_line_segment_2d<T>::to_line()\
    \ const {\n    return ::tools::line_2d<T>::through(this->m_p1, this->m_p2);\n\
    \  }\n\n  template <typename T>\n  ::tools::vector2<T> directed_line_segment_2d<T>::to_vector()\
    \ const {\n    return this->m_p2 - this->m_p1;\n  }\n\n  template <typename T>\n\
    \  ::tools::directed_line_segment_2d<T> directed_line_segment_2d<T>::operator+()\
    \ const {\n    return *this;\n  }\n\n  template <typename T>\n  ::tools::directed_line_segment_2d<T>\
    \ directed_line_segment_2d<T>::operator-() const {\n    return ::tools::directed_line_segment_2d<T>(this->m_p2,\
    \ this->m_p1);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const ::tools::vector2<T> base = lhs.to_vector();\n \
    \     const ::tools::directed_line_segment_2d<T> fixed_rhs = base.inner_product(rhs.to_vector())\
    \ > T(0) ? rhs : -rhs;\n      const T d1(0);\n      const T d2 = base.inner_product(base);\n\
    \      const T d3 = base.inner_product(fixed_rhs.m_p1 - lhs.m_p1);\n      const\
    \ T d4 = base.inner_product(fixed_rhs.m_p2 - lhs.m_p1);\n      if (d1 == d4) return\
    \ result_t(variant_t(lhs.m_p1));\n      if (d2 == d3) return result_t(variant_t(lhs.m_p2));\n\
    \      if (d3 <= d1 && d2 <= d4) return result_t(variant_t(lhs));\n      if (d1\
    \ <= d3 && d4 <= d2) return result_t(variant_t(fixed_rhs));\n      if (d3 <= d1\
    \ && d1 <= d4 && d4 <= d2) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ fixed_rhs.m_p2)));\n      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t(variant_t(::tools::directed_line_segment_2d<T>(fixed_rhs.m_p1,\
    \ lhs.m_p2)));\n      return ::std::nullopt;\n    }\n    if (l1.is_parallel_to(l2))\
    \ return ::std::nullopt;\n    if (lhs.m_p1 == rhs.m_p1 || lhs.m_p1 == rhs.m_p2)\
    \ return result_t(variant_t(lhs.m_p1));\n    if (lhs.m_p2 == rhs.m_p1 || lhs.m_p2\
    \ == rhs.m_p2) return result_t(variant_t(lhs.m_p2));\n    if (((rhs.m_p1.y - lhs.m_p1.y)\
    \ * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y - lhs.m_p1.y) * (rhs.m_p1.x - lhs.m_p1.x))\
    \ *\n        ((rhs.m_p2.y - lhs.m_p1.y) * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y\
    \ - lhs.m_p1.y) * (rhs.m_p2.x - lhs.m_p1.x)) > T(0) ||\n        ((lhs.m_p1.y -\
    \ rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x) - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p1.x\
    \ - rhs.m_p1.x)) *\n        ((lhs.m_p2.y - rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x)\
    \ - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p2.x - rhs.m_p1.x)) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*l1.cross_point(l2)));\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>\n\
    \  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::half_line_2d<T>&\
    \ rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const bool has_same_direction = rhs.d().inner_product(lhs.to_vector())\
    \ > T(0);\n      const T d1 = rhs.d().inner_product(lhs.m_p1 - rhs.a());\n   \
    \   const T d2 = rhs.d().inner_product(lhs.m_p2 - rhs.a());\n      if (has_same_direction)\
    \ {\n        if (d2 < T(0)) return ::std::nullopt;\n        if (d2 == T(0)) return\
    \ result_t(variant_t(rhs.a()));\n        if (d1 < T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(rhs.a(),\
    \ lhs.m_p2)));\n        return result_t(variant_t(lhs));\n      } else {\n   \
    \     if (d1 > T(0)) return ::std::nullopt;\n        if (d1 == T(0)) return result_t(variant_t(rhs.a()));\n\
    \        if (d2 > T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ rhs.a())));\n        return result_t(variant_t(lhs));\n      }\n    }\n    if\
    \ (rhs.contains(lhs.m_p1)) return result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2))\
    \ return result_t(variant_t(lhs.m_p2));\n    if ((l2.a() * lhs.m_p1.x + l2.b()\
    \ * lhs.m_p1.y + l2.c()) * (l2.a() * lhs.m_p2.x + l2.b() * lhs.m_p2.y + l2.c())\
    \ > T(0)) return ::std::nullopt;\n    const ::tools::vector2<T> possible_cross_point\
    \ = *l1.cross_point(l2);\n    if (rhs.d().inner_product(possible_cross_point -\
    \ rhs.a()) < T(0)) return ::std::nullopt;\n    return result_t(variant_t(possible_cross_point));\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> lhs_line = lhs.to_line();\n    if (lhs_line ==\
    \ rhs) return result_t(variant_t(lhs));\n    if (rhs.contains(lhs.m_p1)) return\
    \ result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2)) return result_t(variant_t(lhs.m_p2));\n\
    \    if ((rhs.a() * lhs.m_p1.x + rhs.b() * lhs.m_p1.y + rhs.c()) * (rhs.a() *\
    \ lhs.m_p2.x + rhs.b() * lhs.m_p2.y + rhs.c()) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*lhs_line.cross_point(rhs)));\n  }\n\n  template\
    \ <typename T>\n  bool operator==(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return lhs.p1()\
    \ == rhs.p1() && lhs.p2() == rhs.p2();\n  }\n\n  template <typename T>\n  bool\
    \ operator!=(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>&\
    \ rhs) {\n    return !(lhs == rhs);\n  }\n\n  template <typename T>\n  half_line_2d<T>::half_line_2d(const\
    \ ::tools::vector2<T>& a, const ::tools::vector2<T>& d) :\n    m_a(a),\n    m_d(d)\
    \ {\n    assert(d != ::tools::vector2<T>(T(0), T(0)));\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& half_line_2d<T>::a() const {\n    return this->m_a;\n\
    \  }\n\n  template <typename T>\n  bool half_line_2d<T>::contains(const ::tools::vector2<T>&\
    \ p) const {\n    const ::tools::line_2d<T> l = this->to_line();\n    return l.a()\
    \ * p.x + l.b() * p.y + l.c() == T(0) && this->m_d.inner_product(p - this->m_a)\
    \ >= T(0);\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other)\
    \ const {\n    return other.cross_point(*this);\n  }\n\n  template <typename T>\
    \ template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n      result_t operator()(const ::tools::half_line_2d<T>&) {\n     \
    \   return ::std::nullopt;\n      }\n    } visitor;\n    return intersection ?\
    \ ::std::visit(visitor, *intersection) : ::std::nullopt;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::half_line_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ half_line_2d<T>::d() const {\n    return this->m_d;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    if (const auto x = this->to_line().cross_point(other.to_line());\
    \ x) {\n      if (this->m_d.inner_product(*x - this->m_a) >= T(0)) {\n       \
    \ return (other.m_a - *x).squared_l2_norm();\n      } else if (other.m_d.inner_product(*x\
    \ - other.m_a) >= T(0)) {\n        return (this->m_a - *x).squared_l2_norm();\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    } else {\n      if (this->m_d.inner_product(other.m_a) > T(0)) {\n\
    \        return this->to_line().squared_distance(other.to_line());\n      } else\
    \ if (const auto x = this->to_line().projection(other.m_a); this->m_d.inner_product(x\
    \ - this->m_a) >= T(0)) {\n        return this->to_line().squared_distance(other.to_line());\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    }\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return other.squared_distance(this->m_a);\n  }\n\n  template\
    \ <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    auto x = this->to_line().projection(p);\n\
    \    const auto d = this->m_d.inner_product(x - this->m_a);\n    return (p - (d\
    \ < T(0) ? this->m_a : x)).squared_l2_norm();\n  }\n\n  template <typename T>\n\
    \  ::tools::line_2d<T> half_line_2d<T>::to_line() const {\n    return ::tools::line_2d<T>::through(this->m_a,\
    \ this->m_a + this->m_d);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::half_line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>>>\n  operator&(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    using\
    \ variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>,\
    \ ::tools::half_line_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> l1 = lhs.to_line();\n    const ::tools::line_2d<T>\
    \ l2 = rhs.to_line();\n    if (l1 == l2) {\n      if (lhs.d().inner_product(rhs.d())\
    \ > T(0)) {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() - lhs.a())))\
    \ {\n        case 1:\n        case 0:\n          return result_t(variant_t(rhs));\n\
    \        default:\n          return result_t(variant_t(lhs));\n        }\n   \
    \   } else {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() -\
    \ lhs.a()))) {\n        case 1:\n          return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.a(),\
    \ rhs.a())));\n        case 0:\n          return result_t(variant_t(lhs.a()));\n\
    \        default:\n          return ::std::nullopt;\n        }\n      }\n    }\
    \ else if (l1.is_parallel_to(l2)) {\n      return ::std::nullopt;\n    } else\
    \ {\n      const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);\n\
    \      if (lhs.d().inner_product(possible_cross_point - lhs.a()) < T(0) || rhs.d().inner_product(possible_cross_point\
    \ - rhs.a()) < T(0)) {\n        return ::std::nullopt;\n      }\n      return\
    \ result_t(variant_t(possible_cross_point));\n    }\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>>>\n\
    \  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::line_2d<T>& rhs)\
    \ {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const auto lhs_line = lhs.to_line();\n\
    \    if (lhs_line == rhs) return result_t(variant_t(lhs));\n    const auto possible_cross_point\
    \ = lhs_line.cross_point(rhs);\n    return possible_cross_point && lhs.m_d.inner_product(*possible_cross_point\
    \ - lhs.m_a) >= T(0)\n      ? result_t(variant_t(*possible_cross_point))\n   \
    \   : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    return\
    \ lhs.a() == rhs.a() && lhs.d().x * rhs.d().y == rhs.d().x * lhs.d().y;\n  }\n\
    \n  template <typename T>\n  bool operator!=(const ::tools::half_line_2d<T>& lhs,\
    \ const ::tools::half_line_2d<T>& rhs) {\n    return !(lhs == rhs);\n  }\n\n \
    \ template <typename T>\n  line_2d<T>::line_2d(const T& a, const T& b, const T&\
    \ c) :\n    m_a(a),\n    m_b(b),\n    m_c(c) {\n    assert(a != T(0) || b != T(0));\n\
    \  }\n\n  template <typename T>\n  const T& line_2d<T>::a() const {\n    return\
    \ this->m_a;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::b() const\
    \ {\n    return this->m_b;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::c()\
    \ const {\n    return this->m_c;\n  }\n\n  template <typename T>\n  bool line_2d<T>::contains(const\
    \ ::tools::vector2<T>& p) const {\n    return this->m_a * p.x + this->m_b * p.y\
    \ + this->m_c == T(0);\n  }\n\n  template <typename T> template <typename T_>\n\
    \  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>&\
    \ other) const {\n    return other.cross_point(*this);\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {\n    using\
    \ result_t = ::std::optional<::tools::vector2<T>>;\n    if (!this->crosses(other))\
    \ return ::std::nullopt;\n    return result_t(::tools::vector2<T>(\n      (this->m_b\
    \ * other.m_c - other.m_b * this->m_c) / (this->m_a * other.m_b - other.m_a *\
    \ this->m_b),\n      (other.m_a * this->m_c - this->m_a * other.m_c) / (this->m_a\
    \ * other.m_b - other.m_a * this->m_b)\n    ));\n  }\n\n  template <typename T>\n\
    \  bool line_2d<T>::crosses(const ::tools::line_2d<T>& other) const {\n    return\
    \ this->m_a * other.m_b != other.m_a * this->m_b;\n  }\n\n  template <typename\
    \ T>\n  bool line_2d<T>::is_parallel_to(const ::tools::line_2d<T>& other) const\
    \ {\n    return this->m_a * other.m_b == this->m_b * other.m_a;\n  }\n\n  template\
    \ <typename T>\n  ::tools::vector2<T> line_2d<T>::normal() const {\n    return\
    \ ::tools::vector2<T>(this->m_a, this->m_b);\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::vector2<T>>\n  line_2d<T>::projection(const ::tools::vector2<T>& p)\
    \ const {\n    return *::tools::half_line_2d<T>(p, this->normal()).to_line().cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (this->is_parallel_to(other)) {\n\
    \      return ::tools::square(other.m_a * this->m_c - this->m_a * other.m_c) /\
    \ (::tools::square(this->m_a) + ::tools::square(this->m_b)) / ::tools::square(other.m_a);\n\
    \    } else {\n      return T(0);\n    }\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n  line_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {\n \
    \   return (p - this->projection(p)).squared_l2_norm();\n  }\n\n  template <typename\
    \ T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::vector<::tools::vector2<T>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::circle_2d<T, false,\
    \ HasRadius>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename T, bool\
    \ HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::circle_2d<T, true, HasRadius>& rhs) {\n    return rhs &\
    \ lhs;\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::half_line_2d<T>>>>\n  operator&(const ::tools::line_2d<T>& lhs, const\
    \ ::tools::half_line_2d<T>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n\
    \    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    if (lhs == rhs) return\
    \ result_t(variant_t(lhs));\n    const auto possible_cross_point = lhs.cross_point(rhs);\n\
    \    return possible_cross_point ? result_t(variant_t(*possible_cross_point))\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    return lhs.m_b * rhs.m_c == lhs.m_c\
    \ * rhs.m_b && lhs.m_c * rhs.m_a == lhs.m_a * rhs.m_c && lhs.m_a * rhs.m_b ==\
    \ lhs.m_b * rhs.m_a;\n  }\n\n  template <typename T>\n  bool operator!=(const\
    \ ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n    return !(lhs\
    \ == rhs);\n  }\n\n  template <typename T>\n  ::tools::line_2d<T> line_2d<T>::through(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) {\n    return ::tools::line_2d<T>(p1.y\
    \ - p2.y, p2.x - p1.x, (p2.y - p1.y) * p1.x - (p2.x - p1.x) * p1.y);\n  }\n\n\
    \  template <typename T, bool Filled>\n  T polygon_2d<T, Filled>::doubled_signed_area()\
    \ const {\n    T result(0);\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      result += (this->m_points[i].x - this->m_points[(i + 1) % this->m_points.size()].x)\
    \ * (this->m_points[i].y + this->m_points[(i + 1) % this->m_points.size()].y);\n\
    \    }\n    return result;\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename InputIterator>\n  polygon_2d<T, Filled>::polygon_2d(const InputIterator&\
    \ begin, const InputIterator& end) : m_points(begin, end) {\n    assert(this->m_points.size()\
    \ >= 3);\n  }\n\n  template <typename T, bool Filled>\n  polygon_2d<T, Filled>::polygon_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : polygon_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_, bool Filled_>\n  ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> polygon_2d<T, Filled>::area()\
    \ const {\n    return this->doubled_area() / T(2);\n  }\n\n  template <typename\
    \ T, bool Filled> template <bool Filled_>\n  ::std::enable_if_t<Filled_, T> polygon_2d<T,\
    \ Filled>::doubled_area() const {\n    return ::tools::abs(this->doubled_signed_area());\n\
    \  }\n\n  template <typename T, bool Filled>\n  bool polygon_2d<T, Filled>::is_counterclockwise()\
    \ const {\n    return this->doubled_signed_area() > T(0);\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> polygon_2d<T,\
    \ Filled>::minimum_bounding_circle() const {\n    ::std::optional<::tools::circle_2d<T,\
    \ Filled, false>> answer;\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j)\
    \ {\n        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {\n\
    \          if (const auto possible_answer = ::tools::triangle_2d<T, Filled>({this->m_points[i],\
    \ this->m_points[j], this->m_points[k]}).minimum_bounding_circle();\n        \
    \      !answer || answer->squared_radius() < possible_answer.squared_radius())\
    \ {\n            answer = ::std::move(possible_answer);\n          }\n       \
    \ }\n      }\n    }\n    return *answer;\n  }\n\n  template <typename T, bool\
    \ Filled>\n  int polygon_2d<T, Filled>::where(const ::tools::vector2<T>& p) const\
    \ {\n    ::std::vector<::tools::directed_line_segment_2d<T>> edges;\n    for (::std::size_t\
    \ i = 0; i < this->m_points.size(); ++i) {\n      edges.emplace_back(this->m_points[i],\
    \ this->m_points[(i + 1) % this->m_points.size()]);\n    }\n\n    if (std::any_of(edges.begin(),\
    \ edges.end(), [&](const auto& edge) { return edge.contains(p); })) {\n      return\
    \ 0;\n    } else {\n      bool in = false;\n      for (const auto& edge : edges)\
    \ {\n        if ([&]() {\n          const auto l = edge.to_line();\n         \
    \ if (l == ::tools::line_2d<T>(T(0), T(1), -p.y)) return false;\n          if\
    \ (p.x <= edge.p1().x && p.y == edge.p1().y) return edge.p2().y < edge.p1().y;\n\
    \          if (p.x <= edge.p2().x && p.y == edge.p2().y) return edge.p1().y <\
    \ edge.p2().y;\n          if ((edge.p1().y - p.y) * (edge.p2().y - p.y) > T(0))\
    \ return false;\n          return l.a() * (l.a() * p.x + l.b() * p.y + l.c())\
    \ < T(0);\n        }()) {\n          in = !in;\n        }\n      }\n      return\
    \ in ? 1 : -1;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename OutputIterator>\n  void triangle_2d<T, Filled>::sorted_edges(OutputIterator\
    \ result) const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    for (int i = 0; i < 3; ++i) {\n      edges[i] = ::tools::directed_line_segment_2d<T>(this->m_points[i],\
    \ this->m_points[(i + 1) % 3]);\n    }\n    ::std::sort(edges.begin(), edges.end(),\
    \ ::tools::less_by([](const auto& edge) {\n      return edge.squared_length();\n\
    \    }));\n    for (const auto& edge : edges) {\n      *result = edge;\n     \
    \ ++result;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template <typename\
    \ InputIterator>\n  triangle_2d<T, Filled>::triangle_2d(const InputIterator& begin,\
    \ const InputIterator& end) : polygon_2d<T, Filled>(begin, end) {\n    assert(this->m_points.size()\
    \ == 3);\n  }\n\n  template <typename T, bool Filled>\n  triangle_2d<T, Filled>::triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : triangle_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> triangle_2d<T,\
    \ Filled>::circumcircle() const {\n    const auto& A = this->m_points[0];\n  \
    \  const auto& B = this->m_points[1];\n    const auto& C = this->m_points[2];\n\
    \    const auto a2 = (C - B).squared_l2_norm();\n    const auto b2 = (A - C).squared_l2_norm();\n\
    \    const auto c2 = (B - A).squared_l2_norm();\n    const auto kA = a2 * (b2\
    \ + c2 - a2);\n    const auto kB = b2 * (c2 + a2 - b2);\n    const auto kC = c2\
    \ * (a2 + b2 - c2);\n    const auto circumcenter = (kA * A + kB * B + kC * C)\
    \ / (kA + kB + kC);\n    return ::tools::circle_2d<T, Filled, false>(circumcenter,\
    \ (circumcenter - A).squared_l2_norm());\n  }\n\n  template <typename T, bool\
    \ Filled> template <typename T_>\n  ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> triangle_2d<T, Filled>::incircle() const {\n\
    \    const auto& A = this->m_points[0];\n    const auto& B = this->m_points[1];\n\
    \    const auto& C = this->m_points[2];\n    const auto a = (C - B).l2_norm();\n\
    \    const auto b = (A - C).l2_norm();\n    const auto c = (B - A).l2_norm();\n\
    \    const auto incenter = (a * A + b * B + c * C) / (a + b + c);\n    return\
    \ ::tools::circle_2d<T, Filled>(incenter, ::tools::abs(this->doubled_signed_area())\
    \ / (a + b + c));\n  }\n\n  template <typename T, bool Filled> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> triangle_2d<T, Filled>::minimum_bounding_circle()\
    \ const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    this->sorted_edges(edges.begin());\n    if (edges[0].squared_length() + edges[1].squared_length()\
    \ <= edges[2].squared_length()) {\n      const auto center = edges[2].midpoint();\n\
    \      return ::tools::circle_2d<T, Filled, false>(center, (center - edges[2].p1()).squared_l2_norm());\n\
    \    } else {\n      return this->circumcircle();\n    }\n  }\n\n  template <typename\
    \ T, bool Filled>\n  int triangle_2d<T, Filled>::type() const {\n    ::std::array<::tools::directed_line_segment_2d<T>,\
    \ 3> edges;\n    this->sorted_edges(edges.begin());\n    const auto c2 = edges[2].squared_length();\n\
    \    const auto a2b2 = edges[1].squared_length() + edges[0].squared_length();\n\
    \    if (c2 < a2b2) {\n      return 0;\n    } else if (c2 == a2b2) {\n      return\
    \ 1;\n    } else {\n      return 2;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DETAIL_GEOMETRY_2D_HPP\n#define TOOLS_DETAIL_GEOMETRY_2D_HPP\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <cstddef>\n#include <initializer_list>\n#include <limits>\n#include <optional>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include <variant>\n\
    #include <vector>\n#include \"tools/abs.hpp\"\n#include \"tools/is_rational.hpp\"\
    \n#include \"tools/less_by.hpp\"\n#include \"tools/signum.hpp\"\n#include \"tools/square.hpp\"\
    \n#include \"tools/vector2.hpp\"\n\nnamespace tools {\n  template <typename T,\
    \ bool Filled, bool HasRadius = true>\n  class circle_2d;\n\n  template <typename\
    \ T>\n  class directed_line_segment_2d;\n\n  template <typename T>\n  class half_line_2d;\n\
    \n  template <typename T>\n  class line_2d;\n\n  template <typename T, bool Filled>\n\
    \  class polygon_2d;\n\n  template <typename T, bool Filled>\n  class triangle_2d;\n\
    \n  template <typename T, bool Filled, bool HasRadius>\n  class circle_2d {\n\
    \  private:\n    ::tools::vector2<T> m_center;\n    T m_radius;\n    T m_squared_radius;\n\
    \n  public:\n    circle_2d() = default;\n    circle_2d(const ::tools::circle_2d<T,\
    \ Filled, HasRadius>&) = default;\n    circle_2d(::tools::circle_2d<T, Filled,\
    \ HasRadius>&&) = default;\n    ~circle_2d() = default;\n    ::tools::circle_2d<T,\
    \ Filled, HasRadius>& operator=(const ::tools::circle_2d<T, Filled, HasRadius>&)\
    \ = default;\n    ::tools::circle_2d<T, Filled, HasRadius>& operator=(::tools::circle_2d<T,\
    \ Filled, HasRadius>&&) = default;\n\n    circle_2d(const ::tools::vector2<T>&\
    \ center, const T& radius_or_squared_radius);\n\n    template <typename T_ = T,\
    \ bool Filled_ = Filled>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>\
    \ && Filled_, T> area() const;\n    ::tools::vector2<T> center() const;\n    template\
    \ <bool HasRadius_ = HasRadius>\n    ::std::enable_if_t<HasRadius_, T> radius()\
    \ const;\n    T squared_radius() const;\n    ::std::pair<int, int> where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const;\n    int where(const\
    \ ::tools::vector2<T>& p) const;\n\n    template <typename T_, bool HasRadius_>\n\
    \    friend ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::circle_2d<T_,\
    \ false, HasRadius_>, ::std::vector<::tools::vector2<T_>>>>>\n    operator&(const\
    \ ::tools::circle_2d<T_, false, HasRadius_>& lhs, const ::tools::circle_2d<T_,\
    \ false, HasRadius_>& rhs);\n    template <typename T_, bool HasRadius_>\n   \
    \ friend ::std::enable_if_t<::std::is_floating_point_v<T_>, ::std::vector<::tools::vector2<T_>>>\n\
    \    operator&(const ::tools::circle_2d<T_, false, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::circle_2d<T_, true, HasRadius_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n    template <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n\
    \    friend bool operator==(const ::tools::circle_2d<T_, Filled_, HasRadius1>&\
    \ lhs, const ::tools::circle_2d<T_, Filled_, HasRadius2>& rhs);\n    template\
    \ <typename T_, bool Filled_, bool HasRadius1, bool HasRadius2>\n    friend bool\
    \ operator!=(const ::tools::circle_2d<T_, Filled_, HasRadius1>& lhs, const ::tools::circle_2d<T_,\
    \ Filled_, HasRadius2>& rhs);\n  };\n\n  template <typename T>\n  class directed_line_segment_2d\
    \ {\n  private:\n    ::tools::vector2<T> m_p1;\n    ::tools::vector2<T> m_p2;\n\
    \n  public:\n    directed_line_segment_2d() = default;\n    directed_line_segment_2d(const\
    \ ::tools::directed_line_segment_2d<T>&) = default;\n    directed_line_segment_2d(::tools::directed_line_segment_2d<T>&&)\
    \ = default;\n    ~directed_line_segment_2d() = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(const ::tools::directed_line_segment_2d<T>&) = default;\n    ::tools::directed_line_segment_2d<T>&\
    \ operator=(::tools::directed_line_segment_2d<T>&&) = default;\n\n    directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2);\n\n    bool contains(const\
    \ ::tools::vector2<T>& p) const;\n    ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> length() const; \n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    midpoint() const;\n\
    \    const ::tools::vector2<T>& p1() const;\n    const ::tools::vector2<T>& p2()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    T squared_length() const;\n    ::tools::half_line_2d<T> to_half_line()\
    \ const;\n    ::tools::line_2d<T> to_line() const;\n    ::tools::vector2<T> to_vector()\
    \ const;\n\n    ::tools::directed_line_segment_2d<T> operator+() const;\n    ::tools::directed_line_segment_2d<T>\
    \ operator-() const;\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::directed_line_segment_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::directed_line_segment_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n  };\n\n  template\
    \ <typename T>\n  class half_line_2d {\n  private:\n    ::tools::vector2<T> m_a;\n\
    \    ::tools::vector2<T> m_d;\n\n  public:\n    half_line_2d() = default;\n  \
    \  half_line_2d(const ::tools::half_line_2d<T>&) = default;\n    half_line_2d(::tools::half_line_2d<T>&&)\
    \ = default;\n    ~half_line_2d() = default;\n    ::tools::half_line_2d<T>& operator=(const\
    \ ::tools::half_line_2d<T>&) = default;\n    ::tools::half_line_2d<T>& operator=(::tools::half_line_2d<T>&&)\
    \ = default;\n\n    half_line_2d(const ::tools::vector2<T>& a, const ::tools::vector2<T>&\
    \ d);\n\n    const ::tools::vector2<T>& a() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    const ::tools::vector2<T>& d() const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>& other)\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n    ::tools::line_2d<T> to_line() const;\n\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::half_line_2d<T_>& lhs, const ::tools::directed_line_segment_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>, ::tools::half_line_2d<T_>>>>\n    operator&(const\
    \ ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>& rhs);\n   \
    \ template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::half_line_2d<T_>>>>\n    operator&(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend\
    \ bool operator==(const ::tools::half_line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend bool operator!=(const ::tools::half_line_2d<T_>&\
    \ lhs, const ::tools::half_line_2d<T_>& rhs);\n  };\n\n  template <typename T>\n\
    \  class line_2d {\n  private:\n    T m_a;\n    T m_b;\n    T m_c;\n\n  public:\n\
    \    line_2d() = default;\n    line_2d(const ::tools::line_2d<T>&) = default;\n\
    \    line_2d(::tools::line_2d<T>&&) = default;\n    ~line_2d() = default;\n  \
    \  ::tools::line_2d<T>& operator=(const ::tools::line_2d<T>&) = default;\n   \
    \ ::tools::line_2d<T>& operator=(::tools::line_2d<T>&&) = default;\n\n    line_2d(const\
    \ T& a, const T& b, const T& c);\n\n    const T& a() const;\n    const T& b()\
    \ const;\n    const T& c() const;\n    bool contains(const ::tools::vector2<T>&\
    \ p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::directed_line_segment_2d<T>& other) const;\n  \
    \  template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \   cross_point(const ::tools::half_line_2d<T>& other) const;\n    template <typename\
    \ T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n    cross_point(const ::tools::line_2d<T>&\
    \ other) const;\n    bool crosses(const ::tools::line_2d<T>& other) const;\n \
    \   bool is_parallel_to(const ::tools::line_2d<T>& other) const;\n    ::tools::vector2<T>\
    \ normal() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n    projection(const\
    \ ::tools::vector2<T>& p) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::directed_line_segment_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::half_line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::line_2d<T>&\
    \ other) const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n    squared_distance(const ::tools::vector2<T>&\
    \ p) const;\n\n    template <typename T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::vector<::tools::vector2<T_>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::circle_2d<T_, false, HasRadius_>& rhs);\n    template <typename\
    \ T_, bool HasRadius_>\n    friend ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::directed_line_segment_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::circle_2d<T_, true,\
    \ HasRadius_>& rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::directed_line_segment_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>&\
    \ lhs, const ::tools::directed_line_segment_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::std::variant<::tools::vector2<T_>, ::tools::half_line_2d<T_>>>>\n\
    \    operator&(const ::tools::line_2d<T_>& lhs, const ::tools::half_line_2d<T_>&\
    \ rhs);\n    template <typename T_>\n    friend ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::std::variant<::tools::vector2<T_>,\
    \ ::tools::line_2d<T_>>>>\n    operator&(const ::tools::line_2d<T_>& lhs, const\
    \ ::tools::line_2d<T_>& rhs);\n    template <typename T_>\n    friend bool operator==(const\
    \ ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>& rhs);\n    template <typename\
    \ T_>\n    friend bool operator!=(const ::tools::line_2d<T_>& lhs, const ::tools::line_2d<T_>&\
    \ rhs);\n\n    static ::tools::line_2d<T> through(const ::tools::vector2<T>& p1,\
    \ const ::tools::vector2<T>& p2);\n  };\n\n  template <typename T, bool Filled>\n\
    \  class polygon_2d {\n  protected:\n    ::std::vector<::tools::vector2<T>> m_points;\n\
    \    T doubled_signed_area() const;\n\n  public:\n    polygon_2d() = default;\n\
    \    polygon_2d(const ::tools::polygon_2d<T, Filled>&) = default;\n    polygon_2d(::tools::polygon_2d<T,\
    \ Filled>&&) = default;\n    ~polygon_2d() = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(const ::tools::polygon_2d<T, Filled>&) = default;\n    ::tools::polygon_2d<T,\
    \ Filled>& operator=(::tools::polygon_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    polygon_2d(const InputIterator& begin, const InputIterator&\
    \ end);\n    polygon_2d(::std::initializer_list<::tools::vector2<T>> init);\n\n\
    \    template <typename T_ = T, bool Filled_ = Filled>\n    ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> area() const;\n    template\
    \ <bool Filled_ = Filled>\n    ::std::enable_if_t<Filled_, T> doubled_area() const;\n\
    \    bool is_counterclockwise() const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle()\
    \ const;\n    int where(const ::tools::vector2<T>& p) const;\n  };\n\n  template\
    \ <typename T, bool Filled>\n  class triangle_2d : public polygon_2d<T, Filled>\
    \ {\n  private:\n    template <typename OutputIterator>\n    void sorted_edges(OutputIterator\
    \ result) const;\n\n  public:\n    triangle_2d() = default;\n    triangle_2d(const\
    \ ::tools::triangle_2d<T, Filled>&) = default;\n    triangle_2d(::tools::triangle_2d<T,\
    \ Filled>&&) = default;\n    ~triangle_2d() = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(const ::tools::triangle_2d<T, Filled>&) = default;\n    ::tools::triangle_2d<T,\
    \ Filled>& operator=(::tools::triangle_2d<T, Filled>&&) = default;\n\n    template\
    \ <typename InputIterator>\n    triangle_2d(const InputIterator& begin, const\
    \ InputIterator& end);\n    triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init);\n\n    template <typename T_ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> circumcircle()\
    \ const;\n    template <typename T_ = T>\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> incircle() const;\n    template <typename T_\
    \ = T>\n    ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> minimum_bounding_circle() const;\n   \
    \ int type() const;\n  };\n\n  template <typename T, bool Filled, bool HasRadius>\n\
    \  circle_2d<T, Filled, HasRadius>::circle_2d(const ::tools::vector2<T>& center,\
    \ const T& radius_or_squared_radius) : m_center(center) {\n    assert(radius_or_squared_radius\
    \ > T(0));\n    if constexpr (HasRadius) {\n      this->m_radius = radius_or_squared_radius;\n\
    \      this->m_squared_radius = ::tools::square(this->m_radius);\n    } else {\n\
    \      this->m_squared_radius = radius_or_squared_radius;\n    }\n  }\n\n  template\
    \ <typename T, bool Filled, bool HasRadius> template <typename T_, bool Filled_>\n\
    \  ::std::enable_if_t<::std::is_floating_point_v<T_> && Filled_, T> circle_2d<T,\
    \ Filled, HasRadius>::area() const {\n    return ::std::acos(T(-1)) * this->m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  ::tools::vector2<T>\
    \ circle_2d<T, Filled, HasRadius>::center() const {\n    return this->m_center;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius> template <bool HasRadius_>\n\
    \  ::std::enable_if_t<HasRadius_, T> circle_2d<T, Filled, HasRadius>::radius()\
    \ const {\n    return this->m_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  T circle_2d<T, Filled, HasRadius>::squared_radius() const\
    \ {\n    return this->m_squared_radius;\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius>\n  ::std::pair<int, int> circle_2d<T, Filled, HasRadius>::where(const\
    \ ::tools::circle_2d<T, Filled, HasRadius>& other) const {\n    return ::std::make_pair([&]()\
    \ {\n      if (*this == other) {\n        return ::std::numeric_limits<int>::max();\n\
    \      }\n      if constexpr (HasRadius) {\n        const auto d2 = (this->m_center\
    \ - other.m_center).squared_l2_norm();\n        const auto& a_r = this->m_radius;\n\
    \        const auto& b_r = other.m_radius;\n        const ::std::array<T, 2> threshold\
    \ = {::tools::square(a_r - b_r), ::tools::square(a_r + b_r)};\n        if (d2\
    \ < threshold[0]) {\n          return 0;\n        } else if (d2 == threshold[0])\
    \ {\n          return 1;\n        } else if (d2 == threshold[1]) {\n         \
    \ return 3;\n        } else if (threshold[1] < d2) {\n          return 4;\n  \
    \      } else {\n          return 2;\n        }\n      } else {\n        const\
    \ auto d2 = (this->m_center - other.m_center).squared_l2_norm();\n        const\
    \ auto& a_r2 = this->m_squared_radius;\n        const auto& b_r2 = other.m_squared_radius;\n\
    \        const auto threshold = a_r2 + b_r2 - d2;\n        const auto squared_threshold\
    \ = ::tools::square(threshold);\n        const auto v = T(4) * a_r2 * b_r2;\n\
    \        if (threshold > T(0) && v < squared_threshold) {\n          return 0;\n\
    \        } else if (threshold > T(0) && v == squared_threshold) {\n          return\
    \ 1;\n        } else if (threshold < T(0) && v == squared_threshold) {\n     \
    \     return 3;\n        } else if (threshold < T(0) && v < squared_threshold)\
    \ {\n          return 4;\n        } else {\n          return 2;\n        }\n \
    \     }\n    }(), ::tools::signum(this->m_squared_radius - other.m_squared_radius));\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius>\n  int circle_2d<T,\
    \ Filled, HasRadius>::where(const ::tools::vector2<T>& p) const {\n    return\
    \ ::tools::signum(this->m_squared_radius - (p - this->m_center).squared_l2_norm());\n\
    \  }\n\n  template <typename T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::circle_2d<T, false, HasRadius>, ::std::vector<::tools::vector2<T>>>>>\n\
    \  operator&(const ::tools::circle_2d<T, false, HasRadius>& lhs, const ::tools::circle_2d<T,\
    \ false, HasRadius>& rhs) {\n    using variant_t = ::std::variant<::tools::circle_2d<T,\
    \ false, HasRadius>, ::std::vector<::tools::vector2<T>>>;\n    using result_t\
    \ = ::std::optional<variant_t>;\n\n    const auto t = lhs.where(rhs).first;\n\
    \    if (t == ::std::numeric_limits<int>::max()) return result_t(variant_t(lhs));\n\
    \    if (t == 0 || t == 4) return ::std::nullopt;\n\n    const auto& x1 = lhs.m_center.x;\n\
    \    const auto& y1 = lhs.m_center.y;\n    const auto& x2 = rhs.m_center.x;\n\
    \    const auto& y2 = rhs.m_center.y;\n    const ::tools::line_2d<T> l(2 * (x2\
    \ - x1), 2 * (y2 - y1), (x1 + x2) * (x1 - x2) + (y1 + y2) * (y1 - y2) + rhs.m_squared_radius\
    \ - lhs.m_squared_radius);\n\n    return result_t(variant_t(lhs & l));\n  }\n\n\
    \  template <typename T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ ::std::vector<::tools::vector2<T>>>\n  operator&(const ::tools::circle_2d<T,\
    \ false, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using result_t\
    \ = ::std::vector<::tools::vector2<T>>;\n    if (const auto intersection = ::tools::circle_2d<T,\
    \ true, HasRadius>(lhs.m_center, HasRadius ? lhs.m_radius : lhs.m_squared_radius)\
    \ & rhs; intersection) {\n      struct {\n        result_t operator()(const ::tools::vector2<T>&\
    \ v) {\n          return result_t({v});\n        }\n        result_t operator()(const\
    \ ::tools::directed_line_segment_2d<T>& s) {\n          return result_t({s.p1(),\
    \ s.p2()});\n        }\n      } visitor;\n      return ::std::visit(visitor, *intersection);\n\
    \    } else {\n      return result_t();\n    }\n  }\n\n  template <typename T,\
    \ bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::circle_2d<T,\
    \ true, HasRadius>& lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n\n    const auto [a, b, c]\
    \ = (rhs.projection(lhs.m_center) - lhs.m_center).inner_product(rhs.normal())\
    \ >= T(0) ? ::std::make_tuple(rhs.a(), rhs.b(), rhs.c()) : ::std::make_tuple(-rhs.a(),\
    \ -rhs.b(), -rhs.c());\n    const auto& x = lhs.m_center.x;\n    const auto& y\
    \ = lhs.m_center.y;\n    const auto r = HasRadius ? lhs.m_radius : ::std::sqrt(lhs.m_squared_radius);\n\
    \    const auto& r2 = lhs.m_squared_radius;\n    const auto d2 = rhs.squared_distance(lhs.m_center);\n\
    \n    if (d2 < r2) {\n      const auto D = ::std::abs(a * x + b * y + c);\n  \
    \    return result_t(variant_t(::tools::directed_line_segment_2d<T>(\n       \
    \ ::tools::vector2<T>((a * D - b * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + x, (b * D + a * ::std::sqrt((a * a + b * b) * r2 - D * D))\
    \ / (a * a + b * b) + y),\n        ::tools::vector2<T>((a * D + b * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + x, (b * D - a * ::std::sqrt((a\
    \ * a + b * b) * r2 - D * D)) / (a * a + b * b) + y)\n      )));\n    } else if\
    \ (d2 == r2) {\n      return result_t(variant_t(::tools::vector2<T>(a * r / ::std::sqrt(a\
    \ * a + b * b) + x, b * r / ::std::sqrt(a * a + b * b) + y)));\n    } else {\n\
    \      return ::std::nullopt;\n    }\n  }\n\n  template <typename T, bool Filled,\
    \ bool HasRadius1, bool HasRadius2>\n  bool operator==(const ::tools::circle_2d<T,\
    \ Filled, HasRadius1>& lhs, const ::tools::circle_2d<T, Filled, HasRadius2>& rhs)\
    \ {\n    return lhs.m_center == rhs.m_center && lhs.m_squared_radius == rhs.m_squared_radius;\n\
    \  }\n\n  template <typename T, bool Filled, bool HasRadius1, bool HasRadius2>\n\
    \  bool operator!=(const ::tools::circle_2d<T, Filled, HasRadius1>& lhs, const\
    \ ::tools::circle_2d<T, Filled, HasRadius2>& rhs) {\n    return !(lhs == rhs);\n\
    \  }\n\n  template <typename T>\n  directed_line_segment_2d<T>::directed_line_segment_2d(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) :\n    m_p1(p1),\n \
    \   m_p2(p2) {\n    assert(p1 != p2);\n  }\n\n  template <typename T>\n  bool\
    \ directed_line_segment_2d<T>::contains(const ::tools::vector2<T>& p) const {\n\
    \    if (p == this->m_p1 || p == this->m_p2) return true;\n    const ::tools::line_2d<T>\
    \ l = this->to_line();\n    if (!l.contains(p)) return false;\n    const T d =\
    \ (p - this->m_p1).inner_product(this->to_vector());\n    return T(0) <= d &&\
    \ d <= this->squared_length();\n  }\n\n  template <typename T> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T> template <typename T_>\n \
    \ ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  directed_line_segment_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return result_t();\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double> directed_line_segment_2d<T>::length() const {\n    return this->to_vector().l2_norm();\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::vector2<T>>\n  directed_line_segment_2d<T>::midpoint()\
    \ const {\n    return (this->m_p1 + this->m_p2) / T(2);\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& directed_line_segment_2d<T>::p1() const {\n\
    \    return this->m_p1;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ directed_line_segment_2d<T>::p2() const {\n    return this->m_p2;\n  }\n\n \
    \ template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    if (*this & other)\
    \ {\n      return T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2),\n      this->squared_distance(other.m_p1),\n\
    \      this->squared_distance(other.m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return ::std::min({\n      other.squared_distance(this->m_p1),\n\
    \      other.squared_distance(this->m_p2)\n    });\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  directed_line_segment_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    const auto x = this->to_line().projection(p);\n\
    \    const auto d = this->to_vector().inner_product(x - this->m_p1);\n    return\
    \ (p - (d < T(0) ? this->m_p1 : this->squared_length() < d ? this->m_p2 : x)).squared_l2_norm();\n\
    \  }\n\n  template <typename T>\n  T directed_line_segment_2d<T>::squared_length()\
    \ const {\n    return this->to_vector().squared_l2_norm();\n  }\n\n  template\
    \ <typename T>\n  ::tools::half_line_2d<T> directed_line_segment_2d<T>::to_half_line()\
    \ const {\n    return ::tools::half_line_2d<T>(this->m_p1, this->m_p2 - this->m_p1);\n\
    \  }\n\n  template <typename T>\n  ::tools::line_2d<T> directed_line_segment_2d<T>::to_line()\
    \ const {\n    return ::tools::line_2d<T>::through(this->m_p1, this->m_p2);\n\
    \  }\n\n  template <typename T>\n  ::tools::vector2<T> directed_line_segment_2d<T>::to_vector()\
    \ const {\n    return this->m_p2 - this->m_p1;\n  }\n\n  template <typename T>\n\
    \  ::tools::directed_line_segment_2d<T> directed_line_segment_2d<T>::operator+()\
    \ const {\n    return *this;\n  }\n\n  template <typename T>\n  ::tools::directed_line_segment_2d<T>\
    \ directed_line_segment_2d<T>::operator-() const {\n    return ::tools::directed_line_segment_2d<T>(this->m_p2,\
    \ this->m_p1);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    using variant_t\
    \ = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const ::tools::vector2<T> base = lhs.to_vector();\n \
    \     const ::tools::directed_line_segment_2d<T> fixed_rhs = base.inner_product(rhs.to_vector())\
    \ > T(0) ? rhs : -rhs;\n      const T d1(0);\n      const T d2 = base.inner_product(base);\n\
    \      const T d3 = base.inner_product(fixed_rhs.m_p1 - lhs.m_p1);\n      const\
    \ T d4 = base.inner_product(fixed_rhs.m_p2 - lhs.m_p1);\n      if (d1 == d4) return\
    \ result_t(variant_t(lhs.m_p1));\n      if (d2 == d3) return result_t(variant_t(lhs.m_p2));\n\
    \      if (d3 <= d1 && d2 <= d4) return result_t(variant_t(lhs));\n      if (d1\
    \ <= d3 && d4 <= d2) return result_t(variant_t(fixed_rhs));\n      if (d3 <= d1\
    \ && d1 <= d4 && d4 <= d2) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ fixed_rhs.m_p2)));\n      if (d1 <= d3 && d3 <= d2 && d2 <= d4) return result_t(variant_t(::tools::directed_line_segment_2d<T>(fixed_rhs.m_p1,\
    \ lhs.m_p2)));\n      return ::std::nullopt;\n    }\n    if (l1.is_parallel_to(l2))\
    \ return ::std::nullopt;\n    if (lhs.m_p1 == rhs.m_p1 || lhs.m_p1 == rhs.m_p2)\
    \ return result_t(variant_t(lhs.m_p1));\n    if (lhs.m_p2 == rhs.m_p1 || lhs.m_p2\
    \ == rhs.m_p2) return result_t(variant_t(lhs.m_p2));\n    if (((rhs.m_p1.y - lhs.m_p1.y)\
    \ * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y - lhs.m_p1.y) * (rhs.m_p1.x - lhs.m_p1.x))\
    \ *\n        ((rhs.m_p2.y - lhs.m_p1.y) * (lhs.m_p2.x - lhs.m_p1.x) - (lhs.m_p2.y\
    \ - lhs.m_p1.y) * (rhs.m_p2.x - lhs.m_p1.x)) > T(0) ||\n        ((lhs.m_p1.y -\
    \ rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x) - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p1.x\
    \ - rhs.m_p1.x)) *\n        ((lhs.m_p2.y - rhs.m_p1.y) * (rhs.m_p2.x - rhs.m_p1.x)\
    \ - (rhs.m_p2.y - rhs.m_p1.y) * (lhs.m_p2.x - rhs.m_p1.x)) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*l1.cross_point(l2)));\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>>>\n\
    \  operator&(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::half_line_2d<T>&\
    \ rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const ::tools::line_2d<T>\
    \ l1 = lhs.to_line();\n    const ::tools::line_2d<T> l2 = rhs.to_line();\n   \
    \ if (l1 == l2) {\n      const bool has_same_direction = rhs.d().inner_product(lhs.to_vector())\
    \ > T(0);\n      const T d1 = rhs.d().inner_product(lhs.m_p1 - rhs.a());\n   \
    \   const T d2 = rhs.d().inner_product(lhs.m_p2 - rhs.a());\n      if (has_same_direction)\
    \ {\n        if (d2 < T(0)) return ::std::nullopt;\n        if (d2 == T(0)) return\
    \ result_t(variant_t(rhs.a()));\n        if (d1 < T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(rhs.a(),\
    \ lhs.m_p2)));\n        return result_t(variant_t(lhs));\n      } else {\n   \
    \     if (d1 > T(0)) return ::std::nullopt;\n        if (d1 == T(0)) return result_t(variant_t(rhs.a()));\n\
    \        if (d2 > T(0)) return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.m_p1,\
    \ rhs.a())));\n        return result_t(variant_t(lhs));\n      }\n    }\n    if\
    \ (rhs.contains(lhs.m_p1)) return result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2))\
    \ return result_t(variant_t(lhs.m_p2));\n    if ((l2.a() * lhs.m_p1.x + l2.b()\
    \ * lhs.m_p1.y + l2.c()) * (l2.a() * lhs.m_p2.x + l2.b() * lhs.m_p2.y + l2.c())\
    \ > T(0)) return ::std::nullopt;\n    const ::tools::vector2<T> possible_cross_point\
    \ = *l1.cross_point(l2);\n    if (rhs.d().inner_product(possible_cross_point -\
    \ rhs.a()) < T(0)) return ::std::nullopt;\n    return result_t(variant_t(possible_cross_point));\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    using variant_t = ::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> lhs_line = lhs.to_line();\n    if (lhs_line ==\
    \ rhs) return result_t(variant_t(lhs));\n    if (rhs.contains(lhs.m_p1)) return\
    \ result_t(variant_t(lhs.m_p1));\n    if (rhs.contains(lhs.m_p2)) return result_t(variant_t(lhs.m_p2));\n\
    \    if ((rhs.a() * lhs.m_p1.x + rhs.b() * lhs.m_p1.y + rhs.c()) * (rhs.a() *\
    \ lhs.m_p2.x + rhs.b() * lhs.m_p2.y + rhs.c()) > T(0)) return ::std::nullopt;\n\
    \    return result_t(variant_t(*lhs_line.cross_point(rhs)));\n  }\n\n  template\
    \ <typename T>\n  bool operator==(const ::tools::directed_line_segment_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return lhs.p1()\
    \ == rhs.p1() && lhs.p2() == rhs.p2();\n  }\n\n  template <typename T>\n  bool\
    \ operator!=(const ::tools::directed_line_segment_2d<T>& lhs, const ::tools::directed_line_segment_2d<T>&\
    \ rhs) {\n    return !(lhs == rhs);\n  }\n\n  template <typename T>\n  half_line_2d<T>::half_line_2d(const\
    \ ::tools::vector2<T>& a, const ::tools::vector2<T>& d) :\n    m_a(a),\n    m_d(d)\
    \ {\n    assert(d != ::tools::vector2<T>(T(0), T(0)));\n  }\n\n  template <typename\
    \ T>\n  const ::tools::vector2<T>& half_line_2d<T>::a() const {\n    return this->m_a;\n\
    \  }\n\n  template <typename T>\n  bool half_line_2d<T>::contains(const ::tools::vector2<T>&\
    \ p) const {\n    const ::tools::line_2d<T> l = this->to_line();\n    return l.a()\
    \ * p.x + l.b() * p.y + l.c() == T(0) && this->m_d.inner_product(p - this->m_a)\
    \ >= T(0);\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ half_line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>& other)\
    \ const {\n    return other.cross_point(*this);\n  }\n\n  template <typename T>\
    \ template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::directed_line_segment_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n      result_t operator()(const ::tools::half_line_2d<T>&) {\n     \
    \   return ::std::nullopt;\n      }\n    } visitor;\n    return intersection ?\
    \ ::std::visit(visitor, *intersection) : ::std::nullopt;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  half_line_2d<T>::cross_point(const\
    \ ::tools::line_2d<T>& other) const {\n    using result_t = ::std::optional<::tools::vector2<T>>;\n\
    \    const auto intersection = *this & other;\n    struct {\n      result_t operator()(const\
    \ ::tools::vector2<T>& v) {\n        return result_t(v);\n      }\n      result_t\
    \ operator()(const ::tools::half_line_2d<T>&) {\n        return ::std::nullopt;\n\
    \      }\n    } visitor;\n    return intersection ? ::std::visit(visitor, *intersection)\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  const ::tools::vector2<T>&\
    \ half_line_2d<T>::d() const {\n    return this->m_d;\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    if (const auto x = this->to_line().cross_point(other.to_line());\
    \ x) {\n      if (this->m_d.inner_product(*x - this->m_a) >= T(0)) {\n       \
    \ return (other.m_a - *x).squared_l2_norm();\n      } else if (other.m_d.inner_product(*x\
    \ - other.m_a) >= T(0)) {\n        return (this->m_a - *x).squared_l2_norm();\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    } else {\n      if (this->m_d.inner_product(other.m_a) > T(0)) {\n\
    \        return this->to_line().squared_distance(other.to_line());\n      } else\
    \ if (const auto x = this->to_line().projection(other.m_a); this->m_d.inner_product(x\
    \ - this->m_a) >= T(0)) {\n        return this->to_line().squared_distance(other.to_line());\n\
    \      } else {\n        return (this->m_a - other.m_a).squared_l2_norm();\n \
    \     }\n    }\n  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (*this & other) {\n      return\
    \ T(0);\n    }\n    return other.squared_distance(this->m_a);\n  }\n\n  template\
    \ <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  half_line_2d<T>::squared_distance(const\
    \ ::tools::vector2<T>& p) const {\n    auto x = this->to_line().projection(p);\n\
    \    const auto d = this->m_d.inner_product(x - this->m_a);\n    return (p - (d\
    \ < T(0) ? this->m_a : x)).squared_l2_norm();\n  }\n\n  template <typename T>\n\
    \  ::tools::line_2d<T> half_line_2d<T>::to_line() const {\n    return ::tools::line_2d<T>::through(this->m_a,\
    \ this->m_a + this->m_d);\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::half_line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>, ::tools::half_line_2d<T>>>>\n  operator&(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    using\
    \ variant_t = ::std::variant<::tools::vector2<T>, ::tools::directed_line_segment_2d<T>,\
    \ ::tools::half_line_2d<T>>;\n    using result_t = ::std::optional<variant_t>;\n\
    \    const ::tools::line_2d<T> l1 = lhs.to_line();\n    const ::tools::line_2d<T>\
    \ l2 = rhs.to_line();\n    if (l1 == l2) {\n      if (lhs.d().inner_product(rhs.d())\
    \ > T(0)) {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() - lhs.a())))\
    \ {\n        case 1:\n        case 0:\n          return result_t(variant_t(rhs));\n\
    \        default:\n          return result_t(variant_t(lhs));\n        }\n   \
    \   } else {\n        switch (::tools::signum(lhs.d().inner_product(rhs.a() -\
    \ lhs.a()))) {\n        case 1:\n          return result_t(variant_t(::tools::directed_line_segment_2d<T>(lhs.a(),\
    \ rhs.a())));\n        case 0:\n          return result_t(variant_t(lhs.a()));\n\
    \        default:\n          return ::std::nullopt;\n        }\n      }\n    }\
    \ else if (l1.is_parallel_to(l2)) {\n      return ::std::nullopt;\n    } else\
    \ {\n      const ::tools::vector2<T> possible_cross_point = *l1.cross_point(l2);\n\
    \      if (lhs.d().inner_product(possible_cross_point - lhs.a()) < T(0) || rhs.d().inner_product(possible_cross_point\
    \ - rhs.a()) < T(0)) {\n        return ::std::nullopt;\n      }\n      return\
    \ result_t(variant_t(possible_cross_point));\n    }\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>>>\n\
    \  operator&(const ::tools::half_line_2d<T>& lhs, const ::tools::line_2d<T>& rhs)\
    \ {\n    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::half_line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    const auto lhs_line = lhs.to_line();\n\
    \    if (lhs_line == rhs) return result_t(variant_t(lhs));\n    const auto possible_cross_point\
    \ = lhs_line.cross_point(rhs);\n    return possible_cross_point && lhs.m_d.inner_product(*possible_cross_point\
    \ - lhs.m_a) >= T(0)\n      ? result_t(variant_t(*possible_cross_point))\n   \
    \   : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const\
    \ ::tools::half_line_2d<T>& lhs, const ::tools::half_line_2d<T>& rhs) {\n    return\
    \ lhs.a() == rhs.a() && lhs.d().x * rhs.d().y == rhs.d().x * lhs.d().y;\n  }\n\
    \n  template <typename T>\n  bool operator!=(const ::tools::half_line_2d<T>& lhs,\
    \ const ::tools::half_line_2d<T>& rhs) {\n    return !(lhs == rhs);\n  }\n\n \
    \ template <typename T>\n  line_2d<T>::line_2d(const T& a, const T& b, const T&\
    \ c) :\n    m_a(a),\n    m_b(b),\n    m_c(c) {\n    assert(a != T(0) || b != T(0));\n\
    \  }\n\n  template <typename T>\n  const T& line_2d<T>::a() const {\n    return\
    \ this->m_a;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::b() const\
    \ {\n    return this->m_b;\n  }\n\n  template <typename T>\n  const T& line_2d<T>::c()\
    \ const {\n    return this->m_c;\n  }\n\n  template <typename T>\n  bool line_2d<T>::contains(const\
    \ ::tools::vector2<T>& p) const {\n    return this->m_a * p.x + this->m_b * p.y\
    \ + this->m_c == T(0);\n  }\n\n  template <typename T> template <typename T_>\n\
    \  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const ::tools::directed_line_segment_2d<T>&\
    \ other) const {\n    return other.cross_point(*this);\n  }\n\n  template <typename\
    \ T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> ||\
    \ ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n  line_2d<T>::cross_point(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::std::optional<::tools::vector2<T>>>\n \
    \ line_2d<T>::cross_point(const ::tools::line_2d<T>& other) const {\n    using\
    \ result_t = ::std::optional<::tools::vector2<T>>;\n    if (!this->crosses(other))\
    \ return ::std::nullopt;\n    return result_t(::tools::vector2<T>(\n      (this->m_b\
    \ * other.m_c - other.m_b * this->m_c) / (this->m_a * other.m_b - other.m_a *\
    \ this->m_b),\n      (other.m_a * this->m_c - this->m_a * other.m_c) / (this->m_a\
    \ * other.m_b - other.m_a * this->m_b)\n    ));\n  }\n\n  template <typename T>\n\
    \  bool line_2d<T>::crosses(const ::tools::line_2d<T>& other) const {\n    return\
    \ this->m_a * other.m_b != other.m_a * this->m_b;\n  }\n\n  template <typename\
    \ T>\n  bool line_2d<T>::is_parallel_to(const ::tools::line_2d<T>& other) const\
    \ {\n    return this->m_a * other.m_b == this->m_b * other.m_a;\n  }\n\n  template\
    \ <typename T>\n  ::tools::vector2<T> line_2d<T>::normal() const {\n    return\
    \ ::tools::vector2<T>(this->m_a, this->m_b);\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::vector2<T>>\n  line_2d<T>::projection(const ::tools::vector2<T>& p)\
    \ const {\n    return *::tools::half_line_2d<T>(p, this->normal()).to_line().cross_point(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::directed_line_segment_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::half_line_2d<T>& other) const {\n    return other.squared_distance(*this);\n\
    \  }\n\n  template <typename T> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, T>\n  line_2d<T>::squared_distance(const\
    \ ::tools::line_2d<T>& other) const {\n    if (this->is_parallel_to(other)) {\n\
    \      return ::tools::square(other.m_a * this->m_c - this->m_a * other.m_c) /\
    \ (::tools::square(this->m_a) + ::tools::square(this->m_b)) / ::tools::square(other.m_a);\n\
    \    } else {\n      return T(0);\n    }\n  }\n\n  template <typename T> template\
    \ <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ T>\n  line_2d<T>::squared_distance(const ::tools::vector2<T>& p) const {\n \
    \   return (p - this->projection(p)).squared_l2_norm();\n  }\n\n  template <typename\
    \ T, bool HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::vector<::tools::vector2<T>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::circle_2d<T, false,\
    \ HasRadius>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename T, bool\
    \ HasRadius>\n  ::std::enable_if_t<::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::circle_2d<T, true, HasRadius>& rhs) {\n    return rhs &\
    \ lhs;\n  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::directed_line_segment_2d<T>>>>\n  operator&(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::directed_line_segment_2d<T>& rhs) {\n    return rhs & lhs;\n\
    \  }\n\n  template <typename T>\n  ::std::enable_if_t<::tools::is_rational_v<T>\
    \ || ::std::is_floating_point_v<T>, ::std::optional<::std::variant<::tools::vector2<T>,\
    \ ::tools::half_line_2d<T>>>>\n  operator&(const ::tools::line_2d<T>& lhs, const\
    \ ::tools::half_line_2d<T>& rhs) {\n    return rhs & lhs;\n  }\n\n  template <typename\
    \ T>\n  ::std::enable_if_t<::tools::is_rational_v<T> || ::std::is_floating_point_v<T>,\
    \ ::std::optional<::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>>>\n\
    \  operator&(const ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n\
    \    using variant_t = ::std::variant<::tools::vector2<T>, ::tools::line_2d<T>>;\n\
    \    using result_t = ::std::optional<variant_t>;\n    if (lhs == rhs) return\
    \ result_t(variant_t(lhs));\n    const auto possible_cross_point = lhs.cross_point(rhs);\n\
    \    return possible_cross_point ? result_t(variant_t(*possible_cross_point))\
    \ : ::std::nullopt;\n  }\n\n  template <typename T>\n  bool operator==(const ::tools::line_2d<T>&\
    \ lhs, const ::tools::line_2d<T>& rhs) {\n    return lhs.m_b * rhs.m_c == lhs.m_c\
    \ * rhs.m_b && lhs.m_c * rhs.m_a == lhs.m_a * rhs.m_c && lhs.m_a * rhs.m_b ==\
    \ lhs.m_b * rhs.m_a;\n  }\n\n  template <typename T>\n  bool operator!=(const\
    \ ::tools::line_2d<T>& lhs, const ::tools::line_2d<T>& rhs) {\n    return !(lhs\
    \ == rhs);\n  }\n\n  template <typename T>\n  ::tools::line_2d<T> line_2d<T>::through(const\
    \ ::tools::vector2<T>& p1, const ::tools::vector2<T>& p2) {\n    return ::tools::line_2d<T>(p1.y\
    \ - p2.y, p2.x - p1.x, (p2.y - p1.y) * p1.x - (p2.x - p1.x) * p1.y);\n  }\n\n\
    \  template <typename T, bool Filled>\n  T polygon_2d<T, Filled>::doubled_signed_area()\
    \ const {\n    T result(0);\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      result += (this->m_points[i].x - this->m_points[(i + 1) % this->m_points.size()].x)\
    \ * (this->m_points[i].y + this->m_points[(i + 1) % this->m_points.size()].y);\n\
    \    }\n    return result;\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename InputIterator>\n  polygon_2d<T, Filled>::polygon_2d(const InputIterator&\
    \ begin, const InputIterator& end) : m_points(begin, end) {\n    assert(this->m_points.size()\
    \ >= 3);\n  }\n\n  template <typename T, bool Filled>\n  polygon_2d<T, Filled>::polygon_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : polygon_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_, bool Filled_>\n  ::std::enable_if_t<(::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>) && Filled_, T> polygon_2d<T, Filled>::area()\
    \ const {\n    return this->doubled_area() / T(2);\n  }\n\n  template <typename\
    \ T, bool Filled> template <bool Filled_>\n  ::std::enable_if_t<Filled_, T> polygon_2d<T,\
    \ Filled>::doubled_area() const {\n    return ::tools::abs(this->doubled_signed_area());\n\
    \  }\n\n  template <typename T, bool Filled>\n  bool polygon_2d<T, Filled>::is_counterclockwise()\
    \ const {\n    return this->doubled_signed_area() > T(0);\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> polygon_2d<T,\
    \ Filled>::minimum_bounding_circle() const {\n    ::std::optional<::tools::circle_2d<T,\
    \ Filled, false>> answer;\n    for (::std::size_t i = 0; i < this->m_points.size();\
    \ ++i) {\n      for (::std::size_t j = i + 1; j < this->m_points.size(); ++j)\
    \ {\n        for (::std::size_t k = j + 1; k < this->m_points.size(); ++k) {\n\
    \          if (const auto possible_answer = ::tools::triangle_2d<T, Filled>({this->m_points[i],\
    \ this->m_points[j], this->m_points[k]}).minimum_bounding_circle();\n        \
    \      !answer || answer->squared_radius() < possible_answer.squared_radius())\
    \ {\n            answer = ::std::move(possible_answer);\n          }\n       \
    \ }\n      }\n    }\n    return *answer;\n  }\n\n  template <typename T, bool\
    \ Filled>\n  int polygon_2d<T, Filled>::where(const ::tools::vector2<T>& p) const\
    \ {\n    ::std::vector<::tools::directed_line_segment_2d<T>> edges;\n    for (::std::size_t\
    \ i = 0; i < this->m_points.size(); ++i) {\n      edges.emplace_back(this->m_points[i],\
    \ this->m_points[(i + 1) % this->m_points.size()]);\n    }\n\n    if (std::any_of(edges.begin(),\
    \ edges.end(), [&](const auto& edge) { return edge.contains(p); })) {\n      return\
    \ 0;\n    } else {\n      bool in = false;\n      for (const auto& edge : edges)\
    \ {\n        if ([&]() {\n          const auto l = edge.to_line();\n         \
    \ if (l == ::tools::line_2d<T>(T(0), T(1), -p.y)) return false;\n          if\
    \ (p.x <= edge.p1().x && p.y == edge.p1().y) return edge.p2().y < edge.p1().y;\n\
    \          if (p.x <= edge.p2().x && p.y == edge.p2().y) return edge.p1().y <\
    \ edge.p2().y;\n          if ((edge.p1().y - p.y) * (edge.p2().y - p.y) > T(0))\
    \ return false;\n          return l.a() * (l.a() * p.x + l.b() * p.y + l.c())\
    \ < T(0);\n        }()) {\n          in = !in;\n        }\n      }\n      return\
    \ in ? 1 : -1;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template\
    \ <typename OutputIterator>\n  void triangle_2d<T, Filled>::sorted_edges(OutputIterator\
    \ result) const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    for (int i = 0; i < 3; ++i) {\n      edges[i] = ::tools::directed_line_segment_2d<T>(this->m_points[i],\
    \ this->m_points[(i + 1) % 3]);\n    }\n    ::std::sort(edges.begin(), edges.end(),\
    \ ::tools::less_by([](const auto& edge) {\n      return edge.squared_length();\n\
    \    }));\n    for (const auto& edge : edges) {\n      *result = edge;\n     \
    \ ++result;\n    }\n  }\n\n  template <typename T, bool Filled>\n  template <typename\
    \ InputIterator>\n  triangle_2d<T, Filled>::triangle_2d(const InputIterator& begin,\
    \ const InputIterator& end) : polygon_2d<T, Filled>(begin, end) {\n    assert(this->m_points.size()\
    \ == 3);\n  }\n\n  template <typename T, bool Filled>\n  triangle_2d<T, Filled>::triangle_2d(::std::initializer_list<::tools::vector2<T>>\
    \ init) : triangle_2d(init.begin(), init.end()) {\n  }\n\n  template <typename\
    \ T, bool Filled> template <typename T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_>\
    \ || ::std::is_floating_point_v<T_>, ::tools::circle_2d<T, Filled, false>> triangle_2d<T,\
    \ Filled>::circumcircle() const {\n    const auto& A = this->m_points[0];\n  \
    \  const auto& B = this->m_points[1];\n    const auto& C = this->m_points[2];\n\
    \    const auto a2 = (C - B).squared_l2_norm();\n    const auto b2 = (A - C).squared_l2_norm();\n\
    \    const auto c2 = (B - A).squared_l2_norm();\n    const auto kA = a2 * (b2\
    \ + c2 - a2);\n    const auto kB = b2 * (c2 + a2 - b2);\n    const auto kC = c2\
    \ * (a2 + b2 - c2);\n    const auto circumcenter = (kA * A + kB * B + kC * C)\
    \ / (kA + kB + kC);\n    return ::tools::circle_2d<T, Filled, false>(circumcenter,\
    \ (circumcenter - A).squared_l2_norm());\n  }\n\n  template <typename T, bool\
    \ Filled> template <typename T_>\n  ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled>> triangle_2d<T, Filled>::incircle() const {\n\
    \    const auto& A = this->m_points[0];\n    const auto& B = this->m_points[1];\n\
    \    const auto& C = this->m_points[2];\n    const auto a = (C - B).l2_norm();\n\
    \    const auto b = (A - C).l2_norm();\n    const auto c = (B - A).l2_norm();\n\
    \    const auto incenter = (a * A + b * B + c * C) / (a + b + c);\n    return\
    \ ::tools::circle_2d<T, Filled>(incenter, ::tools::abs(this->doubled_signed_area())\
    \ / (a + b + c));\n  }\n\n  template <typename T, bool Filled> template <typename\
    \ T_>\n  ::std::enable_if_t<::tools::is_rational_v<T_> || ::std::is_floating_point_v<T_>,\
    \ ::tools::circle_2d<T, Filled, false>> triangle_2d<T, Filled>::minimum_bounding_circle()\
    \ const {\n    ::std::array<::tools::directed_line_segment_2d<T>, 3> edges;\n\
    \    this->sorted_edges(edges.begin());\n    if (edges[0].squared_length() + edges[1].squared_length()\
    \ <= edges[2].squared_length()) {\n      const auto center = edges[2].midpoint();\n\
    \      return ::tools::circle_2d<T, Filled, false>(center, (center - edges[2].p1()).squared_l2_norm());\n\
    \    } else {\n      return this->circumcircle();\n    }\n  }\n\n  template <typename\
    \ T, bool Filled>\n  int triangle_2d<T, Filled>::type() const {\n    ::std::array<::tools::directed_line_segment_2d<T>,\
    \ 3> edges;\n    this->sorted_edges(edges.begin());\n    const auto c2 = edges[2].squared_length();\n\
    \    const auto a2b2 = edges[1].squared_length() + edges[0].squared_length();\n\
    \    if (c2 < a2b2) {\n      return 0;\n    } else if (c2 == a2b2) {\n      return\
    \ 1;\n    } else {\n      return 2;\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/abs.hpp
  - tools/is_rational.hpp
  - tools/less_by.hpp
  - tools/signum.hpp
  - tools/square.hpp
  - tools/is_monoid.hpp
  - tools/vector2.hpp
  - tools/vector.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/detail/geometry_2d.hpp
  requiredBy:
  - tools/polygon_2d.hpp
  - tools/half_line_2d.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/triangle_2d.hpp
  - tools/line_2d.hpp
  - tools/circle_2d.hpp
  timestamp: '2024-04-13 13:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
documentation_of: tools/detail/geometry_2d.hpp
layout: document
redirect_from:
- /library/tools/detail/geometry_2d.hpp
- /library/tools/detail/geometry_2d.hpp.html
title: tools/detail/geometry_2d.hpp
---
