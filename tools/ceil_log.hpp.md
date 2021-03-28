---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: tools/ceil.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil_log.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\
    \n\n\n\n#line 5 \"tools/detail/ceil_and_floor.hpp\"\n\nnamespace tools {\n\n \
    \ /**\n   * floor function\n   * License: CC0\n   * @author anqooqie\n   * @param\
    \ <M> type of `lhs`\n   * @param <N> type of `rhs`\n   * @param lhs left hand\
    \ side operand\n   * @param rhs right hand side operand\n   * @return $\\left\\\
    lfloor \\frac{\\mathrm{lhs}}{\\mathrm{rhs}} \\right\\rfloor$\n   */\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs);\n\n  /**\n   * ceiling function\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <M> type of `lhs`\n   * @param <N> type of\
    \ `rhs`\n   * @param lhs left hand side operand\n   * @param rhs right hand side\
    \ operand\n   * @return $\\left\\lceil \\frac{\\mathrm{lhs}}{\\mathrm{rhs}} \\\
    right\\rceil$\n   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \n#line 7 \"tools/ceil_log.hpp\"\n\nnamespace tools {\n\n  /**\n   * ceil of logarithm\n\
    \   * License: CC0\n   * @author anqooqie\n   * @param <M> type of base\n   *\
    \ @param <N> type of antilogarithm\n   * @param base $b$\n   * @param antilogarithm\
    \ $x$\n   * @return $\\left\\lceil \\log_b(x) \\right\\rceil$\n   */\n  template\
    \ <typename M, typename N>\n  ::std::common_type_t<M, N> ceil_log(const M& base,\
    \ const N& antilogarithm) {\n    assert(2 <= base && base <= 1000000000000000000);\n\
    \    assert(1 <= antilogarithm && antilogarithm <= 1000000000000000000);\n\n \
    \   const ::std::common_type_t<M, N> threshold = tools::ceil(antilogarithm, base);\n\
    \    ::std::common_type_t<M, N> logarithm = 0;\n    for (::std::common_type_t<M,\
    \ N> pow = 1; pow < antilogarithm; pow = (pow < threshold ? pow * base : antilogarithm))\
    \ {\n      ++logarithm;\n    }\n\n    return logarithm;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_LOG_HPP\n#define TOOLS_CEIL_LOG_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n#include \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  /**\n\
    \   * ceil of logarithm\n   * License: CC0\n   * @author anqooqie\n   * @param\
    \ <M> type of base\n   * @param <N> type of antilogarithm\n   * @param base $b$\n\
    \   * @param antilogarithm $x$\n   * @return $\\left\\lceil \\log_b(x) \\right\\\
    rceil$\n   */\n  template <typename M, typename N>\n  ::std::common_type_t<M,\
    \ N> ceil_log(const M& base, const N& antilogarithm) {\n    assert(2 <= base &&\
    \ base <= 1000000000000000000);\n    assert(1 <= antilogarithm && antilogarithm\
    \ <= 1000000000000000000);\n\n    const ::std::common_type_t<M, N> threshold =\
    \ tools::ceil(antilogarithm, base);\n    ::std::common_type_t<M, N> logarithm\
    \ = 0;\n    for (::std::common_type_t<M, N> pow = 1; pow < antilogarithm; pow\
    \ = (pow < threshold ? pow * base : antilogarithm)) {\n      ++logarithm;\n  \
    \  }\n\n    return logarithm;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: false
  path: tools/ceil_log.hpp
  requiredBy: []
  timestamp: '2021-03-07 02:52:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_log.test.cpp
documentation_of: tools/ceil_log.hpp
layout: document
redirect_from:
- /library/tools/ceil_log.hpp
- /library/tools/ceil_log.hpp.html
title: tools/ceil_log.hpp
---
