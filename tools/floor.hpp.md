---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/floor_log.hpp
    title: tools/floor_log.hpp
  - icon: ':warning:'
    path: tools/round.hpp
    title: tools/round.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor.hpp\"\n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  /**\n   * floor function\n\
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
    \ -rhs);\n  }\n}\n\n\n#line 5 \"tools/floor.hpp\"\n\n\n"
  code: '#ifndef TOOLS_FLOOR_HPP

    #define TOOLS_FLOOR_HPP


    #include "tools/detail/ceil_and_floor.hpp"


    #endif

    '
  dependsOn:
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: false
  path: tools/floor.hpp
  requiredBy:
  - tools/floor_log.hpp
  - tools/round.hpp
  timestamp: '2021-02-15 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor_log.test.cpp
documentation_of: tools/floor.hpp
layout: document
redirect_from:
- /library/tools/floor.hpp
- /library/tools/floor.hpp.html
title: tools/floor.hpp
---
