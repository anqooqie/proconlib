#ifndef TOOLS_BATCH_SORT_HPP
#define TOOLS_BATCH_SORT_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/permutation.hpp"

namespace tools {
  template <std::strict_weak_order<int, int> Compare, typename R0, typename... Rs>
  requires std::ranges::random_access_range<R0> && (std::ranges::random_access_range<Rs> && ...)
        && std::ranges::sized_range<R0> && (std::ranges::sized_range<Rs> && ...)
  tools::permutation<int> batch_sort(const Compare comp, R0& r0, Rs&... rs) {
    const int n = std::ranges::size(r0);
    assert(((std::ranges::ssize(rs) == n) && ...));

    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::ranges::sort(indices, comp);

    const auto reorder = [&]<typename R>(R& r) {
      std::vector<std::ranges::range_value_t<R>> tmp(n);
      auto begin = std::ranges::begin(r);
      for (int i = 0; i < n; ++i) {
        tmp[i] = std::move(begin[indices[i]]);
      }
      std::ranges::move(tmp, begin);
    };
    reorder(r0);
    (reorder(rs), ...);

    return tools::permutation<int>(std::move(indices)).inv();
  }
}

#endif
