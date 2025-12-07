#ifndef TOOLS_IS_RATIONAL_HPP
#define TOOLS_IS_RATIONAL_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct is_rational : std::false_type {};

  template <typename T>
  inline constexpr bool is_rational_v = tools::is_rational<T>::value;
}

#endif
