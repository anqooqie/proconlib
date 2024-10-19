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
    path: tools/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector3.hpp
    title: Three dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector4.hpp
    title: Four dimensional vector
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
  - icon: ':heavy_check_mark:'
    path: tests/pdsu.test.cpp
    title: tests/pdsu.test.cpp
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
  bundledCode: "#line 1 \"tools/vector.hpp\"\n\n\n\n#include <cstddef>\n#include <array>\n\
    #include <initializer_list>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    #include <type_traits>\n#include <iterator>\n#include <algorithm>\n#include <utility>\n\
    #include <cmath>\n#include <iostream>\n#include <string>\n#include <functional>\n\
    #include <tuple>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr\
    \ float abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double\
    \ abs(const double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double\
    \ abs(const long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int\
    \ abs(const int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const\
    \ long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const\
    \ long long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const\
    \ unsigned int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned\
    \ long x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
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
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR_HPP\n#define TOOLS_VECTOR_HPP\n\n#include <cstddef>\n\
    #include <array>\n#include <initializer_list>\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n#include <type_traits>\n#include <iterator>\n#include <algorithm>\n\
    #include <utility>\n#include <cmath>\n#include <iostream>\n#include <string>\n\
    #include <functional>\n#include <tuple>\n#include \"tools/abs.hpp\"\n#include\
    \ \"tools/tuple_hash.hpp\"\n\nnamespace tools {\n  namespace detail {\n    namespace\
    \ vector {\n      template <typename T, ::std::size_t N>\n      class members\
    \ {\n      protected:\n        constexpr static bool variable_sized = false;\n\
    \        constexpr static bool has_aliases = false;\n        ::std::array<T, N>\
    \ m_values;\n        members() : m_values() {}\n        members(const ::std::initializer_list<T>\
    \ il) : m_values(il) {\n          assert(il.size() == N);\n        }\n      };\n\
    \n      template <typename T>\n      class members<T, 2> {\n      protected:\n\
    \        constexpr static bool variable_sized = false;\n        constexpr static\
    \ bool has_aliases = true;\n        ::std::array<T*, 2> m_values;\n        members()\
    \ : m_values{&this->x, &this->y} {}\n        members(const T& x, const T& y) :\
    \ m_values{&this->x, &this->y}, x(x), y(y) {}\n        members(const ::std::initializer_list<T>\
    \ il) : m_values{&this->x, &this->y}, x(il.begin()[0]), y(il.begin()[1]) {\n \
    \         assert(il.size() == 2);\n        }\n\n      public:\n        T x;\n\
    \        T y;\n      };\n\n      template <typename T>\n      class members<T,\
    \ 3> {\n      protected:\n        constexpr static bool variable_sized = false;\n\
    \        constexpr static bool has_aliases = true;\n        ::std::array<T*, 3>\
    \ m_values;\n        members() : m_values{&this->x, &this->y, &this->z} {}\n \
    \       members(const T& x, const T& y, const T& z) : m_values{&this->x, &this->y,\
    \ &this->z}, x(x), y(y), z(z) {}\n        members(const ::std::initializer_list<T>\
    \ il) : m_values{&this->x, &this->y, &this->z}, x(il.begin()[0]), y(il.begin()[1]),\
    \ z(il.begin()[2]) {\n          assert(il.size() == 3);\n        }\n\n      public:\n\
    \        T x;\n        T y;\n        T z;\n      };\n\n      template <typename\
    \ T>\n      class members<T, 4> {\n      protected:\n        constexpr static\
    \ bool variable_sized = false;\n        constexpr static bool has_aliases = true;\n\
    \        ::std::array<T*, 4> m_values;\n        members() : m_values{&this->x,\
    \ &this->y, &this->z, &this->w} {}\n        members(const T& x, const T& y, const\
    \ T& z, const T& w) : m_values{&this->x, &this->y, &this->z, &this->w}, x(x),\
    \ y(y), z(z), w(w) {}\n        members(const ::std::initializer_list<T> il) :\
    \ m_values{&this->x, &this->y, &this->z, &this->w}, x(il.begin()[0]), y(il.begin()[1]),\
    \ z(il.begin()[2]), w(il.begin()[3]) {\n          assert(il.size() == 4);\n  \
    \      }\n\n      public:\n        T x;\n        T y;\n        T z;\n        T\
    \ w;\n      };\n\n      template <typename T>\n      class members<T, ::std::numeric_limits<::std::size_t>::max()>\
    \ {\n      protected:\n        constexpr static bool variable_sized = true;\n\
    \        constexpr static bool has_aliases = false;\n        ::std::vector<T>\
    \ m_values;\n        members() = default;\n        members(const ::std::size_t\
    \ n) : m_values(n) {}\n        members(const ::std::size_t n, const T& value)\
    \ : m_values(n, value) {}\n        template <typename InputIter>\n        members(const\
    \ InputIter first, const InputIter last) : m_values(first, last) {}\n        members(const\
    \ ::std::initializer_list<T> il) : m_values(il) {}\n      };\n    }\n  }\n\n \
    \ template <typename T, ::std::size_t N = ::std::numeric_limits<::std::size_t>::max()>\n\
    \  class vector : public ::tools::detail::vector::members<T, N> {\n  private:\n\
    \    using Base = ::tools::detail::vector::members<T, N>;\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double>;\n    using V = ::tools::vector<T, N>;\n    constexpr static bool\
    \ variable_sized = Base::variable_sized;\n    constexpr static bool has_aliases\
    \ = Base::has_aliases;\n\n  public:\n    using reference = T&;\n    using const_reference\
    \ = const T&;\n    using size_type = ::std::size_t;\n    using difference_type\
    \ = ::std::ptrdiff_t;\n    using pointer = T*;\n    using const_pointer = const\
    \ T*;\n    using value_type = T;\n    class iterator {\n    private:\n      V*\
    \ m_parent;\n      size_type m_i;\n\n    public:\n      using difference_type\
    \ = ::std::ptrdiff_t;\n      using value_type = T;\n      using reference = T&;\n\
    \      using pointer = T*;\n      using iterator_category = ::std::random_access_iterator_tag;\n\
    \n      iterator() = default;\n      iterator(const iterator&) = default;\n  \
    \    iterator(iterator&&) = default;\n      ~iterator() = default;\n      iterator&\
    \ operator=(const iterator&) = default;\n      iterator& operator=(iterator&&)\
    \ = default;\n\n      iterator(V * const parent, const size_type i) : m_parent(parent),\
    \ m_i(i) {}\n\n      reference operator*() const {\n        return (*this->m_parent)[this->m_i];\n\
    \      }\n      pointer operator->() const {\n        return &(*(*this));\n  \
    \    }\n\n      iterator& operator++() {\n        ++this->m_i;\n        return\
    \ *this;\n      }\n      iterator operator++(int) {\n        const auto self =\
    \ *this;\n        ++*this;\n        return self;\n      }\n      iterator& operator--()\
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
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/vector.hpp
  requiredBy:
  - tools/greater_by_arg.hpp
  - tools/detail/geometry_2d.hpp
  - tools/vector3.hpp
  - tools/ccw.hpp
  - tools/matrix.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/quaternion.hpp
  - tools/circle_2d.hpp
  - tools/polygon_2d.hpp
  - tools/less_by_arg_total.hpp
  - tools/convex_hull.hpp
  - tools/vector4.hpp
  - tools/half_line_2d.hpp
  - tools/vector2.hpp
  - tools/less_by_arg.hpp
  - tools/greater_by_arg_total.hpp
  - tools/triangle_2d.hpp
  - tools/line_2d.hpp
  timestamp: '2024-03-23 22:25:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/less_by_arg_total.test.cpp
  - tests/matrix/static.test.cpp
  - tests/matrix/determinant.test.cpp
  - tests/matrix/inv.test.cpp
  - tests/matrix/rank.test.cpp
  - tests/matrix/multiplies.test.cpp
  - tests/matrix/solve.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/ccw.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/online_cumsum.test.cpp
  - tests/convex_hull.test.cpp
  - tests/greater_by_arg_total.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/pdsu.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/greater_by_arg.test.cpp
documentation_of: tools/vector.hpp
layout: document
title: Vector
---

It is a $n$-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Methods based on std::vector&lt;T&gt;
```cpp
vector<T> v();
vector<T> v(const vector<T>& u);
vector<T> v(vector<T>&& u);
vector<T>& v.operator=(const vector<T>& u);
vector<T>& v.operator=(vector<T>&& u);

vector<T> v(std::size_t n);
vector<T> v(std::size_t n, T value);
template <typename InputIter>
vector<T> v(InputIter first, InputIter last);
vector<T> v(std::initializer_list<T> il);

(vector<T>::iterator or vector<T>::const_iterator) v.begin();
(vector<T>::iterator or vector<T>::const_iterator) v.end();
vector<T>::const_iterator v.cbegin();
vector<T>::const_iterator v.cend();
(vector<T>::reverse_iterator or vector<T>::const_reverse_iterator) v.rbegin();
(vector<T>::reverse_iterator or vector<T>::const_reverse_iterator) v.rend();
vector<T>::const_reverse_iterator v.crbegin();
vector<T>::const_reverse_iterator v.crend();

std::size_t v.size();
bool v.empty();

(T& or const T&) v.operator[](std::size_t i);
(T& or const T&) v.front();
(T& or const T&) v.back();

bool operator==(vector<T> v, vector<T> u);
bool operator!=(vector<T> v, vector<T> u);
```

They are methods based on `std::vector<T>`.

### Constraints
- Same as ones of `std::vector<T>`.

### Time Complexity
- Same as ones of `std::vector<T>`.

## Arithmetic operators
```cpp
(1) vector<T> operator+(vector<T> v);
(2) vector<T> operator-(vector<T> v);
(3) vector<T>& v.operator+=(vector<T> u);
(4) vector<T> operator+(vector<T> v, vector<T> u);
(5) vector<T>& v.operator-=(vector<T> u);
(6) vector<T> operator-(vector<T> v, vector<T> u);
(7) vector<T>& v.operator*=(T c);
(8) vector<T> operator*(T c, vector<T> v);
(9) vector<T> operator*(vector<T> v, T c);
(10) vector<T>& v.operator/=(T c);
(11) vector<T> operator/(vector<T> v, T c);
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another $n$-dimensional vector and $c$ is a scholar value.

### Constraints
- (3), (4), (5), (6)
    - The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.
- (10), (11)
    - $c \neq 0$

### Time Complexity
- $O(n)$

## inner_product
```cpp
T v.inner_product(vector<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.

### Time Complexity
- $O(n)$

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1$.

### Constraints
- None

### Time Complexity
- $O(n)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2^2 = \overrightarrow{v} \cdot \overrightarrow{v}$.

### Constraints
- None

### Time Complexity
- $O(n)$

## l2_norm
```cpp
std::is_conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2$.

### Constraints
- None

### Time Complexity
- $O(n)$

## normalized
```cpp
vector<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`.

### Time Complexity
- $O(n)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, vector<T>& self);
```

It is equivalent to the following code.

```cpp
for (auto& v : self) is >> v;
return is;
```

### Constraints
- None

### Time Complexity
- $O(n)$

## operator&lt;&lt;
```cpp
std::ostream& operator<<(std::ostream& os, const vector<T>& self);
```

It is equivalent to the following code.

```cpp
os << '(';
for (std::size_t i = 0; i < self.size(); ++i) {
  if (i > 0) os << ", ";
  os << self[i];
}
os << ')';
return os;
```

### Constraints
- None

### Time Complexity
- $O(n)$
