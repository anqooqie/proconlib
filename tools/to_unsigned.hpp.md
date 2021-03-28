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
  bundledCode: "#line 1 \"tools/to_unsigned.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  /**\n   * converts a signed integer into unsigned one\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * std::int_fast64_t i;\n \
    \  * decltype(tools::to_unsigned(i)) // => std::uint_fast64_t\n   * ```\n   *\n\
    \   * @author anqooqie\n   * @param <T> type of input\n   * @param x input\n \
    \  * @return `x` converted into unsigned type\n   */\n  template <typename T>\n\
    \  constexpr typename ::std::make_unsigned<T>::type to_unsigned(const T x) noexcept\
    \ {\n    return x;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TO_UNSIGNED_HPP\n#define TOOLS_TO_UNSIGNED_HPP\n\n#include\
    \ <type_traits>\n\nnamespace tools {\n\n  /**\n   * converts a signed integer\
    \ into unsigned one\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * std::int_fast64_t\
    \ i;\n   * decltype(tools::to_unsigned(i)) // => std::uint_fast64_t\n   * ```\n\
    \   *\n   * @author anqooqie\n   * @param <T> type of input\n   * @param x input\n\
    \   * @return `x` converted into unsigned type\n   */\n  template <typename T>\n\
    \  constexpr typename ::std::make_unsigned<T>::type to_unsigned(const T x) noexcept\
    \ {\n    return x;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/to_unsigned.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/to_unsigned.hpp
layout: document
redirect_from:
- /library/tools/to_unsigned.hpp
- /library/tools/to_unsigned.hpp.html
title: tools/to_unsigned.hpp
---
