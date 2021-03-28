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
  bundledCode: "#line 1 \"tools/less_by_second.hpp\"\n\n\n\n#include <utility>\n\n\
    namespace tools {\n\n  class less_by_second {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.second < y.second;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_SECOND_HPP\n#define TOOLS_LESS_BY_SECOND_HPP\n\n#include\
    \ <utility>\n\nnamespace tools {\n\n  class less_by_second {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.second < y.second;\n    }\n\
    \  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by_second.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/less_by_second.hpp
layout: document
title: std::less by second
---

It is almost equivalent to `std::less` except that it compares pairs by the second element.

## Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::less_by_second());
```

## License
- CC0

## Author
- anqooqie
