#ifndef TOOLS_IS_UNSIGNED_HPP
#define TOOLS_IS_UNSIGNED_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct is_unsigned : ::std::is_unsigned<T> {};

  template <typename T>
  inline constexpr bool is_unsigned_v = ::tools::is_unsigned<T>::value;
}

#endif
