#ifndef TOOLS_CMP_LESS_HPP
#define TOOLS_CMP_LESS_HPP

#include <type_traits>

namespace tools {
  template <typename T, typename U>
  constexpr bool cmp_less(const T t, const U u) noexcept {
    using UT = ::std::make_unsigned_t<T>;
    using UU = ::std::make_unsigned_t<U>;
    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {
      return t < u;
    } else if constexpr (::std::is_signed_v<T>) {
      return t < 0 ? true : UT(t) < u;
    } else {
      return u < 0 ? false : t < UU(u);
    }
  }
}

#endif
