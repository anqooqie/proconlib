#ifndef TOOLS_LOG_HPP
#define TOOLS_LOG_HPP

#include <cmath>

namespace tools {
  template <typename T>
  auto log(const T x) {
    return ::std::log(x);
  }
}

#endif
