#ifndef TOOLS_LESS_EQUAL_MOEBIUS_HPP
#define TOOLS_LESS_EQUAL_MOEBIUS_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/less_equal_moebius_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> less_equal_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::less_equal_moebius_inplace(a);
    return a;
  }
}

#endif
