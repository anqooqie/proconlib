---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/binary_heap.hpp
    title: Binary heap
  - icon: ':heavy_check_mark:'
    path: tools/dual_segtree.hpp
    title: Dual segment tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/binary_heap.test.cpp
    title: tests/binary_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_POW2_HPP\n#define TOOLS_POW2_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/pow2.hpp
  requiredBy:
  - tools/dual_segtree.hpp
  - tools/binary_heap.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/binary_heap.test.cpp
  - tests/dual_segtree.test.cpp
documentation_of: tools/pow2.hpp
layout: document
title: $2^x$
---

```cpp
template <typename T>
constexpr T pow2(T x);
```

It returns $2^x$.

## Constraints
- $0 \leq x < $ `std::numeric_limits<T>::digits`

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
