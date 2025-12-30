#ifndef TOOLS_DIVISOR_MOEBIUS_HPP
#define TOOLS_DIVISOR_MOEBIUS_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/commutative_group.hpp"
#include "tools/divisor_moebius_inplace.hpp"

namespace tools {
  template <tools::commutative_group G, std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> divisor_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::divisor_moebius_inplace<G>(a);
    return a;
  }

  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> divisor_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::divisor_moebius_inplace(a);
    return a;
  }
}

#endif
