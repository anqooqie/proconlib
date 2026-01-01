#ifndef TOOLS_INVERSION_NUMBER_HPP
#define TOOLS_INVERSION_NUMBER_HPP

#include <algorithm>
#include <concepts>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/fenwicktree.hpp"
#include "tools/compressed.hpp"

namespace tools {

  template <std::ranges::input_range R>
  requires std::totally_ordered<std::ranges::range_value_t<R>>
  long long inversion_number(R&& a) {
    const auto compressed = tools::compressed<int>(std::forward<R>(a));

    if (compressed.empty()) return 0;

    const auto max = std::ranges::max(compressed);
    atcoder::fenwick_tree<int> fw(max + 1);
    long long res = 0;
    for (const auto x : compressed) {
      res += fw.sum(x + 1, max + 1);
      fw.add(x, 1);
    }

    return res;
  }
}

#endif
