---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: tools/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: tools/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: tools/prime_factorization.hpp
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: tools/totient.hpp
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
  bundledCode: "#line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  /**\n\
    \   * x * y (mod m)\n   * License: CC0\n   * @author anqooqie\n   * @param <T1>\
    \ type of x\n   * @param <T2> type of y\n   * @param <T3> type of m\n   * @param\
    \ x x\n   * @param y y\n   * @param m m\n   * @return x * y (mod m)\n   */\n \
    \ template <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const\
    \ T1 x, const T2 y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128\
    \ prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if\
    \ (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_PROD_MOD_HPP\n#define TOOLS_PROD_MOD_HPP\n\nnamespace tools\
    \ {\n\n  /**\n   * x * y (mod m)\n   * License: CC0\n   * @author anqooqie\n \
    \  * @param <T1> type of x\n   * @param <T2> type of y\n   * @param <T3> type\
    \ of m\n   * @param x x\n   * @param y y\n   * @param m m\n   * @return x * y\
    \ (mod m)\n   */\n  template <typename T1, typename T2, typename T3>\n  constexpr\
    \ T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128 = unsigned\
    \ __int128;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y)\
    \ % u128(m);\n    if (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n\
    \    return prod_mod;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/prod_mod.hpp
  requiredBy:
  - tools/is_prime.hpp
  - tools/prime_factorization.hpp
  - tools/totient.hpp
  - tools/pow_mod.hpp
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prime_factorization.test.cpp
  - tests/is_prime.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/prod_mod.hpp
layout: document
redirect_from:
- /library/tools/prod_mod.hpp
- /library/tools/prod_mod.hpp.html
title: tools/prod_mod.hpp
---
