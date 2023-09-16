---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: Matrix
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
    path: tests/matrix/solve.test.cpp
    title: tests/matrix/solve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/vector.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <initializer_list>\n#line 1 \"tools/detail/vector_common.hpp\"\n\n\n\n\
    #include <type_traits>\n#include <cassert>\n#line 7 \"tools/detail/vector_common.hpp\"\
    \n#include <algorithm>\n#include <cmath>\n#include <iostream>\n#include <string>\n\
    #line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const\
    \ float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned\
    \ int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned long\
    \ x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\
    \n\n#define TOOLS_DETAIL_VECTOR_COMMON(V) \\\n  private:\\\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
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
    \        is >> v;\\\n      }\\\n      return is;\\\n    }\n\n\n#line 8 \"tools/vector.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class vector {\n  private:\n\
    \    ::std::vector<T> m_values;\n\n  public:\n    using reference = T&;\n    using\
    \ const_reference = const T&;\n    using size_type = ::std::size_t;\n    using\
    \ difference_type = ::std::ptrdiff_t;\n    using pointer = T*;\n    using const_pointer\
    \ = const T*;\n    using value_type = T;\n    using iterator = typename ::std::vector<T>::iterator;\n\
    \    using const_iterator = typename ::std::vector<T>::const_iterator;\n    using\
    \ reverse_iterator = typename ::std::vector<T>::reverse_iterator;\n    using const_reverse_iterator\
    \ = typename ::std::vector<T>::const_reverse_iterator;\n\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    explicit vector(size_type n) : m_values(n) {}\n    vector(size_type\
    \ n, const_reference value) : m_values(n, value) {}\n    template <typename InputIter>\
    \ vector(const InputIter first, const InputIter last) : m_values(first, last)\
    \ {}\n    vector(const ::std::initializer_list<T> il) : m_values(il) {}\n\n  \
    \  iterator begin() { return this->m_values.begin(); }\n    const_iterator begin()\
    \ const { return this->m_values.begin(); }\n    iterator end() { return this->m_values.end();\
    \ }\n    const_iterator end() const { return this->m_values.end(); }\n    const_iterator\
    \ cbegin() const { return this->m_values.cbegin(); }\n    const_iterator cend()\
    \ const { return this->m_values.cend(); }\n    reverse_iterator rbegin() { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator rbegin() const { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator crbegin() const { return\
    \ this->m_values.crbegin(); }\n    reverse_iterator rend() { return this->m_values.rend();\
    \ }\n    const_reverse_iterator rend() const { return this->m_values.rend(); }\n\
    \    const_reverse_iterator crend() const { return this->m_values.crend(); }\n\
    \n    size_type size() const { return this->m_values.size(); }\n    bool empty()\
    \ const { return this->m_values.empty(); }\n\n    reference operator[](const size_type\
    \ n) { return this->m_values[n]; }\n    const_reference operator[](const size_type\
    \ n) const { return this->m_values[n]; }\n    reference front() { return *this->begin();\
    \ }\n    const_reference front() const { return *this->begin(); }\n    reference\
    \ back() { return *this->rbegin(); }\n    const_reference back() const { return\
    \ *this->rbegin(); }\n\n    void swap(::tools::vector<T>& other) { this->m_values.swap(other.m_values);\
    \ }\n\n    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector<T>)\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_VECTOR_HPP\n#define TOOLS_VECTOR_HPP\n\n#include <vector>\n\
    #include <cstddef>\n#include <initializer_list>\n#include \"tools/detail/vector_common.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class vector {\n  private:\n\
    \    ::std::vector<T> m_values;\n\n  public:\n    using reference = T&;\n    using\
    \ const_reference = const T&;\n    using size_type = ::std::size_t;\n    using\
    \ difference_type = ::std::ptrdiff_t;\n    using pointer = T*;\n    using const_pointer\
    \ = const T*;\n    using value_type = T;\n    using iterator = typename ::std::vector<T>::iterator;\n\
    \    using const_iterator = typename ::std::vector<T>::const_iterator;\n    using\
    \ reverse_iterator = typename ::std::vector<T>::reverse_iterator;\n    using const_reverse_iterator\
    \ = typename ::std::vector<T>::const_reverse_iterator;\n\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    explicit vector(size_type n) : m_values(n) {}\n    vector(size_type\
    \ n, const_reference value) : m_values(n, value) {}\n    template <typename InputIter>\
    \ vector(const InputIter first, const InputIter last) : m_values(first, last)\
    \ {}\n    vector(const ::std::initializer_list<T> il) : m_values(il) {}\n\n  \
    \  iterator begin() { return this->m_values.begin(); }\n    const_iterator begin()\
    \ const { return this->m_values.begin(); }\n    iterator end() { return this->m_values.end();\
    \ }\n    const_iterator end() const { return this->m_values.end(); }\n    const_iterator\
    \ cbegin() const { return this->m_values.cbegin(); }\n    const_iterator cend()\
    \ const { return this->m_values.cend(); }\n    reverse_iterator rbegin() { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator rbegin() const { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator crbegin() const { return\
    \ this->m_values.crbegin(); }\n    reverse_iterator rend() { return this->m_values.rend();\
    \ }\n    const_reverse_iterator rend() const { return this->m_values.rend(); }\n\
    \    const_reverse_iterator crend() const { return this->m_values.crend(); }\n\
    \n    size_type size() const { return this->m_values.size(); }\n    bool empty()\
    \ const { return this->m_values.empty(); }\n\n    reference operator[](const size_type\
    \ n) { return this->m_values[n]; }\n    const_reference operator[](const size_type\
    \ n) const { return this->m_values[n]; }\n    reference front() { return *this->begin();\
    \ }\n    const_reference front() const { return *this->begin(); }\n    reference\
    \ back() { return *this->rbegin(); }\n    const_reference back() const { return\
    \ *this->rbegin(); }\n\n    void swap(::tools::vector<T>& other) { this->m_values.swap(other.m_values);\
    \ }\n\n    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector<T>)\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  isVerificationFile: false
  path: tools/vector.hpp
  requiredBy:
  - tools/matrix.hpp
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/matrix/solve.test.cpp
  - tests/matrix/determinant.test.cpp
  - tests/matrix/inv.test.cpp
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

void v.swap(vector<T>& u);

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
