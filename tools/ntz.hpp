#ifndef TOOLS_NTZ_HPP
#define TOOLS_NTZ_HPP

#include <type_traits>
#include <cassert>
#include "tools/popcount.hpp"

namespace tools {

  template <typename T>
  T ntz(T x) {
    static_assert(::std::is_integral_v<T>);
    assert(x > 0);
    if constexpr (::std::is_signed_v<T>) {
      return static_cast<T>(::tools::ntz<::std::make_unsigned_t<T>>(x));
    } else {
      return ::tools::popcount((x & -x) - static_cast<T>(1));
    }
  }
}

#endif
