#ifndef TOOLS_MULTIPLE_MOEBIUS_INPLACE_HPP
#define TOOLS_MULTIPLE_MOEBIUS_INPLACE_HPP

#include <iterator>
#include <ranges>
#include <utility>
#include "tools/commutative_group.hpp"
#include "tools/eratosthenes_sieve.hpp"
#include "tools/groups.hpp"

namespace tools {
  template <tools::commutative_group G, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void multiple_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    if (N < 2) return;

    tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = 1; i * p < N; ++i) {
        std::ranges::begin(b)[i] = G::op(std::ranges::begin(b)[i], G::inv(std::ranges::begin(b)[i * p]));
      }
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void multiple_moebius_inplace(R&& b) {
    tools::multiple_moebius_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(b));
  }
}

#endif
