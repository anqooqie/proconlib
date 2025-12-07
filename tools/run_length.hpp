#ifndef TOOLS_RUN_LENGTH_HPP
#define TOOLS_RUN_LENGTH_HPP

#include <iterator>
#include <cstddef>
#include <utility>
#include <cstdint>

namespace tools {
  template <typename InputIterator, typename OutputIterator>
  void run_length(const InputIterator& begin, const InputIterator& end, OutputIterator result) {
    using T = typename std::iterator_traits<InputIterator>::value_type;
    if (begin == end) return;

    std::pair<T, std::size_t> prev;
    for (auto [it, breaks] = std::make_pair(begin, false); !breaks; breaks = it == end, it = std::next(it, breaks ? 0 : 1)) {
      bool flg1, flg2;
      if (it == begin) {
        flg1 = false;
        flg2 = true;
      } else if (it == end) {
        flg1 = true;
        flg2 = false;
      } else if (*it != prev.first) {
        flg1 = true;
        flg2 = true;
      } else {
        flg1 = false;
        flg2 = false;
      }
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
