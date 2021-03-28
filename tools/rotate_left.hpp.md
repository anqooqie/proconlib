---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://blog.regehr.org/
    - https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523
    - https://stackoverflow.com/users/224132/peter-cordes
  bundledCode: "#line 1 \"tools/rotate_left.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <cstddef>\n#include <limits>\n#include <stdexcept>\n#include <string>\n\
    \nnamespace tools {\n\n  /**\n   * circular shift to the left\n   * License: CC\
    \ BY-SA 3.0\n   * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 5-bit circular shift to the left\n \
    \  * tools::rotate_left(x, 5);\n   * ```\n   *\n   * @author John Regehr ( https://blog.regehr.org/\
    \ )\n   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes\
    \ )\n   * @param <T> type of $value$\n   * @param value input\n   * @param count\
    \ shift distance\n   * @return `value` left-shifted by `input`-bit with a manner\
    \ of the circular shift\n   */\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T rotate_left(const T& value,\
    \ const ::std::size_t& count) noexcept {\n    return (value << (count & ::std::numeric_limits<T>::max()))\
    \ | (value >> (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));\n\
    \  }\n\n  /**\n   * circular shift to the left\n   * License: CC BY-SA 3.0\n \
    \  * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 5-bit circular shift to the left\n \
    \  * tools::rotate_left(x, 5);\n   * ```\n   *\n   * @author John Regehr ( https://blog.regehr.org/\
    \ )\n   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes\
    \ )\n   * @param <T> type of $value$\n   * @param value input\n   * @param count\
    \ shift distance\n   * @return `value` left-shifted by `input`-bit with a manner\
    \ of the circular shift\n   * @throws std::invalid_argument if `value` is negative\n\
    \   */\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  T rotate_left(const T& value, const ::std::size_t&\
    \ count) {\n    return value >= static_cast<T>(0)\n      ? static_cast<T>(::tools::rotate_left(static_cast<typename\
    \ ::std::make_unsigned<T>::type>(value), count))\n      : (throw ::std::invalid_argument(\"\
    value of tools::rotate_left must be non-negative, but was \" + ::std::to_string(value)\
    \ + \".\"));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ROTATE_LEFT_HPP\n#define TOOLS_ROTATE_LEFT_HPP\n\n#include\
    \ <type_traits>\n#include <cstddef>\n#include <limits>\n#include <stdexcept>\n\
    #include <string>\n\nnamespace tools {\n\n  /**\n   * circular shift to the left\n\
    \   * License: CC BY-SA 3.0\n   * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 5-bit circular shift to the left\n \
    \  * tools::rotate_left(x, 5);\n   * ```\n   *\n   * @author John Regehr ( https://blog.regehr.org/\
    \ )\n   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes\
    \ )\n   * @param <T> type of $value$\n   * @param value input\n   * @param count\
    \ shift distance\n   * @return `value` left-shifted by `input`-bit with a manner\
    \ of the circular shift\n   */\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T rotate_left(const T& value,\
    \ const ::std::size_t& count) noexcept {\n    return (value << (count & ::std::numeric_limits<T>::max()))\
    \ | (value >> (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));\n\
    \  }\n\n  /**\n   * circular shift to the left\n   * License: CC BY-SA 3.0\n \
    \  * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 5-bit circular shift to the left\n \
    \  * tools::rotate_left(x, 5);\n   * ```\n   *\n   * @author John Regehr ( https://blog.regehr.org/\
    \ )\n   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes\
    \ )\n   * @param <T> type of $value$\n   * @param value input\n   * @param count\
    \ shift distance\n   * @return `value` left-shifted by `input`-bit with a manner\
    \ of the circular shift\n   * @throws std::invalid_argument if `value` is negative\n\
    \   */\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  T rotate_left(const T& value, const ::std::size_t&\
    \ count) {\n    return value >= static_cast<T>(0)\n      ? static_cast<T>(::tools::rotate_left(static_cast<typename\
    \ ::std::make_unsigned<T>::type>(value), count))\n      : (throw ::std::invalid_argument(\"\
    value of tools::rotate_left must be non-negative, but was \" + ::std::to_string(value)\
    \ + \".\"));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rotate_left.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/rotate_left.hpp
layout: document
redirect_from:
- /library/tools/rotate_left.hpp
- /library/tools/rotate_left.hpp.html
title: tools/rotate_left.hpp
---
