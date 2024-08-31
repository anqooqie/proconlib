---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extend_input.hpp
    title: Extend operator>>
  - icon: ':heavy_check_mark:'
    path: tools/extend_output.hpp
    title: Extend operator<<
  - icon: ':question:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':x:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':x:'
    path: tools/stirling_1st.hpp
    title: Signed Stirling numbers of the first kind
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extend_input.test.cpp
    title: tests/extend_input.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extend_output.test.cpp
    title: tests/extend_output.test.cpp
  - icon: ':x:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multipoint_evaluation.test.cpp
    title: tests/polynomial/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
    title: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - icon: ':x:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/taylor_shift.test.cpp
    title: tests/polynomial/taylor_shift.test.cpp
  - icon: ':x:'
    path: tests/polynomial_interpolation.test.cpp
    title: tests/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/consistent.test.cpp
    title: tests/stirling_1st/consistent.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/fixed_k.test.cpp
    title: tests/stirling_1st/fixed_k.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/fixed_n.test.cpp
    title: tests/stirling_1st/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - tools/berlekamp_massey.hpp
  - tools/util.hpp
  - tools/extend_output.hpp
  - tools/polynomial.hpp
  - tools/bostan_mori.hpp
  - tools/stirling_1st.hpp
  - tools/polynomial_interpolation.hpp
  - tools/extend_input.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/extend_output.test.cpp
  - tests/extend_input.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/util.test.cpp
  - tests/has_mod.test.cpp
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

If an instance of `T` has the member function `mod()`, `tools::has_mod<T>::value` is `true`.
Otherwise, it is `false`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
