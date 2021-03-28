---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/greater_by_first.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace tools {\n\n  class greater_by_first {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.first > y.first;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_BY_FIRST_HPP\n#define TOOLS_GREATER_BY_FIRST_HPP\n\n\
    #include <utility>\n\nnamespace tools {\n\n  class greater_by_first {\n  public:\n\
    \    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.first > y.first;\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_by_first.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/greater_by_first.hpp
layout: document
title: std::greater by first
---

It is almost equivalent to `std::greater` except that it compares pairs by the first element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_first());
```

## License
- CC0

## Author
- anqooqie
