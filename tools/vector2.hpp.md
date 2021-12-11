---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"tools/vector2.hpp\"\n\n\n\n#include <cmath>\n#include <type_traits>\n\
    #include <cstddef>\n#include <array>\n#include <functional>\n#include <iostream>\n\
    #line 1 \"tools/pair_hash.hpp\"\n\n\n\n#line 5 \"tools/pair_hash.hpp\"\n#include\
    \ <utility>\n#include <random>\n#line 8 \"tools/pair_hash.hpp\"\n#include <cstdint>\n\
    \nnamespace tools {\n\n  template <class T1, class T2>\n  struct pair_hash {\n\
    \    using result_type = ::std::size_t;\n    using argument_type = ::std::pair<T1,\
    \ T2>;\n    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {\n\
    \      static const ::std::size_t salt = ::std::random_device()();\n      static\
    \ const ::std::hash<T1> hasher1 = ::std::hash<T1>();\n      static const ::std::hash<T2>\
    \ hasher2 = ::std::hash<T2>();\n      static const ::std::hash<::std::size_t>\
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
    \ tools {\n\n  template <typename T>\n  class vector2 {\n  public:\n    T x;\n\
    \    T y;\n\n    vector2() :\n      vector2(T(), T()) {\n    }\n\n    vector2(const\
    \ T& x, const T& y) :\n      x(x),\n      y(y) {\n    }\n\n    double norm() const\
    \ {\n      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n  \
    \  }\n\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    ::tools::vector2<T>\
    \ operator+() const {\n      return *this;\n    }\n\n    ::tools::vector2<T> operator-()\
    \ const {\n      return ::tools::vector2<T>(-this->x, -this->y);\n    }\n\n  \
    \  friend ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x + rhs.x,\
    \ lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template\
    \ <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n    friend ::tools::vector2<T> operator*(const\
    \ OTHER& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs\
    \ * rhs.x, lhs * rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n  \
    \  T inner_product(const ::tools::vector2<T>& other) const {\n      return this->x\
    \ * other.x + this->y * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>&\
    \ other) const {\n      return this->x * other.y - this->y * other.x;\n    }\n\
    \n    ::tools::vector2<T>& operator+=(const ::tools::vector2<T>& other) {\n  \
    \    return *this = *this + other;\n    }\n\n    ::tools::vector2<T>& operator-=(const\
    \ ::tools::vector2<T>& other) {\n      return *this = *this - other;\n    }\n\n\
    \    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator*=(const OTHER& other) {\n      return *this = *this * other;\n    }\n\
    \n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
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
    \ key.y));\n    }\n  };\n\n  template <typename T>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::vector2<T>& self) {\n    return os << '(' << self.x << \"\
    , \" << self.y << ')';\n  }\n\n  template <typename T>\n  ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::vector2<T>& self) {\n    return is >> self.x >> self.y;\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_VECTOR2_HPP\n#define TOOLS_VECTOR2_HPP\n\n#include <cmath>\n\
    #include <type_traits>\n#include <cstddef>\n#include <array>\n#include <functional>\n\
    #include <iostream>\n#include \"tools/pair_hash.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename T>\n  class vector2 {\n  public:\n    T x;\n    T y;\n\n\
    \    vector2() :\n      vector2(T(), T()) {\n    }\n\n    vector2(const T& x,\
    \ const T& y) :\n      x(x),\n      y(y) {\n    }\n\n    double norm() const {\n\
    \      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n    }\n\
    \n    T squared_norm() const {\n      return this->inner_product(*this);\n   \
    \ }\n\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    ::tools::vector2<T>\
    \ operator+() const {\n      return *this;\n    }\n\n    ::tools::vector2<T> operator-()\
    \ const {\n      return ::tools::vector2<T>(-this->x, -this->y);\n    }\n\n  \
    \  friend ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const\
    \ ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x + rhs.x,\
    \ lhs.y + rhs.y);\n    }\n\n    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>&\
    \ lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs.x\
    \ - rhs.x, lhs.y - rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);\n    }\n    template\
    \ <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n    friend ::tools::vector2<T> operator*(const\
    \ OTHER& lhs, const ::tools::vector2<T>& rhs) {\n      return ::tools::vector2<T>(lhs\
    \ * rhs.x, lhs * rhs.y);\n    }\n\n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    friend\
    \ ::tools::vector2<T> operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs)\
    \ {\n      return ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);\n    }\n\n  \
    \  T inner_product(const ::tools::vector2<T>& other) const {\n      return this->x\
    \ * other.x + this->y * other.y;\n    }\n\n    T outer_product(const ::tools::vector2<T>&\
    \ other) const {\n      return this->x * other.y - this->y * other.x;\n    }\n\
    \n    ::tools::vector2<T>& operator+=(const ::tools::vector2<T>& other) {\n  \
    \    return *this = *this + other;\n    }\n\n    ::tools::vector2<T>& operator-=(const\
    \ ::tools::vector2<T>& other) {\n      return *this = *this - other;\n    }\n\n\
    \    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator*=(const OTHER& other) {\n      return *this = *this * other;\n    }\n\
    \n    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER,\
    \ ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector2<T>&\
    \ operator/=(const OTHER& other) {\n      return *this = *this / other;\n    }\n\
    \n    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>&\
    \ rhs) {\n      return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n\n    friend\
    \ bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs)\
    \ {\n      return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n\n    static ::std::array<::tools::vector2<T>,\
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
    \ key.y));\n    }\n  };\n\n  template <typename T>\n  ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::vector2<T>& self) {\n    return os << '(' << self.x << \"\
    , \" << self.y << ')';\n  }\n\n  template <typename T>\n  ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::vector2<T>& self) {\n    return is >> self.x >> self.y;\n  }\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/pair_hash.hpp
  isVerificationFile: false
  path: tools/vector2.hpp
  requiredBy:
  - tools/less_by_arg.hpp
  - tools/ccw.hpp
  - tools/greater_by_arg.hpp
  - tools/convex_hull.hpp
  timestamp: '2021-11-28 18:16:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/greater_by_arg.test.cpp
  - tests/ccw.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/convex_hull.test.cpp
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

## norm
```cpp
double v.norm();
```

It returns $\left\|\overrightarrow{v}\right\| = \sqrt{x^2 + y^2}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## squared_norm
```cpp
T v.squared_norm();
```

It returns $\overrightarrow{v} \cdot \overrightarrow{v} = x^2 + y^2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## normalized
```cpp
vector2<double> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\|\overrightarrow{v}\right\|}$.

### Constraints
- `<T>` is `double`

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
