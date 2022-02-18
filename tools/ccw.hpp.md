---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: 2D vector
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_arg.hpp
    title: std::greater by the argument
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg.hpp
    title: std::less by the argument
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ccw.test.cpp
    title: tests/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convex_hull.test.cpp
    title: tests/convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/greater_by_arg.test.cpp
    title: tests/greater_by_arg.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/less_by_arg.test.cpp
    title: tests/less_by_arg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ccw.hpp\"\n\n\n\n#line 1 \"tools/vector2.hpp\"\n\n\
    \n\n#include <cmath>\n#include <type_traits>\n#include <cstddef>\n#include <array>\n\
    #include <iostream>\n#include <functional>\n#line 1 \"tools/pair_hash.hpp\"\n\n\
    \n\n#line 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n#line\
    \ 8 \"tools/pair_hash.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n  template\
    \ <class T1, class T2>\n  struct pair_hash {\n    using result_type = ::std::size_t;\n\
    \    using argument_type = ::std::pair<T1, T2>;\n    ::std::size_t operator()(const\
    \ ::std::pair<T1, T2>& key) const {\n      static const ::std::size_t salt = ::std::random_device()();\n\
    \      static const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static\
    \ const ::std::hash<T2> hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
    \ hasher3 = ::std::hash<::std::size_t>();\n      ::std::size_t result = 0;\n \
    \     result ^= hasher1(key.first) + static_cast<::std::size_t>(0x9e3779b9) +\
    \ (result << static_cast<::std::size_t>(6)) + (result >> static_cast<::std::size_t>(2));\n\
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
    \ key.second));\n    }\n  };\n}\n\n\n#line 11 \"tools/vector2.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class vector2 {\n  private:\n    using\
    \ F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\n\n  public:\n\
    \    T x;\n    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n    }\n\n \
    \   vector2(const T& x, const T& y) :\n      x(x),\n      y(y) {\n    }\n\n  \
    \  F norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_norm()));\n\
    \    }\n\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>,\
    \ ::std::nullptr_t> = nullptr>\n    ::tools::vector2<T> normalized() const {\n\
    \      return *this / this->norm();\n    }\n\n    ::tools::vector2<T> turn90()\
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
    \ key.y));\n    }\n  };\n}\n\n\n#line 5 \"tools/ccw.hpp\"\n\nnamespace tools {\n\
    \  template <typename T>\n  ::std::int_fast64_t ccw(const ::tools::vector2<T>&\
    \ a, ::tools::vector2<T> b, ::tools::vector2<T> c) {\n    b -= a;\n    c -= a;\n\
    \    if (b.outer_product(c) > 0) return +1;\n    if (b.outer_product(c) < 0) return\
    \ -1;\n    if (b.inner_product(c) < 0) return +2;\n    if (b.squared_norm() <\
    \ c.squared_norm()) return -2;\n    return 0;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CCW_HPP\n#define TOOLS_CCW_HPP\n\n#include \"tools/vector2.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  ::std::int_fast64_t ccw(const\
    \ ::tools::vector2<T>& a, ::tools::vector2<T> b, ::tools::vector2<T> c) {\n  \
    \  b -= a;\n    c -= a;\n    if (b.outer_product(c) > 0) return +1;\n    if (b.outer_product(c)\
    \ < 0) return -1;\n    if (b.inner_product(c) < 0) return +2;\n    if (b.squared_norm()\
    \ < c.squared_norm()) return -2;\n    return 0;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/pair_hash.hpp
  isVerificationFile: false
  path: tools/ccw.hpp
  requiredBy:
  - tools/less_by_arg.hpp
  - tools/convex_hull.hpp
  - tools/greater_by_arg.hpp
  timestamp: '2022-02-19 03:37:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/less_by_arg.test.cpp
  - tests/ccw.test.cpp
  - tests/convex_hull.test.cpp
  - tests/greater_by_arg.test.cpp
documentation_of: tools/ccw.hpp
layout: document
title: Counter clockwise function
---

```cpp
template <typename T>
std::int_fast64_t ccw(tools::vector2<T> a, tools::vector2<T> b, tools::vector2<T> c);
```

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
+1 & \text{(if $a$, $b$ and $c$ make a counterclockwise turn on the regular orthogonal coordinate system ($(\infty, 0)$ is on the right side and $(0, \infty)$ is on the upper side))}\\
-1 & \text{(if $a$, $b$ and $c$ make a clockwise turn on the regular orthogonal coordinate system)}\\
+2 & \text{(if $c$ - $a$ - $b$ are on a line in this order ($c \neq a$))}\\
-2 & \text{(if $a$ - $b$ - $c$ are on a line in this order ($c \neq b$))}\\
0 & \text{(otherwise; i.e., $a$ - $c$ - $b$ are on a line in this order, $c = a$, $c = b$ or $a = b$)}
\end{array}\right.&
\end{align*}$$

## Constraints
- None

## Time Complexity
- $O(1)$

## References
- [Spaghetti Source (ccw) - 点の進行方向](http://www.prefield.com/algorithm/geometry/ccw.html)

## License
- CC0

## Author
- anqooqie
