---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':heavy_check_mark:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':heavy_check_mark:'
    path: tools/detail/line_like_2d.hpp
    title: tools/detail/line_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/polygon_like_2d.hpp
    title: tools/detail/polygon_like_2d.hpp
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
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ccw.test.cpp
    title: tests/ccw.test.cpp
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
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector2.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cmath>\n#include <cstddef>\n#include <array>\n#include <iostream>\n#include\
    \ <functional>\n#line 1 \"tools/abs.hpp\"\n\n\n\n#line 5 \"tools/abs.hpp\"\n\n\
    namespace tools {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n\n#line 1 \"tools/pair_hash.hpp\"\
    \n\n\n\n#line 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n\
    #line 8 \"tools/pair_hash.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n \
    \ template <class T1, class T2>\n  struct pair_hash {\n    using result_type =\
    \ ::std::size_t;\n    using argument_type = ::std::pair<T1, T2>;\n    ::std::size_t\
    \ operator()(const ::std::pair<T1, T2>& key) const {\n      static const ::std::size_t\
    \ salt = ::std::random_device()();\n      static const ::std::hash<T1> hasher1\
    \ = ::std::hash<T1>();\n      static const ::std::hash<T2> hasher2 = ::std::hash<T2>();\n\
    \      static const ::std::hash<::std::size_t> hasher3 = ::std::hash<::std::size_t>();\n\
    \      ::std::size_t result = 0;\n      result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher2(key.second) + static_cast<::std::size_t>(0x9e3779b9)\
    \ + (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      result ^= hasher3(salt) + static_cast<::std::size_t>(0x9e3779b9) + (result\
    \ << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
    \      return result;\n    }\n  };\n\n  template <>\n  struct pair_hash<::std::uint64_t,\
    \ ::std::uint64_t> {\n    using result_type = ::std::size_t;\n    using argument_type\
    \ = ::std::pair<::std::uint64_t, ::std::uint64_t>;\n    ::std::size_t operator()(const\
    \ ::std::pair<::std::uint64_t, ::std::uint64_t>& key) const {\n      static const\
    \ ::std::hash<::std::uint64_t> hasher = ::std::hash<::std::uint64_t>();\n    \
    \  return hasher(((key.first << static_cast<::std::uint64_t>(32)) | (key.first\
    \ >> static_cast<::std::uint64_t>(32))) ^ key.second);\n    }\n  };\n\n  template\
    \ <>\n  struct pair_hash<::std::int64_t, ::std::int64_t> {\n    using result_type\
    \ = ::std::size_t;\n    using argument_type = ::std::pair<::std::int64_t, ::std::int64_t>;\n\
    \    ::std::size_t operator()(const ::std::pair<::std::int64_t, ::std::int64_t>&\
    \ key) const {\n      static const ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>\
    \ hasher = ::tools::pair_hash<::std::uint64_t, ::std::uint64_t>();\n      return\
    \ hasher(::std::make_pair<::std::uint64_t, ::std::uint64_t>(key.first, key.second));\n\
    \    }\n  };\n\n  template <>\n  struct pair_hash<::std::uint32_t, ::std::uint32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::uint32_t,\
    \ ::std::uint32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::uint32_t,\
    \ ::std::uint32_t>& key) const {\n      static const ::std::hash<::std::uint64_t>\
    \ hasher = ::std::hash<::std::uint64_t>();\n      return hasher((static_cast<::std::uint64_t>(key.first)\
    \ << static_cast<::std::uint64_t>(32)) | static_cast<::std::uint64_t>(key.second));\n\
    \    }\n  };\n\n  template <>\n  struct pair_hash<::std::int32_t, ::std::int32_t>\
    \ {\n    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<::std::int32_t,\
    \ ::std::int32_t>;\n    ::std::size_t operator()(const ::std::pair<::std::int32_t,\
    \ ::std::int32_t>& key) const {\n      static const ::tools::pair_hash<::std::uint32_t,\
    \ ::std::uint32_t> hasher = ::tools::pair_hash<::std::uint32_t, ::std::uint32_t>();\n\
    \      return hasher(::std::make_pair<::std::uint32_t, ::std::uint32_t>(key.first,\
    \ key.second));\n    }\n  };\n}\n\n\n#line 12 \"tools/vector2.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class vector2 {\n  private:\n    using\
    \ F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\n\n  public:\n\
    \    T x;\n    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n    }\n\n \
    \   vector2(const T& x, const T& y) :\n      x(x),\n      y(y) {\n    }\n\n  \
    \  T l1_norm() const {\n      return ::tools::abs(this->x) + ::tools::abs(this->y);\n\
    \    }\n\n    F l2_norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\n\
    \    }\n\n    T squared_l2_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>,\
    \ ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T> normalized() const {\n\
    \      return *this / this->l2_norm();\n    }\n\n    ::tools::vector2<T> turn90()\
    \ const {\n      return ::tools::vector2<T>(-this->y, this->x);\n    }\n\n   \
    \ ::tools::vector2<T> turn270() const {\n      return ::tools::vector2<T>(this->y,\
    \ -this->x);\n    }\n\n    ::tools::vector2<T> operator+() const {\n      return\
    \ *this;\n    }\n\n    ::tools::vector2<T> operator-() const {\n      return ::tools::vector2<T>(-this->x,\
    \ -this->y);\n    }\n\n    friend ::tools::vector2<T> operator+(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ + rhs.x, lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const\
    \ ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    friend ::tools::vector2<T> operator*(const OTHER& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs * rhs.x, lhs\
    \ * rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n    T inner_product(const\
    \ ::tools::vector2<T>& other) const {\n      return this->x * other.x + this->y\
    \ * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>& other) const\
    \ {\n      return this->x * other.y - this->y * other.x;\n    }\n\n    ::tools::vector2<T>&\
    \ operator+=(const ::tools::vector2<T>& other) {\n      return *this = *this +\
    \ other;\n    }\n\n    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>&\
    \ other) {\n      return *this = *this - other;\n    }\n\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    ::tools::vector2<T>& operator*=(const OTHER& other) {\n    \
    \  return *this = *this * other;\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {\n      return\
    \ os << '(' << self.x << \", \" << self.y << ')';\n    }\n\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, ::tools::vector2<T>& self) {\n      return is\
    \ >> self.x >> self.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
    \ 4> four_directions() {\n      return ::std::array<::tools::vector2<T>, 4>({\n\
    \        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(0),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1))\n      });\n\
    \    }\n\n    static ::std::array<::tools::vector2<T>, 8> eight_directions() {\n\
    \      return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(1)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(-1)),\n      \
    \  ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(-1))\n      });\n    }\n  };\n}\n\nnamespace std {\n  template\
    \ <typename T>\n  struct hash<::tools::vector2<T>> {\n    using result_type =\
    \ ::std::size_t;\n    using argument_type = ::tools::vector2<T>;\n    ::std::size_t\
    \ operator()(const ::tools::vector2<T>& key) const {\n      static const ::tools::pair_hash<T,\
    \ T> hasher = ::tools::pair_hash<T, T>();\n      return hasher(::std::make_pair(key.x,\
    \ key.y));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR2_HPP\n#define TOOLS_VECTOR2_HPP\n\n#include <type_traits>\n\
    #include <cmath>\n#include <cstddef>\n#include <array>\n#include <iostream>\n\
    #include <functional>\n#include \"tools/abs.hpp\"\n#include \"tools/pair_hash.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  class vector2 {\n  private:\n\
    \    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\n\
    \n  public:\n    T x;\n    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n\
    \    }\n\n    vector2(const T& x, const T& y) :\n      x(x),\n      y(y) {\n \
    \   }\n\n    T l1_norm() const {\n      return ::tools::abs(this->x) + ::tools::abs(this->y);\n\
    \    }\n\n    F l2_norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\n\
    \    }\n\n    T squared_l2_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>,\
    \ ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T> normalized() const {\n\
    \      return *this / this->l2_norm();\n    }\n\n    ::tools::vector2<T> turn90()\
    \ const {\n      return ::tools::vector2<T>(-this->y, this->x);\n    }\n\n   \
    \ ::tools::vector2<T> turn270() const {\n      return ::tools::vector2<T>(this->y,\
    \ -this->x);\n    }\n\n    ::tools::vector2<T> operator+() const {\n      return\
    \ *this;\n    }\n\n    ::tools::vector2<T> operator-() const {\n      return ::tools::vector2<T>(-this->x,\
    \ -this->y);\n    }\n\n    friend ::tools::vector2<T> operator+(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ + rhs.x, lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const\
    \ ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    friend ::tools::vector2<T> operator*(const OTHER& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs * rhs.x, lhs\
    \ * rhs.y);\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    friend ::tools::vector2<T>\
    \ operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs) {\n      return\
    \ ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n    T inner_product(const\
    \ ::tools::vector2<T>& other) const {\n      return this->x * other.x + this->y\
    \ * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>& other) const\
    \ {\n      return this->x * other.y - this->y * other.x;\n    }\n\n    ::tools::vector2<T>&\
    \ operator+=(const ::tools::vector2<T>& other) {\n      return *this = *this +\
    \ other;\n    }\n\n    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>&\
    \ other) {\n      return *this = *this - other;\n    }\n\n    template <typename\
    \ OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t>\
    \ = nullptr>\n    ::tools::vector2<T>& operator*=(const OTHER& other) {\n    \
    \  return *this = *this * other;\n    }\n\n    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER,\
    \ ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {\n      return\
    \ os << '(' << self.x << \", \" << self.y << ')';\n    }\n\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, ::tools::vector2<T>& self) {\n      return is\
    \ >> self.x >> self.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
    \ 4> four_directions() {\n      return ::std::array<::tools::vector2<T>, 4>({\n\
    \        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(0),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1))\n      });\n\
    \    }\n\n    static ::std::array<::tools::vector2<T>, 8> eight_directions() {\n\
    \      return ::std::array<::tools::vector2<T>, 8>({\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(0)),\n        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(1)),\n\
    \        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1),\
    \ static_cast<T>(1)),\n        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),\n\
    \        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(-1)),\n      \
    \  ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),\n        ::tools::vector2<T>(static_cast<T>(1),\
    \ static_cast<T>(-1))\n      });\n    }\n  };\n}\n\nnamespace std {\n  template\
    \ <typename T>\n  struct hash<::tools::vector2<T>> {\n    using result_type =\
    \ ::std::size_t;\n    using argument_type = ::tools::vector2<T>;\n    ::std::size_t\
    \ operator()(const ::tools::vector2<T>& key) const {\n      static const ::tools::pair_hash<T,\
    \ T> hasher = ::tools::pair_hash<T, T>();\n      return hasher(::std::make_pair(key.x,\
    \ key.y));\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/abs.hpp
  - tools/pair_hash.hpp
  isVerificationFile: false
  path: tools/vector2.hpp
  requiredBy:
  - tools/less_by_arg_total.hpp
  - tools/less_by_arg.hpp
  - tools/triangle_2d.hpp
  - tools/ccw.hpp
  - tools/convex_hull.hpp
  - tools/line_2d.hpp
  - tools/greater_by_arg.hpp
  - tools/polygon_2d.hpp
  - tools/greater_by_arg_total.hpp
  - tools/half_line_2d.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/detail/polygon_like_2d.hpp
  - tools/detail/line_like_2d.hpp
  timestamp: '2022-07-23 13:26:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/greater_by_arg_total.test.cpp
  - tests/ccw.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/less_by_arg_total.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/convex_hull.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/greater_by_arg.test.cpp
documentation_of: tools/vector2.hpp
layout: document
title: 2D vector
---

It is a two-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) vector2<T> v();
(2) vector2<T> v(T x, T y);
```

- (1)
    - It creates a vector $(0, 0)$.
- (2)
    - It creates a vector whose coordinates are the specified values.

The type parameter `<T>` represents the type of the coordinates.

### Constraints
- None

### Time Complexity
- $O(1)$

## x
```cpp
T v.x;
```

It is the x-coordinate of the vector.

## y
```cpp
T v.y;
```

It is the y-coordinate of the vector.

## l1_norm
```cpp
T v.l1_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_1 = \|x\| + \|y\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l2_norm
```cpp
std::conditional_t<std::is_floating_point_v<T>, T, double> v.l2_norm();
```

It returns $\left\\|\overrightarrow{v}\right\\|_2 = \sqrt{x^2 + y^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_l2_norm
```cpp
T v.squared_l2_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector2<T> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\\|\overrightarrow{v}\right\\|_2}$.

### Constraints
- `std::is_floating_point_v<T>` is `true`

### Time Complexity
- $O(1)$

## turn90
```cpp
vector2<T> v.turn90();
```

It returns $(-y, x)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## turn270
```cpp
vector2<T> v.turn270();
```

It returns $(y, -x)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## inner_product
```cpp
T v.inner_product(vector2<T> u);
```

It returns $\overrightarrow{v} \cdot \overrightarrow{u}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## outer_product
```cpp
T v.outer_product(vector2<T> u);
```

It returns $\left\|\overrightarrow{v} \times \overrightarrow{u}\right\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Arithmetic operations
```cpp
(1) vector2<T> +v;
(2) vector2<T> -v;
(3) vector2<T> v + u;
(4) vector2<T> v - u;
(5) vector2<T> v * c;
(6) vector2<T> c * v;
(7) vector2<T> v / c;
(8) vector2<T>& v += u;
(9) vector2<T>& v -= u;
(10) vector2<T>& v *= c;
(11) vector2<T>& v /= c;
(12) bool v == u;
(13) bool v != u;
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another vector and $c$ is a scholar value.

### Constraints
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(1)$

## four_directions
```cpp
std::array<vector2<T>, 4> vector2<T>::four_directions();
```

It returns vectors $\left(\cos\left(\frac{i}{2}\pi\right), \sin\left(\frac{i}{2}\pi\right)\right)$ for $0 \leq i < 4$.

### Constraints
- None

### Time Complexity
- $O(1)$

## eight_directions
```cpp
std::array<vector2<T>, 8> vector2<T>::eight_directions();
```

It returns vectors $\left(\mathrm{RI}\left(\cos\left(\frac{i}{4}\pi\right)\right), \mathrm{RI}\left(\sin\left(\frac{i}{4}\pi\right)\right)\right)$ for $0 \leq i < 8$ where $\mathrm{RI}(x)$ rounds $x$ towards infinity.

### Constraints
- None

### Time Complexity
- $O(1)$
