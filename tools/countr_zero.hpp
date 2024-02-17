#ifndef TOOLS_COUNTR_ZERO_HPP
#define TOOLS_COUNTR_ZERO_HPP

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <cassert>
#include <algorithm>
#include <limits>

// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6
// License: unknown
// Author: 白山 風露

namespace tools {
  namespace detail {
    namespace countr_zero {
      template <::std::size_t N>
      struct ntz_traits;

      template <>
      struct ntz_traits<1> {
        using type = bool;
        static constexpr int shift = 0;
        static constexpr type magic = true;
        static constexpr int ntz_table[2] = {
          1,  0
        };
      };

      template <>
      struct ntz_traits<8> {
        using type = ::std::uint8_t;
        static constexpr int shift = 4;
        static constexpr type magic = UINT8_C(0x1D);
        static constexpr int ntz_table[15] = {
          8,  0, -1,  1,  6, -1, -1,  2,  7, -1,  5, -1, -1,  4,  3
        };
      };

      template <>
      struct ntz_traits<16> {
        using type = ::std::uint16_t;
        static constexpr int shift = 11;
        static constexpr type magic = UINT16_C(0x0F2D);
        static constexpr int ntz_table[31] = {
          16,  0, -1,  1, -1,  8, -1,  2, 14, -1, -1,  9, -1, 11, -1,  3,
          15, -1,  7, -1, 13, -1, 10, -1, -1,  6, 12, -1,  5, -1,  4,
        };
      };

      template <>
      struct ntz_traits<32> {
        using type = ::std::uint32_t;
        static constexpr int shift = 26;
        static constexpr type magic = UINT32_C(0x07C56E99);
        static constexpr int ntz_table[63] = {
          32,  0, -1,  1, -1, 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,
          30, -1, -1, 23, -1, 12, 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,
          31, -1,  9, -1, 28, -1, 24, -1, -1, 22, -1, 13, -1, 15, 18, -1,
          -1,  8, 27, -1, 21, -1, -1, 17,  7, -1, 20, -1,  6, -1,  5
        };
      };

      template <>
      struct ntz_traits<64> {
        using type = ::std::uint64_t;
        static constexpr int shift = 57;
        static constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);
        static constexpr int ntz_table[127] = {
          64,  0, -1,  1, -1, 12, -1,  2, 60, -1, 13, -1, -1, 53, -1,  3,
          61, -1, -1, 21, -1, 14, -1, 42, -1, 24, 54, -1, -1, 28, -1,  4,
          62, -1, 58, -1, 19, -1, 22, -1, -1, 17, 15, -1, -1, 33, -1, 43,
          -1, 50, -1, 25, 55, -1, -1, 35, -1, 38, 29, -1, -1, 45, -1,  5,
          63, -1, 11, -1, 59, -1, 52, -1, -1, 20, -1, 41, 23, -1, 27, -1,
          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1, -1, 34, 37, -1, 44, -1,
          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1, 31, 48, -1, 36, -1,
          9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,  7, -1,  6,
        };
      };
    }
  }

  template <typename T>
  constexpr int countr_zero(const T x) noexcept {
    static_assert(::std::is_integral_v<T>);
    if constexpr (::std::is_signed_v<T>) {
      assert(x >= 0);
      return ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x), ::std::numeric_limits<T>::digits);
    } else {
      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;
      using type = typename tr::type;
      return tr::ntz_table[static_cast<type>(tr::magic * static_cast<type>(x & -x)) >> tr::shift];
    }
  }
}

#endif
