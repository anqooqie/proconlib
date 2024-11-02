---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_greater_equal.hpp
    title: Polyfill of std::cmp_greater_equal
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less_equal.hpp
    title: Polyfill of std::cmp_less_equal
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/is_in_grid.test.cpp
    title: tests/is_in_grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_in_grid.hpp\"\n\n\n\n#include <cassert>\n#line\
    \ 1 \"tools/cmp_greater_equal.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\
    \n#include <type_traits>\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n    using UT\
    \ = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n  \
    \  if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/cmp_greater_equal.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T, typename U>\n  constexpr bool cmp_greater_equal(const\
    \ T t, const U u) noexcept {\n    return !::tools::cmp_less(t, u);\n  }\n}\n\n\
    \n#line 1 \"tools/cmp_less_equal.hpp\"\n\n\n\n#line 5 \"tools/cmp_less_equal.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less_equal(const\
    \ T t, const U u) noexcept {\n    return !::tools::cmp_less(u, t);\n  }\n}\n\n\
    \n#line 8 \"tools/is_in_grid.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T1, typename T2, typename T3, typename T4>\n  constexpr bool is_in_grid(const\
    \ T1 r, const T2 c, const T3 h, const T4 w) noexcept {\n    assert(::tools::cmp_greater_equal(h,\
    \ 0));\n    assert(::tools::cmp_greater_equal(w, 0));\n    return ::tools::cmp_less_equal(0,\
    \ r) && ::tools::cmp_less(r, h) && ::tools::cmp_less_equal(0, c) && ::tools::cmp_less(c,\
    \ w);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_IS_IN_GRID_HPP\n#define TOOLS_IS_IN_GRID_HPP\n\n#include <cassert>\n\
    #include \"tools/cmp_greater_equal.hpp\"\n#include \"tools/cmp_less_equal.hpp\"\
    \n#include \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename T1,\
    \ typename T2, typename T3, typename T4>\n  constexpr bool is_in_grid(const T1\
    \ r, const T2 c, const T3 h, const T4 w) noexcept {\n    assert(::tools::cmp_greater_equal(h,\
    \ 0));\n    assert(::tools::cmp_greater_equal(w, 0));\n    return ::tools::cmp_less_equal(0,\
    \ r) && ::tools::cmp_less(r, h) && ::tools::cmp_less_equal(0, c) && ::tools::cmp_less(c,\
    \ w);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/cmp_greater_equal.hpp
  - tools/cmp_less.hpp
  - tools/cmp_less_equal.hpp
  isVerificationFile: false
  path: tools/is_in_grid.hpp
  requiredBy: []
  timestamp: '2024-11-02 17:42:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/is_in_grid.test.cpp
documentation_of: tools/is_in_grid.hpp
layout: document
title: Check whether $(r, c)$ is in a grid of height $h$ and width $w$
---

```cpp
template <typename T1, typename T2, typename T3, typename T4>
bool is_in_grid(T1 r, T2 c, T3 h, T4 w);
```

It returns $0 \leq r < h \land 0 \leq c < w$.

### Constraints
- `<T1>` is an integral type.
- `<T2>` is an integral type.
- `<T3>` is an integral type.
- `<T4>` is an integral type.
- $h \geq 0$
- $w \geq 0$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
