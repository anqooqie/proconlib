---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':question:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log.hpp
    title: $\left\lceil \log_b(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_quotients.hpp
    title: Enumerate the range of $\left\lceil \frac{A}{x} \right\rceil$
  - icon: ':question:'
    path: tools/ceil_sqrt.hpp
    title: $\left\lceil \sqrt{x} \right\rceil$
  - icon: ':x:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':x:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  - icon: ':x:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  - icon: ':x:'
    path: tools/mo.hpp
    title: Mo's algorithm
  - icon: ':x:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':x:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':x:'
    path: tools/range_of_digit_products.hpp
    title: Range of digit products
  - icon: ':question:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':x:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  - icon: ':x:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  - icon: ':x:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':x:'
    path: tools/zero_one_knapsack.hpp
    title: 0-1 knapsack problem
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
    path: tests/ceil.test.cpp
    title: tests/ceil.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_quotients.test.cpp
    title: tests/ceil_quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_sqrt.test.cpp
    title: tests/ceil_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':x:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':x:'
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  - icon: ':x:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':x:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':x:'
    path: tests/log_mod.test.cpp
    title: tests/log_mod.test.cpp
  - icon: ':x:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':x:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
  - icon: ':x:'
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':x:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':x:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':x:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':x:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':x:'
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  - icon: ':x:'
    path: tests/rotate_right.test.cpp
    title: tests/rotate_right.test.cpp
  - icon: ':x:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  - icon: ':x:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - icon: ':x:'
    path: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - icon: ':x:'
    path: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
    title: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr\
    \ ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M,\
    \ N>;\n    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs\
    \ > N(0)) || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_HPP\n#define TOOLS_CEIL_HPP\n\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n   \
    \ using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ceil.hpp
  requiredBy:
  - tools/rolling_hash.hpp
  - tools/round.hpp
  - tools/detail/rolling_hash.hpp
  - tools/ceil_sqrt.hpp
  - tools/dynamic_bitset.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/segmented_sieve.hpp
  - tools/ceil_log.hpp
  - tools/ceil_kth_root.hpp
  - tools/sparse_fps_pow.hpp
  - tools/bigint.hpp
  - tools/range_of_digit_products.hpp
  - tools/zero_one_knapsack.hpp
  - tools/mo.hpp
  - tools/bigdecimal.hpp
  - tools/rational.hpp
  - tools/log_mod.hpp
  - tools/ceil_quotients.hpp
  - tools/pow_mod_cache.hpp
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/range_of_digit_products.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/fastio/string.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/rotate_left.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/ceil_log.test.cpp
  - tests/has_mod.test.cpp
  - tests/segmented_sieve.test.cpp
  - tests/ceil.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/random.test.cpp
  - tests/ceil_sqrt.test.cpp
  - tests/bezout.test.cpp
  - tests/mo.test.cpp
  - tests/rotate_right.test.cpp
  - tests/ceil_quotients.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/log_mod.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  - tests/line_2d/projection.test.cpp
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
