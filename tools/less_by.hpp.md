---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n   \
    \ less_by(const F& selector) : selector(selector) {\n    }\n\n    template <class\
    \ T>\n    bool operator()(const T& x, const T& y) const {\n      return selector(x)\
    \ < selector(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_HPP\n#define TOOLS_LESS_BY_HPP\n\nnamespace tools {\n\
    \n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n\
    \    less_by(const F& selector) : selector(selector) {\n    }\n\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ selector(x) < selector(y);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mex.test.cpp
documentation_of: tools/less_by.hpp
layout: document
title: std::less by key
---

It is almost equivalent to `std::less` except that it compares values by the given key selector.

## Usage
```cpp
std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x); }));
```

## License
- CC0

## Author
- anqooqie
