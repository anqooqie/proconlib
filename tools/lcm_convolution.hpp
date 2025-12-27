#ifndef TOOLS_LCM_CONVOLUTION_HPP
#define TOOLS_LCM_CONVOLUTION_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/divisor_moebius_inplace.hpp"
#include "tools/divisor_zeta_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> lcm_convolution(R1&& a_orig, R2&& b_orig, const int K) {
    assert(K >= 0);

    using T = std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>;
    auto a = std::forward<R1>(a_orig) | std::ranges::to<std::vector<T>>();
    auto b = std::forward<R2>(b_orig) | std::ranges::to<std::vector<T>>();
    const int N = a.size();
    const int M = b.size();

    std::vector<T> c(K);
    if (std::min({N, M, K}) > 0) {
      c[0] = a[0] * b[0];
    }
    if (std::min(M, K) > 0) {
      for (int i = 1; i < N; ++i) {
        c[0] += a[i] * b[0];
      }
    }
    if (std::min(N, K) > 0) {
      for (int i = 1; i < M; ++i) {
        c[0] += a[0] * b[i];
      }
    }

    a.resize(K, T(0));
    tools::divisor_zeta_inplace(a);
    b.resize(K, T(0));
    tools::divisor_zeta_inplace(b);

    for (int i = 1; i < K; ++i) {
      c[i] = a[i] * b[i];
    }
    tools::divisor_moebius_inplace(c);

    return c;
  }

  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> lcm_convolution(R1&& a, R2&& b) {
    if constexpr ((std::ranges::sized_range<R1> || std::ranges::forward_range<R1>) && (std::ranges::sized_range<R2> || std::ranges::forward_range<R2>)) {
      const int N = [&]() {
        if constexpr (std::ranges::sized_range<R1>) {
          return std::ranges::size(a);
        } else {
          return std::ranges::distance(a);
        }
      }();
      const int M = [&]() {
        if constexpr (std::ranges::sized_range<R2>) {
          return std::ranges::size(b);
        } else {
          return std::ranges::distance(b);
        }
      }();
      assert(N == M);
      return tools::lcm_convolution(std::forward<R1>(a), std::forward<R2>(b), N);
    } else {
      return tools::lcm_convolution(std::forward<R1>(a) | std::ranges::to<std::vector>(), std::forward<R2>(b) | std::ranges::to<std::vector>());
    }
  }
}

#endif
