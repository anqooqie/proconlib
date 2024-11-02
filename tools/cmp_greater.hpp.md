---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cmp_greater.test.cpp
    title: tests/cmp_greater.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cmp_greater.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n    using UT\
    \ = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n  \
    \  if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/cmp_greater.hpp\"\n\nnamespace tools {\n \
    \ template <typename T, typename U>\n  constexpr bool cmp_greater(const T t, const\
    \ U u) noexcept {\n    return ::tools::cmp_less(u, t);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CMP_GREATER_HPP\n#define TOOLS_CMP_GREATER_HPP\n\n#include\
    \ \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_greater(const T t, const U u) noexcept {\n    return\
    \ ::tools::cmp_less(u, t);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/cmp_greater.hpp
  requiredBy: []
  timestamp: '2024-11-02 17:20:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cmp_greater.test.cpp
documentation_of: tools/cmp_greater.hpp
layout: document
title: Polyfill of std::cmp_greater
---

```cpp
template <typename T, typename U>
constexpr bool cmp_greater(T t, U u) noexcept;
```

It is identical to `std::cmp_greater` in C++20.

### Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
