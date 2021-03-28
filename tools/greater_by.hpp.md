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
  bundledCode: "#line 1 \"tools/greater_by.hpp\"\n\n\n\nnamespace tools {\n\n  /**\n\
    \   * `std::greater` by key\n   * License: CC0\n   *\n   * Usage:\n   * ```\n\
    \   * std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) { return std::abs(x);\
    \ }));\n   * ```\n   *\n   * @author anqooqie\n   * @param <F> type of selector\n\
    \   */\n  template <class F>\n  class greater_by {\n  private:\n    F selector;\n\
    \n  public:\n    greater_by(const F& selector) : selector(selector) {\n    }\n\
    \n    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) > selector(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_BY_HPP\n#define TOOLS_GREATER_BY_HPP\n\nnamespace tools\
    \ {\n\n  /**\n   * `std::greater` by key\n   * License: CC0\n   *\n   * Usage:\n\
    \   * ```\n   * std::sort(a.begin(), a.end(), tools::greater_by([](int a_i) {\
    \ return std::abs(x); }));\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <F> type of selector\n   */\n  template <class F>\n  class greater_by {\n  private:\n\
    \    F selector;\n\n  public:\n    greater_by(const F& selector) : selector(selector)\
    \ {\n    }\n\n    template <class T>\n    bool operator()(const T& x, const T&\
    \ y) const {\n      return selector(x) > selector(y);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_by.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/greater_by.hpp
layout: document
redirect_from:
- /library/tools/greater_by.hpp
- /library/tools/greater_by.hpp.html
title: tools/greater_by.hpp
---
