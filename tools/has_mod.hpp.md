---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extend_input.hpp
    title: Extend operator>>
  - icon: ':heavy_check_mark:'
    path: tools/extend_output.hpp
    title: Extend operator<<
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extend_input.test.cpp
    title: tests/extend_input.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extend_output.test.cpp
    title: tests/extend_output.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/has_mod.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace tools {\n  template <typename T, typename = ::std::void_t<>>\n\
    \  struct has_mod : ::std::false_type {};\n\n  template <typename T>\n  struct\
    \ has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type\
    \ {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;\n\
    }\n\n\n"
  code: "#ifndef TOOLS_HAS_MOD_HPP\n#define TOOLS_HAS_MOD_HPP\n\n#include <type_traits>\n\
    #include <utility>\n\nnamespace tools {\n  template <typename T, typename = ::std::void_t<>>\n\
    \  struct has_mod : ::std::false_type {};\n\n  template <typename T>\n  struct\
    \ has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type\
    \ {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/has_mod.hpp
  requiredBy:
  - tools/extend_input.hpp
  - tools/util.hpp
  - tools/polynomial.hpp
  - tools/extend_output.hpp
  - tools/bostan_mori.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extend_input.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/extend_output.test.cpp
  - tests/has_mod.test.cpp
  - tests/util.test.cpp
documentation_of: tools/has_mod.hpp
layout: document
title: Check whether T has the member function mod()
---

```cpp
template <typename T>
struct has_mod {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool has_mod_v = has_mod<T>::value;
```

`tools::has_mod<T>::value` will be `true` if `T` has the member function `mod()`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
