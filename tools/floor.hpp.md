---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_log.hpp
    title: $\left\lfloor \log_b(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/cast_to_long_long.test.cpp
    title: tests/bigdecimal/cast_to_long_long.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/divides.test.cpp
    title: tests/bigdecimal/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/hand.test.cpp
    title: tests/bigdecimal/hand.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/minus.test.cpp
    title: tests/bigdecimal/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/multiplies.test.cpp
    title: tests/bigdecimal/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/plus.test.cpp
    title: tests/bigdecimal/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/random.test.cpp
    title: tests/bigdecimal/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/rounding.test.cpp
    title: tests/bigdecimal/rounding.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/divides.test.cpp
    title: tests/bigint/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/minus.test.cpp
    title: tests/bigint/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/modulus.test.cpp
    title: tests/bigint/modulus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/multiplies.test.cpp
    title: tests/bigint/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/plus.test.cpp
    title: tests/bigint/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor.test.cpp
    title: tests/floor.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr\
    \ ::std::common_type_t<M, N> floor(const M lhs, const N rhs) {\n    using T =\
    \ ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return lhs / rhs\
    \ - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs > N(0))) && lhs % rhs);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_HPP\n#define TOOLS_FLOOR_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M lhs, const N rhs) {\n  \
    \  using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs > N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/floor.hpp
  requiredBy:
  - tools/modint_for_rolling_hash.hpp
  - tools/floor_log.hpp
  - tools/bigint.hpp
  - tools/rational.hpp
  - tools/round.hpp
  - tools/bigdecimal.hpp
  - tools/pow_mod_cache.hpp
  - tools/rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/has_mod.test.cpp
  - tests/floor_log.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/fastio/string.test.cpp
  - tests/bezout.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/line_2d/projection.test.cpp
documentation_of: tools/floor.hpp
layout: document
title: $\left\lfloor \frac{x}{y} \right\rfloor$
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> floor(M x, N y);
```

It returns $\left\lfloor \frac{x}{y} \right\rfloor$.

## Constraints
- $y \neq 0$
- $\lnot (x =$ `std::numeric_limits<std::common_type_t<M, N>>::min()` $\land\,y = -1)$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
