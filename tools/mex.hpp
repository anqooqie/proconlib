#ifndef TOOLS_MEX_HPP
#define TOOLS_MEX_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/cmp_less.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <std::ranges::input_range R>
  requires tools::integral<std::ranges::range_value_t<R>>
  std::ranges::range_value_t<R> mex(R&& a) {
    if constexpr (std::ranges::forward_range<R>) {
      assert(std::ranges::all_of(a, [](const auto& a_i) { return a_i >= 0; }));

      using T = std::ranges::range_value_t<R>;
      const int n = std::ranges::distance(a);

      std::vector<bool> exists(n, false);
      for (const auto& a_i : a) {
        if (tools::cmp_less(a_i, n)) {
          exists[a_i] = true;
        }
      }

      for (int i = 0; i < n; ++i) {
        if (!exists[i]) {
          return static_cast<T>(i);
        }
      }
      return static_cast<T>(n);
    } else {
      return tools::mex(std::forward<R>(a) | std::ranges::to<std::vector>());
    }
  }
}

#endif
