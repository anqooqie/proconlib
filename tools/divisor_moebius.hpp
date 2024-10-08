#ifndef TOOLS_DIVISOR_MOEBIUS_HPP
#define TOOLS_DIVISOR_MOEBIUS_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/eratosthenes_sieve.hpp"

namespace tools {
  template <typename RandomAccessIterator>
  void divisor_moebius(const RandomAccessIterator begin, const RandomAccessIterator end) {
    const int N = end - begin;
    if (N < 2) return;

    ::tools::eratosthenes_sieve<int> sieve(N - 1);
    for (const auto p : sieve.prime_range(1, N - 1)) {
      for (int i = (N - 1) / p; i >= 1; --i) {
        begin[i * p] -= begin[i];
      }
    }
  }

  template <typename InputIterator, typename OutputIterator>
  void divisor_moebius(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> b(begin, end);
    ::tools::divisor_moebius(b.begin(), b.end());
    ::std::move(b.begin(), b.end(), result);
  }
}

#endif
