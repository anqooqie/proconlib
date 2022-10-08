#ifndef TOOLS_FLOOR_LOG2_HPP
#define TOOLS_FLOOR_LOG2_HPP

#include <type_traits>
#include <cassert>
#include <limits>
#include "tools/popcount.hpp"

namespace tools {

  template <typename T>
  T floor_log2(T x) {
    static_assert(::std::is_integral_v<T>);
    assert(x > 0);
    if constexpr (::std::is_signed_v<T>) {
      return static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));
    } else {
      const auto log2 = [](const int w) {
        if (w == 8) return 3;
        if (w == 16) return 4;
        if (w == 32) return 5;
        if (w == 64) return 6;
        return -1;
      };
      static_assert(log2(::std::numeric_limits<T>::digits) >= 0);

      x |= (x >> 1);
      x |= (x >> 2);
      x |= (x >> 4);
      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);
      if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);
      if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);
      return ::tools::popcount(x) - static_cast<T>(1);
    }
  }
}

#endif
