#ifndef TOOLS_COUNTR_ZERO_HPP
#define TOOLS_COUNTR_ZERO_HPP

#include <algorithm>
#include <bit>
#include <cassert>
#include <limits>
#include <type_traits>
#include "tools/is_integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"

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
}

#endif
