#ifndef TOOLS_COMPRESSED_HPP
#define TOOLS_COMPRESSED_HPP

#include <algorithm>
#include <concepts>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/integral.hpp"
#include "tools/lower_bound.hpp"

namespace tools {
  template <tools::integral T, std::ranges::input_range R>
  requires std::totally_ordered<std::ranges::range_value_t<R>>
  std::vector<T> compressed(R&& a) {
    if constexpr (std::ranges::forward_range<R>) {
      auto sorted = a | std::ranges::to<std::vector>();
      std::ranges::sort(sorted);
      sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
      return std::forward<R>(a) | std::views::transform([&](const auto& a_i) { return tools::lower_bound(sorted, a_i); }) | std::ranges::to<std::vector<T>>();
    } else {
      return tools::compressed<T>(std::forward<R>(a) | std::ranges::to<std::vector>());
    }
  }

  template <std::ranges::input_range R>
  requires std::totally_ordered<std::ranges::range_value_t<R>>
  std::vector<std::conditional_t<tools::integral<std::ranges::range_value_t<R>>, std::ranges::range_value_t<R>, int>> compressed(R&& a) {
    return tools::compressed<std::conditional_t<tools::integral<std::ranges::range_value_t<R>>, std::ranges::range_value_t<R>, int>>(std::forward<R>(a));
  }
}

#endif
