#ifndef TOOLS_LARGEST_RECTANGLE_IN_HISTOGRAM_HPP
#define TOOLS_LARGEST_RECTANGLE_IN_HISTOGRAM_HPP

#include <iterator>
#include <stack>
#include <utility>
#include <tuple>
#include "tools/chmax.hpp"

namespace tools {
  template <typename InputIterator>
  typename std::iterator_traits<InputIterator>::value_type largest_rectangle_in_histogram(const InputIterator& begin, const InputIterator& end) {
    using T = typename std::iterator_traits<InputIterator>::value_type;

    T result = 0;
    std::stack<std::pair<T, T>> dp;
    for (auto [i, it, breaks] = std::make_tuple(0, begin, false); !breaks; ++i, breaks = it == end, it = std::next(it, breaks ? 0 : 1)) {
      const T v = it != end ? *it : 0;
      if (dp.empty() || dp.top().second < v) {
        dp.emplace(i, v);
      } else if (dp.top().second > v) {
        T leftmost;
        while (!dp.empty() && dp.top().second > v) {
          leftmost = dp.top().first;
          tools::chmax(result, dp.top().second * (i - dp.top().first));
          dp.pop();
        }
        if (dp.empty() || dp.top().second < v) {
          dp.emplace(leftmost, v);
        }
      }
    }

    return result;
  }
}

#endif
