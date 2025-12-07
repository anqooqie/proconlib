#ifndef TOOLS_CEIL_KTH_ROOT_HPP
#define TOOLS_CEIL_KTH_ROOT_HPP

#include <cassert>
#include "tools/ceil_sqrt.hpp"
#include "tools/ceil.hpp"
#include "tools/pow.hpp"
#include "tools/safe_int.hpp"

namespace tools {

  template <typename T, typename U>
  T ceil_kth_root(const T x, const U k) {
    assert(x >= 0);
    assert(k >= 1);

    if (x == 0) return 0;
    if (k == 1) return x;
    if (k == 2) return tools::ceil_sqrt(x);
    if (k == 3) {
      T ok = 1;
      T ng;
      for (ng = 2; (ng - 1) * (ng - 1) < tools::ceil(x, ng - 1); ng *= 2);

      while (ng - ok > 1) {
        const T mid = ok + (ng - ok) / 2;
        if ((mid - 1) * (mid - 1) < tools::ceil(x, mid - 1)) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      return ok;
    }

    T ok = 1;
    T ng;
    for (ng = 2; tools::pow(tools::safe_int<T>(ng - 1), k) < tools::safe_int<T>(x); ng *= 2);

    while (ng - ok > 1) {
      const T mid = ok + (ng - ok) / 2;
      if (tools::pow(tools::safe_int<T>(mid - 1), k) < tools::safe_int<T>(x)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
}

#endif
