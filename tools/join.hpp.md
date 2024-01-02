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
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree_diameter.test.cpp
    title: tests/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/undoable_dsu.test.cpp
    title: tests/undoable_dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include <sstream>\n\
    \nnamespace tools {\n\n  template <typename Iterator>\n  ::std::string join(const\
    \ Iterator begin, const Iterator end, const ::std::string delimiter) {\n    ::std::ostringstream\
    \ ss;\n    ::std::string current_delimiter = \"\";\n    for (Iterator it = begin;\
    \ it != end; ++it) {\n      ss << current_delimiter << *it;\n      current_delimiter\
    \ = delimiter;\n    }\n    return ss.str();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_JOIN_HPP\n#define TOOLS_JOIN_HPP\n\n#include <string>\n#include\
    \ <sstream>\n\nnamespace tools {\n\n  template <typename Iterator>\n  ::std::string\
    \ join(const Iterator begin, const Iterator end, const ::std::string delimiter)\
    \ {\n    ::std::ostringstream ss;\n    ::std::string current_delimiter = \"\"\
    ;\n    for (Iterator it = begin; it != end; ++it) {\n      ss << current_delimiter\
    \ << *it;\n      current_delimiter = delimiter;\n    }\n    return ss.str();\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/join.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cycle_detection/undirected.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/tree_diameter.test.cpp
  - tests/lis.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/undoable_dsu.test.cpp
documentation_of: tools/join.hpp
layout: document
title: Join elements with delimiter
---

```cpp
template <typename Iterator>
std::string join(Iterator begin, Iterator end, std::string delimiter);
```

It returns a string, that is joined elements with `delimtier`.

## License
- CC0

## Author
- anqooqie
