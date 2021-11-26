---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy:
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
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
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
    path: tests/divisors.test.cpp
    title: tests/divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_garner.test.cpp
    title: tests/extended_garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
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
  bundledCode: "#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"\
    tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M\
    \ lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else\
    \ {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      }\
    \ else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\
    \n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MOD_HPP\n#define TOOLS_MOD_HPP\n\n#include <type_traits>\n\
    #include \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/mod.hpp
  requiredBy:
  - tools/is_prime.hpp
  - tools/divisors.hpp
  - tools/pow_mod.hpp
  - tools/garner.hpp
  - tools/prime_factorization.hpp
  - tools/tetration_mod.hpp
  - tools/extended_lucas.hpp
  - tools/inv_mod.hpp
  - tools/rich_pow_mod_cache.hpp
  - tools/round.hpp
  - tools/extended_garner.hpp
  - tools/totient.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/divisors.test.cpp
  - tests/prime_factorization.test.cpp
  - tests/extended_garner.test.cpp
  - tests/is_prime.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/mod.hpp
layout: document
title: Minimum non-negative reminder
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> mod(M a, N b);
```

It returns $r$, which satisfies $a = qb + r$ and $0 \leq r < \|b\|$.

## Constraints
- $b \neq 0$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
