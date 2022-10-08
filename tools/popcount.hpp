#ifndef TOOLS_POPCOUNT_HPP
#define TOOLS_POPCOUNT_HPP

#include <type_traits>
#include <cassert>
#include <limits>
#include <cstdint>

namespace tools {

  template <typename T>
  T popcount(T x) {
    static_assert(::std::is_integral_v<T>);
    assert(x >= 0);
    if constexpr (::std::is_signed_v<T>) {
      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));
    } else {
      const auto log2 = [](const int w) {
        if (w == 8) return 3;
        if (w == 16) return 4;
        if (w == 32) return 5;
        if (w == 64) return 6;
        return -1;
      };
      static_assert(log2(::std::numeric_limits<T>::digits) >= 0);

      if constexpr (::std::numeric_limits<T>::digits == 8) {
        x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));
        x = (x & UINT8_C(0x33)) + (x >> 2 & UINT8_C(0x33));
        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));
      } else if constexpr (::std::numeric_limits<T>::digits == 16) {
        x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));
        x = (x & UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));
        x = (x & UINT16_C(0x0f0f)) + (x >> 4 & UINT16_C(0x0f0f));
        x = (x & UINT16_C(0x00ff)) + (x >> 8 & UINT16_C(0x00ff));
      } else if constexpr (::std::numeric_limits<T>::digits == 32) {
        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));
        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));
        x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));
        x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));
        x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));
      } else if constexpr (::std::numeric_limits<T>::digits == 64) {
        x = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));
        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));
        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));
        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));
        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));
        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));
      }

      return x;
    }
  }
}

#endif
