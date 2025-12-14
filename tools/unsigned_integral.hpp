#ifndef TOOLS_UNSIGNED_INTEGRAL_HPP
#define TOOLS_UNSIGNED_INTEGRAL_HPP

#include "tools/integral.hpp"
#include "tools/is_unsigned.hpp"

namespace tools {
  template <typename T>
  concept unsigned_integral = tools::integral<T> && tools::is_unsigned_v<T>;
}

#endif
