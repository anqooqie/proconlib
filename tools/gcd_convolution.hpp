#ifndef TOOLS_GCD_CONVOLUTION_HPP
#define TOOLS_GCD_CONVOLUTION_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/multiple_zeta.hpp"
#include "tools/multiple_moebius.hpp"

namespace tools {
  template <typename InputIterator, typename RandomAccessIterator>
  void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end) {
    using T = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<T> a(a_begin, a_end);
    std::vector<T> b(b_begin, b_end);
    const int N = a.size();
    const int M = b.size();
    const int K = std::distance(c_begin, c_end);

    std::vector<T> offset(std::min(std::max(N, M), K), T(0));
    if (std::min({N, M, K}) > 0) {
      offset[0] += a[0] * b[0];
    }
    if (M > 0) {
      for (int i = 1; i < std::min(N, K); ++i) {
        offset[i] += a[i] * b[0];
      }
    }
    if (N > 0) {
      for (int i = 1; i < std::min(M, K); ++i) {
        offset[i] += a[0] * b[i];
      }
    }

    tools::multiple_zeta(a.begin(), a.end());
    tools::multiple_zeta(b.begin(), b.end());

    if (std::min(N, M) <= K) {
      if (std::min(N, M) > 0) {
        c_begin[0] = 0;
      }
      for (int i = 1; i < std::min(N, M); ++i) {
        c_begin[i] = a[i] * b[i];
      }
      tools::multiple_moebius(c_begin, c_begin + std::min(N, M));
      std::fill(c_begin + std::min(N, M), c_end, T(0));
    } else {
      std::vector<T> c;
      c.reserve(std::min(N, M));
      c.push_back(0);
      for (int i = 1; i < std::min(N, M); ++i) {
        c.push_back(a[i] * b[i]);
      }
      tools::multiple_moebius(c.begin(), c.end());
      std::move(c.begin(), c.begin() + K, c_begin);
    }

    for (int i = 0; i < std::min(std::max(N, M), K); ++i) {
      c_begin[i] += offset[i];
    }
  }
}

#endif
