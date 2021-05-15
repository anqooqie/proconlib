---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Primality test
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Prime factorization
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x,\
    \ const T2 y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128 prod_mod\
    \ = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if (((x >= 0)\
    \ ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_PROD_MOD_HPP\n#define TOOLS_PROD_MOD_HPP\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const\
    \ T1 x, const T2 y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128\
    \ prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if\
    \ (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/prod_mod.hpp
  requiredBy:
  - tools/totient.hpp
  - tools/pow_mod.hpp
  - tools/is_prime.hpp
  - tools/prime_factorization.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/is_prime.test.cpp
  - tests/prime_factorization.test.cpp
documentation_of: tools/prod_mod.hpp
layout: document
title: $x \cdot y \pmod{M}$
---

```cpp
template <typename T1, typename T2, typename T3>
constexpr T3 prod_mod(const T1 x, T2 y, const T3 M);
```

It returns $x \cdot y \pmod{M}$.

## License
- CC0

## Author
- anqooqie
