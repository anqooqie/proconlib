#ifndef TOOLS_MULTIPLE_MOEBIUS_INPLACE_HPP
#define TOOLS_MULTIPLE_MOEBIUS_INPLACE_HPP

#include <iterator>
#include <ranges>
#include "tools/eratosthenes_sieve.hpp"

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void multiple_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    if (N < 2) return;

    tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = 1; i * p < N; ++i) {
        std::ranges::begin(b)[i] -= std::ranges::begin(b)[i * p];
      }
    }
  }
}

#endif
