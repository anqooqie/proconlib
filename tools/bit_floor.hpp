#ifndef TOOLS_BIT_FLOOR_HPP
#define TOOLS_BIT_FLOOR_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  constexpr T bit_floor(T) noexcept;

  template <typename T>
  constexpr T bit_floor(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_floor<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_floor(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr ::tools::uint128_t bit_floor<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return x & ~(x >> 1);
  }
#endif
}

#endif
