#ifndef TOOLS_MAKE_SIGNED_HPP
#define TOOLS_MAKE_SIGNED_HPP

#include <type_traits>

namespace tools {
  template <typename T>
  struct make_signed : std::make_signed<T> {};

  template <typename T>
  using make_signed_t = typename tools::make_signed<T>::type;
}

#endif
