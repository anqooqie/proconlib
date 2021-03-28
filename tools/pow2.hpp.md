---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/dual_segtree.hpp
    title: tools/dual_segtree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  /**\n   * power of two\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <T> type of the operand\n   * @param x exponent\n\
    \   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  /**\n   * power of two\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <T> type of the operand\n   * @param x exponent\n\
    \   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_POW2_HPP\n#define TOOLS_POW2_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  /**\n   * power of two\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <T> type of the operand\n   * @param\
    \ x exponent\n   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  /**\n   * power of two\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <T> type of the operand\n   * @param x exponent\n\
    \   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/pow2.hpp
  requiredBy:
  - tools/dual_segtree.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/pow2.hpp
layout: document
redirect_from:
- /library/tools/pow2.hpp
- /library/tools/pow2.hpp.html
title: tools/pow2.hpp
---
