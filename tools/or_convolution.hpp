#ifndef TOOLS_OR_CONVOLUTION_HPP
#define TOOLS_OR_CONVOLUTION_HPP

#include <iterator>
#include <vector>
#include "tools/subset_zeta.hpp"
#include "tools/subset_moebius.hpp"

namespace tools {
  template <typename InputIterator, typename RandomAccessIterator>
  void or_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end) {
    using T = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<T> a(a_begin, a_end);
    std::vector<T> b(b_begin, b_end);
    const int K = std::distance(c_begin, c_end);

    a.resize(K, T(0));
    tools::subset_zeta(a.begin(), a.end());
    b.resize(K, T(0));
    tools::subset_zeta(b.begin(), b.end());

    for (int i = 0; i < K; ++i) {
      c_begin[i] = a[i] * b[i];
    }
    tools::subset_moebius(c_begin, c_end);
  }
}

#endif
