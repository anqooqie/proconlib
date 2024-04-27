---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor_log.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n#line 1 \"tools/floor.hpp\"\n\n\n\n#line 6 \"tools/floor.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M,\
    \ N>;\n    assert(rhs != N(0));\n    return lhs / rhs - T(((lhs > M(0) && rhs\
    \ < N(0)) || (lhs < M(0) && rhs > N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 7 \"\
    tools/floor_log.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  ::std::common_type_t<M, N> floor_log(const M& base, const N& antilogarithm)\
    \ {\n    assert(2 <= base && base <= 1000000000000000000);\n    assert(1 <= antilogarithm\
    \ && antilogarithm <= 1000000000000000000);\n\n    const ::std::common_type_t<M,\
    \ N> threshold = ::tools::floor(antilogarithm, base);\n    ::std::common_type_t<M,\
    \ N> logarithm = 0;\n    for (::std::common_type_t<M, N> pow = 1; pow <= antilogarithm;\
    \ pow = (pow <= threshold ? pow * base : antilogarithm + 1)) {\n      ++logarithm;\n\
    \    }\n\n    return logarithm - 1;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_LOG_HPP\n#define TOOLS_FLOOR_LOG_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n#include \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  ::std::common_type_t<M, N> floor_log(const M& base,\
    \ const N& antilogarithm) {\n    assert(2 <= base && base <= 1000000000000000000);\n\
    \    assert(1 <= antilogarithm && antilogarithm <= 1000000000000000000);\n\n \
    \   const ::std::common_type_t<M, N> threshold = ::tools::floor(antilogarithm,\
    \ base);\n    ::std::common_type_t<M, N> logarithm = 0;\n    for (::std::common_type_t<M,\
    \ N> pow = 1; pow <= antilogarithm; pow = (pow <= threshold ? pow * base : antilogarithm\
    \ + 1)) {\n      ++logarithm;\n    }\n\n    return logarithm - 1;\n  }\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/floor.hpp
  isVerificationFile: false
  path: tools/floor_log.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor_log.test.cpp
documentation_of: tools/floor_log.hpp
layout: document
title: $\left\lfloor \log_b(x) \right\rfloor$
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> floor_log(M b, N x);
```

It returns $\left\lfloor \log_b(x) \right\rfloor$.

### Constraints
- $2 \leq b \leq 10^{18}$
- $1 \leq x \leq 10^{18}$

### Time Complexity
- $O(\log x)$

### License
- CC0

### Author
- anqooqie
