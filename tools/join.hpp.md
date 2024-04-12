---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cycle_detection/undirected.test.cpp
    title: tests/cycle_detection/undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis.test.cpp
    title: tests/lis.test.cpp
  - icon: ':x:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prim/basic.test.cpp
    title: tests/prim/basic.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree_diameter.test.cpp
    title: tests/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/undoable_dsu.test.cpp
    title: tests/undoable_dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include <sstream>\n\
    #include <iterator>\n\nnamespace tools {\n\n  template <typename Iterator>\n \
    \ ::std::string join(const Iterator begin, const Iterator end, const ::std::string&\
    \ delimiter) {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss\
    \ << *begin;\n      for (auto it = ::std::next(begin); it != end; ++it) {\n  \
    \      ss << delimiter << *it;\n      }\n    }\n    return ss.str();\n  }\n\n\
    \  template <typename Iterator, typename F>\n  ::std::string join(const Iterator\
    \ begin, const Iterator end, const F& mapper, const ::std::string& delimiter)\
    \ {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss << mapper(*begin);\n\
    \      for (auto it = ::std::next(begin); it != end; ++it) {\n        ss << delimiter\
    \ << mapper(*it);\n      }\n    }\n    return ss.str();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_JOIN_HPP\n#define TOOLS_JOIN_HPP\n\n#include <string>\n#include\
    \ <sstream>\n#include <iterator>\n\nnamespace tools {\n\n  template <typename\
    \ Iterator>\n  ::std::string join(const Iterator begin, const Iterator end, const\
    \ ::std::string& delimiter) {\n    ::std::ostringstream ss;\n    if (begin !=\
    \ end) {\n      ss << *begin;\n      for (auto it = ::std::next(begin); it !=\
    \ end; ++it) {\n        ss << delimiter << *it;\n      }\n    }\n    return ss.str();\n\
    \  }\n\n  template <typename Iterator, typename F>\n  ::std::string join(const\
    \ Iterator begin, const Iterator end, const F& mapper, const ::std::string& delimiter)\
    \ {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss << mapper(*begin);\n\
    \      for (auto it = ::std::next(begin); it != end; ++it) {\n        ss << delimiter\
    \ << mapper(*it);\n      }\n    }\n    return ss.str();\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/join.hpp
  requiredBy: []
  timestamp: '2024-04-06 03:06:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/prim/basic.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/cycle_detection/undirected.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/tree_diameter.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/undoable_dsu.test.cpp
  - tests/lis.test.cpp
documentation_of: tools/join.hpp
layout: document
title: Join elements with delimiter
---

## (1)
```cpp
template <typename Iterator>
std::string join(Iterator begin, Iterator end, std::string d);
```

Given $n$ elements $e_0, e_1, \cdots, e_{n - 1}$, it returns $e_0 + d + e_1 + d + \cdots + d + e_{n - 1}$ where $+$ is string concatenation.
Note that it returns an empty string if $n = 0$.

### Constraints
- `operator<<` for `std::ostream` and `typename std::iterator_traits<Iterator>::value_type` is defined.

### Time Complexity
- $\sum_{i = 0}^{n - 1} \|e_i\| + n \|d\|$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename Iterator, typename F>
std::string join(Iterator begin, Iterator end, F f, std::string d);
```

Given $n$ elements $e_0, e_1, \cdots, e_{n - 1}$, it returns $f(e_0) + d + f(e_1) + d + \cdots + d + f(e_{n - 1})$ where $+$ is string concatenation.
Note that it returns an empty string if $n = 0$.

### Constraints
- `operator<<` for `std::ostream` and `decltype(f(std::declval<typename std::iterator_traits<Iterator>::value_type>()))` is defined.

### Time Complexity
- $\sum_{i = 0}^{n - 1} t(e_i) + n \|d\|$ where it takes $t(x)$ time to get $f(x)$

### License
- CC0

### Author
- anqooqie
