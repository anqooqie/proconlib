#ifndef TOOLS_INTEGRAL_HPP
#define TOOLS_INTEGRAL_HPP

#include "tools/is_integral.hpp"

namespace tools {
  template <typename T>
  concept integral = ::tools::is_integral_v<T>;
}

#endif
