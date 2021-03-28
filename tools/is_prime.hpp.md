---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: tools/mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: tools/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: tools/prod_mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: tools/quo.hpp
  _extendedRequiredBy:
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
    links:
    - http://miller-rabin.appspot.com/
    - https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95
  bundledCode: "#line 1 \"tools/is_prime.hpp\"\n\n\n\n#include <cstdint>\n#include\
    \ <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  /**\n\
    \   * x * y (mod m)\n   * License: CC0\n   * @author anqooqie\n   * @param <T1>\
    \ type of x\n   * @param <T2> type of y\n   * @param <T3> type of m\n   * @param\
    \ x x\n   * @param y y\n   * @param m m\n   * @return x * y (mod m)\n   */\n \
    \ template <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const\
    \ T1 x, const T2 y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128\
    \ prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if\
    \ (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\
    \n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * returns quotient as integer division\n  \
    \ * License: CC0\n   * @author anqooqie\n   * @param <M> type of lhs\n   * @param\
    \ <N> type of rhs\n   * @param lhs $a$\n   * @param rhs $b$\n   * @return q, that\
    \ satisfies $a = qb + r$ and $0 \\leq r < |b|$\n   */\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N\
    \ rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n      if\
    \ (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n  \
    \      return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"\
    tools/mod.hpp\"\n\nnamespace tools {\n\n  /**\n   * returns minimum non-negative\
    \ reminder\n   * License: CC0\n   * @author anqooqie\n   * @param <M> type of\
    \ lhs\n   * @param <N> type of rhs\n   * @param lhs $a$\n   * @param rhs $b$\n\
    \   * @return r, that satisfies $a = qb + r$ and $0 \\leq r < |b|$\n   */\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  /**\n   * x ** y (mod m)\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T1> type of x\n   * @param <T2> type of y\n   * @param <T3> type\
    \ of m\n   * @param x x\n   * @param y y\n   * @param m m\n   * @return x ** y\
    \ (mod m)\n   */\n  template <typename T1, typename T2, typename T3>\n  constexpr\
    \ T3 pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3\
    \ r = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n &\
    \ 1) > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 8 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * check whether $n$ is a prime or not\n   *\
    \ License: CC0\n   * References:\n   * \u30DF\u30E9\u30FC-\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u6CD5 - Wikipedia ( https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95\
    \ )\n   * Deterministic variants of the Miller-Rabin primality test. Miller-Rabin\
    \ SPRP bases records ( http://miller-rabin.appspot.com/ )\n   *\n   * Usage:\n\
    \   * ```\n   * static_assert(tools::is_prime(P), \"P must be prime.\");\n   *\
    \ ```\n   *\n   * @author anqooqie\n   * @param n input\n   * @return `true` if\
    \ $n$ is a prime, and `false` if $n$ is not a prime\n   */\n  constexpr bool is_prime(const\
    \ ::std::uint_fast64_t n) {\n    constexpr ::std::array<::std::uint_fast64_t,\
    \ 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    if (n\
    \ <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return\
    \ false;\n\n    ::std::uint_fast64_t d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\
    \n    for (const ::std::uint_fast64_t a : bases) {\n      if (a % n == 0) return\
    \ true;\n\n      ::std::uint_fast64_t power = d;\n      ::std::uint_fast64_t target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_IS_PRIME_HPP\n#define TOOLS_IS_PRIME_HPP\n\n#include <cstdint>\n\
    #include <array>\n#include \"tools/prod_mod.hpp\"\n#include \"tools/pow_mod.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * check whether $n$ is a prime or not\n   *\
    \ License: CC0\n   * References:\n   * \u30DF\u30E9\u30FC-\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u6CD5 - Wikipedia ( https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95\
    \ )\n   * Deterministic variants of the Miller-Rabin primality test. Miller-Rabin\
    \ SPRP bases records ( http://miller-rabin.appspot.com/ )\n   *\n   * Usage:\n\
    \   * ```\n   * static_assert(tools::is_prime(P), \"P must be prime.\");\n   *\
    \ ```\n   *\n   * @author anqooqie\n   * @param n input\n   * @return `true` if\
    \ $n$ is a prime, and `false` if $n$ is not a prime\n   */\n  constexpr bool is_prime(const\
    \ ::std::uint_fast64_t n) {\n    constexpr ::std::array<::std::uint_fast64_t,\
    \ 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    if (n\
    \ <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return\
    \ false;\n\n    ::std::uint_fast64_t d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\
    \n    for (const ::std::uint_fast64_t a : bases) {\n      if (a % n == 0) return\
    \ true;\n\n      ::std::uint_fast64_t power = d;\n      ::std::uint_fast64_t target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/is_prime.hpp
  requiredBy:
  - tools/prime_factorization.hpp
  - tools/totient.hpp
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prime_factorization.test.cpp
  - tests/is_prime.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/is_prime.hpp
layout: document
redirect_from:
- /library/tools/is_prime.hpp
- /library/tools/is_prime.hpp.html
title: tools/is_prime.hpp
---
