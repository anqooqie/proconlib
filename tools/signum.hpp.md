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
  bundledCode: "#line 1 \"tools/signum.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  /**\n   * sign function\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T> type of input\n   * @param x input\n   * @return $-1$ if $x$\
    \ is negative, $1$ if $x$ is positive, $0$ if $x$ is zero\n   */\n  template <typename\
    \ T>\n  constexpr int signum(const T x) noexcept {\n    if constexpr (::std::is_signed_v<T>)\
    \ {\n      return (T(0) < x) - (x < T(0));\n    } else {\n      return T(0) <\
    \ x;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SIGNUM_HPP\n#define TOOLS_SIGNUM_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  /**\n   * sign function\n   * License: CC0\n   * @author\
    \ anqooqie\n   * @param <T> type of input\n   * @param x input\n   * @return $-1$\
    \ if $x$ is negative, $1$ if $x$ is positive, $0$ if $x$ is zero\n   */\n  template\
    \ <typename T>\n  constexpr int signum(const T x) noexcept {\n    if constexpr\
    \ (::std::is_signed_v<T>) {\n      return (T(0) < x) - (x < T(0));\n    } else\
    \ {\n      return T(0) < x;\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/signum.hpp
  requiredBy: []
  timestamp: '2021-03-28 15:49:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/signum.hpp
layout: document
redirect_from:
- /library/tools/signum.hpp
- /library/tools/signum.hpp.html
title: tools/signum.hpp
---
