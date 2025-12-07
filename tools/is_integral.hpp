#ifndef TOOLS_IS_INTEGRAL_HPP
#define TOOLS_IS_INTEGRAL_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct is_integral : std::is_integral<T> {};

  template <typename T>
  inline constexpr bool is_integral_v = tools::is_integral<T>::value;
}

#endif
