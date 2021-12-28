---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/binary_heap.hpp
    title: Binary heap
  - icon: ':heavy_check_mark:'
    path: tools/disjoint_sparse_table.hpp
    title: Disjoint sparse table
  - icon: ':heavy_check_mark:'
    path: tools/divisors.hpp
    title: List all divisors
  - icon: ':heavy_check_mark:'
    path: tools/dual_segtree.hpp
    title: Dual segment tree
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':heavy_check_mark:'
    path: tools/lca.hpp
    title: Lowest common ancestor
  - icon: ':heavy_check_mark:'
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/binary_heap.test.cpp
    title: tests/binary_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/disjoint_sparse_table.test.cpp
    title: tests/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/divisors.test.cpp
    title: tests/divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lca.test.cpp
    title: tests/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree.test.cpp
    title: tests/li_chao_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prime_factorization.test.cpp
    title: tests/prime_factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ssize.test.cpp
    title: tests/ssize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
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
  - tools/lca.hpp
  - tools/prime_factorization.hpp
  - tools/li_chao_segtree.hpp
  - tools/extended_lucas.hpp
  - tools/binary_heap.hpp
  - tools/dual_segtree.hpp
  - tools/divisors.hpp
  - tools/disjoint_sparse_table.hpp
  - tools/tetration_mod.hpp
  - tools/totient.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/prime_factorization.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/divisors.test.cpp
  - tests/lca.test.cpp
  - tests/ssize.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/dual_segtree.test.cpp
  - tests/disjoint_sparse_table.test.cpp
  - tests/li_chao_segtree.test.cpp
  - tests/binary_heap.test.cpp
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