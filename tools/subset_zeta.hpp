#ifndef TOOLS_SUBSET_ZETA_HPP
#define TOOLS_SUBSET_ZETA_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/commutative_monoid.hpp"
#include "tools/subset_zeta_inplace.hpp"

namespace tools {
  template <tools::commutative_monoid M, std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> subset_zeta(R&& a) {
    auto b = std::forward<R>(a) | std::ranges::to<std::vector>();
    tools::subset_zeta_inplace<M>(b);
    return b;
  }

  template <std::ranges::input_range R>
  std::vector<std::ranges::range_value_t<R>> subset_zeta(R&& a) {
    auto b = std::forward<R>(a) | std::ranges::to<std::vector>();
    tools::subset_zeta_inplace(b);
    return b;
  }
}

#endif
