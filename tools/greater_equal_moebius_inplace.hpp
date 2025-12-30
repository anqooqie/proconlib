#ifndef TOOLS_GREATER_EQUAL_MOEBIUS_INPLACE_HPP
#define TOOLS_GREATER_EQUAL_MOEBIUS_INPLACE_HPP

#include <iterator>
#include <ranges>
#include <utility>
#include "tools/group.hpp"
#include "tools/groups.hpp"

namespace tools {
  template <tools::group G, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void greater_equal_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    for (int i = 0; i + 1 < N; ++i) {
      std::ranges::begin(b)[i] = G::op(std::ranges::begin(b)[i], G::inv(std::ranges::begin(b)[i + 1]));
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void greater_equal_moebius_inplace(R&& b) {
    tools::greater_equal_moebius_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(b));
  }
}

#endif
