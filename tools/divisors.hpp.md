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
  bundledCode: "#line 1 \"tools/divisors.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cmath>\n#include <algorithm>\n#include <iterator>\n\nnamespace tools {\n\n\
    \  /**\n   * gets all divisors\n   * License: CC0\n   * @author anqooqie\n   *\
    \ @param <T> type of input\n   * @param n input\n   * @return all divisors of\
    \ $n$\n   */\n  template <typename T>\n  ::std::vector<T> divisors(const T& n)\
    \ {\n    ::std::vector<T> head;\n    ::std::vector<T> tail;\n\n    T i;\n    for\
    \ (i = static_cast<T>(1); i * i < n; ++i) {\n      if (n % i == static_cast<T>(0))\
    \ {\n        head.push_back(i);\n        tail.push_back(n / i);\n      }\n   \
    \ }\n\n    // if n is a square number\n    if (i * i == n) {\n      head.push_back(i);\n\
    \    }\n\n    ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));\n\
    \    return head;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DIVISORS_HPP\n#define TOOLS_DIVISORS_HPP\n\n#include <vector>\n\
    #include <cmath>\n#include <algorithm>\n#include <iterator>\n\nnamespace tools\
    \ {\n\n  /**\n   * gets all divisors\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T> type of input\n   * @param n input\n   * @return all divisors\
    \ of $n$\n   */\n  template <typename T>\n  ::std::vector<T> divisors(const T&\
    \ n) {\n    ::std::vector<T> head;\n    ::std::vector<T> tail;\n\n    T i;\n \
    \   for (i = static_cast<T>(1); i * i < n; ++i) {\n      if (n % i == static_cast<T>(0))\
    \ {\n        head.push_back(i);\n        tail.push_back(n / i);\n      }\n   \
    \ }\n\n    // if n is a square number\n    if (i * i == n) {\n      head.push_back(i);\n\
    \    }\n\n    ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));\n\
    \    return head;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/divisors.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/divisors.hpp
layout: document
redirect_from:
- /library/tools/divisors.hpp
- /library/tools/divisors.hpp.html
title: tools/divisors.hpp
---
