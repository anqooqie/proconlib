#ifndef TOOLS_GCD_HPP
#define TOOLS_GCD_HPP

#include <type_traits>
#include <numeric>

namespace tools {
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n) {
    return ::std::gcd(m, n);
  }
}

#endif
