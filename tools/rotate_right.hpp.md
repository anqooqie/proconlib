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
  bundledCode: "#line 1 \"tools/rotate_right.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <cstddef>\n#include <limits>\n#include <stdexcept>\n#include <string>\n\
    \nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T rotate_right(const T& value,\
    \ const ::std::size_t& count) noexcept {\n    return (value >> (count & ::std::numeric_limits<T>::max()))\
    \ | (value << (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));\n\
    \  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  T rotate_right(const T& value, const ::std::size_t&\
    \ count) {\n    return value >= static_cast<T>(0)\n      ? static_cast<T>(::tools::rotate_right(static_cast<typename\
    \ ::std::make_unsigned<T>::type>(value), count))\n      : (throw ::std::invalid_argument(\"\
    value of tools::rotate_right must be non-negative, but was \" + ::std::to_string(value)\
    \ + \".\"));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ROTATE_RIGHT_HPP\n#define TOOLS_ROTATE_RIGHT_HPP\n\n#include\
    \ <type_traits>\n#include <cstddef>\n#include <limits>\n#include <stdexcept>\n\
    #include <string>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T rotate_right(const T& value,\
    \ const ::std::size_t& count) noexcept {\n    return (value >> (count & ::std::numeric_limits<T>::max()))\
    \ | (value << (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));\n\
    \  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  T rotate_right(const T& value, const ::std::size_t&\
    \ count) {\n    return value >= static_cast<T>(0)\n      ? static_cast<T>(::tools::rotate_right(static_cast<typename\
    \ ::std::make_unsigned<T>::type>(value), count))\n      : (throw ::std::invalid_argument(\"\
    value of tools::rotate_right must be non-negative, but was \" + ::std::to_string(value)\
    \ + \".\"));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rotate_right.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/rotate_right.hpp
layout: document
title: Circular shift to the right
---

```cpp
template <typename T>
T rotate_right(T value, std::size_t count);
```

It returns `value` right-shifted by `input`-bit with a manner of the circular shift.

## Usage
```cpp
// 5-bit circular shift to the right
tools::rotate_right(x, 5);
```

## References
- [Stack Overflow](https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523)

## License
- CC BY-SA 3.0

## Authors
- [John Regehr](https://blog.regehr.org/)
- [Peter Cordes](https://stackoverflow.com/users/224132/peter-cordes)
