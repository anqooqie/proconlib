#ifndef TOOLS_DETAIL_POW_MOD_U64_HPP
#define TOOLS_DETAIL_POW_MOD_U64_HPP

#include <cstdint>
#include "tools/detail/prod_mod_u64.hpp"

namespace tools {
  namespace detail {

    // x ** n (mod m)
    constexpr ::std::uint_fast64_t pow_mod_u64(const ::std::uint_fast64_t x, ::std::uint_fast64_t n, const ::std::uint_fast64_t m) {
      if (m == 1) return 0;
      ::std::uint_fast64_t r = 1;
      ::std::uint_fast64_t y = x % m;
      while (n > 0) {
        if ((n & 1) > 0) {
          r = ::tools::detail::prod_mod_u64(r, y, m);
        }
        y = ::tools::detail::prod_mod_u64(y, y, m);
        n /= 2;
      }
      return r;
    }
  }
}

#endif
