---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bezout.hpp
    title: "B\xE9zout's identity"
  - icon: ':heavy_check_mark:'
    path: tools/divisors.hpp
    title: List all divisors
  - icon: ':heavy_check_mark:'
    path: tools/extended_garner.hpp
    title: Extended Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':warning:'
    path: tools/rich_pow_mod_cache.hpp
    title: Precompute $b^n \pmod{M}$ for $-\infty < n < \infty$
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/divisors.test.cpp
    title: tests/divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_garner.test.cpp
    title: tests/extended_garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
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
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
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
  - tools/garner.hpp
  - tools/mod.hpp
  - tools/extended_lucas.hpp
  - tools/divisors.hpp
  - tools/extgcd.hpp
  - tools/extended_garner.hpp
  - tools/round.hpp
  - tools/is_prime.hpp
  - tools/totient.hpp
  - tools/rich_pow_mod_cache.hpp
  - tools/inv_mod.hpp
  - tools/tetration_mod.hpp
  - tools/prime_factorization.hpp
  - tools/pow_mod.hpp
  - tools/bezout.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/divisors.test.cpp
  - tests/totient.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/bezout.test.cpp
  - tests/extgcd.test.cpp
  - tests/extended_garner.test.cpp
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

It returns $q$, which satisfies $a = qb + r$ and $0 \leq r < \|b\|$.

## Constraints
- $b \neq 0$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
