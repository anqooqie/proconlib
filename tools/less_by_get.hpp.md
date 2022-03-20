---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/mo.hpp
    title: Mo's algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/less_by_get.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <tuple>\n\nnamespace tools {\n\n  template <::std::size_t I>\n  struct less_by_get\
    \ {\n    template <class T>\n    bool operator()(const T& x, const T& y) const\
    \ {\n      return ::std::get<I>(x) < ::std::get<I>(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_GET_HPP\n#define TOOLS_LESS_BY_GET_HPP\n\n#include\
    \ <cstddef>\n#include <tuple>\n\nnamespace tools {\n\n  template <::std::size_t\
    \ I>\n  struct less_by_get {\n    template <class T>\n    bool operator()(const\
    \ T& x, const T& y) const {\n      return ::std::get<I>(x) < ::std::get<I>(y);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by_get.hpp
  requiredBy:
  - tools/mo.hpp
  timestamp: '2022-03-20 20:07:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mo.test.cpp
documentation_of: tools/less_by_get.hpp
layout: document
title: std::less by std::get
---

It compares two values by `std::get`.

### Usage
```cpp
std::vector<std::tuple<int, int, int>> a;
std::sort(a.begin(), a.end(), tools::less_by_get<2>());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::size_t I>
tools::less_by_get<I> comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T>
bool comp.operator()(T x, T y);
```

It returns `true` if `std::get<I>(x) < std::get<I>(y)`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
