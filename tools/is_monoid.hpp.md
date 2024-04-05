---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/online_cumsum.hpp
    title: Online cumulative sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/is_monoid.test.cpp
    title: tests/is_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/online_cumsum.test.cpp
    title: tests/online_cumsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_monoid.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace tools {\n\n  template <typename M, typename = void>\n\
    \  struct is_monoid : ::std::false_type {};\n\n  template <typename M>\n  struct\
    \ is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename M::T, decltype(M::op(::std::declval<typename\
    \ M::T>(), ::std::declval<typename M::T>()))> &&\n    ::std::is_same_v<typename\
    \ M::T, decltype(M::e())>\n  , void>> : ::std::true_type {};\n\n  template <typename\
    \ M>\n  inline constexpr bool is_monoid_v = ::tools::is_monoid<M>::value;\n}\n\
    \n\n"
  code: "#ifndef TOOLS_IS_MONOID_HPP\n#define TOOLS_IS_MONOID_HPP\n\n#include <type_traits>\n\
    #include <utility>\n\nnamespace tools {\n\n  template <typename M, typename =\
    \ void>\n  struct is_monoid : ::std::false_type {};\n\n  template <typename M>\n\
    \  struct is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename M::T,\
    \ decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename M::T>()))>\
    \ &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n  , void>> : ::std::true_type\
    \ {};\n\n  template <typename M>\n  inline constexpr bool is_monoid_v = ::tools::is_monoid<M>::value;\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_monoid.hpp
  requiredBy:
  - tools/online_cumsum.hpp
  timestamp: '2024-03-23 15:55:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/online_cumsum.test.cpp
  - tests/is_monoid.test.cpp
documentation_of: tools/is_monoid.hpp
layout: document
title: Check whether T is a monoid
---

```cpp
template <typename M>
struct is_monoid {
  static constexpr bool value;
};

template <typename M>
inline constexpr bool is_monoid_v = is_monoid<M>::value;
```

If `<M>` satisfies the following conditions, `tools::is_monoid<M>::value` is `true`.

- `typename M::T` exists.
- The static member function `typename M::T M::op(typename M::T, typename M::T)` exists.
- The static member function `typename M::T M::e()` exists.

Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
