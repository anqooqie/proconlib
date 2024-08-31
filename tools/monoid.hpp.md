---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
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
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/ord_mod.hpp
    title: $\mathrm{ord}(x)$ for $x \in (\mathbb{Z}/p\mathbb{Z})^\times$
  - icon: ':heavy_check_mark:'
    path: tools/partition_function.hpp
    title: Partition function
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
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
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/monoid.test.cpp
    title: tests/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ord_mod.test.cpp
    title: tests/ord_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partition_function/all.test.cpp
    title: tests/partition_function/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partition_function/consistent.test.cpp
    title: tests/partition_function/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partition_function/diagonal.test.cpp
    title: tests/partition_function/diagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
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
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <algorithm>\n#include <limits>\n#include <cassert>\n#line 1 \"tools/gcd.hpp\"\
    \n\n\n\n#line 5 \"tools/gcd.hpp\"\n#include <numeric>\n\nnamespace tools {\n \
    \ template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> gcd(const\
    \ M m, const N n) {\n    return ::std::gcd(m, n);\n  }\n}\n\n\n#line 9 \"tools/monoid.hpp\"\
    \n\nnamespace tools {\n  namespace monoid {\n    template <typename M, M ...dummy>\n\
    \    struct max;\n\n    template <typename M>\n    struct max<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::max(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::min();\n        } else {\n       \
    \   return -::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct max<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(E <= lhs);\n        assert(E\
    \ <= rhs);\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename M, M ...dummy>\n\
    \    struct min;\n\n    template <typename M>\n    struct min<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::min(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::max();\n        } else {\n       \
    \   return ::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct min<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(lhs <= E);\n        assert(rhs\
    \ <= E);\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n    private:\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n \
    \       return T(1);\n      }\n    };\n\n    template <>\n    struct multiplies<bool>\
    \ {\n      using T = bool;\n      static T op(const bool lhs, const bool rhs)\
    \ {\n        return lhs && rhs;\n      }\n      static T e() {\n        return\
    \ true;\n      }\n    };\n\n    template <typename M>\n    struct gcd {\n    private:\n\
    \      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> &&\
    \ !::std::is_same_v<M, bool>), \"If M is a built-in arithmetic type, it must be\
    \ integral except for bool.\");\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return ::tools::gcd(lhs, rhs);\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n    };\n\n    template <typename M,\
    \ M E>\n    struct update {\n      static_assert(::std::is_integral_v<M>, \"M\
    \ must be a built-in integral type.\");\n\n      using T = M;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n     \
    \ }\n      static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MONOID_HPP\n#define TOOLS_MONOID_HPP\n\n#include <type_traits>\n\
    #include <algorithm>\n#include <limits>\n#include <cassert>\n#include \"tools/gcd.hpp\"\
    \n\nnamespace tools {\n  namespace monoid {\n    template <typename M, M ...dummy>\n\
    \    struct max;\n\n    template <typename M>\n    struct max<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::max(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::min();\n        } else {\n       \
    \   return -::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct max<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(E <= lhs);\n        assert(E\
    \ <= rhs);\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename M, M ...dummy>\n\
    \    struct min;\n\n    template <typename M>\n    struct min<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::min(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::max();\n        } else {\n       \
    \   return ::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct min<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(lhs <= E);\n        assert(rhs\
    \ <= E);\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n    private:\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n \
    \       return T(1);\n      }\n    };\n\n    template <>\n    struct multiplies<bool>\
    \ {\n      using T = bool;\n      static T op(const bool lhs, const bool rhs)\
    \ {\n        return lhs && rhs;\n      }\n      static T e() {\n        return\
    \ true;\n      }\n    };\n\n    template <typename M>\n    struct gcd {\n    private:\n\
    \      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> &&\
    \ !::std::is_same_v<M, bool>), \"If M is a built-in arithmetic type, it must be\
    \ integral except for bool.\");\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return ::tools::gcd(lhs, rhs);\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n    };\n\n    template <typename M,\
    \ M E>\n    struct update {\n      static_assert(::std::is_integral_v<M>, \"M\
    \ must be a built-in integral type.\");\n\n      using T = M;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n     \
    \ }\n      static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/gcd.hpp
  isVerificationFile: false
  path: tools/monoid.hpp
  requiredBy:
  - tools/sparse_fps_pow.hpp
  - tools/ceil_kth_root.hpp
  - tools/convolution.hpp
  - tools/large_fact_mod_cache.hpp
  - tools/partition_function.hpp
  - tools/berlekamp_massey.hpp
  - tools/fps.hpp
  - tools/tetration_mod.hpp
  - tools/bell.hpp
  - tools/quaternion.hpp
  - tools/detail/rolling_hash.hpp
  - tools/sample_point_shift.hpp
  - tools/rolling_hash.hpp
  - tools/polynomial.hpp
  - tools/stirling_2nd.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/bernoulli.hpp
  - tools/bostan_mori.hpp
  - tools/floor_kth_root.hpp
  - tools/totient.hpp
  - tools/stirling_1st.hpp
  - tools/polynomial_interpolation.hpp
  - tools/pow.hpp
  - tools/ord_mod.hpp
  - tools/twelvefold_way.hpp
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tetration_mod.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/convolution/double.test.cpp
  - tests/convolution/dynamic_mod.test.cpp
  - tests/convolution/mod1000000007.test.cpp
  - tests/convolution/mod998244353.test.cpp
  - tests/is_group.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/partition_function/diagonal.test.cpp
  - tests/partition_function/consistent.test.cpp
  - tests/partition_function/all.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/monoid.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/ord_mod.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/is_monoid.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/totient.test.cpp
  - tests/disjoint_sparse_table.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/permutation.test.cpp
  - tests/has_mod.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/compositional_inverse.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/inv_other_mods.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/composition.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/bernoulli.test.cpp
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
(1) template <typename M> struct monoid::max;
(2) template <typename M, M E> struct monoid::max;
```

It is a monoid $(M, \max, E)$.

- (1)
    - If `<M>` is a built-in integral type, let $E$ be `std::numeric_limits<M>::min()`.
    - If `<M>` is a built-in floating-point type, let $E$ be `-std::numeric_limits<M>::infinity()`.

### Constraints
- (1)
    - $M$ is a built-in arithmetic type.
- (2)
    - $M$ is a built-in integral type.

### Time Complexity
- Not applicable

## monoid::max::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::max::op
```
static M op(M x, M y);
```

It returns $\max(x, y)$.

### Constraints
- $E \leq x$
- $E \leq y$

### Time Complexity
- $O(1)$

## monoid::max::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::min
```cpp
(1) template <typename M> struct monoid::min;
(2) template <typename M, M E> struct monoid::min;
```

It is a monoid $(M, \min, E)$.

- (1)
    - If `<M>` is a built-in integral type, let $E$ be `std::numeric_limits<M>::max()`.
    - If `<M>` is a built-in floating-point type, let $E$ be `std::numeric_limits<M>::infinity()`.

### Constraints
- (1)
    - $M$ is a built-in arithmetic type.
- (2)
    - $M$ is a built-in integral type.

### Time Complexity
- Not applicable

## monoid::min::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::min::op
```
static M op(M x, M y);
```

It returns $\min(x, y)$.

### Constraints
- $x \leq E$
- $y \leq E$

### Time Complexity
- $O(1)$

## monoid::min::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::multiplies
```cpp
template <typename M> struct monoid::multiplies;
```

It is a monoid $(M, \times, 1)$.

### Constraints
- If `x` is `<M>` and `y` is `<M>`, then `x * y` is also `<M>`.
- For all `x` in `<M>`, `y` in `<M>` and `z` in `<M>`, `(x * y) * z` $=$ `x * (y * z)`.
- For all `x` in `<M>`, `M(1) * x` $=$ `x * M(1)` $=$ `x`.

### Time Complexity
- Not applicable

## monoid::multiplies::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::multiplies::op
```
static M op(M x, M y);
```

It returns `x * y`.

### Constraints
- None

### Time Complexity
- Same as that of `x * y`

## monoid::multiplies::e
```
static M e();
```

It returns `M(1)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(1)`

## monoid::gcd
```cpp
template <typename M> struct monoid::gcd;
```

It is a monoid $(M, \gcd, 0)$.
Note that we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$ in this monoid.

### Constraints
- `tools::gcd(x, y)` is defined for `x` and `y` of type `<M>`. In particular, `<M>` is neither a built-in floating-point type nor `bool`.

### Time Complexity
- Not applicable

## monoid::gcd::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::gcd::op
```
static M op(M x, M y);
```

It returns `tools::gcd(x, y)`.
For a built-in integral type `<M>`, this is equivalent to returning `std::gcd(x, y)`.

### Constraints
- None

### Time Complexity
- Same as that of `tools::gcd(x, y)`

## monoid::gcd::e
```
static M e();
```

It returns `M(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(0)`.

## monoid::update
```cpp
template <typename M, M E> struct monoid::update;
```

It is a monoid $(M, U, E)$ where

$$\begin{align*}
U(x, y) &= \left\{\begin{array}{ll}
y & \text{(if $x = E$)}\\
x & \text{(if $x \neq E$)}
\end{array}\right.
\end{align*}$$

### Constraints
- `<M>` is a built-in integral type.

### Time Complexity
- Not applicable

## monoid::update::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::update::op
```
static M op(M x, M y);
```

It returns $U(x, y)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::update::e
```
static M e();
```

It returns `E`.

### Constraints
- None

### Time Complexity
- $O(1)$
