---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/floor_quotients.test.cpp
    title: tests/floor_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor_quotients.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <tuple>\n#include <cassert>\n#include <limits>\n\nnamespace tools {\n  template\
    \ <typename T>\n  ::std::vector<::std::tuple<T, T, T>> floor_quotients(const T\
    \ A) {\n    assert(A >= 0);\n\n    ::std::vector<::std::tuple<T, T, T>> res;\n\
    \    T x;\n    for (x = 1; x * x <= A; ++x) {\n      res.emplace_back(x, x + 1,\
    \ A / x);\n    }\n    for (T q = A / x; q > 0; --q) {\n      res.emplace_back(A\
    \ / (q + 1) + 1, A / q + 1, q);\n    }\n    res.emplace_back(A + 1, ::std::numeric_limits<T>::max(),\
    \ 0);\n\n    return res;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_QUOTIENTS_HPP\n#define TOOLS_FLOOR_QUOTIENTS_HPP\n\n\
    #include <vector>\n#include <tuple>\n#include <cassert>\n#include <limits>\n\n\
    namespace tools {\n  template <typename T>\n  ::std::vector<::std::tuple<T, T,\
    \ T>> floor_quotients(const T A) {\n    assert(A >= 0);\n\n    ::std::vector<::std::tuple<T,\
    \ T, T>> res;\n    T x;\n    for (x = 1; x * x <= A; ++x) {\n      res.emplace_back(x,\
    \ x + 1, A / x);\n    }\n    for (T q = A / x; q > 0; --q) {\n      res.emplace_back(A\
    \ / (q + 1) + 1, A / q + 1, q);\n    }\n    res.emplace_back(A + 1, ::std::numeric_limits<T>::max(),\
    \ 0);\n\n    return res;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/floor_quotients.hpp
  requiredBy: []
  timestamp: '2023-07-09 15:30:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor_quotients.test.cpp
documentation_of: tools/floor_quotients.hpp
layout: document
title: Enumerate the range of $\left\lfloor \frac{A}{x} \right\rfloor$
---

```cpp
template <typename T>
std::vector<std::tuple<T, T, T>> floor_quotients(T A);
```

It returns the tuples such that the $i$-th tuple $(l_i, r_i, q_i)$ satisfies $l_i \leq x < r_i \Rightarrow \left\lfloor \frac{A}{x} \right\rfloor = q_i$, in ascending order of $l_i$.
The last tuple would be $(A + 1, \infty, 0)$ mathematically, but it actually returns `std::numeric_limits<T>::max()` instead of $\infty$ since a integral type `<T>` cannot represent infinity.

### Constraints
- `<T>` is a built-in integral type.
- $A \geq 0$

### Time Complexity
- $O(\sqrt{A})$

### License
- CC0

### Author
- anqooqie
