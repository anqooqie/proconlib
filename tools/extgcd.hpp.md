---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: tools/quo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extgcd.test.cpp
    title: tests/extgcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  /**\n   * returns quotient\
    \ as integer division\n   * License: CC0\n   * @author anqooqie\n   * @param <M>\
    \ type of lhs\n   * @param <N> type of rhs\n   * @param lhs $a$\n   * @param rhs\
    \ $b$\n   * @return q, that satisfies $a = qb + r$ and $0 \\leq r < |b|$\n   */\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const\
    \ M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else\
    \ {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      }\
    \ else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\
    \n#line 6 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  /**\n   * extended Euclidean\
    \ algorithm\n   * License: CC0\n   * Note: gcd in this function regards 0 as an\
    \ identity element, so gcd in this function can be treated as a monoid.\n   *\n\
    \   * Usage:\n   * ```\n   * // a * x0 + b * y0 = gcd\n   * const auto [x0, y0,\
    \ gcd] = tools::extgcd(a, b);\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <T> type of operands\n   * @param prev_r $a$\n   * @param r $b$\n   * @return\
    \ $\\[x0, y0, \\gcd(a, b)\\]$ which satisfies $a * x0 + b * y0 = \\gcd(a, b)$\n\
    \   */\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r)\
    \ {\n    T prev_s = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t = 1;\n    while\
    \ (r != 0) {\n      const T q = ::tools::quo(prev_r, r);\n      const T next_r\
    \ = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n      const T next_s\
    \ = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n      const T next_t\
    \ = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n    }\n\n    if (prev_r\
    \ < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t, prev_r};\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_EXTGCD_HPP\n#define TOOLS_EXTGCD_HPP\n\n#include <tuple>\n\
    #include \"tools/quo.hpp\"\n\nnamespace tools {\n\n  /**\n   * extended Euclidean\
    \ algorithm\n   * License: CC0\n   * Note: gcd in this function regards 0 as an\
    \ identity element, so gcd in this function can be treated as a monoid.\n   *\n\
    \   * Usage:\n   * ```\n   * // a * x0 + b * y0 = gcd\n   * const auto [x0, y0,\
    \ gcd] = tools::extgcd(a, b);\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <T> type of operands\n   * @param prev_r $a$\n   * @param r $b$\n   * @return\
    \ $\\[x0, y0, \\gcd(a, b)\\]$ which satisfies $a * x0 + b * y0 = \\gcd(a, b)$\n\
    \   */\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r)\
    \ {\n    T prev_s = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t = 1;\n    while\
    \ (r != 0) {\n      const T q = ::tools::quo(prev_r, r);\n      const T next_r\
    \ = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n      const T next_s\
    \ = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n      const T next_t\
    \ = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n    }\n\n    if (prev_r\
    \ < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t, prev_r};\n  }\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/extgcd.hpp
  requiredBy: []
  timestamp: '2021-03-28 15:53:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extgcd.test.cpp
documentation_of: tools/extgcd.hpp
layout: document
redirect_from:
- /library/tools/extgcd.hpp
- /library/tools/extgcd.hpp.html
title: tools/extgcd.hpp
---
