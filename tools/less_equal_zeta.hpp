#ifndef TOOLS_LESS_EQUAL_ZETA_HPP
#define TOOLS_LESS_EQUAL_ZETA_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/less_equal_zeta_inplace.hpp"
#include "tools/monoid.hpp"

namespace tools {
  template <tools::monoid M, std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> less_equal_zeta(R&& a) {
    auto b = std::forward<R>(a) | std::ranges::to<std::vector>();
    tools::less_equal_zeta_inplace<M>(b);
    return b;
  }

  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> less_equal_zeta(R&& a) {
    auto b = std::forward<R>(a) | std::ranges::to<std::vector>();
    tools::less_equal_zeta_inplace(b);
    return b;
  }
}

#endif
