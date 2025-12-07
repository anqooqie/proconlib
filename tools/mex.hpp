#ifndef TOOLS_MEX_HPP
#define TOOLS_MEX_HPP

#include <type_traits>
#include <utility>
#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>

namespace tools {

  template <typename InputIterator>
  std::decay_t<decltype(*std::declval<InputIterator>())> mex(InputIterator begin, InputIterator end) {
    using T = std::decay_t<decltype(*std::declval<InputIterator>())>;
    const std::vector<T> orig(begin, end);
    const std::size_t n = orig.size();

    assert(std::all_of(orig.begin(), orig.end(), [](const auto& o) { return o >= 0; }));

    std::vector<bool> exists(n, false);
    for (const std::size_t o : orig) {
      if (o < n) {
        exists[o] = true;
      }
    }
    for (std::size_t i = 0; i < n; ++i) {
      if (!exists[i]) {
        return i;
      }
    }
    return n;
  }
}

#endif
