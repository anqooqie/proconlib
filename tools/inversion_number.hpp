#ifndef TOOLS_INVERSION_NUMBER_HPP
#define TOOLS_INVERSION_NUMBER_HPP

#include <algorithm>
#include <iterator>
#include <ranges>
#include <vector>
#include "atcoder/fenwicktree.hpp"
#include "tools/compress.hpp"

namespace tools {

  template <::std::ranges::range R>
  long long inversion_number(R&& a) {
    ::std::vector<int> compressed;
    ::tools::compress(a, ::std::back_inserter(compressed));

    if (compressed.empty()) return 0;

    const auto max = *::std::ranges::max_element(compressed);
    ::atcoder::fenwick_tree<int> fw(max + 1);
    long long res = 0;
    for (const auto x : compressed) {
      res += fw.sum(x + 1, max + 1);
      fw.add(x, 1);
    }

    return res;
  }
}

#endif
