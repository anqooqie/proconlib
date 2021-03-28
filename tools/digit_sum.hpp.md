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
  bundledCode: "#line 1 \"tools/digit_sum.hpp\"\n\n\n\nnamespace tools {\n\n  /**\n\
    \   * sum of digits\n   * License: CC0\n   * @aurhor anqooqie\n   * @param n input\n\
    \   * @return sum of digits of `n`\n   */\n  template <typename T>\n  T digit_sum(T\
    \ n) {\n    T sum = 0;\n    for (; n > 0; n /= 10) {\n      sum += n % 10;\n \
    \   }\n    return sum;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DIGIT_SUM_HPP\n#define TOOLS_DIGIT_SUM_HPP\n\nnamespace tools\
    \ {\n\n  /**\n   * sum of digits\n   * License: CC0\n   * @aurhor anqooqie\n \
    \  * @param n input\n   * @return sum of digits of `n`\n   */\n  template <typename\
    \ T>\n  T digit_sum(T n) {\n    T sum = 0;\n    for (; n > 0; n /= 10) {\n   \
    \   sum += n % 10;\n    }\n    return sum;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/digit_sum.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/digit_sum.hpp
layout: document
redirect_from:
- /library/tools/digit_sum.hpp
- /library/tools/digit_sum.hpp.html
title: tools/digit_sum.hpp
---
