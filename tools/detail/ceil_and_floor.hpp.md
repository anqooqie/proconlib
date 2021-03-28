---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: tools/ceil.hpp
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log.hpp
    title: tools/ceil_log.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: tools/floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_log.hpp
    title: tools/floor_log.hpp
  - icon: ':warning:'
    path: tools/round.hpp
    title: tools/round.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  /**\n   * floor function\n   * License: CC0\n   * @author\
    \ anqooqie\n   * @param <M> type of `lhs`\n   * @param <N> type of `rhs`\n   *\
    \ @param lhs left hand side operand\n   * @param rhs right hand side operand\n\
    \   * @return $\\left\\lfloor \\frac{\\mathrm{lhs}}{\\mathrm{rhs}} \\right\\rfloor$\n\
    \   */\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DETAIL_CEIL_AND_FLOOR_HPP\n#define TOOLS_DETAIL_CEIL_AND_FLOOR_HPP\n\
    \n#include <type_traits>\n\nnamespace tools {\n\n  /**\n   * floor function\n\
    \   * License: CC0\n   * @author anqooqie\n   * @param <M> type of `lhs`\n   *\
    \ @param <N> type of `rhs`\n   * @param lhs left hand side operand\n   * @param\
    \ rhs right hand side operand\n   * @return $\\left\\lfloor \\frac{\\mathrm{lhs}}{\\\
    mathrm{rhs}} \\right\\rfloor$\n   */\n  template <typename M, typename N>\n  constexpr\
    \ ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs);\n\n  /**\n   *\
    \ ceiling function\n   * License: CC0\n   * @author anqooqie\n   * @param <M>\
    \ type of `lhs`\n   * @param <N> type of `rhs`\n   * @param lhs left hand side\
    \ operand\n   * @param rhs right hand side operand\n   * @return $\\left\\lceil\
    \ \\frac{\\mathrm{lhs}}{\\mathrm{rhs}} \\right\\rceil$\n   */\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const\
    \ N& rhs);\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        lhs / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n \
    \       ::tools::floor(-lhs, -rhs);\n  }\n  \n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs)\
    \ {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        (lhs - 1 + rhs) / rhs :\n\
    \      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs, rhs) :\n      lhs\
    \ >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n        ::tools::ceil(-lhs,\
    \ -rhs);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/detail/ceil_and_floor.hpp
  requiredBy:
  - tools/ceil_log.hpp
  - tools/floor_log.hpp
  - tools/round.hpp
  - tools/floor.hpp
  - tools/ceil.hpp
  timestamp: '2021-02-15 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor_log.test.cpp
  - tests/ceil_log.test.cpp
documentation_of: tools/detail/ceil_and_floor.hpp
layout: document
redirect_from:
- /library/tools/detail/ceil_and_floor.hpp
- /library/tools/detail/ceil_and_floor.hpp.html
title: tools/detail/ceil_and_floor.hpp
---
