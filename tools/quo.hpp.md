---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Prime factorization
  - icon: ':warning:'
    path: tools/rich_pow_mod_cache.hpp
    title: Precompute $b^n \pmod{M}$ for $-\infty < n < \infty$
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extgcd.test.cpp
    title: tests/extgcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/is_prime.test.cpp
    title: tests/is_prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prime_factorization.test.cpp
    title: tests/prime_factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_QUO_H\n#define TOOLS_QUO_H\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/quo.hpp
  requiredBy:
  - tools/totient.hpp
  - tools/pow_mod.hpp
  - tools/is_prime.hpp
  - tools/round.hpp
  - tools/rich_pow_mod_cache.hpp
  - tools/extgcd.hpp
  - tools/mod.hpp
  - tools/prime_factorization.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/extgcd.test.cpp
  - tests/is_prime.test.cpp
  - tests/prime_factorization.test.cpp
documentation_of: tools/quo.hpp
layout: document
title: Quotient as integer division
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> quo(M a, N b);
```

It returns $q$, which satisfies $a = qb + r \land 0 \leq r < \|b\|$.

## License
- CC0

## Author
- anqooqie
