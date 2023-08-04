---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_sqrt.test.cpp
    title: tests/ceil_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/log_mod.test.cpp
    title: tests/log_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil_sqrt.hpp\"\n\n\n\n#include <cassert>\n#line 1\
    \ \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs /\
    \ rhs + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n\
    }\n\n\n#line 6 \"tools/ceil_sqrt.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T ceil_sqrt(const T n) {\n    assert(n >= 0);\n\n    if (n == 0) return\
    \ 0;\n\n    T ok = 1;\n    T ng;\n    for (ng = 2; ng - 1 < tools::ceil(n, ng\
    \ - 1); ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = ok + (ng -\
    \ ok) / 2;\n      if (mid - 1 < tools::ceil(n, mid - 1)) {\n        ok = mid;\n\
    \      } else {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\
    \n\n"
  code: "#ifndef TOOLS_CEIL_SQRT_HPP\n#define TOOLS_CEIL_SQRT_HPP\n\n#include <cassert>\n\
    #include \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n\
    \  T ceil_sqrt(const T n) {\n    assert(n >= 0);\n\n    if (n == 0) return 0;\n\
    \n    T ok = 1;\n    T ng;\n    for (ng = 2; ng - 1 < tools::ceil(n, ng - 1);\
    \ ng *= 2);\n\n    while (ng - ok > 1) {\n      const T mid = ok + (ng - ok) /\
    \ 2;\n      if (mid - 1 < tools::ceil(n, mid - 1)) {\n        ok = mid;\n    \
    \  } else {\n        ng = mid;\n      }\n    }\n\n    return ok;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/ceil_sqrt.hpp
  requiredBy:
  - tools/ceil_kth_root.hpp
  - tools/log_mod.hpp
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_kth_root.test.cpp
  - tests/ceil_sqrt.test.cpp
  - tests/log_mod.test.cpp
documentation_of: tools/ceil_sqrt.hpp
layout: document
title: $\left\lceil \sqrt{x} \right\rceil$
---

```cpp
template <typename T>
T ceil_sqrt(T x);
```

It returns $\left\lceil \sqrt{x} \right\rceil$.

## Constraints
- $x \geq 0$

## Time Complexity
- $O(\log x)$

## License
- CC0

## Author
- anqooqie
