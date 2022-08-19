---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/berlekamp_massey.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <algorithm>\n#include <utility>\n\
    \nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void berlekamp_massey(InputIterator begin, InputIterator end, OutputIterator\
    \ result) {\n    using M = ::std::decay_t<decltype(*begin)>;\n    ::std::vector<M>\
    \ A(begin, end);\n    ::std::vector<M> C({M(1)});\n    ::std::vector<M> B({M(1)});\n\
    \    ::std::size_t L = 0;\n    ::std::size_t m = 1;\n    M b(1);\n\n    for (::std::size_t\
    \ n = 0; n < A.size(); ++n) {\n      M d(0);\n      for (::std::size_t i = 0;\
    \ i <= L; ++i) {\n        d += C[i] * A[n - i];\n      }\n\n      if (d == M(0))\
    \ {\n        ++m;\n      } else {\n        const auto update_C = [&]() {\n   \
    \       C.resize(::std::max(C.size(), B.size() + m));\n          const auto coeff\
    \ = d / b;\n          for (::std::size_t i = 0; i < B.size(); ++i) {\n       \
    \     C[i + m] -= coeff * B[i];\n          }\n        };\n        if (2 * L <=\
    \ n) {\n          const auto T = C;\n          update_C();\n          L = n +\
    \ 1 - L;\n          B = ::std::move(T);\n          b = d;\n          m = 1;\n\
    \        } else {\n          update_C();\n          ++m;\n        }\n      }\n\
    \    }\n\n    for (const auto& C_i : C) {\n      *result = C_i;\n      ++result;\n\
    \    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_BERLEKAMP_MASSEY_HPP\n#define TOOLS_BERLEKAMP_MASSEY_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <cstddef>\n#include <algorithm>\n\
    #include <utility>\n\nnamespace tools {\n  template <typename InputIterator, typename\
    \ OutputIterator>\n  void berlekamp_massey(InputIterator begin, InputIterator\
    \ end, OutputIterator result) {\n    using M = ::std::decay_t<decltype(*begin)>;\n\
    \    ::std::vector<M> A(begin, end);\n    ::std::vector<M> C({M(1)});\n    ::std::vector<M>\
    \ B({M(1)});\n    ::std::size_t L = 0;\n    ::std::size_t m = 1;\n    M b(1);\n\
    \n    for (::std::size_t n = 0; n < A.size(); ++n) {\n      M d(0);\n      for\
    \ (::std::size_t i = 0; i <= L; ++i) {\n        d += C[i] * A[n - i];\n      }\n\
    \n      if (d == M(0)) {\n        ++m;\n      } else {\n        const auto update_C\
    \ = [&]() {\n          C.resize(::std::max(C.size(), B.size() + m));\n       \
    \   const auto coeff = d / b;\n          for (::std::size_t i = 0; i < B.size();\
    \ ++i) {\n            C[i + m] -= coeff * B[i];\n          }\n        };\n   \
    \     if (2 * L <= n) {\n          const auto T = C;\n          update_C();\n\
    \          L = n + 1 - L;\n          B = ::std::move(T);\n          b = d;\n \
    \         m = 1;\n        } else {\n          update_C();\n          ++m;\n  \
    \      }\n      }\n    }\n\n    for (const auto& C_i : C) {\n      *result = C_i;\n\
    \      ++result;\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/berlekamp_massey.hpp
  requiredBy: []
  timestamp: '2022-08-20 00:15:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/berlekamp_massey.test.cpp
documentation_of: tools/berlekamp_massey.hpp
layout: document
title: Berlekamp-Massey algorithm
---

```cpp
template <typename InputIterator, typename OutputIterator>
void berlekamp_massey(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence of elements $(a_0, a_1, \ldots, a_{N - 1})$ on a field $K$, it finds a sequence of elements $(1, c_1, c_2, \ldots, c_d)$ on $K$ of the minimum length $d \geq 0$ such that $a_i + \sum_{j=1}^d c_j a_{i - j} \equiv 0$ for $d \leq i < N$.

Berlekamp-Massey algorithm can be used in the following situation.
We have the first $2d$ terms of an infinite sequence.
The sequence is known to be generated from a linear recurrence equation of at most degree $d$.
If we give the first $2d$ terms to Berlekamp-Massey algorithm, we can identify the coefficients of the linear recurrence equation.

Example:
Assume that we have the first $4$ terms $(0, 1, 1, 2)$ of an infinite sequence $(a_0, a_1, \ldots)$.
The sequence is known to be generated from a linear recurrence equation of at most degree $2$.
We can find that the sequence is generated from $a_{n+2} - a_{n+1} - a_n \equiv 0$ by Berlekamp-Massey algorithm.
The infinite sequence is the Fibonacci sequence.

### Constraints
- None

### Time Complexity
- $O(N^2)$

### References
- [数列の漸化式の特定と第N項の計算    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/number_theory/barlekamp_massey)

### License
- CC0

### Author
- anqooqie
