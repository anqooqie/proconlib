#ifndef TOOLS_DIVISOR_ZETA_HPP
#define TOOLS_DIVISOR_ZETA_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/eratosthenes_sieve.hpp"

namespace tools {
  template <typename RandomAccessIterator>
  void divisor_zeta(const RandomAccessIterator begin, const RandomAccessIterator end) {
    const int N = end - begin;
    if (N < 2) return;

    ::tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = 1; i * p < N; ++i) {
        begin[i * p] += begin[i];
      }
    }
  }

  template <typename InputIterator, typename OutputIterator>
  void divisor_zeta(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> a(begin, end);
    ::tools::divisor_zeta(a.begin(), a.end());
    ::std::move(a.begin(), a.end(), result);
  }
}

#endif
