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
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':question:'
    path: tools/fact_mod_cache.hpp
    title: Precompute $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P},
      {}_n P_r \pmod{P}$
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':heavy_check_mark:'
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  - icon: ':heavy_check_mark:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/partition_function.hpp
    title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j)
      \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':question:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':x:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  - icon: ':heavy_check_mark:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  _extendedVerifiedWith:
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
    path: tests/fact_mod_cache.test.cpp
    title: tests/fact_mod_cache.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod1000000007.test.cpp
    title: tests/fps/exp_mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod998244353.test.cpp
    title: tests/fps/exp_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/inv_mod1000000007.test.cpp
    title: tests/fps/inv_mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/inv_mod998244353.test.cpp
    title: tests/fps/inv_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/log_mod1000000007.test.cpp
    title: tests/fps/log_mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/log_mod998244353.test.cpp
    title: tests/fps/log_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/pow_mod1000000007.test.cpp
    title: tests/fps/pow_mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/pow_mod998244353.test.cpp
    title: tests/fps/pow_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree/line.test.cpp
    title: tests/li_chao_segtree/line.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree/segment.test.cpp
    title: tests/li_chao_segtree/segment.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partition_function/n.test.cpp
    title: tests/partition_function/n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partition_function/n_k.test.cpp
    title: tests/partition_function/n_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ssize.test.cpp
    title: tests/ssize.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsp.test.cpp
    title: tests/tsp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto\
    \ ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SSIZE_HPP\n#define TOOLS_SSIZE_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ssize.hpp
  requiredBy:
  - tools/mcf_graph.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/fact_mod_cache.hpp
  - tools/bigint.hpp
  - tools/rolling_hash.hpp
  - tools/bigdecimal.hpp
  - tools/pow_mod_cache.hpp
  - tools/fps.hpp
  - tools/detail/rolling_hash.hpp
  - tools/partition_function.hpp
  - tools/stirling_2nd.hpp
  - tools/weighted_bipartite_matching.hpp
  - tools/rational.hpp
  - tools/li_chao_segtree.hpp
  timestamp: '2021-11-27 17:23:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/fps/pow_mod1000000007.test.cpp
  - tests/fps/inv_mod1000000007.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/exp_mod1000000007.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/log_mod1000000007.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fact_mod_cache.test.cpp
  - tests/tsp.test.cpp
  - tests/has_mod.test.cpp
  - tests/permutation.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/ssize.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/stirling_2nd.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/li_chao_segtree/segment.test.cpp
  - tests/li_chao_segtree/line.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/partition_function/n.test.cpp
  - tests/partition_function/n_k.test.cpp
  - tests/persistent_stack.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/range_of_digit_products.test.cpp
documentation_of: tools/ssize.hpp
layout: document
title: Polyfill of std::ssize
---

```cpp
template <typename C>
constexpr auto ssize(const C& c) -> std::common_type_t<std::ptrdiff_t, std::make_signed_t<decltype(c.size())>>;
```

It is a compatible alternative of `std::ssize` in C++20.

## Constraints
- `c.size()` is defined.

## Time Complexity
- Same as the time complexity of `c.size()`.

## License
- CC0

## Author
- anqooqie
