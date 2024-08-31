---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':x:'
    path: tests/tsort/query.test.cpp
    title: tests/tsort/query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/permutation.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <cstddef>\n#include <numeric>\n#include <algorithm>\n#include\
    \ <iterator>\n#include <utility>\n#include <iostream>\n#include <string>\n\nnamespace\
    \ tools {\n  template <typename T>\n  class permutation {\n  private:\n    ::std::vector<T>\
    \ m_perm;\n    ::std::vector<T> m_inv;\n\n    void verify_consistency() const\
    \ {\n#ifndef NDEBUG\n      ::std::vector<bool> unique(this->m_perm.size(), true);\n\
    \      for (const T x : this->m_perm) {\n        assert(0 <= x && x < T(this->m_perm.size()));\n\
    \        assert(unique[x]);\n        unique[x] = false;\n      }\n#endif\n   \
    \ }\n\n    void make_inv() {\n      this->m_inv.resize(this->m_perm.size());\n\
    \      for (::std::size_t i = 0; i < this->m_perm.size(); ++i) {\n        this->m_inv[this->m_perm[i]]\
    \ = i;\n      }\n    }\n\n  public:\n    permutation() = default;\n    permutation(const\
    \ ::tools::permutation<T>&) = default;\n    permutation(::tools::permutation<T>&&)\
    \ = default;\n    ~permutation() = default;\n    ::tools::permutation<T>& operator=(const\
    \ ::tools::permutation<T>&) = default;\n    ::tools::permutation<T>& operator=(::tools::permutation<T>&&)\
    \ = default;\n\n    explicit permutation(::std::size_t n) : m_perm(n), m_inv(n)\
    \ {\n      ::std::iota(this->m_perm.begin(), this->m_perm.end(), 0);\n      ::std::iota(this->m_inv.begin(),\
    \ this->m_inv.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_perm(begin, end) {\n      this->verify_consistency();\n\
    \      this->make_inv();\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_perm.size();\n    }\n    T operator[](const ::std::size_t i) const {\n\
    \      assert(i < this->size());\n      return this->m_perm[i];\n    }\n    typename\
    \ ::std::vector<T>::const_iterator begin() const {\n      return this->m_perm.begin();\n\
    \    }\n    typename ::std::vector<T>::const_iterator end() const {\n      return\
    \ this->m_perm.end();\n    }\n\n    ::tools::permutation<T>& swap_from_left(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_inv[this->m_perm[y]] = x;\n   \
    \   this->m_inv[this->m_perm[x]] = y;\n      ::std::swap(this->m_perm[x], this->m_perm[y]);\n\
    \      return *this;\n    }\n    ::tools::permutation<T>& swap_from_right(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_perm[this->m_inv[y]] = x;\n   \
    \   this->m_perm[this->m_inv[x]] = y;\n      ::std::swap(this->m_inv[x], this->m_inv[y]);\n\
    \      return *this;\n    }\n\n    T id() const {\n      if (this->size() == 0)\
    \ return 0;\n\n      ::std::vector<T> left(this->size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n\n      ::std::vector<T> fact(this->size());\n      fact[0]\
    \ = 1;\n      for (::std::size_t i = 1; i < this->size(); ++i) {\n        fact[i]\
    \ = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for (::std::size_t i =\
    \ 0; i < this->size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_perm[i]);\n        id += ::std::distance(left.begin(), it)\
    \ * fact[this->m_perm.size() - 1 - i];\n        left.erase(it);\n      }\n\n \
    \     return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ n, T id) {\n      if (n == 0) return ::tools::permutation<T>(0);\n\n      ::std::vector<T>\
    \ left(n);\n      ::std::iota(left.begin(), left.end(), 0);\n\n      ::std::vector<T>\
    \ fact(n);\n      fact[0] = 1;\n      for (::std::size_t i = 1; i < n; ++i) {\n\
    \        fact[i] = fact[i - 1] * i;\n      }\n\n      ::std::vector<T> p;\n  \
    \    for (::std::size_t i = 0; i < n; ++i) {\n        auto it = ::std::next(left.begin(),\
    \ id / fact[n - i - 1]);\n        p.push_back(*it);\n        left.erase(it);\n\
    \        id %= fact[n - i - 1];\n      }\n\n      return ::tools::permutation<T>(p.begin(),\
    \ p.end());\n    }\n\n    ::tools::permutation<T> inv() const {\n      return\
    \ ::tools::permutation<T>(this->m_inv.begin(), this->m_inv.end());\n    }\n  \
    \  ::tools::permutation<T>& inv_inplace() {\n      this->m_perm.swap(this->m_inv);\n\
    \      return *this;\n    }\n    T inv(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_inv[i];\n    }\n\n    ::tools::permutation<T>&\
    \ operator*=(const ::tools::permutation<T>& other) {\n      assert(this->size()\
    \ == other.size());\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n\
    \        this->m_inv[i] = other.m_perm[this->m_perm[i]];\n      }\n      this->m_perm.swap(this->m_inv);\n\
    \      this->make_inv();\n      return *this;\n    }\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return ::tools::permutation<T>(lhs) *= rhs;\n    }\n\n    friend\
    \ bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_perm == rhs.m_perm;\n    }\n    friend bool operator!=(const\
    \ ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {\n      return\
    \ lhs.m_perm != rhs.m_perm;\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::permutation<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T value : self.m_perm) {\n        os <<\
    \ delimiter << value;\n        delimiter = \", \";\n      }\n      return os <<\
    \ ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>&\
    \ self) {\n      for (T& value : self.m_perm) {\n        is >> value;\n      }\n\
    \      self.verify_consistency();\n      self.make_inv();\n      return is;\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PERMUTATION_HPP\n#define TOOLS_PERMUTATION_HPP\n\n#include\
    \ <vector>\n#include <cassert>\n#include <cstddef>\n#include <numeric>\n#include\
    \ <algorithm>\n#include <iterator>\n#include <utility>\n#include <iostream>\n\
    #include <string>\n\nnamespace tools {\n  template <typename T>\n  class permutation\
    \ {\n  private:\n    ::std::vector<T> m_perm;\n    ::std::vector<T> m_inv;\n\n\
    \    void verify_consistency() const {\n#ifndef NDEBUG\n      ::std::vector<bool>\
    \ unique(this->m_perm.size(), true);\n      for (const T x : this->m_perm) {\n\
    \        assert(0 <= x && x < T(this->m_perm.size()));\n        assert(unique[x]);\n\
    \        unique[x] = false;\n      }\n#endif\n    }\n\n    void make_inv() {\n\
    \      this->m_inv.resize(this->m_perm.size());\n      for (::std::size_t i =\
    \ 0; i < this->m_perm.size(); ++i) {\n        this->m_inv[this->m_perm[i]] = i;\n\
    \      }\n    }\n\n  public:\n    permutation() = default;\n    permutation(const\
    \ ::tools::permutation<T>&) = default;\n    permutation(::tools::permutation<T>&&)\
    \ = default;\n    ~permutation() = default;\n    ::tools::permutation<T>& operator=(const\
    \ ::tools::permutation<T>&) = default;\n    ::tools::permutation<T>& operator=(::tools::permutation<T>&&)\
    \ = default;\n\n    explicit permutation(::std::size_t n) : m_perm(n), m_inv(n)\
    \ {\n      ::std::iota(this->m_perm.begin(), this->m_perm.end(), 0);\n      ::std::iota(this->m_inv.begin(),\
    \ this->m_inv.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_perm(begin, end) {\n      this->verify_consistency();\n\
    \      this->make_inv();\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_perm.size();\n    }\n    T operator[](const ::std::size_t i) const {\n\
    \      assert(i < this->size());\n      return this->m_perm[i];\n    }\n    typename\
    \ ::std::vector<T>::const_iterator begin() const {\n      return this->m_perm.begin();\n\
    \    }\n    typename ::std::vector<T>::const_iterator end() const {\n      return\
    \ this->m_perm.end();\n    }\n\n    ::tools::permutation<T>& swap_from_left(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_inv[this->m_perm[y]] = x;\n   \
    \   this->m_inv[this->m_perm[x]] = y;\n      ::std::swap(this->m_perm[x], this->m_perm[y]);\n\
    \      return *this;\n    }\n    ::tools::permutation<T>& swap_from_right(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_perm[this->m_inv[y]] = x;\n   \
    \   this->m_perm[this->m_inv[x]] = y;\n      ::std::swap(this->m_inv[x], this->m_inv[y]);\n\
    \      return *this;\n    }\n\n    T id() const {\n      if (this->size() == 0)\
    \ return 0;\n\n      ::std::vector<T> left(this->size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n\n      ::std::vector<T> fact(this->size());\n      fact[0]\
    \ = 1;\n      for (::std::size_t i = 1; i < this->size(); ++i) {\n        fact[i]\
    \ = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for (::std::size_t i =\
    \ 0; i < this->size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_perm[i]);\n        id += ::std::distance(left.begin(), it)\
    \ * fact[this->m_perm.size() - 1 - i];\n        left.erase(it);\n      }\n\n \
    \     return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ n, T id) {\n      if (n == 0) return ::tools::permutation<T>(0);\n\n      ::std::vector<T>\
    \ left(n);\n      ::std::iota(left.begin(), left.end(), 0);\n\n      ::std::vector<T>\
    \ fact(n);\n      fact[0] = 1;\n      for (::std::size_t i = 1; i < n; ++i) {\n\
    \        fact[i] = fact[i - 1] * i;\n      }\n\n      ::std::vector<T> p;\n  \
    \    for (::std::size_t i = 0; i < n; ++i) {\n        auto it = ::std::next(left.begin(),\
    \ id / fact[n - i - 1]);\n        p.push_back(*it);\n        left.erase(it);\n\
    \        id %= fact[n - i - 1];\n      }\n\n      return ::tools::permutation<T>(p.begin(),\
    \ p.end());\n    }\n\n    ::tools::permutation<T> inv() const {\n      return\
    \ ::tools::permutation<T>(this->m_inv.begin(), this->m_inv.end());\n    }\n  \
    \  ::tools::permutation<T>& inv_inplace() {\n      this->m_perm.swap(this->m_inv);\n\
    \      return *this;\n    }\n    T inv(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_inv[i];\n    }\n\n    ::tools::permutation<T>&\
    \ operator*=(const ::tools::permutation<T>& other) {\n      assert(this->size()\
    \ == other.size());\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n\
    \        this->m_inv[i] = other.m_perm[this->m_perm[i]];\n      }\n      this->m_perm.swap(this->m_inv);\n\
    \      this->make_inv();\n      return *this;\n    }\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return ::tools::permutation<T>(lhs) *= rhs;\n    }\n\n    friend\
    \ bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_perm == rhs.m_perm;\n    }\n    friend bool operator!=(const\
    \ ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {\n      return\
    \ lhs.m_perm != rhs.m_perm;\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::permutation<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T value : self.m_perm) {\n        os <<\
    \ delimiter << value;\n        delimiter = \", \";\n      }\n      return os <<\
    \ ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>&\
    \ self) {\n      for (T& value : self.m_perm) {\n        is >> value;\n      }\n\
    \      self.verify_consistency();\n      self.make_inv();\n      return is;\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/permutation.hpp
  requiredBy: []
  timestamp: '2023-02-11 13:12:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/tsort/query.test.cpp
  - tests/permutation.test.cpp
documentation_of: tools/permutation.hpp
layout: document
title: Permutation
---

It is a permutation of $n$ elements.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) permutation<T> p(std::size_t n);
(2) template <typename Iterator> permutation<T> p(Iterator begin, Iterator end);
```

It creates an identity permutation of $n$ elements.
The type parameter `<T>` represents the type of the elements.

### Constraints
- (1)
    - None
- (2)
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are unique.
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are $0$ or more.
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are less than $\mathrm{end} - \mathrm{begin}$.

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t p.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
T p[std::size_t i];
```

It returns the position to which the $i$-th element mapped by the permutation.
In other words, the permutation maps the $i$-th element to the `p[i]`-th element.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## begin
```cpp
typename std::vector<T>::const_iterator p.begin();
```

It returns the iterator pointing to the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
typename std::vector<T>::const_iterator p.end();
```

It returns the iterator pointing to the element which would follow the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## swap_from_left
```cpp
permutation<T>& p.swap_from_left(T x, T y);
```

Let $p^\ast$ be $p$ just before the function call.
Let $q$ be the following permutation of $n$ elements.

$$\begin{align*}
q(i) &= \left\{\begin{array}{ll}
p^\ast(y) & \text{(if $i = x$)}\\
p^\ast(x) & \text{(if $i = y$)}\\
p^\ast(i) & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

It updates $p$ to $q$, and returns the updated $p$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(1)$

## swap_from_right
```cpp
permutation<T>& p.swap_from_right(T x, T y);
```

Let $p^\ast$ be $p$ just before the function call.
Let $q$ be the following permutation of $n$ elements.

$$\begin{align*}
q(i) &= \left\{\begin{array}{ll}
y & \text{(if $p^\ast(i) = x$)}\\
x & \text{(if $p^\ast(i) = y$)}\\
p^\ast(i) & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

It updates $p$ to $q$, and returns the updated $p$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(1)$

## id
```cpp
T p.id();
```

It returns the number of permutations of $n$ elements less than $p$ in lexicographical order.

### Constraints
- None

### Time Complexity
- $O(n^2)$

## from
```cpp
permutation<T> permutation<T>::from(std::size_t n, T id);
```

It returns the permutation of $n$ elements $p$, such that `p.id() == id`.

### Constraints
- $0 \leq \mathrm{id} < n!$

### Time Complexity
- $O(n^2)$

## inv
```cpp
(1) tools::permutation<T> p.inv();
(2) tools::permutation<T> p.inv(std::size_t i);
```

- (1)
    - It returns $p^{-1}$.
    - $p^{-1}$ maps the `p[i]`-th element to the $i$-th element.
- (2)
    - It returns the position that the permutation maps to the $i$-th element.
    - In other words, the permutation maps the `p.inv(i)`-th element to the $i$-th element.

### Constraints
- (1)
    - None
- (2)
    - $0 \leq i < n$

### Time Complexity
- (1)
    - $O(n)$
- (2)
    - $O(1)$

## inv_inplace
```cpp
tools::permutation<T>& p.inv_inplace();
```

It updates $p$ to $p^{-1}$, and returns the updated $p$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator*
```cpp
tools::permutation<T> operator*(permutation<T> p1, permutation<T> p2);
```

It returns the merged permutation $p_3 = p_1 \circ p_2$.
$p_3$ maps the $i$-th element to the `p2[p1[i]]`-th element.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$

## operator*=
```cpp
tools::permutation<T>& p1.operator*=(permutation<T> p2);
```

It updates $p_1$ to $p_1 \circ p_2$, and returns the updated $p_1$.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$
