---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bigint/divides.test.cpp
    title: tests/bigint/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/minus.test.cpp
    title: tests/bigint/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/modulus.test.cpp
    title: tests/bigint/modulus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/multiplies.test.cpp
    title: tests/bigint/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/plus.test.cpp
    title: tests/bigint/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ssize.test.cpp
    title: tests/ssize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto\
    \ ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SSIZE_HPP\n#define TOOLS_SSIZE_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ssize.hpp
  requiredBy:
  - tools/bigint.hpp
  timestamp: '2021-11-27 17:23:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/permutation.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/ssize.test.cpp
documentation_of: tools/ssize.hpp
layout: document
title: Polyfill of std::ssize
---

```cpp
template <typename C>
constexpr auto ssize(const C& c) -> std::common_type_t<std::ptrdiff_t, std::make_signed_t<decltype(c.size())>>;
```

It is a compatible alternative of `std::ssize` in C++20.

## Constraints
- `c.size()` is defined.

## Time Complexity
- Same as the time complexity of `c.size()`.

## License
- CC0

## Author
- anqooqie
