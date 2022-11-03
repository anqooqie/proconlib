#ifndef TOOLS_EXP_HPP
#define TOOLS_EXP_HPP

#include <cmath>

namespace tools {
  template <typename T>
  auto exp(const T x) {
    return ::std::exp(x);
  }
}

#endif
