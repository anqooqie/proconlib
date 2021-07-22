#ifndef TOOLS_LESS_BY_ARG_HPP
#define TOOLS_LESS_BY_ARG_HPP

#include "tools/vector2.hpp"

// Source: https://codeforces.com/blog/entry/72815
// License: unknown
// Author: Alpha_Q

namespace tools {

  class less_by_arg {
  public:
    template <typename T>
    bool operator()(const ::tools::vector2<T>& a, const ::tools::vector2<T>& b) const {
      const auto up = [](const ::tools::vector2<T>& p) {
        return p.y > 0 || (p.y == 0 && p.x >= 0);
      };
      return up(a) == up(b) ? a.x * b.y > a.y * b.x : up(a) < up(b);
    }
  };
}

#endif
