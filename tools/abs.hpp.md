---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/detail/polygon_and_triangle_2d.hpp
    title: tools/detail/polygon_and_triangle_2d.hpp
  - icon: ':warning:'
    path: tools/polygon_2d.hpp
    title: tools/polygon_2d.hpp
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: tools/triangle_2d.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/abs.hpp\"\n\n\n\n#include <cmath>\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ABS_HPP\n#define TOOLS_ABS_HPP\n\n#include <cmath>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/abs.hpp
  requiredBy:
  - tools/polygon_2d.hpp
  - tools/detail/polygon_and_triangle_2d.hpp
  - tools/triangle_2d.hpp
  timestamp: '2022-01-31 01:05:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/abs.hpp
layout: document
title: Unified interface for std::abs(x) and x.abs()
---

```cpp
(1)
template <typename T>
auto abs(T x) -> decltype(std::abs(x));

(2)
template <typename T>
auto abs(T x) -> decltype(x.abs());
```

It returns `std::abs(x)` if `std::abs(x)` is available.
In addition, it returns `x.abs()` if `x.abs()` is available.

## Constraints
- `std::abs(x)` or `x.abs()` is available

## Time Complexity
- (1)
    - $O(1)$
- (2)
    - Same as `x.abs()`

## License
- CC0

## Author
- anqooqie
