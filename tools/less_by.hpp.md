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
  bundledCode: "#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  /**\n\
    \   * `std::less` by key\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   *\
    \ std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x);\
    \ }));\n   * ```\n   *\n   * @author anqooqie\n   * @param <F> type of selector\n\
    \   */\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\
    \n  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_HPP\n#define TOOLS_LESS_BY_HPP\n\nnamespace tools {\n\
    \n  /**\n   * `std::less` by key\n   * License: CC0\n   *\n   * Usage:\n   * ```\n\
    \   * std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x);\
    \ }));\n   * ```\n   *\n   * @author anqooqie\n   * @param <F> type of selector\n\
    \   */\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\
    \n  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/less_by.hpp
layout: document
redirect_from:
- /library/tools/less_by.hpp
- /library/tools/less_by.hpp.html
title: tools/less_by.hpp
---
