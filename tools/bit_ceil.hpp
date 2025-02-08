#ifndef TOOLS_BIT_CEIL_HPP
#define TOOLS_BIT_CEIL_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  constexpr T bit_ceil(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_ceil<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_ceil(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr ::tools::uint128_t bit_ceil<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    if (x <= 1) return 1;
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return ++x;
  }
#endif
}

#endif
