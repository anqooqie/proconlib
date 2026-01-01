#ifndef TOOLS_CMP_EQUAL_HPP
#define TOOLS_CMP_EQUAL_HPP

#include "tools/integral.hpp"
#include "tools/is_signed.hpp"
#include "tools/make_unsigned.hpp"

namespace tools {
  template <tools::integral T, tools::integral U>
  constexpr bool cmp_equal(const T t, const U u) noexcept {
    using UT = tools::make_unsigned_t<T>;
    using UU = tools::make_unsigned_t<U>;
    if constexpr (tools::is_signed_v<T> == tools::is_signed_v<U>) {
      return t == u;
    } else if constexpr (tools::is_signed_v<T>) {
      return t < 0 ? false : static_cast<UT>(t) == u;
    } else {
      return u < 0 ? false : t == static_cast<UU>(u);
    }
  }
}

#endif
