#ifndef TOOLS_GCD_CONVOLUTION_HPP
#define TOOLS_GCD_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include "tools/osa_k.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end) {
    if (c_begin == c_end) return;

    using T = ::std::decay_t<decltype(*a_begin)>;
    ::std::vector<T> a(a_begin, a_end);
    ::std::vector<T> b(b_begin, b_end);
    ::std::fill(c_begin, c_end, T(0));
    if (a.empty() || b.empty()) {
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

    ::tools::osa_k<::std::size_t> osa_k(::std::max({N, M, K}));
    for (const auto p : osa_k.prime_range(1, N)) {
      for (::std::size_t k = (N - 1) / p; k >= 1; --k) {
        a[k] += a[k * p];
      }
    }
    for (const auto p : osa_k.prime_range(1, M)) {
      for (::std::size_t k = (M - 1) / p; k >= 1; --k) {
        b[k] += b[k * p];
      }
    }

    a.resize(::std::min({N, M, K}));
    b.resize(::std::min({N, M, K}));
    for (::std::size_t i = 1; i < ::std::min({N, M, K}); ++i) {
      c_begin[i] = a[i] * b[i];
    }

    for (const auto p : osa_k.prime_range(1, K)) {
      for (::std::size_t k = 1; k * p < K; ++k) {
        c_begin[k] -= c_begin[k * p];
      }
    }

    for (::std::size_t i = 0; i < K; ++i) {
      c_begin[i] += base[i];
    }
  }
}

#endif
