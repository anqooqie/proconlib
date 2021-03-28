#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include <type_traits>

namespace tools {

  template <typename T>
  constexpr int signum(const T x) noexcept {
    if constexpr (::std::is_signed_v<T>) {
      return (T(0) < x) - (x < T(0));
    } else {
      return T(0) < x;
    }
  }
}

#endif
