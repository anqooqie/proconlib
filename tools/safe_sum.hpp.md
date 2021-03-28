---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bellman_ford.hpp
    title: tools/bellman_ford.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bellman_ford.test.cpp
    title: tests/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/safe_sum.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <stdexcept>\n\nnamespace tools {\n\n  /**\n   * computes $A + B$ but handles\
    \ `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * License: CC0\n   * @author anqooqie\n   * @param <T> an\
    \ underlying set of the sum operation\n   * @param lhs left hand side operand\n\
    \   * @param rhs right hand side operand\n   * @return $\\mathrm{lhs} + \\mathrm{rhs}$\
    \ when we regard `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * @throws std::runtime_error if $\\mathrm{lhs} + \\mathrm{rhs}$\
    \ is indefinite.\n   */\n  template <typename T>\n  T safe_sum(const T& lhs, const\
    \ T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::max())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::min()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::min())\
    \ return ::std::numeric_limits<T>::min();\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::max()) return ::std::numeric_limits<T>::max();\n\
    \    return lhs + rhs;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SAFE_SUM_HPP\n#define TOOLS_SAFE_SUM_HPP\n\n#include <limits>\n\
    #include <stdexcept>\n\nnamespace tools {\n\n  /**\n   * computes $A + B$ but\
    \ handles `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * License: CC0\n   * @author anqooqie\n   * @param <T> an\
    \ underlying set of the sum operation\n   * @param lhs left hand side operand\n\
    \   * @param rhs right hand side operand\n   * @return $\\mathrm{lhs} + \\mathrm{rhs}$\
    \ when we regard `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * @throws std::runtime_error if $\\mathrm{lhs} + \\mathrm{rhs}$\
    \ is indefinite.\n   */\n  template <typename T>\n  T safe_sum(const T& lhs, const\
    \ T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::max())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::min()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::min())\
    \ return ::std::numeric_limits<T>::min();\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::max()) return ::std::numeric_limits<T>::max();\n\
    \    return lhs + rhs;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/safe_sum.hpp
  requiredBy:
  - tools/bellman_ford.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bellman_ford.test.cpp
documentation_of: tools/safe_sum.hpp
layout: document
redirect_from:
- /library/tools/safe_sum.hpp
- /library/tools/safe_sum.hpp.html
title: tools/safe_sum.hpp
---
