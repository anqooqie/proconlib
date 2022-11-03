---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/permutation.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <numeric>\n#include <cassert>\n#include <utility>\n#include\
    \ <iterator>\n#include <iostream>\n#include <string>\n\nnamespace tools {\n  template\
    \ <typename T>\n  class permutation {\n  private:\n    ::std::vector<T> m_vector;\n\
    \n    void verify_consistency() const {\n#ifndef NDEBUG\n      ::std::vector<bool>\
    \ unique(this->m_vector.size(), true);\n      for (const T& x : this->m_vector)\
    \ {\n        assert(0 <= x && x < T(this->m_vector.size()));\n        assert(unique[x]);\n\
    \        unique[x] = false;\n      }\n#endif\n    }\n\n  public:\n    permutation()\
    \ = default;\n    permutation(const ::tools::permutation<T>&) = default;\n   \
    \ permutation(::tools::permutation<T>&&) = default;\n    ~permutation() = default;\n\
    \    ::tools::permutation<T>& operator=(const ::tools::permutation<T>&) = default;\n\
    \    ::tools::permutation<T>& operator=(::tools::permutation<T>&&) = default;\n\
    \n    permutation(::std::size_t dim) : m_vector(dim) {\n      ::std::iota(this->m_vector.begin(),\
    \ this->m_vector.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_vector(begin, end) {\n      this->verify_consistency();\n\
    \    }\n\n    T operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    typename ::std::vector<T>::const_iterator\
    \ begin() const {\n      return this->m_vector.begin();\n    }\n    typename ::std::vector<T>::const_iterator\
    \ end() const {\n      return this->m_vector.end();\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vector.size();\n    }\n\n    void swap(const\
    \ ::std::size_t i, const ::std::size_t j) {\n      assert(i < this->size());\n\
    \      assert(j < this->size());\n      ::std::swap(this->m_vector[i], this->m_vector[j]);\n\
    \    }\n\n    T id() const {\n      if (this->m_vector.empty()) return 0;\n\n\
    \      ::std::vector<T> left(this->m_vector.size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n      ::std::vector<T> fact(this->m_vector.size());\n     \
    \ fact[0] = 1;\n      for (::std::size_t i = 1; i < this->m_vector.size(); ++i)\
    \ {\n        fact[i] = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for\
    \ (::std::size_t i = 0; i < this->m_vector.size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_vector[i]);\n        id += std::distance(left.begin(), it)\
    \ * fact[this->m_vector.size() - 1 - i];\n        left.erase(it);\n      }\n\n\
    \      return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ dim, T id) {\n      if (dim == 0) return ::tools::permutation<T>(0);\n\n   \
    \   ::std::vector<T> left(dim);\n      ::std::iota(left.begin(), left.end(), 0);\n\
    \      ::std::vector<T> fact(dim);\n      fact[0] = 1;\n      for (::std::size_t\
    \ i = 1; i < dim; ++i) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n    \
    \  ::std::vector<T> p;\n      for (::std::size_t i = 0; i < dim; ++i) {\n    \
    \    auto it = std::next(left.begin(), id / fact[dim - i - 1]);\n        p.push_back(*it);\n\
    \        left.erase(it);\n        id %= fact[dim - i - 1];\n      }\n\n      return\
    \ ::tools::permutation<T>(p.begin(), p.end());\n    }\n\n    ::tools::permutation<T>\
    \ inv() const {\n      ::tools::permutation<T> result(this->size());\n      for\
    \ (::std::size_t i = 0; i < this->size(); ++i) {\n        result.m_vector[this->m_vector[i]]\
    \ = i;\n      }\n      return result;\n    }\n\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      assert(lhs.size() == rhs.size());\n      ::tools::permutation<T>\
    \ result(lhs.size());\n      for (::std::size_t i = 0; i < lhs.size(); ++i) {\n\
    \        result.m_vector[i] = rhs.m_vector[lhs.m_vector[i]];\n      }\n      return\
    \ result;\n    }\n    friend bool operator==(const ::tools::permutation<T>& lhs,\
    \ const ::tools::permutation<T>& rhs) {\n      return lhs.m_vector == rhs.m_vector;\n\
    \    }\n    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_vector != rhs.m_vector;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {\n    \
    \  os << '(';\n      ::std::string delimiter = \"\";\n      for (const T& value\
    \ : self.m_vector) {\n        os << delimiter << value;\n        delimiter = \"\
    , \";\n      }\n      return os << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::permutation<T>& self) {\n      for (T& value : self.m_vector) {\n\
    \        is >> value;\n      }\n      self.verify_consistency();\n      return\
    \ is;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PERMUTATION_HPP\n#define TOOLS_PERMUTATION_HPP\n\n#include\
    \ <vector>\n#include <cstddef>\n#include <numeric>\n#include <cassert>\n#include\
    \ <utility>\n#include <iterator>\n#include <iostream>\n#include <string>\n\nnamespace\
    \ tools {\n  template <typename T>\n  class permutation {\n  private:\n    ::std::vector<T>\
    \ m_vector;\n\n    void verify_consistency() const {\n#ifndef NDEBUG\n      ::std::vector<bool>\
    \ unique(this->m_vector.size(), true);\n      for (const T& x : this->m_vector)\
    \ {\n        assert(0 <= x && x < T(this->m_vector.size()));\n        assert(unique[x]);\n\
    \        unique[x] = false;\n      }\n#endif\n    }\n\n  public:\n    permutation()\
    \ = default;\n    permutation(const ::tools::permutation<T>&) = default;\n   \
    \ permutation(::tools::permutation<T>&&) = default;\n    ~permutation() = default;\n\
    \    ::tools::permutation<T>& operator=(const ::tools::permutation<T>&) = default;\n\
    \    ::tools::permutation<T>& operator=(::tools::permutation<T>&&) = default;\n\
    \n    permutation(::std::size_t dim) : m_vector(dim) {\n      ::std::iota(this->m_vector.begin(),\
    \ this->m_vector.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_vector(begin, end) {\n      this->verify_consistency();\n\
    \    }\n\n    T operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    typename ::std::vector<T>::const_iterator\
    \ begin() const {\n      return this->m_vector.begin();\n    }\n    typename ::std::vector<T>::const_iterator\
    \ end() const {\n      return this->m_vector.end();\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vector.size();\n    }\n\n    void swap(const\
    \ ::std::size_t i, const ::std::size_t j) {\n      assert(i < this->size());\n\
    \      assert(j < this->size());\n      ::std::swap(this->m_vector[i], this->m_vector[j]);\n\
    \    }\n\n    T id() const {\n      if (this->m_vector.empty()) return 0;\n\n\
    \      ::std::vector<T> left(this->m_vector.size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n      ::std::vector<T> fact(this->m_vector.size());\n     \
    \ fact[0] = 1;\n      for (::std::size_t i = 1; i < this->m_vector.size(); ++i)\
    \ {\n        fact[i] = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for\
    \ (::std::size_t i = 0; i < this->m_vector.size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_vector[i]);\n        id += std::distance(left.begin(), it)\
    \ * fact[this->m_vector.size() - 1 - i];\n        left.erase(it);\n      }\n\n\
    \      return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ dim, T id) {\n      if (dim == 0) return ::tools::permutation<T>(0);\n\n   \
    \   ::std::vector<T> left(dim);\n      ::std::iota(left.begin(), left.end(), 0);\n\
    \      ::std::vector<T> fact(dim);\n      fact[0] = 1;\n      for (::std::size_t\
    \ i = 1; i < dim; ++i) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n    \
    \  ::std::vector<T> p;\n      for (::std::size_t i = 0; i < dim; ++i) {\n    \
    \    auto it = std::next(left.begin(), id / fact[dim - i - 1]);\n        p.push_back(*it);\n\
    \        left.erase(it);\n        id %= fact[dim - i - 1];\n      }\n\n      return\
    \ ::tools::permutation<T>(p.begin(), p.end());\n    }\n\n    ::tools::permutation<T>\
    \ inv() const {\n      ::tools::permutation<T> result(this->size());\n      for\
    \ (::std::size_t i = 0; i < this->size(); ++i) {\n        result.m_vector[this->m_vector[i]]\
    \ = i;\n      }\n      return result;\n    }\n\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      assert(lhs.size() == rhs.size());\n      ::tools::permutation<T>\
    \ result(lhs.size());\n      for (::std::size_t i = 0; i < lhs.size(); ++i) {\n\
    \        result.m_vector[i] = rhs.m_vector[lhs.m_vector[i]];\n      }\n      return\
    \ result;\n    }\n    friend bool operator==(const ::tools::permutation<T>& lhs,\
    \ const ::tools::permutation<T>& rhs) {\n      return lhs.m_vector == rhs.m_vector;\n\
    \    }\n    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_vector != rhs.m_vector;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {\n    \
    \  os << '(';\n      ::std::string delimiter = \"\";\n      for (const T& value\
    \ : self.m_vector) {\n        os << delimiter << value;\n        delimiter = \"\
    , \";\n      }\n      return os << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::permutation<T>& self) {\n      for (T& value : self.m_vector) {\n\
    \        is >> value;\n      }\n      self.verify_consistency();\n      return\
    \ is;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/permutation.hpp
  requiredBy: []
  timestamp: '2021-12-26 18:29:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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

## size
```cpp
std::size_t p.size();
```

It returns the number of elements.

### Constraints
- None

### Time Complexity
- $O(1)$

## swap
```cpp
void p.swap(std::size_t i, std::size_t j);
```

It swaps the $i$-th element and the $j$-th element.

### Constraints
- $0 \leq i < n$
- $0 \leq j < n$

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
tools::permutation<T> p.inv();
```

It returns $p^{-1}$.
$p^{-1}$ maps the `p[i]`-th element to the $i$-th element.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator*
```cpp
tools::permutation<T> p2 * p1;
```

It returns the merged permutation $p_3 = p_2 \circ p_1$.
$p_3$ maps the $i$-th element to the `p2[p1[i]]`-th element.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$
