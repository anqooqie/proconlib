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
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log.hpp
    title: $\left\lceil \log_b(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_sqrt.hpp
    title: $\left\lceil \sqrt{x} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  - icon: ':heavy_check_mark:'
    path: tools/mo.hpp
    title: Mo's algorithm
  - icon: ':warning:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/range_of_digit_products.hpp
    title: Range of digit products
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  - icon: ':heavy_check_mark:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
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
    path: tests/ceil.test.cpp
    title: tests/ceil.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_sqrt.test.cpp
    title: tests/ceil_sqrt.test.cpp
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
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
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
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rotate_right.test.cpp
    title: tests/rotate_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr\
    \ ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n    assert(rhs\
    \ != 0);\n    return lhs / rhs + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0))\
    \ && lhs % rhs);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_HPP\n#define TOOLS_CEIL_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n   \
    \ assert(rhs != 0);\n    return lhs / rhs + (((lhs > 0 && rhs > 0) || (lhs < 0\
    \ && rhs < 0)) && lhs % rhs);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ceil.hpp
  requiredBy:
  - tools/round.hpp
  - tools/mo.hpp
  - tools/rational.hpp
  - tools/rolling_hash.hpp
  - tools/segmented_sieve.hpp
  - tools/detail/rolling_hash.hpp
  - tools/ceil_sqrt.hpp
  - tools/range_of_digit_products.hpp
  - tools/ceil_kth_root.hpp
  - tools/bigint.hpp
  - tools/ceil_log.hpp
  - tools/pow_mod_cache.hpp
  - tools/dynamic_bitset.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/bigdecimal.hpp
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_sqrt.test.cpp
  - tests/ceil.test.cpp
  - tests/ceil_log.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/rotate_left.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/range_of_digit_products.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/plus.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/bezout.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/mo.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/segmented_sieve.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/rotate_right.test.cpp
documentation_of: tools/ceil.hpp
layout: document
title: $\left\lceil \frac{x}{y} \right\rceil$
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> ceil(M x, N y);
```

It returns $\left\lceil \frac{x}{y} \right\rceil$.

## Constraints
- $y \neq 0$
- $\lnot (x =$ `std::numeric_limits<std::common_type_t<M, N>>::min()` $\land\,y = -1)$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
