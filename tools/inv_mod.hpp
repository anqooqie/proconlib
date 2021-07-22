#ifndef TOOLS_INV_MOD_HPP
#define TOOLS_INV_MOD_HPP

#include <cassert>
#include "tools/extgcd.hpp"
#include "tools/mod.hpp"

namespace tools {

  template <typename T1, typename T2>
  constexpr T2 inv_mod(const T1 x, const T2 m) {
    const auto [x0, y0, gcd] = ::tools::extgcd(x, m);
    assert(gcd == 1);
    return ::tools::mod(x0, m);
  }
}

#endif
