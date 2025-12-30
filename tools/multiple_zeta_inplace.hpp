#ifndef TOOLS_MULTIPLE_ZETA_INPLACE_HPP
#define TOOLS_MULTIPLE_ZETA_INPLACE_HPP

#include <iterator>
#include <ranges>
#include <utility>
#include "tools/commutative_monoid.hpp"
#include "tools/eratosthenes_sieve.hpp"
#include "tools/groups.hpp"

namespace tools {
  template <tools::commutative_monoid M, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void multiple_zeta_inplace(R&& a) {
    const int N = std::ranges::distance(a);
    if (N < 2) return;

    tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = (N - 1) / p; i >= 1; --i) {
        std::ranges::begin(a)[i] = M::op(std::ranges::begin(a)[i], std::ranges::begin(a)[i * p]);
      }
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void multiple_zeta_inplace(R&& a) {
    tools::multiple_zeta_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(a));
  }
}

#endif
