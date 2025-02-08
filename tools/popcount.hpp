#ifndef TOOLS_POPCOUNT_HPP
#define TOOLS_POPCOUNT_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  constexpr int popcount(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::popcount<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::popcount(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr int popcount<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    x = (x & UINT128_C(0x55555555555555555555555555555555)) + (x >> 1 & UINT128_C(0x55555555555555555555555555555555));
    x = (x & UINT128_C(0x33333333333333333333333333333333)) + (x >> 2 & UINT128_C(0x33333333333333333333333333333333));
    x = (x & UINT128_C(0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT128_C(0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f));
    x = (x & UINT128_C(0x00ff00ff00ff00ff00ff00ff00ff00ff)) + (x >> 8 & UINT128_C(0x00ff00ff00ff00ff00ff00ff00ff00ff));
    x = (x & UINT128_C(0x0000ffff0000ffff0000ffff0000ffff)) + (x >> 16 & UINT128_C(0x0000ffff0000ffff0000ffff0000ffff));
    x = (x & UINT128_C(0x00000000ffffffff00000000ffffffff)) + (x >> 32 & UINT128_C(0x00000000ffffffff00000000ffffffff));
    x = (x & UINT128_C(0x0000000000000000ffffffffffffffff)) + (x >> 64 & UINT128_C(0x0000000000000000ffffffffffffffff));
    return x;
  }
#endif
}

#endif
