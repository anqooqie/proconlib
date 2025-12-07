#ifndef TOOLS_SAMPLE_POINT_SHIFT_HPP
#define TOOLS_SAMPLE_POINT_SHIFT_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/convolution.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/is_prime.hpp"
#include "tools/modint.hpp"
#include "tools/monoids.hpp"
#include "tools/online_cumsum.hpp"

namespace tools {
  template <std::ranges::input_range R>
  requires tools::modint<std::ranges::range_value_t<R>>
  auto sample_point_shift(R&& f, const std::ranges::range_value_t<R> c) {
    using T = std::ranges::range_value_t<R>;

    if constexpr (std::ranges::forward_range<R> || std::ranges::sized_range<R>) {
      assert(tools::is_prime(T::mod()));
      const int N = std::ranges::distance(f);
      assert(1 <= N && N <= T::mod());

      tools::fact_mod_cache<T> cache;
      const std::array<T, 2> minus_1_pow = {T(1), T(-1)};

      tools::online_cumsum<tools::monoids::multiplies<T>, true> nl(N);
      tools::online_cumsum<tools::monoids::multiplies<T>, false> nr(N);
      {
        T last = c;
        for (int i = 0; i < N; ++i, --last) {
          nl[i] = nr[i] = last;
        }
      }

      T answer(0);
      for (const auto& [i, f_i] : f | std::views::enumerate) {
        answer += nl.prod(0, i) * nr.prod(i + 1, N) * minus_1_pow[(N - 1 - i) & 1] * cache.fact_inv(N - 1 - i) * cache.fact_inv(i) * f_i;
      }

      return answer;
    } else {
      return tools::sample_point_shift(std::forward<R>(f) | std::ranges::to<std::vector<T>>(), c);
    }
  }

  template <std::ranges::input_range R>
  requires tools::modint<std::ranges::range_value_t<R>>
  auto sample_point_shift(R&& f, const std::ranges::range_value_t<R> c, const int M) {
    using T = std::ranges::range_value_t<R>;

    if constexpr (std::ranges::forward_range<R> || std::ranges::sized_range<R>) {
      assert(tools::is_prime(T::mod()));
      const int N = std::ranges::distance(f);
      assert(1 <= N && N <= T::mod());
      assert(0 <= M);

      if (M == 1) {
        return std::vector<T>{tools::sample_point_shift(std::forward<R>(f), c)};
      }
      if (M == 0) {
        return std::vector<T>{};
      }

      tools::fact_mod_cache<T> cache;
      const std::array<T, 2> minus_1_pow = {T(1), T(-1)};

      auto c1 = tools::convolution(
        std::forward<R>(f) | std::views::enumerate | std::views::transform([&](const auto& tuple) {
          const auto& [i, f_i] = tuple;
          return f_i * cache.fact_inv(i);
        }),
        std::views::iota(0, N) | std::views::transform([&](const auto i) {
          return minus_1_pow[i & 1] * cache.fact_inv(i);
        })
      );
      c1.resize(N);

      std::vector<T> c2;
      {
        std::vector<T> a2(N);
        for (int i = 0; i < N; ++i) {
          a2[i] = c1[N - 1 - i] * cache.fact(N - 1 - i);
        }

        std::vector<T> b2(N);
        b2[0] = T(1);
        T b = c;
        for (int i = 1; i < N; ++i, --b) {
          b2[i] = b2[i - 1] * b;
        }
        for (int i = 0; i < N; ++i) {
          b2[i] *= cache.fact_inv(i);
        }

        c2 = tools::convolution(std::move(a2), std::move(b2));
        c2.resize(N);
        std::ranges::reverse(c2);
        for (int i = 0; i < N; ++i) {
          c2[i] *= cache.fact_inv(i);
        }
      }

      const int m = std::min(M, T::mod());
      auto c3 = tools::convolution(
        std::move(c2),
        std::views::iota(0, m) | std::views::transform([&](const auto i) { return cache.fact_inv(i); })
      );
      c3.resize(m);
      for (int i = 0; i < m; ++i) {
        c3[i] *= cache.fact(i);
      }

      c3.resize(M);
      for (int i = m; i < M; ++i) {
        c3[i] = c3[i % T::mod()];
      }

      return c3;
    } else {
      return tools::sample_point_shift(std::forward<R>(f) | std::ranges::to<std::vector<T>>(), c, M);
    }
  }
}

#endif
