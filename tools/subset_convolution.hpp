#ifndef TOOLS_SUBSET_CONVOLUTION_HPP
#define TOOLS_SUBSET_CONVOLUTION_HPP

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/group.hpp"
#include "tools/is_group.hpp"
#include "tools/is_monoid.hpp"
#include "tools/monoid.hpp"

namespace tools {
  template <typename AG, typename MM, ::std::ranges::input_range R1, ::std::ranges::input_range R2>
  requires (::std::ranges::sized_range<R1> && ::std::ranges::sized_range<R2>)
  auto subset_convolution(R1&& a, R2&& b) {
    static_assert(::tools::is_group_v<AG>);
    static_assert(::tools::is_monoid_v<MM>);
    static_assert(::std::same_as<typename AG::T, typename MM::T>);
    static_assert(::std::assignable_from<typename AG::T&, ::std::ranges::range_value_t<R1>>);
    static_assert(::std::assignable_from<typename AG::T&, ::std::ranges::range_value_t<R2>>);

    using T = typename AG::T;

    assert(::std::has_single_bit(::std::ranges::size(a)));
    assert(::std::has_single_bit(::std::ranges::size(b)));
    assert(::std::ranges::size(a) == ::std::ranges::size(b));

    const int N = ::std::countr_zero(::std::ranges::size(a));
    const int pow2_N = 1 << N;

    auto za = ::std::vector(pow2_N, ::std::vector(N + 1, AG::e()));
    {
      int i = 0;
      for (auto&& a_i : a) {
        za[i][::std::popcount<unsigned int>(i)] = a_i;
        ++i;
      }
    }

    auto zb = ::std::vector(pow2_N, ::std::vector(N + 1, AG::e()));
    {
      int i = 0;
      for (auto&& b_i : b) {
        zb[i][::std::popcount<unsigned int>(i)] = b_i;
        ++i;
      }
    }

    for (int w = 0; w < N; ++w) {
      for (int i = 0; i < pow2_N; ++i) {
        if (i & (1 << w)) {
          for (int j = 0; j <= N; ++j) {
            za[i][j] = AG::op(za[i][j], za[i ^ (1 << w)][j]);
            zb[i][j] = AG::op(zb[i][j], zb[i ^ (1 << w)][j]);
          }
        }
      }
    }

    auto zc = ::std::vector(pow2_N, ::std::vector(N + 1, AG::e()));
    for (int i = 0; i < pow2_N; ++i) {
      for (int j = 0; j <= N; ++j) {
        for (int k = 0; k <= j; ++k) {
          zc[i][j] = AG::op(zc[i][j], MM::op(za[i][k], zb[i][j - k]));
        }
      }
    }

    for (int w = 0; w < N; ++w) {
      for (int i = 0; i < pow2_N; ++i) {
        if (i & (1 << w)) {
          for (int j = 0; j <= N; ++j) {
            zc[i][j] = AG::op(zc[i][j], AG::inv(zc[i ^ (1 << w)][j]));
          }
        }
      }
    }

    ::std::vector<T> c;
    c.reserve(pow2_N);
    for (int i = 0; i < pow2_N; ++i) {
      c.push_back(zc[i][::std::popcount<unsigned int>(i)]);
    }

    return c;
  }

  template <typename AG, typename MM, ::std::ranges::input_range R1, ::std::ranges::input_range R2>
  requires (!(::std::ranges::sized_range<R1> && ::std::ranges::sized_range<R2>))
  auto subset_convolution(R1&& a, R2&& b) {
    ::std::vector<::std::ranges::range_value_t<R1>> va;
    ::std::ranges::copy(::std::forward<R1>(a), ::std::back_inserter(va));
    ::std::vector<::std::ranges::range_value_t<R2>> vb;
    ::std::ranges::copy(::std::forward<R2>(b), ::std::back_inserter(vb));
    return ::tools::subset_convolution(::std::move(va), ::std::move(vb));
  }

  template <::std::ranges::input_range R1, ::std::ranges::input_range R2>
  auto subset_convolution(R1&& a, R2&& b) {
    using T = ::std::common_type_t<::std::ranges::range_value_t<R1>, ::std::ranges::range_value_t<R2>>;
    return ::tools::subset_convolution<::tools::group::plus<T>, ::tools::monoid::multiplies<T>, R1, R2>(::std::forward<R1>(a), ::std::forward<R2>(b));
  }
}

#endif
