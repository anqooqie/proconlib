#ifndef TOOLS_COMPRESS_HPP
#define TOOLS_COMPRESS_HPP

#include <algorithm>
#include <ranges>
#include <vector>
#include "tools/integral.hpp"
#include "tools/lower_bound.hpp"

namespace tools {
  template <std::ranges::forward_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
        && tools::integral<std::ranges::range_value_t<R>>
  void compress(R&& a) {
    auto sorted = a | std::ranges::to<std::vector>();
    std::ranges::sort(sorted);
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    for (auto& a_i : a) {
      a_i = tools::lower_bound(sorted, a_i);
    }
  }
}

#endif
