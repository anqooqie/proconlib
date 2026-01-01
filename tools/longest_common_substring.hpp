#ifndef TOOLS_LONGEST_COMMON_SUBSTRING_HPP
#define TOOLS_LONGEST_COMMON_SUBSTRING_HPP

#include <algorithm>
#include <concepts>
#include <iterator>
#include <ranges>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/string.hpp"
#include "tools/mex.hpp"
#include "tools/chmax.hpp"

namespace tools {
  template <std::ranges::input_range R1, std::ranges::input_range R2>
  requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>> && (
    std::same_as<std::ranges::range_value_t<R1>, char> ||
    std::same_as<std::ranges::range_value_t<R1>, int> ||
    std::same_as<std::ranges::range_value_t<R1>, unsigned int> ||
    std::same_as<std::ranges::range_value_t<R1>, long long> ||
    std::same_as<std::ranges::range_value_t<R1>, unsigned long long> 
  )
  std::tuple<int, int, int, int> longest_common_substring(R1&& S, R2&& T) {
    using Z = std::ranges::range_value_t<R1>;
    using Container = std::conditional_t<std::same_as<Z, char>, std::string, std::vector<Z>>;

    auto ST = std::forward<R1>(S) | std::ranges::to<Container>();
    const int N = ST.size();
    std::ranges::copy(std::forward<R2>(T), std::back_inserter(ST));
    const int M = ST.size() - N;

    ST.push_back(tools::mex(ST));
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
