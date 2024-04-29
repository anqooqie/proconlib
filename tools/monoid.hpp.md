---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bernoulli.hpp
    title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':question:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':x:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':x:'
    path: tools/partition_function.hpp
    title: Partition function
  - icon: ':question:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':x:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':x:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  - icon: ':x:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':x:'
    path: tools/stirling_1st.hpp
    title: Signed Stirling numbers of the first kind
  - icon: ':question:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':x:'
    path: tools/totient.hpp
    title: Euler's totient function
  - icon: ':x:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
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
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/double.test.cpp
    title: tests/convolution/double.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/dynamic_mod.test.cpp
    title: tests/convolution/dynamic_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod1000000007.test.cpp
    title: tests/convolution/mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod998244353.test.cpp
    title: tests/convolution/mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/disjoint_sparse_table.test.cpp
    title: tests/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_kth_root.test.cpp
    title: tests/floor_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/composition.test.cpp
    title: tests/fps/composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/compositional_inverse.test.cpp
    title: tests/fps/compositional_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod998244353.test.cpp
    title: tests/fps/exp_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_other_mods.test.cpp
    title: tests/fps/exp_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/inv_mod998244353.test.cpp
    title: tests/fps/inv_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/inv_other_mods.test.cpp
    title: tests/fps/inv_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/log_mod998244353.test.cpp
    title: tests/fps/log_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/log_other_mods.test.cpp
    title: tests/fps/log_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/pow_mod998244353.test.cpp
    title: tests/fps/pow_mod998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/pow_other_mods.test.cpp
    title: tests/fps/pow_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/is_group.test.cpp
    title: tests/is_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/is_monoid.test.cpp
    title: tests/is_monoid.test.cpp
  - icon: ':x:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':x:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
  - icon: ':x:'
    path: tests/partition_function/all.test.cpp
    title: tests/partition_function/all.test.cpp
  - icon: ':x:'
    path: tests/partition_function/consistent.test.cpp
    title: tests/partition_function/consistent.test.cpp
  - icon: ':x:'
    path: tests/partition_function/diagonal.test.cpp
    title: tests/partition_function/diagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multipoint_evaluation.test.cpp
    title: tests/polynomial/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
    title: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - icon: ':x:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/taylor_shift.test.cpp
    title: tests/polynomial/taylor_shift.test.cpp
  - icon: ':x:'
    path: tests/polynomial_interpolation.test.cpp
    title: tests/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':x:'
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/consistent.test.cpp
    title: tests/stirling_1st/consistent.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/fixed_k.test.cpp
    title: tests/stirling_1st/fixed_k.test.cpp
  - icon: ':x:'
    path: tests/stirling_1st/fixed_n.test.cpp
    title: tests/stirling_1st/fixed_n.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd/all.test.cpp
    title: tests/stirling_2nd/all.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd/consistent.test.cpp
    title: tests/stirling_2nd/consistent.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd/fixed_k.test.cpp
    title: tests/stirling_2nd/fixed_k.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd/fixed_n.test.cpp
    title: tests/stirling_2nd/fixed_n.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid {\n  \
    \  template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n    struct\
    \ max {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n       \
    \ return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_MONOID_HPP\n#define TOOLS_MONOID_HPP\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n   \
    \ struct max {\n      using T = M;\n      static T op(const T& lhs, const T& rhs)\
    \ {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n   \
    \     return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/monoid.hpp
  requiredBy:
  - tools/partition_function.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/polynomial.hpp
  - tools/totient.hpp
  - tools/stirling_1st.hpp
  - tools/large_fact_mod_cache.hpp
  - tools/bostan_mori.hpp
  - tools/ceil_kth_root.hpp
  - tools/sparse_fps_pow.hpp
  - tools/stirling_2nd.hpp
  - tools/floor_kth_root.hpp
  - tools/convolution.hpp
  - tools/tetration_mod.hpp
  - tools/berlekamp_massey.hpp
  - tools/bernoulli.hpp
  - tools/twelvefold_way.hpp
  - tools/quaternion.hpp
  - tools/sample_point_shift.hpp
  - tools/polynomial_interpolation.hpp
  - tools/bell.hpp
  - tools/pow.hpp
  - tools/fps.hpp
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/polynomial_product.test.cpp
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/convolution/mod998244353.test.cpp
  - tests/convolution/mod1000000007.test.cpp
  - tests/convolution/dynamic_mod.test.cpp
  - tests/convolution/double.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/is_monoid.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/bernoulli.test.cpp
  - tests/disjoint_sparse_table.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/totient.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/composition.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/inv_other_mods.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/compositional_inverse.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/partition_function/all.test.cpp
  - tests/partition_function/consistent.test.cpp
  - tests/partition_function/diagonal.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/permutation.test.cpp
  - tests/is_group.test.cpp
  - tests/has_mod.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
documentation_of: tools/monoid.hpp
layout: document
title: Typical monoids
---

They are typical monoids.

### License
- CC0

### Author
- anqooqie

## monoid::max
```cpp
namespace monoid {
  template <typename M, M E = std::numeric_limits<M>::lowest()>
  struct max {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::max(x, y);
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, \max, E)$.
If $E$ is not specified, then $E$ is `std::numeric_limits<M>::lowest()`.

### Constraints
- $M$ is comparable.
- If $E$ is not specified, $M$ is any of floating-point or integral types.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $\max(\max(x, y), z) = \max(x, \max(y, z))$.
- For all $x$ in $M$, $\max(E, x) = \max(x, E) = x$.

### Time Complexity
- Not applicable

## monoid::min
```cpp
namespace monoid {
  template <typename M, M E = std::numeric_limits<M>::max()>
  struct min {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::min(x, y);
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, \min, E)$.
If $E$ is not specified, then $E$ is `std::numeric_limits<M>::max()`.

### Constraints
- $M$ is comparable.
- If $E$ is not specified, $M$ is any of floating-point or integral types.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $\min(\min(x, y), z) = \min(x, \min(y, z))$.
- For all $x$ in $M$, $\min(E, x) = \min(x, E) = x$.

### Time Complexity
- Not applicable

## monoid::multiplies
```cpp
namespace monoid {
  template <typename M>
  struct multiplies {
    using T = M;
    static T op(const T& x, const T& y) {
      return x * y;
    }
    static T e() {
      return T(1);
    }
  };
}
```

It is a monoid $(M, \cdot, 1)$.

### Constraints
- `decltype(std::declval<M>() * std::declval<M>())` is `M`.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $(x \cdot y) \cdot z = x \cdot (y \cdot z)$.
- For all $x$ in $M$, `M(1)` $\cdot x = x \cdot$ `M(1)` $= x$.

### Time Complexity
- Not applicable

## monoid::gcd
```cpp
namespace monoid {
  template <typename M>
  struct gcd {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::gcd(x, y);
    }
    static T e() {
      return T(0);
    }
  };
}
```

It is a monoid $(M, \gcd, 0)$.

### Constraints
- $M$ is any of integral types.

### Time Complexity
- Not applicable

## monoid::update
```cpp
namespace monoid {
  template <typename M, M E>
  struct update {
    using T = M;
    static T op(const T& x, const T& y) {
      return x == E ? y : x;
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, U, E)$ where

$$\begin{align*}
U(x, y) &= \left\{\begin{array}{ll}
y & \text{(if $x = E$)}\\
x & \text{(if $x \neq E$)}
\end{array}\right.
\end{align*}$$

### Constraints
- None

### Time Complexity
- Not applicable
