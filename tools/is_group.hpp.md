---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/online_cumsum.hpp
    title: Online cumulative sum
  - icon: ':heavy_check_mark:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/is_group.test.cpp
    title: tests/is_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/online_cumsum.test.cpp
    title: tests/online_cumsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_group.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace tools {\n\n  template <typename G, typename = void>\n\
    \  struct is_group : ::std::false_type {};\n\n  template <typename G>\n  struct\
    \ is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename G::T, decltype(G::op(::std::declval<typename\
    \ G::T>(), ::std::declval<typename G::T>()))> &&\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::e())> &&\n    ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename\
    \ G::T>()))>\n  , void>> : ::std::true_type {};\n\n  template <typename G>\n \
    \ inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n}\n\n\n"
  code: "#ifndef TOOLS_IS_GROUP_HPP\n#define TOOLS_IS_GROUP_HPP\n\n#include <type_traits>\n\
    #include <utility>\n\nnamespace tools {\n\n  template <typename G, typename =\
    \ void>\n  struct is_group : ::std::false_type {};\n\n  template <typename G>\n\
    \  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename G::T,\
    \ decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename G::T>()))>\
    \ &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n  , void>> : ::std::true_type\
    \ {};\n\n  template <typename G>\n  inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_group.hpp
  requiredBy:
  - tools/sample_point_shift.hpp
  - tools/online_cumsum.hpp
  - tools/large_fact_mod_cache.hpp
  timestamp: '2024-03-23 15:55:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/online_cumsum.test.cpp
  - tests/is_group.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
documentation_of: tools/is_group.hpp
layout: document
title: Check whether T is a group
---

```cpp
template <typename G>
struct is_group {
  static constexpr bool value;
};

template <typename G>
inline constexpr bool is_group_v = is_group<G>::value;
```

If `<G>` satisfies the following conditions, `tools::is_group<G>::value` is `true`.

- `typename G::T` exists.
- The static member function `typename G::T G::op(typename G::T, typename G::T)` exists.
- The static member function `typename G::T G::e()` exists.
- The static member function `typename G::T G::inv(typename G::T)` exists.

Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
