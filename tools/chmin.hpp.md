---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  /**\n   * runs `lhs = std::min(lhs, rhs);`\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <M> type of lhs\n   * @param <N> type of rhs\n\
    \   * @param lhs left hand side operand\n   * @param rhs right hand side operand\n\
    \   * @return `true` if `lhs` has been updated, `false` otherwise\n   */\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool\
    \ updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_CHMIN_HPP\n#define TOOLS_CHMIN_HPP\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  /**\n   * runs `lhs = std::min(lhs, rhs);`\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <M> type of lhs\n   * @param <N> type\
    \ of rhs\n   * @param lhs left hand side operand\n   * @param rhs right hand side\
    \ operand\n   * @return `true` if `lhs` has been updated, `false` otherwise\n\
    \   */\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs)\
    \ {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/chmin.hpp
  requiredBy: []
  timestamp: '2021-03-20 18:55:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/chmin.hpp
layout: document
redirect_from:
- /library/tools/chmin.hpp
- /library/tools/chmin.hpp.html
title: tools/chmin.hpp
---
