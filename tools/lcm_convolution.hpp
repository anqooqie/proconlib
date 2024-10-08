#ifndef TOOLS_LCM_CONVOLUTION_HPP
#define TOOLS_LCM_CONVOLUTION_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/divisor_zeta.hpp"
#include "tools/divisor_moebius.hpp"

namespace tools {
  template <typename InputIterator, typename RandomAccessIterator>
  void lcm_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> a(a_begin, a_end);
    ::std::vector<T> b(b_begin, b_end);
    const int N = a.size();
    const int M = b.size();
    const int K = ::std::distance(c_begin, c_end);

    if (::std::min({N, M, K}) > 0) {
      c_begin[0] = a[0] * b[0];
    }
    if (::std::min(M, K) > 0) {
      for (int i = 1; i < N; ++i) {
        c_begin[0] += a[i] * b[0];
      }
    }
    if (::std::min(N, K) > 0) {
      for (int i = 1; i < M; ++i) {
        c_begin[0] += a[0] * b[i];
      }
    }

    a.resize(K, T(0));
    ::tools::divisor_zeta(a.begin(), a.end());
    b.resize(K, T(0));
    ::tools::divisor_zeta(b.begin(), b.end());

    for (int i = 1; i < K; ++i) {
      c_begin[i] = a[i] * b[i];
    }
    ::tools::divisor_moebius(c_begin, c_end);
  }
}

#endif
