#ifndef TOOLS_GCD_CONVOLUTION_HPP
#define TOOLS_GCD_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include "tools/eratosthenes_sieve.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end) {
    if (c_begin == c_end) return;

    using T = ::std::decay_t<decltype(*a_begin)>;
    ::std::vector<T> a(a_begin, a_end);
    ::std::vector<T> b(b_begin, b_end);
    if (a.empty() || b.empty()) {
      ::std::fill(c_begin, c_end, T(0));
      return;
    }
    const ::std::size_t N = a.size();
    const ::std::size_t M = b.size();
    const ::std::size_t K = ::std::distance(c_begin, c_end);

    ::std::vector<T> base(K, T(0));
    base[0] = a[0] * b[0];
    for (::std::size_t i = 1; i < ::std::min(N, K); ++i) {
      base[i] += a[i] * b[0];
    }
    for (::std::size_t i = 1; i < ::std::min(M, K); ++i) {
      base[i] += a[0] * b[i];
    }

    ::tools::eratosthenes_sieve<::std::size_t> sieve(::std::max({N, M, K}) > 2 ? ::std::max({N, M, K}) - 1 : 1);
    if (N > 1) {
      for (const auto p : sieve.prime_range(1, N - 1)) {
        for (::std::size_t k = (N - 1) / p; k >= 1; --k) {
          a[k] += a[k * p];
        }
      }
    }
    if (M > 1) {
      for (const auto p : sieve.prime_range(1, M - 1)) {
        for (::std::size_t k = (M - 1) / p; k >= 1; --k) {
          b[k] += b[k * p];
        }
      }
    }

    for (::std::size_t i = 1; i < ::std::min({N, M, K}); ++i) {
      c_begin[i] = a[i] * b[i];
    }
    ::std::fill(::std::next(c_begin, ::std::min({N, M, K})), c_end, T(0));

    if (K > 1) {
      for (const auto p : sieve.prime_range(1, K - 1)) {
        for (::std::size_t k = 1; k * p < K; ++k) {
          c_begin[k] -= c_begin[k * p];
        }
      }
    }

    for (::std::size_t i = 0; i < K; ++i) {
      c_begin[i] += base[i];
    }
  }
}

#endif
