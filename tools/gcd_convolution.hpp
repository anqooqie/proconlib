#ifndef TOOLS_GCD_CONVOLUTION_HPP
#define TOOLS_GCD_CONVOLUTION_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/multiple_moebius_inplace.hpp"
#include "tools/multiple_zeta_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> gcd_convolution(R1&& a_orig, R2&& b_orig, const int K) {
    assert(K >= 0);

    using T = std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>;
    auto a = std::forward<R1>(a_orig) | std::ranges::to<std::vector<T>>();
    auto b = std::forward<R2>(b_orig) | std::ranges::to<std::vector<T>>();
    const int N = a.size();
    const int M = b.size();

    std::vector<T> offset(std::min(std::max(N, M), K), T(0));
    if (std::min({N, M, K}) > 0) {
      offset[0] += a[0] * b[0];
    }
    if (M > 0) {
      for (int i = 1; i < std::min(N, K); ++i) {
        offset[i] += a[i] * b[0];
      }
    }
    if (N > 0) {
      for (int i = 1; i < std::min(M, K); ++i) {
        offset[i] += a[0] * b[i];
      }
    }

    tools::multiple_zeta_inplace(a);
    tools::multiple_zeta_inplace(b);

    std::vector<T> c;
    if (std::min(N, M) <= K) {
      c.reserve(K);
      if (std::min(N, M) > 0) {
        c.emplace_back(0);
      }
      for (int i = 1; i < std::min(N, M); ++i) {
        c.push_back(a[i] * b[i]);
      }
      tools::multiple_moebius_inplace(c);
      c.resize(K, T(0));
    } else {
      c.reserve(std::min(N, M));
      c.emplace_back(0);
      for (int i = 1; i < std::min(N, M); ++i) {
        c.push_back(a[i] * b[i]);
      }
      tools::multiple_moebius_inplace(c);
      c.resize(K);
    }

    for (int i = 0; i < std::min(std::max(N, M), K); ++i) {
      c[i] += offset[i];
    }
    return c;
  }

  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> gcd_convolution(R1&& a, R2&& b) {
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
      return tools::gcd_convolution(std::forward<R1>(a), std::forward<R2>(b), N);
    } else {
      return tools::gcd_convolution(std::forward<R1>(a) | std::ranges::to<std::vector>(), std::forward<R2>(b) | std::ranges::to<std::vector>());
    }
  }
}

#endif
