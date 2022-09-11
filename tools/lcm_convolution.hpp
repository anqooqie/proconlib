#ifndef TOOLS_LCM_CONVOLUTION_HPP
#define TOOLS_LCM_CONVOLUITON_HPP

#include <type_traits>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include "tools/osa_k.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void lcm_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end) {
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

    c_begin[0] = a[0] * b[0];
    for (::std::size_t i = 1; i < N; ++i) {
      c_begin[0] += a[i] * b[0];
    }
    for (::std::size_t i = 1; i < M; ++i) {
      c_begin[0] += a[0] * b[i];
    }

    a.resize(K, T(0));
    b.resize(K, T(0));
    ::tools::osa_k<::std::size_t> osa_k(K);
    for (const auto p : osa_k.prime_range(1, K)) {
      for (::std::size_t k = 1; k * p < K; ++k) {
        a[k * p] += a[k];
        b[k * p] += b[k];
      }
    }

    for (::std::size_t i = 1; i < K; ++i) {
      c_begin[i] = a[i] * b[i];
    }

    for (const auto p : osa_k.prime_range(1, K)) {
      for (::std::size_t k = (K - 1) / p; k >= 1; --k) {
        c_begin[k * p] -= c_begin[k];
      }
    }
  }
}

#endif
