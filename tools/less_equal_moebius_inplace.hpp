#ifndef TOOLS_LESS_EQUAL_MOEBIUS_INPLACE_HPP
#define TOOLS_LESS_EQUAL_MOEBIUS_INPLACE_HPP

#include <iterator>
#include <ranges>
#include <utility>
#include "tools/group.hpp"
#include "tools/groups.hpp"

namespace tools {
  template <tools::group G, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void less_equal_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    for (int i = N - 1; i - 1 >= 0; --i) {
      std::ranges::begin(b)[i] = G::op(G::inv(std::ranges::begin(b)[i - 1]), std::ranges::begin(b)[i]);
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void less_equal_moebius_inplace(R&& b) {
    tools::less_equal_moebius_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(b));
  }
}

#endif
