#ifndef TOOLS_LIS_HPP
#define TOOLS_LIS_HPP

#include <tuple>
#include <vector>
#include <type_traits>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include "tools/persistent_stack.hpp"

namespace tools {
  template <typename InputIterator>
  auto lis(const InputIterator begin, const InputIterator end, const bool strict) -> ::std::pair<::std::vector<::std::decay_t<decltype(*begin)>>, ::std::vector<::std::size_t>> {
    using T = ::std::decay_t<decltype(*begin)>;
    ::std::vector<T> a(begin, end);
    ::tools::persistent_stack<::std::size_t>::buffer buffer;
    ::std::vector<::tools::persistent_stack<::std::size_t>> dp({::tools::persistent_stack<::std::size_t>(buffer)});

    for (::std::size_t i = 0; i < a.size(); ++i) {
      ::std::size_t ok = 0;
      ::std::size_t ng = dp.size();
      while (ng - ok > 1) {
        const auto mid = ok + (ng - ok) / 2;
        if (a[dp[mid].top()] < a[i] + (strict ? 0 : 1)) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      if (ng < dp.size()) {
        if (a[i] < a[dp[ng].top()]) {
          dp[ng] = dp[ok].push(i);
        }
      } else {
        dp.push_back(dp[ok].push(i));
      }
    }

    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> res;
    auto& [lis, indices] = res;

    for (auto stack = dp.back(); !stack.empty(); stack = stack.pop()) {
      indices.push_back(stack.top());
    }
    ::std::reverse(indices.begin(), indices.end());
    ::std::transform(indices.begin(), indices.end(), ::std::back_inserter(lis), [&](const ::std::size_t i) { return a[i]; });

    return res;
  }
}

#endif
