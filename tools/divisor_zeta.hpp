#ifndef TOOLS_DIVISOR_ZETA_HPP
#define TOOLS_DIVISOR_ZETA_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/divisor_zeta_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> divisor_zeta(R&& a) {
    auto b = std::forward<R>(a) | std::ranges::to<std::vector>();
    tools::divisor_zeta_inplace(b);
    return b;
  }
}

#endif
