#ifndef TOOLS_GREATER_EQUAL_MOEBIUS_HPP
#define TOOLS_GREATER_EQUAL_MOEBIUS_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/greater_equal_moebius_inplace.hpp"
#include "tools/group.hpp"

namespace tools {
  template <tools::group G, std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> greater_equal_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::greater_equal_moebius_inplace<G>(a);
    return a;
  }

  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> greater_equal_moebius(R&& b) {
    auto a = std::forward<R>(b) | std::ranges::to<std::vector>();
    tools::greater_equal_moebius_inplace(a);
    return a;
  }
}

#endif
