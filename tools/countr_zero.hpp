#ifndef TOOLS_COUNTR_ZERO_HPP
#define TOOLS_COUNTR_ZERO_HPP

#include <algorithm>
#include <bit>
#include <cassert>
#include <cstddef>
#include <limits>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  constexpr int countr_zero(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::std::min(::tools::countr_zero<::tools::make_unsigned_t<T>>(x), ::std::numeric_limits<T>::digits);
    } else {
      return ::std::countr_zero(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  namespace detail {
    namespace countr_zero {
      template <::std::size_t N>
      struct ntz_traits;

      template <>
      struct ntz_traits<128> {
        using type = ::tools::uint128_t;
        static constexpr int shift = 120;
        static constexpr type magic = UINT128_C(0x01061438916347932a5cd9d3ead7b77f);
        static constexpr int ntz_table[255] = {
          128,   0,   1,  -1,   2,  -1,   8,  -1,   3,  -1,  15,  -1,   9,  -1,  22,  -1,
            4,  -1,  29,  -1,  16,  -1,  36,  -1,  10,  -1,  43,  -1,  23,  -1,  50,  -1,
            5,  -1,  33,  -1,  30,  -1,  57,  -1,  17,  -1,  64,  -1,  37,  -1,  71,  -1,
           11,  -1,  60,  -1,  44,  -1,  78,  -1,  24,  -1,  85,  -1,  51,  -1,  92,  -1,
           -1,   6,  -1,  20,  -1,  34,  -1,  48,  31,  -1,  -1,  69,  58,  -1,  -1,  90,
           18,  -1,  67,  -1,  65,  -1,  99,  -1,  38,  -1, 101,  -1,  72,  -1, 106,  -1,
           -1,  12,  -1,  40,  -1,  61,  -1,  82,  45,  -1,  -1, 103,  79,  -1, 113,  -1,
           -1,  25,  -1,  74,  86,  -1,  -1, 116,  -1,  52,  -1, 108,  -1,  93,  -1, 120,
          127,  -1,  -1,   7,  -1,  14,  -1,  21,  -1,  28,  -1,  35,  -1,  42,  -1,  49,
           -1,  32,  -1,  56,  -1,  63,  -1,  70,  -1,  59,  -1,  77,  -1,  84,  -1,  91,
           -1,  19,  -1,  47,  -1,  68,  -1,  89,  -1,  66,  -1,  98,  -1, 100,  -1, 105,
           -1,  39,  -1,  81,  -1, 102,  -1, 112,  -1,  73,  -1, 115,  -1, 107,  -1, 119,
          126,  -1,  13,  -1,  27,  -1,  41,  -1,  -1,  55,  62,  -1,  -1,  76,  83,  -1,
           -1,  46,  -1,  88,  -1,  97,  -1, 104,  -1,  80,  -1, 111,  -1, 114,  -1, 118,
          125,  -1,  26,  -1,  54,  -1,  75,  -1,  -1,  87,  96,  -1,  -1, 110,  -1, 117,
          124,  -1,  53,  -1,  -1,  95, 109,  -1, 123,  -1,  94,  -1, 122,  -1, 121
        };
      };

      template <typename T>
      constexpr int impl(const T x) noexcept {
        using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;
        using type = typename tr::type;
        return tr::ntz_table[static_cast<type>(tr::magic * static_cast<type>(x & -x)) >> tr::shift];
      }
    }
  }

  template <>
  constexpr int countr_zero<::tools::uint128_t>(const ::tools::uint128_t x) noexcept {
    return ::tools::detail::countr_zero::impl(x);
  }
#endif
}

#endif
