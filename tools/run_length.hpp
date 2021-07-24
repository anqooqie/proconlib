#ifndef TOOLS_RUN_LENGTH_HPP
#define TOOLS_RUN_LENGTH_HPP

#include <iterator>
#include <utility>
#include <cstdint>

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void run_length(const InputIterator& begin, const InputIterator& end, OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    if (begin == end) return;

    ::std::pair<T, ::std::int_fast64_t> prev;
    for (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks = it == end, it = ::std::next(it, breaks ? 0 : 1)) {
      const auto [flg1, flg2] = [&]() {
        if (it == begin) return ::std::make_pair(false, true);
        if (it == end) return ::std::make_pair(true, false);
        if (*it != prev.first) return ::std::make_pair(true, true);
        return ::std::make_pair(false, false);
      }();
      if (flg1 || flg2) {
        if (flg1) {
          *result = prev;
          ++result;
        }
        if (flg2) {
          prev.first = *it;
          prev.second = 1;
        }
      } else {
        ++prev.second;
      }
    }
  }
}

#endif
