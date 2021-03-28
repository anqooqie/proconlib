---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: tools/quo.hpp
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
  bundledCode: "#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"\
    tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  /**\n\
    \   * returns quotient as integer division\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <M> type of lhs\n   * @param <N> type of rhs\n   * @param lhs $a$\n\
    \   * @param rhs $b$\n   * @return q, that satisfies $a = qb + r$ and $0 \\leq\
    \ r < |b|$\n   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  /**\n\
    \   * returns minimum non-negative reminder\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <M> type of lhs\n   * @param <N> type of rhs\n   * @param lhs $a$\n\
    \   * @param rhs $b$\n   * @return r, that satisfies $a = qb + r$ and $0 \\leq\
    \ r < |b|$\n   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MOD_HPP\n#define TOOLS_MOD_HPP\n\n#include <type_traits>\n\
    #include \"tools/quo.hpp\"\n\nnamespace tools {\n\n  /**\n   * returns minimum\
    \ non-negative reminder\n   * License: CC0\n   * @author anqooqie\n   * @param\
    \ <M> type of lhs\n   * @param <N> type of rhs\n   * @param lhs $a$\n   * @param\
    \ rhs $b$\n   * @return r, that satisfies $a = qb + r$ and $0 \\leq r < |b|$\n\
    \   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/mod.hpp
  requiredBy:
  - tools/is_prime.hpp
  - tools/prime_factorization.hpp
  - tools/round.hpp
  - tools/rich_pow_mod_cache.hpp
  - tools/totient.hpp
  - tools/pow_mod.hpp
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prime_factorization.test.cpp
  - tests/is_prime.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/mod.hpp
layout: document
redirect_from:
- /library/tools/mod.hpp
- /library/tools/mod.hpp.html
title: tools/mod.hpp
---
