#ifndef TOOLS_CEIL_SQRT_HPP
#define TOOLS_CEIL_SQRT_HPP

#include <cassert>
#include "tools/ceil.hpp"

namespace tools {

  template <typename T>
  T ceil_sqrt(const T n) {
    assert(n >= 0);

    if (n == 0) return 0;

    T ok = 1;
    T ng;
    for (ng = 2; ng - 1 < tools::ceil(n, ng - 1); ng *= 2);

    while (ng - ok > 1) {
      const T mid = ok + (ng - ok) / 2;
      if (mid - 1 < tools::ceil(n, mid - 1)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
}

#endif
