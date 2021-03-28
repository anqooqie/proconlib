---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: tools/monoid.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: tools/pow.hpp
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: tools/totient.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\nnamespace\
    \ tools {\n  namespace monoid {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return static_cast<T>(1);\n      }\n   \
    \ };\n\n    template <typename Type>\n    struct gcd {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return static_cast<T>(0);\n  \
    \    }\n    };\n\n    template <typename Type, Type E>\n    struct update {\n\
    \      using T = Type;\n      static T op(const T lhs, const T rhs) {\n      \
    \  return rhs == E ? lhs : rhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools\
    \ {\n\n  /**\n   * calculates square\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <M> monoid\n   * @param x input\n   * @return $x^2$\n   */\n  template\
    \ <typename M>\n  typename M::T square(const typename M::T& x) {\n    return M::op(x,\
    \ x);\n  }\n\n  /**\n   * calculates square\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param <T> type of input\n   * @param x input\n   * @return $x^2$\n   */\n\
    \  template <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_SQUARE_HPP\n#define TOOLS_SQUARE_HPP\n\n#include \"tools/monoid.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * calculates square\n   * License: CC0\n  \
    \ * @author anqooqie\n   * @param <M> monoid\n   * @param x input\n   * @return\
    \ $x^2$\n   */\n  template <typename M>\n  typename M::T square(const typename\
    \ M::T& x) {\n    return M::op(x, x);\n  }\n\n  /**\n   * calculates square\n\
    \   * License: CC0\n   * @author anqooqie\n   * @param <T> type of input\n   *\
    \ @param x input\n   * @return $x^2$\n   */\n  template <typename T>\n  T square(const\
    \ T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n  }\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  isVerificationFile: false
  path: tools/square.hpp
  requiredBy:
  - tools/totient.hpp
  - tools/pow.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
documentation_of: tools/square.hpp
layout: document
redirect_from:
- /library/tools/square.hpp
- /library/tools/square.hpp.html
title: tools/square.hpp
---
