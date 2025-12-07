#ifndef TOOLS_GOLDEN_SECTION_SEARCH_HPP
#define TOOLS_GOLDEN_SECTION_SEARCH_HPP

#include <utility>
#include <type_traits>
#include <cassert>
#include <cmath>
#include <limits>
#include <array>
#include <algorithm>

namespace tools {
  template <typename T, typename F>
  auto golden_section_search(const T l, const T r, const F& f, const bool search_maximum) -> std::pair<T, std::decay_t<decltype(f(std::declval<T>()))>> {
    assert(l <= r);

    using V = std::decay_t<decltype(f(std::declval<T>()))>;
    const auto comp = [&](const V x, const V y) { return search_maximum ? x < y : x > y; };
    const T phi = (std::sqrt(T(5)) + T(1)) / T(2);
    const T phi_inv = (std::sqrt(T(5)) - T(1)) / T(2);
    const int loop_count = static_cast<int>(std::ceil(std::numeric_limits<T>::digits / std::log2(phi))) - 2;

    std::array<std::pair<T, V>, 4> search;
    search[0] = std::make_pair(l, f(l));
    search[3] = std::make_pair(r, f(r));
    T resolution = (r - l) * phi_inv;
    search[2] = std::make_pair(l + resolution, f(l + resolution));
    resolution *= phi_inv;
    search[1] = std::make_pair(l + resolution, f(l + resolution));

    for (int i = 0; i < loop_count; ++i) {
      if (comp(search[1].second, search[2].second)) {
        search[0] = search[1];
        search[1] = search[2];
        resolution *= phi_inv;
        search[2] = std::make_pair(search[3].first - resolution, f(search[3].first - resolution));
      } else {
        search[3] = search[2];
        search[2] = search[1];
        resolution *= phi_inv;
        search[1] = std::make_pair(search[0].first + resolution, f(search[0].first + resolution));
      }
    }

    return *std::max_element(search.begin(), search.end(), [&](const auto& x, const auto& y) { return comp(x.second, y.second); });
  }
}

#endif
