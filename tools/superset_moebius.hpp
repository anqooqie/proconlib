#ifndef TOOLS_SUPERSET_MOEBIUS_HPP
#define TOOLS_SUPERSET_MOEBIUS_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/pow2.hpp"

namespace tools {
  template <typename RandomAccessIterator>
  void superset_moebius(const RandomAccessIterator begin, const RandomAccessIterator end) {
    const int N = end - begin;

    for (int w = 0; ::tools::pow2(w) < N; ++w) {
      for (int i = 0; ; i += ::tools::pow2(w)) {
        for (; !((i >> w) & 1); ++i) {
          if (!(i + ::tools::pow2(w) < N)) goto NEXT_W;
          begin[i] -= begin[i + ::tools::pow2(w)];
        }
      }
    NEXT_W:
      ;
    }
  }

  template <typename InputIterator, typename OutputIterator>
  void superset_moebius(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> b(begin, end);
    ::tools::superset_moebius(b.begin(), b.end());
    ::std::move(b.begin(), b.end(), result);
  }
}

#endif
