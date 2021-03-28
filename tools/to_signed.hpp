#ifndef TOOLS_TO_SIGNED_HPP
#define TOOLS_TO_SIGNED_HPP

#include <type_traits>

namespace tools {

  template <typename T>
  constexpr typename ::std::make_signed<T>::type to_signed(const T x) noexcept {
    return x;
  }
}

#endif
