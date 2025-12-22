#ifndef TOOLS_RUN_LENGTH_HPP
#define TOOLS_RUN_LENGTH_HPP

#include <ranges>
#include <utility>
#include <vector>
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T, std::ranges::input_range R>
  auto run_length(R&& r) {
    std::vector<std::pair<std::ranges::range_value_t<R>, T>> res;

    for (const auto& x : r) {
      if (res.empty() || res.back().first != x) {
        res.emplace_back(x, 1);
      } else {
        ++res.back().second;
      }
    }

    return res;
  }

  template <std::ranges::input_range R>
  auto run_length(R&& r) {
    return tools::run_length<int>(std::forward<R>(r));
  }
}

#endif
