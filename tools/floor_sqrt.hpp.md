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
  bundledCode: "#line 1 \"tools/floor_sqrt.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  /**\n   * computes $\\left\\lfloor \\sqrt{x} \\right\\rfloor$\n\
    \   * License: CC0\n   * @author anqooqie\n   * @param x input\n   * @return $\\\
    left\\lfloor \\sqrt{x} \\right\\rfloor$\n   */\n  template <typename T>\n  T floor_sqrt(T\
    \ n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T ng;\n    for (ng = 1; ng *\
    \ ng <= n; ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = (ok + ng)\
    \ / 2;\n      if (mid * mid <= n) {\n        ok = mid;\n      } else {\n     \
    \   ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_SQRT_HPP\n#define TOOLS_FLOOR_SQRT_HPP\n\n#include <cassert>\n\
    \nnamespace tools {\n\n  /**\n   * computes $\\left\\lfloor \\sqrt{x} \\right\\\
    rfloor$\n   * License: CC0\n   * @author anqooqie\n   * @param x input\n   * @return\
    \ $\\left\\lfloor \\sqrt{x} \\right\\rfloor$\n   */\n  template <typename T>\n\
    \  T floor_sqrt(T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T ng;\n    for\
    \ (ng = 1; ng * ng <= n; ng *= 2);\n\n    while (ng - ok > 1) {\n      const T\
    \ mid = (ok + ng) / 2;\n      if (mid * mid <= n) {\n        ok = mid;\n     \
    \ } else {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/floor_sqrt.hpp
  requiredBy: []
  timestamp: '2021-02-15 00:21:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/floor_sqrt.hpp
layout: document
redirect_from:
- /library/tools/floor_sqrt.hpp
- /library/tools/floor_sqrt.hpp.html
title: tools/floor_sqrt.hpp
---
