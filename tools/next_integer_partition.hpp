#ifndef TOOLS_NEXT_INTEGER_PARTITION
#define TOOLS_NEXT_INTEGER_PARTITION

#include <algorithm>
#include <cassert>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral Z>
  bool next_integer_partition(std::vector<Z>& a) {
    assert(!a.empty());
    assert(a.back() >= 1);
    assert(std::ranges::all_of(a | std::views::adjacent<2>, [](const auto& pair) { return std::get<0>(pair) >= std::get<1>(pair); }));

    if (a.front() == 1) {
      const Z sum = a.size();
      a.clear();
      a.push_back(sum);
      return false;
    }

    Z remain = 0;
    while (a.back() == 1) {
      ++remain;
      a.pop_back();
    }

    --a.back();
    ++remain;
    const Z bound = a.back();
    while (remain > 0) {
      a.push_back(std::min(remain, bound));
      remain -= a.back();
    }

    return true;
  }

  template <tools::integral Z1, tools::integral Z2>
  bool next_integer_partition(std::vector<std::pair<Z1, Z2>>& a) {
    assert(!a.empty());
    assert(a.back().first >= 1);
    assert(std::ranges::all_of(a | std::views::adjacent<2>, [](const auto& pair) { return std::get<0>(pair).first > std::get<1>(pair).first; }));
    assert(std::ranges::all_of(a, [](const auto& a_i) { return a_i.second >= 1; }));

    if (a.front().first == 1) {
      assert(a.size() == 1);
      a.front() = std::pair<Z1, Z2>{a.front().second, 1};
      return false;
    }

    Z1 remain = 0;
    if (a.back().first == 1) {
      remain = a.back().second;
      a.pop_back();
    }

    assert(!a.empty());
    assert(a.back().first >= 2);
    --a.back().second;
    remain += a.back().first;
    const Z1 bound = a.back().first - 1;
    if (a.back().second == 0) {
      a.pop_back();
    }

    a.emplace_back(bound, remain / bound);
    remain -= bound * a.back().second;
    if (remain > 0) {
      a.emplace_back(remain, 1);
    }

    return true;
  }
}

#endif
