---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/next_value.test.cpp
    title: tests/wavelet_matrix/next_value.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/compressor.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#include\
    \ <iterator>\n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template\
    \ <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator first,\
    \ ForwardIterator last, const T& value) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 8 \"tools/compressor.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  class compressor {\n  private:\n    ::std::vector<T>\
    \ m_sorted;\n\n  public:\n    compressor() = default;\n    compressor(const ::tools::compressor<T>&)\
    \ = default;\n    compressor(::tools::compressor<T>&&) = default;\n    ~compressor()\
    \ = default;\n    ::tools::compressor<T>& operator=(const ::tools::compressor<T>&)\
    \ = default;\n    ::tools::compressor<T>& operator=(::tools::compressor<T>&&)\
    \ = default;\n\n    template <typename InputIterator>\n    compressor(InputIterator\
    \ begin, InputIterator end) : m_sorted(begin, end) {\n      ::std::sort(this->m_sorted.begin(),\
    \ this->m_sorted.end());\n      this->m_sorted.erase(::std::unique(this->m_sorted.begin(),\
    \ this->m_sorted.end()), this->m_sorted.end());\n    }\n    compressor(const ::std::vector<T>&\
    \ v) : compressor(v.begin(), v.end()) {\n    }\n\n    T size() const {\n     \
    \ return this->m_sorted.size();\n    }\n    T compress(const T& x) const {\n \
    \     const T i = ::tools::lower_bound(this->m_sorted.begin(), this->m_sorted.end(),\
    \ x);\n      assert(i < this->size());\n      assert(this->m_sorted[i] == x);\n\
    \      return i;\n    }\n    T decompress(const T& i) const {\n      assert(0\
    \ <= i && i < this->size());\n      return this->m_sorted[i];\n    }\n\n    auto\
    \ begin() {\n      return this->m_sorted.cbegin();\n    }\n    auto begin() const\
    \ {\n      return this->m_sorted.cbegin();\n    }\n    auto end() {\n      return\
    \ this->m_sorted.cend();\n    }\n    auto end() const {\n      return this->m_sorted.cend();\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_COMPRESSOR_HPP\n#define TOOLS_COMPRESSOR_HPP\n\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n#include \"tools/lower_bound.hpp\"\n\
    \nnamespace tools {\n  template <typename T>\n  class compressor {\n  private:\n\
    \    ::std::vector<T> m_sorted;\n\n  public:\n    compressor() = default;\n  \
    \  compressor(const ::tools::compressor<T>&) = default;\n    compressor(::tools::compressor<T>&&)\
    \ = default;\n    ~compressor() = default;\n    ::tools::compressor<T>& operator=(const\
    \ ::tools::compressor<T>&) = default;\n    ::tools::compressor<T>& operator=(::tools::compressor<T>&&)\
    \ = default;\n\n    template <typename InputIterator>\n    compressor(InputIterator\
    \ begin, InputIterator end) : m_sorted(begin, end) {\n      ::std::sort(this->m_sorted.begin(),\
    \ this->m_sorted.end());\n      this->m_sorted.erase(::std::unique(this->m_sorted.begin(),\
    \ this->m_sorted.end()), this->m_sorted.end());\n    }\n    compressor(const ::std::vector<T>&\
    \ v) : compressor(v.begin(), v.end()) {\n    }\n\n    T size() const {\n     \
    \ return this->m_sorted.size();\n    }\n    T compress(const T& x) const {\n \
    \     const T i = ::tools::lower_bound(this->m_sorted.begin(), this->m_sorted.end(),\
    \ x);\n      assert(i < this->size());\n      assert(this->m_sorted[i] == x);\n\
    \      return i;\n    }\n    T decompress(const T& i) const {\n      assert(0\
    \ <= i && i < this->size());\n      return this->m_sorted[i];\n    }\n\n    auto\
    \ begin() {\n      return this->m_sorted.cbegin();\n    }\n    auto begin() const\
    \ {\n      return this->m_sorted.cbegin();\n    }\n    auto end() {\n      return\
    \ this->m_sorted.cend();\n    }\n    auto end() const {\n      return this->m_sorted.cend();\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/lower_bound.hpp
  isVerificationFile: false
  path: tools/compressor.hpp
  requiredBy: []
  timestamp: '2023-06-28 13:29:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/wavelet_matrix/next_value.test.cpp
documentation_of: tools/compressor.hpp
layout: document
title: Compress values (for more complicated cases)
---

It provides the mapping which maps the $i$-th ($0$-indexed) least integer in a given integer set to $i$, and the inverse mapping of it.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <typename InputIterator>
compressor<T> cp(InputIterator begin, InputIterator end);

(2)
compressor<T> cp(std::vector<T> v);
```

It creates an integer set initialized with a given integer container.

### Constraints
- (1)
    - `begin` $\leq$ `end`

### Time Complexity
- (1)
    - $O(n \log n)$ where $n$ is `end` $-$ `begin`
- (2)
    - $O(n \log n)$ where $n$ is `v.size()`

## size
```cpp
T cp.size();
```

It returns the number of distinct integers in the set.

### Constraints
- None

### Time Complexity
- $O(1)$

## compress
```cpp
T cp.compress(T x);
```

It returns $i$ such that the $i$-th ($0$-indexed) least integer in the set is $x$.

### Constraints
- The set contains $x$.

### Time Complexity
- $O(\log n)$ where $n$ is `cp.size()`

## decompress
```cpp
T cp.decompress(T i);
```

It returns the $i$-th ($0$-indexed) least integer in the set.

### Constraints
- $0 \leq i < $ `cp.size()`

### Time Complexity
- $O(1)$

## begin
```cpp
typename std::vector<T>::const_iterator cp.begin();
```

It returns the iterator pointing to the least integer in the set.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
typename std::vector<T>::const_iterator cp.end();
```

It returns the iterator pointing to the integer which would follow the largest integer in the set.

### Constraints
- None

### Time Complexity
- $O(1)$
