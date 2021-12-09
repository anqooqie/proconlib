---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/matrix/multiplies.test.cpp
    title: tests/matrix/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/solve.test.cpp
    title: tests/matrix/solve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <type_traits>\n#include <cmath>\n#include <cassert>\n#include <iostream>\n\
    #include <string>\n\nnamespace tools {\n  template <typename T>\n  class vector\
    \ {\n  private:\n    ::std::vector<T> m_values;\n\n  public:\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    vector(::std::size_t dim) : m_values(dim) {\n    }\n    vector(::std::size_t\
    \ dim, const T& value) : m_values(dim, value) {\n    }\n\n    T& operator[](const\
    \ ::std::size_t i) {\n      return this->m_values[i];\n    }\n    T operator[](const\
    \ ::std::size_t i) const {\n      return this->m_values[i];\n    }\n\n    ::std::size_t\
    \ dim() const {\n      return this->m_values.size();\n    }\n\n    double norm()\
    \ const {\n      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n\
    \    }\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    T inner_product(const\
    \ ::tools::vector<T>& other) const {\n      assert(this->dim() == other.dim());\n\
    \      T result(0);\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n\
    \        result += this->m_values[i] * other.m_values[i];\n      }\n      return\
    \ result;\n    }\n\n    friend ::tools::vector<T>& operator+(::tools::vector<T>&\
    \ self) {\n      return self;\n    }\n    friend const ::tools::vector<T>& operator+(const\
    \ ::tools::vector<T>& self) {\n      return self;\n    }\n    friend ::tools::vector<T>\
    \ operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      return ::tools::vector<T>(lhs) += rhs;\n    }\n    friend ::tools::vector<T>\
    \ operator-(const ::tools::vector<T>& self) {\n      return ::tools::vector<T>(self)\
    \ *= T(-1);\n    }\n    friend ::tools::vector<T> operator-(const ::tools::vector<T>&\
    \ lhs, const ::tools::vector<T>& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ -= rhs;\n    }\n    friend ::tools::vector<T> operator*(const ::tools::vector<T>&\
    \ lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs) *= rhs;\n    }\n\
    \    friend ::tools::vector<T> operator*(const T& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return ::tools::vector<T>(rhs) *= lhs;\n    }\n    friend ::tools::vector<T>\
    \ operator/(const ::tools::vector<T>& lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ /= rhs;\n    }\n    ::tools::vector<T>& operator+=(const ::tools::vector<T>&\
    \ other) {\n      assert(this->dim() == other.dim());\n      for (::std::size_t\
    \ i = 0; i < this->dim(); ++i) {\n        this->m_values[i] += other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::vector<T>& operator-=(const\
    \ ::tools::vector<T>& other) {\n      assert(this->dim() == other.dim());\n  \
    \    for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ -= other.m_values[i];\n      }\n      return *this;\n    }\n    ::tools::vector<T>&\
    \ operator*=(const T& c) {\n      for (::std::size_t i = 0; i < this->dim(); ++i)\
    \ {\n        this->m_values[i] *= c;\n      }\n      return *this;\n    }\n  \
    \  ::tools::vector<T>& operator/=(const T& c) {\n      const T c_inv = T(1) /\
    \ c;\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ *= c_inv;\n      }\n      return *this;\n    }\n    friend bool operator==(const\
    \ ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n      if (lhs.dim()\
    \ != rhs.dim()) {\n        return false;\n      }\n      for (::std::size_t i\
    \ = 0; i < lhs.dim(); ++i) {\n        if (lhs.m_values[i] != rhs.m_values[i])\
    \ {\n          return false;\n        }\n      }\n      return true;\n    }\n\
    \    friend bool operator!=(const ::tools::vector<T>& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::vector<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T& value : self.m_values) {\n        os\
    \ << delimiter << value;\n        delimiter = \", \";\n      }\n      return os\
    \ << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector<T>&\
    \ self) {\n      for (T& value : self.m_values) {\n        is >> value;\n    \
    \  }\n      return is;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR_HPP\n#define TOOLS_VECTOR_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <type_traits>\n#include <cmath>\n#include <cassert>\n\
    #include <iostream>\n#include <string>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class vector {\n  private:\n    ::std::vector<T> m_values;\n\n  public:\n\
    \    vector() = default;\n    vector(const ::tools::vector<T>&) = default;\n \
    \   vector(::tools::vector<T>&&) = default;\n    ~vector() = default;\n    ::tools::vector<T>&\
    \ operator=(const ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    vector(::std::size_t dim) : m_values(dim) {\n    }\n    vector(::std::size_t\
    \ dim, const T& value) : m_values(dim, value) {\n    }\n\n    T& operator[](const\
    \ ::std::size_t i) {\n      return this->m_values[i];\n    }\n    T operator[](const\
    \ ::std::size_t i) const {\n      return this->m_values[i];\n    }\n\n    ::std::size_t\
    \ dim() const {\n      return this->m_values.size();\n    }\n\n    double norm()\
    \ const {\n      return ::std::sqrt(static_cast<double>(this->squared_norm()));\n\
    \    }\n    T squared_norm() const {\n      return this->inner_product(*this);\n\
    \    }\n    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T,\
    \ double>::value, ::std::nullptr_t>::type = nullptr>\n    ::tools::vector<double>\
    \ normalized() const {\n      return *this / this->norm();\n    }\n\n    T inner_product(const\
    \ ::tools::vector<T>& other) const {\n      assert(this->dim() == other.dim());\n\
    \      T result(0);\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n\
    \        result += this->m_values[i] * other.m_values[i];\n      }\n      return\
    \ result;\n    }\n\n    friend ::tools::vector<T>& operator+(::tools::vector<T>&\
    \ self) {\n      return self;\n    }\n    friend const ::tools::vector<T>& operator+(const\
    \ ::tools::vector<T>& self) {\n      return self;\n    }\n    friend ::tools::vector<T>\
    \ operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      return ::tools::vector<T>(lhs) += rhs;\n    }\n    friend ::tools::vector<T>\
    \ operator-(const ::tools::vector<T>& self) {\n      return ::tools::vector<T>(self)\
    \ *= T(-1);\n    }\n    friend ::tools::vector<T> operator-(const ::tools::vector<T>&\
    \ lhs, const ::tools::vector<T>& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ -= rhs;\n    }\n    friend ::tools::vector<T> operator*(const ::tools::vector<T>&\
    \ lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs) *= rhs;\n    }\n\
    \    friend ::tools::vector<T> operator*(const T& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return ::tools::vector<T>(rhs) *= lhs;\n    }\n    friend ::tools::vector<T>\
    \ operator/(const ::tools::vector<T>& lhs, const T& rhs) {\n      return ::tools::vector<T>(lhs)\
    \ /= rhs;\n    }\n    ::tools::vector<T>& operator+=(const ::tools::vector<T>&\
    \ other) {\n      assert(this->dim() == other.dim());\n      for (::std::size_t\
    \ i = 0; i < this->dim(); ++i) {\n        this->m_values[i] += other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::vector<T>& operator-=(const\
    \ ::tools::vector<T>& other) {\n      assert(this->dim() == other.dim());\n  \
    \    for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ -= other.m_values[i];\n      }\n      return *this;\n    }\n    ::tools::vector<T>&\
    \ operator*=(const T& c) {\n      for (::std::size_t i = 0; i < this->dim(); ++i)\
    \ {\n        this->m_values[i] *= c;\n      }\n      return *this;\n    }\n  \
    \  ::tools::vector<T>& operator/=(const T& c) {\n      const T c_inv = T(1) /\
    \ c;\n      for (::std::size_t i = 0; i < this->dim(); ++i) {\n        this->m_values[i]\
    \ *= c_inv;\n      }\n      return *this;\n    }\n    friend bool operator==(const\
    \ ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {\n      if (lhs.dim()\
    \ != rhs.dim()) {\n        return false;\n      }\n      for (::std::size_t i\
    \ = 0; i < lhs.dim(); ++i) {\n        if (lhs.m_values[i] != rhs.m_values[i])\
    \ {\n          return false;\n        }\n      }\n      return true;\n    }\n\
    \    friend bool operator!=(const ::tools::vector<T>& lhs, const ::tools::vector<T>&\
    \ rhs) {\n      return !(lhs == rhs);\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::vector<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T& value : self.m_values) {\n        os\
    \ << delimiter << value;\n        delimiter = \", \";\n      }\n      return os\
    \ << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector<T>&\
    \ self) {\n      for (T& value : self.m_values) {\n        is >> value;\n    \
    \  }\n      return is;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/vector.hpp
  requiredBy:
  - tools/matrix.hpp
  timestamp: '2021-10-26 00:02:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/matrix/solve.test.cpp
  - tests/matrix/multiplies.test.cpp
documentation_of: tools/vector.hpp
layout: document
title: Vector
---

It is a $n$-dimensional vector.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) vector<T> v(std::size_t n);
(2) vector<T> v(std::size_t n, T x);
```

- (1)
    - It creates a $n$-dimensional vector.
- (2)
    - It creates a $n$-dimensional vector, of which all the elements $x$.

The type parameter `<T>` represents the type of the elements.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator[]
```cpp
T& v[std::size_t i];
```

It is the $i$-th element of the vector.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## dim
```cpp
std::size_t v.dim();
```

It returns the dimension of the vector.

### Constraints
- None

### Time Complexity
- $O(1)$

## norm
```cpp
double v.norm();
```

It returns $\left\|\overrightarrow{v}\right\|$.

### Constraints
- None

### Time Complexity
- $O(n)$

## squared_norm
```cpp
T v.squared_norm();
```

It returns $\left\|\overrightarrow{v}\right\|^2 = \overrightarrow{v} \cdot \overrightarrow{v}$.

### Constraints
- None

### Time Complexity
- $O(n)$

## normalized
```cpp
vector<double> v.normalized();
```

It returns $\frac{\overrightarrow{v}}{\left\|\overrightarrow{v}\right\|}$.

### Constraints
- `<T>` is `double`

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

## Arithmetic operations
```cpp
(1) vector<T> +v;
(2) vector<T> -v;
(3) vector<T> v + u;
(4) vector<T> v - u;
(5) vector<T> v * c;
(6) vector<T> c * v;
(7) vector<T> v / c;
(8) vector<T>& v += u;
(9) vector<T>& v -= u;
(10) vector<T>& v *= c;
(11) vector<T>& v /= c;
(12) bool v == u;
(13) bool v != u;
```

It supports basic arithmetic operations on vectors where $\overrightarrow{u}$ is another $n$-dimensional vector and $c$ is a scholar value.

### Constraints
- (3), (4), (8), (9), (12), (13)
    - The dimension of $\overrightarrow{u}$ is equal to the dimension of $\overrightarrow{v}$.
- (7), (11)
    - $c \neq 0$

### Time Complexity
- $O(n)$