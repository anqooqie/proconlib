#ifndef TOOLS_DIVISOR_ZETA_INPLACE_HPP
#define TOOLS_DIVISOR_ZETA_INPLACE_HPP

#include <iterator>
#include <ranges>
#include "tools/eratosthenes_sieve.hpp"

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void divisor_zeta_inplace(R&& a) {
    const int N = std::ranges::distance(a);
    if (N < 2) return;

    tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = 1; i * p < N; ++i) {
        std::ranges::begin(a)[i * p] += std::ranges::begin(a)[i];
      }
    }
  }
}

#endif
