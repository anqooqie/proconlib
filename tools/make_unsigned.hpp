#ifndef TOOLS_MAKE_UNSIGNED_HPP
#define TOOLS_MAKE_UNSIGNED_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct make_unsigned : std::make_unsigned<T> {};

  template <typename T>
  using make_unsigned_t = typename tools::make_unsigned<T>::type;
}

#endif
