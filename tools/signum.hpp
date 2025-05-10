#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include "tools/is_unsigned.hpp"

namespace tools {

  template <typename T>
  constexpr int signum(const T x) noexcept {
    if constexpr (::tools::is_unsigned_v<T>) {
      return T(0) < x;
    } else {
      return (T(0) < x) - (x < T(0));
    }
  }
}

#endif
