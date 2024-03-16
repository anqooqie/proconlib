---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':question:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/partition_function.hpp
    title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j)
      \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
  - icon: ':question:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':x:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':heavy_check_mark:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Stirling numbers of the first kind $s(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  - icon: ':heavy_check_mark:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  - icon: ':x:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
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
    path: tests/circle_2d/intersection_to_circle.test.cpp
    title: tests/circle_2d/intersection_to_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/intersection_to_line.test.cpp
    title: tests/circle_2d/intersection_to_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/with_radius.test.cpp
    title: tests/circle_2d/where/with_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/without_radius.test.cpp
    title: tests/circle_2d/where/without_radius.test.cpp
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
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
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
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
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
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
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
  - icon: ':x:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':x:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':x:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':x:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st.test.cpp
    title: tests/stirling_1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
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
  - tools/rolling_hash.hpp
  - tools/line_2d.hpp
  - tools/floor_kth_root.hpp
  - tools/partition_function.hpp
  - tools/bernoulli.hpp
  - tools/sparse_fps_pow.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/pow.hpp
  - tools/berlekamp_massey.hpp
  - tools/polynomial_interpolation.hpp
  - tools/bostan_mori.hpp
  - tools/fps.hpp
  - tools/polygon_2d.hpp
  - tools/tetration_mod.hpp
  - tools/stirling_1st.hpp
  - tools/detail/rolling_hash.hpp
  - tools/detail/geometry_2d.hpp
  - tools/square.hpp
  - tools/ceil_kth_root.hpp
  - tools/totient.hpp
  - tools/convolution.hpp
  - tools/stirling_2nd.hpp
  - tools/triangle_2d.hpp
  - tools/half_line_2d.hpp
  - tools/polynomial.hpp
  - tools/quaternion.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/circle_2d.hpp
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/has_mod.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/stirling_1st.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/partition_function/n.test.cpp
  - tests/partition_function/n_k.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/disjoint_sparse_table.test.cpp
  - tests/permutation.test.cpp
  - tests/bernoulli.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/compositional_inverse.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/composition.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/inv_other_mods.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/totient.test.cpp
  - tests/convolution/double.test.cpp
  - tests/convolution/mod1000000007.test.cpp
  - tests/convolution/mod998244353.test.cpp
  - tests/convolution/dynamic_mod.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/stirling_2nd.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
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
