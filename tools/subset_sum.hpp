#ifndef TOOLS_SUBSET_SUM_HPP
#define TOOLS_SUBSET_SUM_HPP

#include <concepts>
#include <ranges>
#include <tuple>
#include <vector>
#include "tools/binomial_product.hpp"
#include "tools/modint.hpp"

namespace tools {
  template <::tools::modint M, ::std::ranges::input_range R>
  requires ::std::integral<::std::ranges::range_value_t<R>>
  auto subset_sum(R&& s, const int t) {
    assert(t >= 0);
    ::std::vector<int> tally(t + 1, 0);
    for (const auto& s_i : s) {
      assert(s_i >= 0);
      if (s_i <= t) {
        ++tally[s_i];
      }
    }
    return ::tools::binomial_product(tally | ::std::views::enumerate | ::std::views::transform([](const auto& tuple) {
      return ::std::make_tuple(M(1), M(1), ::std::get<0>(tuple), ::std::get<1>(tuple));
    }), t + 1);
  }
}

#endif
