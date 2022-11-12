---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/logn_integer_partition.test.cpp
    title: tests/logn_integer_partition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/logn_integer_partition.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename T>\n  ::std::vector<T>\
    \ logn_integer_partition(T n) {\n    assert(n >= 0);\n    ::std::vector<T> res;\n\
    \    for (T pow2 = 1; pow2 < n; n -= pow2, pow2 *= 2) {\n      res.push_back(pow2);\n\
    \    }\n    if (n > 0) res.push_back(n);\n    return res;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_LOGN_INTEGER_PARTITION_HPP\n#define TOOLS_LOGN_INTEGER_PARTITION_HPP\n\
    \n#include <vector>\n#include <cassert>\n\nnamespace tools {\n  template <typename\
    \ T>\n  ::std::vector<T> logn_integer_partition(T n) {\n    assert(n >= 0);\n\
    \    ::std::vector<T> res;\n    for (T pow2 = 1; pow2 < n; n -= pow2, pow2 *=\
    \ 2) {\n      res.push_back(pow2);\n    }\n    if (n > 0) res.push_back(n);\n\
    \    return res;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/logn_integer_partition.hpp
  requiredBy: []
  timestamp: '2022-10-15 20:30:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/logn_integer_partition.test.cpp
documentation_of: tools/logn_integer_partition.hpp
layout: document
title: Multiset $S$ such that $\{\sum_{x \in S'} x | S' \subseteq S\} = \{0, 1, \ldots,
  N\}$ and $|S| = O(\log N)$
---

```cpp
template <typename T>
std::vector<T> logn_integer_partition(T n);
```

It returns a multiset $S$ such that $\\{\sum_{x \in S'} x \| S' \subseteq S\\} = \\{0, 1, \ldots, N\\}$ and $\|S\| = O(\log N)$.

## Constraints
- $n \geq 0$

## Time Complexity
- $O(\log n)$

## License
- CC0

## Author
- anqooqie
