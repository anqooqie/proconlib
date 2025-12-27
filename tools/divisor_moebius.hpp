#ifndef TOOLS_DIVISOR_MOEBIUS_HPP
#define TOOLS_DIVISOR_MOEBIUS_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/divisor_moebius_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> divisor_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::divisor_moebius_inplace(a);
    return a;
  }
}

#endif
