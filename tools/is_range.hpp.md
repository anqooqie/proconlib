---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/fill.test.cpp
    title: tests/fill.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_range.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <iterator>\n#include <utility>\n\nnamespace tools {\n  template <typename T,\
    \ typename = ::std::void_t<>>\n  struct is_range : ::std::false_type {};\n\n \
    \ template <typename T>\n  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()),\
    \ ::std::end(::std::declval<T>()))>> : ::std::true_type {};\n\n  template <typename\
    \ T>\n  inline constexpr bool is_range_v = ::tools::is_range<T>::value;\n}\n\n\
    \n"
  code: "#ifndef TOOLS_IS_RANGE_HPP\n#define TOOLS_IS_RANGE_HPP\n\n#include <type_traits>\n\
    #include <iterator>\n#include <utility>\n\nnamespace tools {\n  template <typename\
    \ T, typename = ::std::void_t<>>\n  struct is_range : ::std::false_type {};\n\n\
    \  template <typename T>\n  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()),\
    \ ::std::end(::std::declval<T>()))>> : ::std::true_type {};\n\n  template <typename\
    \ T>\n  inline constexpr bool is_range_v = ::tools::is_range<T>::value;\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_range.hpp
  requiredBy:
  - tools/util.hpp
  - tools/fill.hpp
  timestamp: '2022-11-23 11:35:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/fill.test.cpp
  - tests/util.test.cpp
documentation_of: tools/is_range.hpp
layout: document
title: Check whether T is a range type
---

```cpp
template <typename T>
struct is_range {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_range_v = is_range<T>::value;
```

If an instance of `T` can be passed to `std::begin` and `std::end`, `tools::is_range<T>::value` is `true`.
Otherwise, it is `false`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
