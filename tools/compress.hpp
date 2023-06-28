#ifndef TOOLS_COMPRESS_HPP
#define TOOLS_COMPRESS_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void compress(InputIterator begin, InputIterator end, OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> orig(begin, end);
    ::std::vector<T> sorted(orig);
    ::std::sort(sorted.begin(), sorted.end());
    sorted.erase(::std::unique(sorted.begin(), sorted.end()), sorted.end());
    for (auto it = orig.begin(); it != orig.end(); ++it, ++result) {
      *result = ::tools::lower_bound(sorted.begin(), sorted.end(), *it);
    }
  }
}

#endif
