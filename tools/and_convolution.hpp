#ifndef TOOLS_AND_CONVOLUTION_HPP
#define TOOLS_AND_CONVOLUTION_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/superset_zeta.hpp"
#include "tools/superset_moebius.hpp"

namespace tools {
  template <typename InputIterator, typename RandomAccessIterator>
  void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end) {
    using T = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<T> a(a_begin, a_end);
    std::vector<T> b(b_begin, b_end);
    const int N = a.size();
    const int M = b.size();
    const int K = std::distance(c_begin, c_end);

    tools::superset_zeta(a.begin(), a.end());
    tools::superset_zeta(b.begin(), b.end());

    if (std::min(N, M) <= K) {
      for (int i = 0; i < std::min(N, M); ++i) {
        c_begin[i] = a[i] * b[i];
      }
      tools::superset_moebius(c_begin, c_begin + std::min(N, M));
      std::fill(c_begin + std::min(N, M), c_end, T(0));
    } else {
      std::vector<T> c;
      c.reserve(std::min(N, M));
      for (int i = 0; i < std::min(N, M); ++i) {
        c.push_back(a[i] * b[i]);
      }
      tools::superset_moebius(c.begin(), c.end());
      std::move(c.begin(), c.begin() + K, c_begin);
    }
  }
}

#endif
