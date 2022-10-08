---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':question:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':question:'
    path: tools/pair_hash.hpp
    title: Hash of std::pair
  - icon: ':question:'
    path: tools/vector2.hpp
    title: 2D vector
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/greater_by_arg_total.hpp
    title: std::greater by the argument (total order)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/greater_by_arg_total.test.cpp
    title: tests/greater_by_arg_total.test.cpp
  - icon: ':x:'
    path: tests/less_by_arg_total.test.cpp
    title: tests/less_by_arg_total.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/less_by_arg_total.hpp\"\n\n\n\n#line 1 \"tools/vector2.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <cmath>\n#include <cstddef>\n#include\
    \ <array>\n#include <iostream>\n#include <functional>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\n#line 5 \"tools/abs.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  auto abs(const T& v) -> decltype(::std::abs(v)) {\n    return ::std::abs(v);\n\
    \  }\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(v.abs()) {\n\
    \    return v.abs();\n  }\n}\n\n\n#line 1 \"tools/pair_hash.hpp\"\n\n\n\n#line\
    \ 5 \"tools/pair_hash.hpp\"\n#include <utility>\n#include <random>\n#line 8 \"\
    tools/pair_hash.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n  template <class\
    \ T1, class T2>\n  struct pair_hash {\n    using result_type = ::std::size_t;\n\
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
    \ key.y));\n    }\n  };\n}\n\n\n#line 1 \"tools/ccw.hpp\"\n\n\n\n#line 5 \"tools/ccw.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  int ccw(const ::tools::vector2<T>&\
    \ a, ::tools::vector2<T> b, ::tools::vector2<T> c) {\n    b -= a;\n    c -= a;\n\
    \    if (b.outer_product(c) > 0) return +1;\n    if (b.outer_product(c) < 0) return\
    \ -1;\n    if (b.inner_product(c) < 0) return +2;\n    if (b.squared_l2_norm()\
    \ < c.squared_l2_norm()) return -2;\n    return 0;\n  }\n}\n\n\n#line 6 \"tools/less_by_arg_total.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  class less_by_arg_total {\n\
    \  private:\n    ::tools::vector2<T> o;\n    ::tools::vector2<T> d;\n\n    int\
    \ where(const ::tools::vector2<T>& p) const {\n      static const ::tools::vector2<T>\
    \ zero(T(0), T(0));\n      static const ::tools::vector2<T> unit_x(T(1), T(0));\n\
    \      if (this->d == zero) {\n        return p.y > T(0) || (p.y == T(0) && p.x\
    \ >= T(0)) ? 0 : 1;\n      } else {\n        if (p == zero) {\n          const\
    \ auto ccw = ::tools::ccw(zero, this->d, unit_x);\n          if (ccw == +1) return\
    \ 2;\n          if (ccw == +2) return 4;\n          if (ccw == -1) return 7;\n\
    \          return 9;\n        } else {\n          if (this->d == p) {\n      \
    \      return 0;\n          }\n          const auto ccw = ::tools::ccw(zero, this->d,\
    \ p);\n          if (ccw == -2) {\n            return 0;\n          }\n      \
    \    if (ccw == +1) {\n            if (::tools::ccw(zero, this->d, unit_x) !=\
    \ +1) return 1;\n            if (::tools::ccw(zero, unit_x, p) == -1) return 1;\n\
    \            return 3;\n          }\n          if (ccw == +2) {\n            return\
    \ 5;\n          }\n          if (ccw == -1) {\n            if (::tools::ccw(zero,\
    \ this->d, unit_x) != -1) return 6;\n            if (::tools::ccw(zero, unit_x,\
    \ p) == -1) return 6;\n            return 8;\n          }\n          return 9;\n\
    \        }\n      }\n    }\n\n  public:\n    less_by_arg_total() = default;\n\
    \    less_by_arg_total(const ::tools::less_by_arg_total<T>&) = default;\n    less_by_arg_total(::tools::less_by_arg_total<T>&&)\
    \ = default;\n    ~less_by_arg_total() = default;\n    ::tools::less_by_arg_total<T>&\
    \ operator=(const ::tools::less_by_arg_total<T>&) = default;\n    ::tools::less_by_arg_total<T>&\
    \ operator=(::tools::less_by_arg_total<T>&&) = default;\n\n    less_by_arg_total(const\
    \ ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : o(o), d(d - o) {\n \
    \   }\n\n    bool operator()(::tools::vector2<T> a, ::tools::vector2<T> b) const\
    \ {\n      a -= this->o;\n      b -= this->o;\n      if (const auto wa = this->where(a),\
    \ wb = this->where(b); wa != wb) return wa < wb;\n      if (const auto ot = a.outer_product(b);\
    \ ot != T(0)) return ot > T(0);\n      return a.squared_l2_norm() < b.squared_l2_norm();\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_ARG_TOTAL_HPP\n#define TOOLS_LESS_BY_ARG_TOTAL_HPP\n\
    \n#include \"tools/vector2.hpp\"\n#include \"tools/ccw.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  class less_by_arg_total {\n  private:\n    ::tools::vector2<T>\
    \ o;\n    ::tools::vector2<T> d;\n\n    int where(const ::tools::vector2<T>& p)\
    \ const {\n      static const ::tools::vector2<T> zero(T(0), T(0));\n      static\
    \ const ::tools::vector2<T> unit_x(T(1), T(0));\n      if (this->d == zero) {\n\
    \        return p.y > T(0) || (p.y == T(0) && p.x >= T(0)) ? 0 : 1;\n      } else\
    \ {\n        if (p == zero) {\n          const auto ccw = ::tools::ccw(zero, this->d,\
    \ unit_x);\n          if (ccw == +1) return 2;\n          if (ccw == +2) return\
    \ 4;\n          if (ccw == -1) return 7;\n          return 9;\n        } else\
    \ {\n          if (this->d == p) {\n            return 0;\n          }\n     \
    \     const auto ccw = ::tools::ccw(zero, this->d, p);\n          if (ccw == -2)\
    \ {\n            return 0;\n          }\n          if (ccw == +1) {\n        \
    \    if (::tools::ccw(zero, this->d, unit_x) != +1) return 1;\n            if\
    \ (::tools::ccw(zero, unit_x, p) == -1) return 1;\n            return 3;\n   \
    \       }\n          if (ccw == +2) {\n            return 5;\n          }\n  \
    \        if (ccw == -1) {\n            if (::tools::ccw(zero, this->d, unit_x)\
    \ != -1) return 6;\n            if (::tools::ccw(zero, unit_x, p) == -1) return\
    \ 6;\n            return 8;\n          }\n          return 9;\n        }\n   \
    \   }\n    }\n\n  public:\n    less_by_arg_total() = default;\n    less_by_arg_total(const\
    \ ::tools::less_by_arg_total<T>&) = default;\n    less_by_arg_total(::tools::less_by_arg_total<T>&&)\
    \ = default;\n    ~less_by_arg_total() = default;\n    ::tools::less_by_arg_total<T>&\
    \ operator=(const ::tools::less_by_arg_total<T>&) = default;\n    ::tools::less_by_arg_total<T>&\
    \ operator=(::tools::less_by_arg_total<T>&&) = default;\n\n    less_by_arg_total(const\
    \ ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : o(o), d(d - o) {\n \
    \   }\n\n    bool operator()(::tools::vector2<T> a, ::tools::vector2<T> b) const\
    \ {\n      a -= this->o;\n      b -= this->o;\n      if (const auto wa = this->where(a),\
    \ wb = this->where(b); wa != wb) return wa < wb;\n      if (const auto ot = a.outer_product(b);\
    \ ot != T(0)) return ot > T(0);\n      return a.squared_l2_norm() < b.squared_l2_norm();\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/vector2.hpp
  - tools/abs.hpp
  - tools/pair_hash.hpp
  - tools/ccw.hpp
  isVerificationFile: false
  path: tools/less_by_arg_total.hpp
  requiredBy:
  - tools/greater_by_arg_total.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/greater_by_arg_total.test.cpp
  - tests/less_by_arg_total.test.cpp
documentation_of: tools/less_by_arg_total.hpp
layout: document
title: std::less by the argument (total order)
---

It compares two vectors by the argument.
More precisely, it maps a vector $v$ to $(\mathrm{class}\_{d - o}(v - o), \mathrm{arg}\_{d - o}(v - o), \|v - o\|)$ and compares two vectors by the mapped value in lexicographical order.

Given a vector $d$, $\mathrm{class}_d(v)$ is defined as follows.

$$\begin{align*}
\mathrm{class}_d(v) &= \left\{\begin{array}{ll}
0 & \text{(if $\mathrm{arg}(d) = \mathrm{arg}(v) \land \|d\| \leq \|v\|$)}\\
1 & \text{(if $\mathrm{arg}(d) \neq \mathrm{arg}(v)$)}\\
2 & \text{(if $\mathrm{arg}(d) = \mathrm{arg}(v) \land \|v\| < \|d\|$)}
\end{array}\right.&
\end{align*}$$

Given a vector $d$, $\mathrm{arg}_d(v)$ is defined as follows.

$$\begin{align*}
\mathrm{arg}_d(v) &= \mathrm{mod}(\mathrm{arg}(v) - \mathrm{arg}(d), 2 \pi)
\end{align*}$$

$\mathrm{arg}(v)$ is defined as follows.

$$\begin{align*}
\mathrm{arg}(v) &= \left\{\begin{array}{ll}
0 & \text{(if $v = (0, 0)$)}\\
\text{the unique real value $\theta$ which satisfies $0 \leq \theta < 2 \pi$, $\|v\| \cos(\theta) = v_x$ and $\|v\| \sin(\theta) = v_y$} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### References
- [How do you polar sort? - Codeforces](https://codeforces.com/blog/entry/72815)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::less_by_arg_total<T> comp(tools::vector2<T> o, tools::vector2<T> d);
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
bool comp(tools::vector2<T> a, tools::vector2<T> b);
```

It returns the following.

$$\begin{align*}
\left\{\begin{array}{ll}
\text{true} & \text{(if $(\mathrm{class}_{d - o}(a - o), \mathrm{arg}_{d - o}(a - o), \|a - o\|) < (\mathrm{class}_{d - o}(b - o), \mathrm{arg}_{d - o}(b - o), \|b - o\|)$ in lexicographical order)}\\
\text{false} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$
