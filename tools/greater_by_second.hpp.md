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
  bundledCode: "#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace tools {\n\n  /**\n   * `std::greater` by second\n   * License: CC0\n\
    \   *\n   * Usage:\n   * ```\n   * std::vector<std::pair<i64, i64>> a;\n   * std::sort(a.begin(),\
    \ a.end(), tools::greater_by_second());\n   * ```\n   *\n   * @author anqooqie\n\
    \   */\n  class greater_by_second {\n  public:\n    template <class T1, class\
    \ T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_BY_SECOND_HPP\n#define TOOLS_GREATER_BY_SECOND_HPP\n\
    \n#include <utility>\n\nnamespace tools {\n\n  /**\n   * `std::greater` by second\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * std::vector<std::pair<i64,\
    \ i64>> a;\n   * std::sort(a.begin(), a.end(), tools::greater_by_second());\n\
    \   * ```\n   *\n   * @author anqooqie\n   */\n  class greater_by_second {\n \
    \ public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_by_second.hpp
  requiredBy: []
  timestamp: '2021-03-20 14:44:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/greater_by_second.hpp
layout: document
redirect_from:
- /library/tools/greater_by_second.hpp
- /library/tools/greater_by_second.hpp.html
title: tools/greater_by_second.hpp
---
