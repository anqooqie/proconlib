---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/qcfium.test.cpp
    title: tests/qcfium.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "tools/qcfium.hpp"




    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")



    '
  code: '#ifndef TOOLS_QCFIUM_HPP

    #define TOOLS_QCFIUM_HPP


    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")


    #endif

    '
  dependsOn: []
  isVerificationFile: false
  path: tools/qcfium.hpp
  requiredBy: []
  timestamp: '2021-07-24 04:45:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/qcfium.test.cpp
  - tests/mo.test.cpp
documentation_of: tools/qcfium.hpp
layout: document
title: QCFium's method
---

```cpp
#include "tools/qcfium.hpp"
```

It enables some compile options to speed up.

## Constraints
- It requires GCC.

## Time Complexity
- Not applicable

## References
- [Speeding Up for Naive Algorithm - Codeforces](https://codeforces.com/blog/entry/66279)

## License
- CC0

## Author
- anqooqie
