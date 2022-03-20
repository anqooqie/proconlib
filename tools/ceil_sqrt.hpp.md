---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_sqrt.test.cpp
    title: tests/ceil_sqrt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil_sqrt.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T ceil_sqrt(T n) {\n    assert(n >= 0);\n\
    \n    T ok = 0;\n    T ng;\n    for (ng = 1; (ng - 1) * (ng - 1) < n; ng *= 2);\n\
    \n    while (ng - ok > 1) {\n      const T mid = ok + (ng - ok) / 2;\n      if\
    \ ((mid - 1) * (mid - 1) < n) {\n        ok = mid;\n      } else {\n        ng\
    \ = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_SQRT_HPP\n#define TOOLS_CEIL_SQRT_HPP\n\n#include <cassert>\n\
    \nnamespace tools {\n\n  template <typename T>\n  T ceil_sqrt(T n) {\n    assert(n\
    \ >= 0);\n\n    T ok = 0;\n    T ng;\n    for (ng = 1; (ng - 1) * (ng - 1) < n;\
    \ ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = ok + (ng - ok) /\
    \ 2;\n      if ((mid - 1) * (mid - 1) < n) {\n        ok = mid;\n      } else\
    \ {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ceil_sqrt.hpp
  requiredBy: []
  timestamp: '2022-03-20 11:06:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_sqrt.test.cpp
documentation_of: tools/ceil_sqrt.hpp
layout: document
title: $\left\lceil \sqrt{x} \right\rceil$
---

```cpp
template <typename T>
T ceil_sqrt(T x);
```

It returns $\left\lceil \sqrt{x} \right\rceil$.

## Constraints
- $0 \leq x \leq 10^{18} + 1000$

## Time Complexity
- $O(\log x)$

## License
- CC0

## Author
- anqooqie
