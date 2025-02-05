#ifndef TOOLS_BIT_CEIL_HPP
#define TOOLS_BIT_CEIL_HPP

#include <bit>
#include <cassert>
#include <type_traits>

namespace tools {
  template <typename T>
  constexpr T bit_ceil(const T x) {
    if constexpr (std::is_signed_v<T>) {
      assert(x >= 0);
      return ::std::bit_ceil<::std::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_ceil(x);
    }
  }
}

#endif
