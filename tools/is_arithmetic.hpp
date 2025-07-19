#ifndef TOOLS_IS_ARITHMETIC_HPP
#define TOOLS_IS_ARITHMETIC_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct is_arithmetic : ::std::is_arithmetic<T> {};

  template <typename T>
  inline constexpr bool is_arithmetic_v = ::tools::is_arithmetic<T>::value;
}

#endif
