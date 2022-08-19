---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/barlekamp_massey.test.cpp
    title: tests/barlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/barlekamp_massey.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <algorithm>\n#include <utility>\n\
    \nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void barlekamp_massey(InputIterator begin, InputIterator end, OutputIterator\
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
  code: "#ifndef TOOLS_BARLEKAMP_MASSEY_HPP\n#define TOOLS_BARLEKAMP_MASSEY_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <cstddef>\n#include <algorithm>\n\
    #include <utility>\n\nnamespace tools {\n  template <typename InputIterator, typename\
    \ OutputIterator>\n  void barlekamp_massey(InputIterator begin, InputIterator\
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
  path: tools/barlekamp_massey.hpp
  requiredBy: []
  timestamp: '2022-08-19 17:41:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/barlekamp_massey.test.cpp
documentation_of: tools/barlekamp_massey.hpp
layout: document
title: Barlekamp-Massey algorithm
---

```cpp
template <typename InputIterator, typename OutputIterator>
void barlekamp_massey(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence of elements $(a_0, a_1, \ldots, a_{N - 1})$ on a field $K$, it returns a sequence of elements $(c_1, c_2, \ldots, c_d)$ on $K$ of the minimum length $d \geq 0$ such that $a_i \equiv \sum_{j=1}^d c_j d_{i - j}$ for $d \leq i < N$.

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
