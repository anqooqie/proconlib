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
  bundledCode: "#line 1 \"tools/safe_diff.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <stdexcept>\n\nnamespace tools {\n\n  /**\n   * computes $A - B$ but handles\
    \ `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * License: CC0\n   * @author anqooqie\n   * @param <T> an\
    \ underlying set of the subtraction operation\n   * @param lhs left hand side\
    \ operand\n   * @param rhs right hand side operand\n   * @return $\\mathrm{lhs}\
    \ - \\mathrm{rhs}$ when we regard `std::numeric_limits<T>::max()` as $\\infty$\
    \ and `std::numeric_limits<T>::min()` as $-\\infty$\n   * @throws std::runtime_error\
    \ if $\\mathrm{lhs} - \\mathrm{rhs}$ is indefinite.\n   */\n  template <typename\
    \ T>\n  T safe_sum(const T& lhs, const T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::min()) return ::std::numeric_limits<T>::max();\n\
    \    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::max())\
    \ return ::std::numeric_limits<T>::min();\n    return lhs - rhs;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SAFE_DIFF_HPP\n#define TOOLS_SAFE_DIFF_HPP\n\n#include <limits>\n\
    #include <stdexcept>\n\nnamespace tools {\n\n  /**\n   * computes $A - B$ but\
    \ handles `std::numeric_limits<T>::max()` as $\\infty$ and `std::numeric_limits<T>::min()`\
    \ as $-\\infty$\n   * License: CC0\n   * @author anqooqie\n   * @param <T> an\
    \ underlying set of the subtraction operation\n   * @param lhs left hand side\
    \ operand\n   * @param rhs right hand side operand\n   * @return $\\mathrm{lhs}\
    \ - \\mathrm{rhs}$ when we regard `std::numeric_limits<T>::max()` as $\\infty$\
    \ and `std::numeric_limits<T>::min()` as $-\\infty$\n   * @throws std::runtime_error\
    \ if $\\mathrm{lhs} - \\mathrm{rhs}$ is indefinite.\n   */\n  template <typename\
    \ T>\n  T safe_sum(const T& lhs, const T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::min()) return ::std::numeric_limits<T>::max();\n\
    \    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::max())\
    \ return ::std::numeric_limits<T>::min();\n    return lhs - rhs;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/safe_diff.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/safe_diff.hpp
layout: document
redirect_from:
- /library/tools/safe_diff.hpp
- /library/tools/safe_diff.hpp.html
title: tools/safe_diff.hpp
---
