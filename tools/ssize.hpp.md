---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bernoulli.hpp
    title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fact_mod_cache.hpp
    title: Cache for $n^{-1}, n!, n!^{-1} \pmod{P}$
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
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
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache for $b^n \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':heavy_check_mark:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  - icon: ':heavy_check_mark:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Signed Stirling numbers of the first kind
  - icon: ':heavy_check_mark:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind
  - icon: ':heavy_check_mark:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
  - icon: ':heavy_check_mark:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bell/all.test.cpp
    title: tests/bell/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/consistent.test.cpp
    title: tests/bell/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/fixed_n.test.cpp
    title: tests/bell/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bernoulli.test.cpp
    title: tests/bernoulli.test.cpp
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
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
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
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
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
    path: tests/monoid.test.cpp
    title: tests/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation.test.cpp
    title: tests/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
    title: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/taylor_shift.test.cpp
    title: tests/polynomial/taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_interpolation.test.cpp
    title: tests/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
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
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ssize.test.cpp
    title: tests/ssize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/consistent.test.cpp
    title: tests/stirling_1st/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_k.test.cpp
    title: tests/stirling_1st/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_n.test.cpp
    title: tests/stirling_1st/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/all.test.cpp
    title: tests/stirling_2nd/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/consistent.test.cpp
    title: tests/stirling_2nd/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_k.test.cpp
    title: tests/stirling_2nd/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_n.test.cpp
    title: tests/stirling_2nd/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsp.test.cpp
    title: tests/tsp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_prod.test.cpp
    title: tests/wavelet_matrix/range_prod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - tools/detail/rolling_hash.hpp
  - tools/sample_point_shift.hpp
  - tools/bostan_mori.hpp
  - tools/bell.hpp
  - tools/bernoulli.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/fact_mod_cache.hpp
  - tools/li_chao_segtree.hpp
  - tools/bigdecimal.hpp
  - tools/sparse_fps_pow.hpp
  - tools/stirling_1st.hpp
  - tools/pow_mod_cache.hpp
  - tools/polynomial_interpolation.hpp
  - tools/twelvefold_way.hpp
  - tools/rational.hpp
  - tools/polynomial.hpp
  - tools/stirling_2nd.hpp
  - tools/rolling_hash.hpp
  - tools/weighted_bipartite_matching.hpp
  - tools/berlekamp_massey.hpp
  - tools/mcf_graph.hpp
  - tools/bigint.hpp
  - tools/large_fact_mod_cache.hpp
  timestamp: '2021-11-27 17:23:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bigint/plus.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/wavelet_matrix/range_prod.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/monoid.test.cpp
  - tests/ssize.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/has_mod.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/persistent_stack.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/li_chao_segtree/line.test.cpp
  - tests/li_chao_segtree/segment.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/fastio/string.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/tsp.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/fact_mod_cache.test.cpp
  - tests/bernoulli.test.cpp
  - tests/permutation.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/polynomial/naive_division.test.cpp
documentation_of: tools/ssize.hpp
layout: document
title: Polyfill of std::ssize
---

```cpp
template <typename C>
constexpr auto ssize(const C& c) -> std::common_type_t<std::ptrdiff_t, std::make_signed_t<decltype(c.size())>>;
```

It is a compatible alternative of `std::ssize` in C++20.

### Constraints
- `c.size()` is defined.

### Time Complexity
- Same as that of `c.size()`.

### License
- CC0

### Author
- anqooqie
