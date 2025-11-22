#ifndef TOOLS_LESS_BY_FIRST_HPP
#define TOOLS_LESS_BY_FIRST_HPP

#include <utility>

namespace tools {

  struct less_by_first {
    template <typename T1, typename T2>
    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const {
      return x.first < y.first;
    }
  };
}

#endif
