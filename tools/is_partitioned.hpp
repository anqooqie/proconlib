#ifndef TOOLS_IS_PARTITIONED_HPP
#define TOOLS_IS_PARTITIONED_HPP

#include <cassert>

namespace tools {
  template <typename T, typename F>
  bool is_partitioned(const T l, const T r, const F& f) {
    assert(l <= r);

    if (r - l <= 1) return true;

    const bool f_l = f(l);
    T m;
    for (m = l + 1; m <= r && f(m) == f_l; ++m);
    if (r < m) return true;

    for (++m; m <= r && f(m) != f_l; ++m);
    if (r < m) return true;

    return false;
  }
}

#endif
