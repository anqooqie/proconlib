#ifndef TOOLS_IS_SIGNED_HPP
#define TOOLS_IS_SIGNED_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct is_signed : ::std::is_signed<T> {};

  template <typename T>
  inline constexpr bool is_signed_v = ::tools::is_signed<T>::value;
}

#endif
