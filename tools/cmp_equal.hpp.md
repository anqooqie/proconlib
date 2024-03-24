---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/suffix_array.hpp
    title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/suffix_array.test.cpp
    title: tests/suffix_array.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cmp_equal.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_equal(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t == u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? false : UT(t) == u;\n    } else {\n      return u <\
    \ 0 ? false : t == UU(u);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CMP_EQUAL_HPP\n#define TOOLS_CMP_EQUAL_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_equal(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t == u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? false : UT(t) == u;\n    } else {\n      return u <\
    \ 0 ? false : t == UU(u);\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cmp_equal.hpp
  requiredBy:
  - tools/suffix_array.hpp
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/suffix_array.test.cpp
documentation_of: tools/cmp_equal.hpp
layout: document
title: Polyfill of std::cmp_equal
---

```cpp
template <typename T, typename U>
constexpr bool cmp_equal(T t, U u) noexcept;
```

It is identical to `std::cmp_equal` in C++20.

## Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
