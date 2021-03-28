---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: tools/mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: tools/prod_mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: tools/quo.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: tools/is_prime.hpp
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
  bundledCode: "#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\
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
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace\
    \ tools {\n\n  /**\n   * x * y (mod m)\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T1> type of x\n   * @param <T2> type of y\n   * @param <T3> type\
    \ of m\n   * @param x x\n   * @param y y\n   * @param m m\n   * @return x * y\
    \ (mod m)\n   */\n  template <typename T1, typename T2, typename T3>\n  constexpr\
    \ T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128 = unsigned\
    \ __int128;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y)\
    \ % u128(m);\n    if (((x >= 0) ^ (y >= 0)) == 1) prod_mod = u128(m) - prod_mod;\n\
    \    return prod_mod;\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  /**\n   * x ** y (mod m)\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T1> type of x\n   * @param <T2> type of y\n   * @param <T3> type\
    \ of m\n   * @param x x\n   * @param y y\n   * @param m m\n   * @return x ** y\
    \ (mod m)\n   */\n  template <typename T1, typename T2, typename T3>\n  constexpr\
    \ T3 pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3\
    \ r = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n &\
    \ 1) > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_POW_MOD_HPP\n#define TOOLS_POW_MOD_HPP\n\n#include \"tools/mod.hpp\"\
    \n#include \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  /**\n   * x ** y (mod\
    \ m)\n   * License: CC0\n   * @author anqooqie\n   * @param <T1> type of x\n \
    \  * @param <T2> type of y\n   * @param <T3> type of m\n   * @param x x\n   *\
    \ @param y y\n   * @param m m\n   * @return x ** y (mod m)\n   */\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const T1 x,\
    \ T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x,\
    \ m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/prod_mod.hpp
  isVerificationFile: false
  path: tools/pow_mod.hpp
  requiredBy:
  - tools/is_prime.hpp
  - tools/prime_factorization.hpp
  - tools/totient.hpp
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prime_factorization.test.cpp
  - tests/is_prime.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/pow_mod.hpp
layout: document
redirect_from:
- /library/tools/pow_mod.hpp
- /library/tools/pow_mod.hpp.html
title: tools/pow_mod.hpp
---
