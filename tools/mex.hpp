#ifndef TOOLS_MEX_HPP
#define TOOLS_MEX_HPP

#include <iterator>
#include <vector>

namespace tools {

  template <typename InputIterator>
  typename ::std::iterator_traits<InputIterator>::value_type mex(InputIterator begin, InputIterator end) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    const ::std::vector<T> orig(begin, end);
    const T n = orig.size();
    ::std::vector<bool> exists(n, false);
    for (const auto& o : orig) {
      if (0 <= o && o < n) {
        exists[o] = true;
      }
    }
    for (T i = 0; i < n; ++i) {
      if (!exists[i]) {
        return i;
      }
    }
    return n;
  }
}

#endif
