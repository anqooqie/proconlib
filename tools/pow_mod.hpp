#ifndef TOOLS_POW_MOD_HPP
#define TOOLS_POW_MOD_HPP

#include "tools/mod.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  template <typename T1, typename T2, typename T3>
  constexpr T3 pow_mod(const T1 x, T2 n, const T3 m) {
    if (m == 1) return 0;
    T3 r = 1;
    T3 y = tools::mod(x, m);
    while (n > 0) {
      if ((n & 1) > 0) {
        r = tools::prod_mod(r, y, m);
      }
      y = tools::prod_mod(y, y, m);
      n /= 2;
    }
    return r;
  }
}

#endif
