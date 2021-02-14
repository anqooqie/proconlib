#ifndef TOOLS_INVERSION_NUMBER_HPP
#define TOOLS_INVERSION_NUMBER_HPP

#include <iterator>
#include <algorithm>
#include <cstddef>
#include "atcoder/fenwicktree.hpp"
#include "tools/compress.hpp"

namespace tools {

  /**
   * returns the number of inversions
   * License: CC0
   * @author anqooqie
   * @param <Iterator> type of the iterators
   * @param begin beginning iterator
   * @param end end iterator
   * @return the number of inversions
   */
  template <typename Iterator>
  typename ::std::iterator_traits<Iterator>::value_type inversion_number(Iterator begin, Iterator end) {
    using T = typename ::std::iterator_traits<Iterator>::value_type;

    ::std::vector<T> compressed;
    ::tools::compress(begin, end, ::std::back_inserter(compressed));

    if (compressed.empty()) return 0;

    ::atcoder::fenwick_tree<T> fw(*::std::max_element(compressed.begin(), compressed.end()) + 1);
    T result = 0;
    for (::std::size_t i = 0; i < compressed.size(); ++i) {
      result += i - fw.sum(0, compressed[i] + 1);
      fw.add(compressed[i], 1);
    }

    return result;
  }
}

#endif
