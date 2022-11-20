#ifndef TOOLS_PROD_MOD_HPP
#define TOOLS_PROD_MOD_HPP

#include "tools/uint128_t.hpp"

namespace tools {

  template <typename T1, typename T2, typename T3>
  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {
    using u128 = ::tools::uint128_t;
    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);
    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;
    return prod_mod;
  }
}

#endif
