#ifndef TOOLS_MANACHER_HPP
#define TOOLS_MANACHER_HPP

#include <iterator>
#include <vector>
#include <cstddef>
#include <utility>
#include <algorithm>
#include "tools/mex.hpp"

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void manacher(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> S(begin, end);
    const auto N = S.size();
    {
      ::std::vector<T> new_S(2 * N + 1, ::tools::mex(S.begin(), S.end()));
      for (::std::size_t i = 0; i < N; ++i) {
        new_S[2 * i + 1] = S[i];
      }
      S = ::std::move(new_S);
    }

    ::std::vector<::std::size_t> R(S.size());
    {
      ::std::size_t i = 0;
      ::std::size_t j = 0;
      while (i < S.size()) {
        for (; i >= j && i + j < S.size() && S[i - j] == S[i + j]; ++j);
        R[i] = j;
        ::std::size_t k;
        for (k = 1; i >= k && k + R[i - k] < j; ++k) {
          R[i + k] = R[i - k];
        }
        i += k;
        j -= k;
      }
    }

    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> new_R(S.size());
    for (::std::size_t i = 0; i <= N; ++i) {
      new_R[i * 2] = ::std::make_pair(i - (R[i * 2] - 1) / 2, i + (R[i * 2] - 1) / 2);
    }
    for (::std::size_t i = 0; i < N; ++i) {
      new_R[i * 2 + 1] = ::std::make_pair(i - (R[i * 2 + 1] / 2 - 1), i + R[i * 2 + 1] / 2);
    }
    ::std::move(new_R.begin(), new_R.end(), result);
  }
}

#endif
