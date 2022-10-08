#ifndef TOOLS_CEIL_LOG2_HPP
#define TOOLS_CEIL_LOG2_HPP

#include <type_traits>
#include <cassert>
#include <limits>
#include <tuple>
#include <array>
#include <cstdint>

// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567
// License: CC BY-SA 3.0
// Author: dgobbi

namespace tools {

  template <typename T>
  T ceil_log2(T x) {
    static_assert(::std::is_integral_v<T>);
    assert(x > 0);
    if constexpr (::std::is_signed_v<T>) {
      return static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));
    } else {
      const auto log2 = [](const int w) {
        if (w == 8) return 3;
        if (w == 16) return 4;
        if (w == 32) return 5;
        if (w == 64) return 6;
        return -1;
      };
      static_assert(log2(::std::numeric_limits<T>::digits) >= 0);

      constexpr auto t = ::std::make_tuple(
        ::std::array<::std::uint8_t, 3>({
          UINT8_C(0xf0),
          UINT8_C(0x0c),
          UINT8_C(0x02)
        }),
        ::std::array<::std::uint16_t, 4>({
          UINT16_C(0xff00),
          UINT16_C(0x00f0),
          UINT16_C(0x000c),
          UINT16_C(0x0002)
        }),
        ::std::array<::std::uint32_t, 5>({
          UINT32_C(0xffff0000),
          UINT32_C(0x0000ff00),
          UINT32_C(0x000000f0),
          UINT32_C(0x0000000c),
          UINT32_C(0x00000002)
        }),
        ::std::array<::std::uint64_t, 6>({
          UINT64_C(0xffffffff00000000),
          UINT64_C(0x00000000ffff0000),
          UINT64_C(0x000000000000ff00),
          UINT64_C(0x00000000000000f0),
          UINT64_C(0x000000000000000c),
          UINT64_C(0x0000000000000002)
        })
      );

      T y = (((x & (x - 1)) == 0) ? 0 : 1);
      T j = ::std::numeric_limits<T>::digits / 2;

      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits) - 3>(t)) {
        T k = (((x & t_i) == 0) ? 0 : j);
        y += k;
        x >>= k;
        j >>= 1;
      }

      return y;
    }
  }
}

#endif
