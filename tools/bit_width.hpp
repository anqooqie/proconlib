#ifndef TOOLS_BIT_WIDTH_HPP
#define TOOLS_BIT_WIDTH_HPP

#include <bit>
#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  constexpr int bit_width(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_width<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_width(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr int bit_width<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    int w = 0;
    if (x & UINT128_C(0xffffffffffffffff0000000000000000)) {
      x >>= 64;
      w += 64;
    }
    if (x & UINT128_C(0xffffffff00000000)) {
      x >>= 32;
      w += 32;
    }
    if (x & UINT128_C(0xffff0000)) {
      x >>= 16;
      w += 16;
    }
    if (x & UINT128_C(0xff00)) {
      x >>= 8;
      w += 8;
    }
    if (x & UINT128_C(0xf0)) {
      x >>= 4;
      w += 4;
    }
    if (x & UINT128_C(0xc)) {
      x >>= 2;
      w += 2;
    }
    if (x & UINT128_C(0x2)) {
      x >>= 1;
      w += 1;
    }
    w += x;
    return w;
  }
#endif
}

#endif
