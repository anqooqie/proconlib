#ifndef TOOLS_FLOOR_KTH_ROOT_HPP
#define TOOLS_FLOOR_KTH_ROOT_HPP

#include <cassert>
#include "tools/floor_sqrt.hpp"
#include "tools/pow.hpp"
#include "tools/safe_int.hpp"

namespace tools {

  template <typename T, typename U>
  T floor_kth_root(const T x, const U k) {
    assert(x >= 0);
    assert(k >= 1);

    if (k == 1) return x;
    if (k == 2) return ::tools::floor_sqrt(x);
    if (k == 3) {
      T ok = 0;
      T ng;
      for (ng = 1; ng * ng <= x / ng; ng *= 2);

      while (ng - ok > 1) {
        const T mid = ok + (ng - ok) / 2;
        if (mid * mid <= x / mid) {
          ok = mid;
        } else {
          ng = mid;
        }
      }
      return ok;
    }

    T ok = 0;
    T ng;
    for (ng = 1; ::tools::pow(::tools::safe_int<T>(ng), k) <= ::tools::safe_int<T>(x); ng *= 2);

    while (ng - ok > 1) {
      const T mid = ok + (ng - ok) / 2;
      if (::tools::pow(::tools::safe_int<T>(mid), k) <= ::tools::safe_int<T>(x)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
}

#endif
