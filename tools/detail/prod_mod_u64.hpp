#ifndef TOOLS_DETAIL_PROD_MOD_U64_HPP
#define TOOLS_DETAIL_PROD_MOD_U64_HPP

#include <cstdint>

namespace tools {
  namespace detail {

    // x * y (mod m)
    constexpr ::std::uint_fast64_t prod_mod_u64(const ::std::uint_fast64_t x, const ::std::uint_fast64_t y, const ::std::uint_fast64_t m) {
      using u128 = unsigned __int128;
      return ::std::uint_fast64_t((u128(x) * u128(y)) % u128(m));
    }
  }
}

#endif
