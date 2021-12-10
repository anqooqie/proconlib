---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor_sqrt.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T floor_sqrt(T n) {\n    assert(n >= 0);\n\
    \n    T ok = 0;\n    T ng;\n    for (ng = 1; ng * ng <= n; ng *= 2);\n\n    while\
    \ (ng - ok > 1) {\n      const T mid = (ok + ng) / 2;\n      if (mid * mid <=\
    \ n) {\n        ok = mid;\n      } else {\n        ng = mid;\n      }\n    }\n\
    \n    return ok;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_SQRT_HPP\n#define TOOLS_FLOOR_SQRT_HPP\n\n#include <cassert>\n\
    \nnamespace tools {\n\n  template <typename T>\n  T floor_sqrt(T n) {\n    assert(n\
    \ >= 0);\n\n    T ok = 0;\n    T ng;\n    for (ng = 1; ng * ng <= n; ng *= 2);\n\
    \n    while (ng - ok > 1) {\n      const T mid = (ok + ng) / 2;\n      if (mid\
    \ * mid <= n) {\n        ok = mid;\n      } else {\n        ng = mid;\n      }\n\
    \    }\n\n    return ok;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/floor_sqrt.hpp
  requiredBy:
  - tools/segmented_sieve.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segmented_sieve.test.cpp
documentation_of: tools/floor_sqrt.hpp
layout: document
title: $\left\lfloor \sqrt{x} \right\rfloor$
---

```cpp
template <typename T>
T floor_sqrt(T x);
```

It returns $\left\lfloor \sqrt{x} \right\rfloor$.

## License
- CC0

## Author
- anqooqie
