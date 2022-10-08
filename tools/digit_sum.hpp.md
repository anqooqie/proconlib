---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/digit_sum.test.cpp
    title: tests/digit_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/digit_sum.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T digit_sum(T n) {\n    assert(n >= 0);\n\
    \    T sum = 0;\n    for (; n > 0; n /= 10) {\n      sum += n % 10;\n    }\n \
    \   return sum;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DIGIT_SUM_HPP\n#define TOOLS_DIGIT_SUM_HPP\n\n#include <cassert>\n\
    \nnamespace tools {\n\n  template <typename T>\n  T digit_sum(T n) {\n    assert(n\
    \ >= 0);\n    T sum = 0;\n    for (; n > 0; n /= 10) {\n      sum += n % 10;\n\
    \    }\n    return sum;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/digit_sum.hpp
  requiredBy: []
  timestamp: '2022-05-29 19:05:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/digit_sum.test.cpp
documentation_of: tools/digit_sum.hpp
layout: document
title: Sum of digits
---

```cpp
template <typename T>
T digit_sum(T n);
```

It returns sum of the digits of $n$.

## Constraints
- $n \geq 0$

## Time Complexity
- $O\left(\log n\right)$

## License
- CC0

## Author
- anqooqie
