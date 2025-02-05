#ifndef TOOLS_BIT_FLOOR_HPP
#define TOOLS_BIT_FLOOR_HPP

#include <bit>
#include <cassert>
#include <type_traits>

namespace tools {
  template <typename T>
  constexpr T bit_floor(const T x) {
    if constexpr (std::is_signed_v<T>) {
      assert(x >= 0);
      return ::std::bit_floor<::std::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_floor(x);
    }
  }
}

#endif
