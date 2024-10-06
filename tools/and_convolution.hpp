#ifndef TOOLS_AND_CONVOLUTION_HPP
#define TOOLS_AND_CONVOLUTION_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include "tools/superset_zeta.hpp"
#include "tools/superset_moebius.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end) {
    using T = ::std::decay_t<decltype(*a_begin)>;
    ::std::vector<T> a(a_begin, a_end);
    ::std::vector<T> b(b_begin, b_end);
    const ::std::size_t N = a.size();
    const ::std::size_t M = b.size();
    const ::std::size_t K = ::std::distance(c_begin, c_end);

    a.resize(::std::min({N, M, K}));
    b.resize(::std::min({N, M, K}));

    ::tools::superset_zeta(a.begin(), a.end());
    ::tools::superset_zeta(b.begin(), b.end());

    for (::std::size_t i = 0; i < ::std::min({N, M, K}); ++i) {
      c_begin[i] = a[i] * b[i];
    }
    ::std::fill(::std::next(c_begin, ::std::min({N, M, K})), c_end, T(0));

    ::tools::superset_moebius(c_begin, c_end);
  }
}

#endif
