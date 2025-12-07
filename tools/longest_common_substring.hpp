#ifndef TOOLS_LONGEST_COMMON_SUBSTRING_HPP
#define TOOLS_LONGEST_COMMON_SUBSTRING_HPP

#include <tuple>
#include <cstddef>
#include <type_traits>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "atcoder/string.hpp"
#include "tools/mex.hpp"
#include "tools/chmax.hpp"

namespace tools {
  template <typename InputIterator>
  std::tuple<std::size_t, std::size_t, std::size_t, std::size_t> longest_common_substring(const InputIterator S_begin, const InputIterator S_end, const InputIterator T_begin, const InputIterator T_end) {
    using Z = std::decay_t<decltype(*std::declval<InputIterator>())>;
    using Container = std::conditional_t<std::is_same_v<Z, char>, std::string, std::vector<Z>>;

    Container ST(S_begin, S_end);
    const int N = ST.size();
    std::copy(T_begin, T_end, std::back_inserter(ST));
    const int M = ST.size() - N;

    ST.push_back(tools::mex(ST.begin(), ST.end()));
    std::rotate(std::next(ST.begin(), N), std::prev(ST.end()), ST.end());

    const auto sa = atcoder::suffix_array(ST);
    const auto lcpa = atcoder::lcp_array(ST, sa);

    int a = 0;
    int c = 0;
    int l = 0;
    const auto is_in_S = [&](const int i) { return i < N; };
    const auto is_in_T = [&](const int i) { return N + 1 <= i; };

    for (int i = 1; i < N + M + 1; ++i) {
      if (is_in_S(sa[i]) && is_in_T(sa[i - 1])) {
        if (tools::chmax(l, lcpa[i - 1])) {
          a = sa[i];
          c = sa[i - 1] - (N + 1);
        }
      } else if (is_in_T(sa[i]) && is_in_S(sa[i - 1])) {
        if (tools::chmax(l, lcpa[i - 1])) {
          a = sa[i - 1];
          c = sa[i] - (N + 1);
        }
      }
    }

    return std::make_tuple(a, a + l, c, c + l);
  }
}

#endif
