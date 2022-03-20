#ifndef TOOLS_CEIL_SQRT_HPP
#define TOOLS_CEIL_SQRT_HPP

#include <cassert>

namespace tools {

  template <typename T>
  T ceil_sqrt(T n) {
    assert(n >= 0);

    T ok = 0;
    T ng;
    for (ng = 1; (ng - 1) * (ng - 1) < n; ng *= 2);

    while (ng - ok > 1) {
      const T mid = ok + (ng - ok) / 2;
      if ((mid - 1) * (mid - 1) < n) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
}

#endif
