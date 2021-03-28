---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: tools/ceil.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: tools/floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: tools/mod.hpp
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: tools/quo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/round.hpp\"\n\n\n\n#include <cstdlib>\n#line 1 \"\
    tools/ceil.hpp\"\n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace tools {\n\n  /**\n   * floor function\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <M> type of `lhs`\n   * @param <N> type\
    \ of `rhs`\n   * @param lhs left hand side operand\n   * @param rhs right hand\
    \ side operand\n   * @return $\\left\\lfloor \\frac{\\mathrm{lhs}}{\\mathrm{rhs}}\
    \ \\right\\rfloor$\n   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  /**\n   * ceiling function\n   *\
    \ License: CC0\n   * @author anqooqie\n   * @param <M> type of `lhs`\n   * @param\
    \ <N> type of `rhs`\n   * @param lhs left hand side operand\n   * @param rhs right\
    \ hand side operand\n   * @return $\\left\\lceil \\frac{\\mathrm{lhs}}{\\mathrm{rhs}}\
    \ \\right\\rceil$\n   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs);\n  \n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs) {\n\
    \    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs / rhs :\n      lhs < 0\
    \ && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n      lhs >= 0 && rhs <\
    \ 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs, -rhs);\n\
    \  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 1 \"tools/floor.hpp\"\n\n\n\n#line 5 \"tools/floor.hpp\"\n\n\n#line 1\
    \ \"tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
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
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 8 \"tools/round.hpp\"\n\nnamespace tools\
    \ {\n\n  /**\n   * banker's rounding function\n   * License: CC0\n   * @author\
    \ anqooqie\n   * @param <T> type of the operands\n   * @param lhs left hand side\
    \ operand\n   * @param rhs right hand side operand\n   * @return rounded value\
    \ of $\\frac{\\mathrm{lhs}}{\\mathrm{rhs}}$ with the manner of banker's rounding\n\
    \   */\n  template <typename T>\n  constexpr T round(const T lhs, const T rhs)\
    \ {\n    return ::std::abs(rhs) % 2 == 0\n      ? ::tools::mod(lhs, rhs) == ::std::abs(rhs)\
    \ / 2\n        ? ::tools::floor(lhs, rhs) % 2 == 0\n          ? ::tools::floor(lhs,\
    \ rhs)\n          : ::tools::ceil(lhs, rhs)\n        : ::tools::mod(lhs, rhs)\
    \ < ::std::abs(rhs) / 2\n          ? ::tools::floor(lhs, rhs)\n          : ::tools::ceil(lhs,\
    \ rhs)\n      : ::tools::mod(lhs, rhs) <= ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs,\
    \ rhs)\n        : ::tools::ceil(lhs, rhs);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ROUND_HPP\n#define TOOLS_ROUND_HPP\n\n#include <cstdlib>\n\
    #include \"tools/ceil.hpp\"\n#include \"tools/floor.hpp\"\n#include \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * banker's rounding function\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <T> type of the operands\n   * @param\
    \ lhs left hand side operand\n   * @param rhs right hand side operand\n   * @return\
    \ rounded value of $\\frac{\\mathrm{lhs}}{\\mathrm{rhs}}$ with the manner of banker's\
    \ rounding\n   */\n  template <typename T>\n  constexpr T round(const T lhs, const\
    \ T rhs) {\n    return ::std::abs(rhs) % 2 == 0\n      ? ::tools::mod(lhs, rhs)\
    \ == ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs) % 2 == 0\n      \
    \    ? ::tools::floor(lhs, rhs)\n          : ::tools::ceil(lhs, rhs)\n       \
    \ : ::tools::mod(lhs, rhs) < ::std::abs(rhs) / 2\n          ? ::tools::floor(lhs,\
    \ rhs)\n          : ::tools::ceil(lhs, rhs)\n      : ::tools::mod(lhs, rhs) <=\
    \ ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs)\n        : ::tools::ceil(lhs,\
    \ rhs);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  - tools/floor.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/round.hpp
  requiredBy: []
  timestamp: '2021-03-20 18:59:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/round.hpp
layout: document
redirect_from:
- /library/tools/round.hpp
- /library/tools/round.hpp.html
title: tools/round.hpp
---
