---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: tools/extgcd.hpp
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: tools/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: tools/mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: tools/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: tools/prime_factorization.hpp
  - icon: ':warning:'
    path: tools/rich_pow_mod_cache.hpp
    title: tools/rich_pow_mod_cache.hpp
  - icon: ':warning:'
    path: tools/round.hpp
    title: tools/round.hpp
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: tools/totient.hpp
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
    \ tools {\n\n  /**\n   * returns quotient as integer division\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <M> type of lhs\n   * @param <N> type of rhs\n\
    \   * @param lhs $a$\n   * @param rhs $b$\n   * @return q, that satisfies $a =\
    \ qb + r$ and $0 \\leq r < |b|$\n   */\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n    if\
    \ (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n      if (rhs >= 0) {\n\
    \        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n        return (-lhs\
    \ - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_QUO_H\n#define TOOLS_QUO_H\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  /**\n   * returns quotient as integer division\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <M> type of lhs\n   * @param <N> type of rhs\n\
    \   * @param lhs $a$\n   * @param rhs $b$\n   * @return q, that satisfies $a =\
    \ qb + r$ and $0 \\leq r < |b|$\n   */\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n    if\
    \ (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n      if (rhs >= 0) {\n\
    \        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n        return (-lhs\
    \ - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/quo.hpp
  requiredBy:
  - tools/is_prime.hpp
  - tools/mod.hpp
  - tools/prime_factorization.hpp
  - tools/extgcd.hpp
  - tools/round.hpp
  - tools/rich_pow_mod_cache.hpp
  - tools/totient.hpp
  - tools/pow_mod.hpp
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extgcd.test.cpp
  - tests/prime_factorization.test.cpp
  - tests/is_prime.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/quo.hpp
layout: document
redirect_from:
- /library/tools/quo.hpp
- /library/tools/quo.hpp.html
title: tools/quo.hpp
---
