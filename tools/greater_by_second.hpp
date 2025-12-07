#ifndef TOOLS_GREATER_BY_SECOND_HPP
#define TOOLS_GREATER_BY_SECOND_HPP

#include <utility>

namespace tools {

  struct greater_by_second {
    template <typename T1, typename T2>
    bool operator()(const std::pair<T1, T2>& x, const std::pair<T1, T2>& y) const {
      return x.second > y.second;
    }
  };
}

#endif
