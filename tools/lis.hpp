#ifndef TOOLS_LIS_HPP
#define TOOLS_LIS_HPP

#include <cstdint>
#include <iterator>
#include <vector>
#include <algorithm>
#include "atcoder/segtree.hpp"
#include "tools/monoid.hpp"
#include "tools/compress.hpp"

namespace tools {
  template <typename InputIterator>
  ::std::int_fast64_t lis(const InputIterator& begin, const InputIterator& end, const bool strict) {
    using M = ::tools::monoid::max<::std::int_fast64_t, 0>;

    ::std::vector<::std::int_fast64_t> compressed;
    ::tools::compress(begin, end, ::std::back_inserter(compressed));

    ::atcoder::segtree<::std::int_fast64_t, M::op, M::e> segtree(compressed.empty() ? 0 : *::std::max_element(compressed.begin(), compressed.end()) + 1);
    for (const ::std::int_fast64_t& c : compressed) {
      segtree.set(c, segtree.prod(0, c + (strict ? 0 : 1)) + 1);
    }

    return segtree.all_prod();
  }
}

#endif
