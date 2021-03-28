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
  bundledCode: "#line 1 \"tools/to_signed.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  /**\n   * converts an unsigned integer into signed one\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * std::uint_fast64_t i;\n\
    \   * decltype(tools::to_signed(i)) // => std::int_fast64_t\n   * ```\n   *\n\
    \   * @author anqooqie\n   * @param <T> type of input\n   * @param x input\n \
    \  * @return `x` converted into signed type\n   */\n  template <typename T>\n\
    \  constexpr typename ::std::make_signed<T>::type to_signed(const T x) noexcept\
    \ {\n    return x;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TO_SIGNED_HPP\n#define TOOLS_TO_SIGNED_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  /**\n   * converts an unsigned integer into signed one\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * std::uint_fast64_t i;\n\
    \   * decltype(tools::to_signed(i)) // => std::int_fast64_t\n   * ```\n   *\n\
    \   * @author anqooqie\n   * @param <T> type of input\n   * @param x input\n \
    \  * @return `x` converted into signed type\n   */\n  template <typename T>\n\
    \  constexpr typename ::std::make_signed<T>::type to_signed(const T x) noexcept\
    \ {\n    return x;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/to_signed.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/to_signed.hpp
layout: document
redirect_from:
- /library/tools/to_signed.hpp
- /library/tools/to_signed.hpp.html
title: tools/to_signed.hpp
---
