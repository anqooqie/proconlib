#ifndef TOOLS_FLOOR_SQRT_HPP
#define TOOLS_FLOOR_SQRT_HPP

#include <cassert>

namespace tools {

  template <typename T>
  T floor_sqrt(const T n) {
    assert(n >= 0);

    T ok = 0;
    T ng;
    for (ng = 1; ng <= n / ng; ng *= 2);

    while (ng - ok > 1) {
      const T mid = ok + (ng - ok) / 2;
      if (mid <= n / mid) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
}

#endif
