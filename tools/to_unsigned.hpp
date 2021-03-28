#ifndef TOOLS_TO_UNSIGNED_HPP
#define TOOLS_TO_UNSIGNED_HPP

#include <type_traits>

namespace tools {

  template <typename T>
  constexpr typename ::std::make_unsigned<T>::type to_unsigned(const T x) noexcept {
    return x;
  }
}

#endif
