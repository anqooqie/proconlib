#ifndef TOOLS_LIS_HPP
#define TOOLS_LIS_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "atcoder/segtree.hpp"
#include "tools/monoid.hpp"
#include "tools/compress.hpp"

namespace tools {
  template <typename InputIterator>
  typename ::std::iterator_traits<InputIterator>::value_type lis(const InputIterator& begin, const InputIterator& end, const bool strict) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    using M = ::tools::monoid::max<T, 0>;

    ::std::vector<T> compressed;
    ::tools::compress(begin, end, ::std::back_inserter(compressed));

    ::atcoder::segtree<T, M::op, M::e> segtree(compressed.empty() ? 0 : *::std::max_element(compressed.begin(), compressed.end()) + 1);
    for (const T& c : compressed) {
      segtree.set(c, segtree.prod(0, c + (strict ? 0 : 1)) + 1);
    }

    return segtree.all_prod();
  }
}

#endif
