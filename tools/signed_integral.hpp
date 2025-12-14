#ifndef TOOLS_SIGNED_INTEGRAL_HPP
#define TOOLS_SIGNED_INTEGRAL_HPP

#include "tools/integral.hpp"
#include "tools/is_signed.hpp"

namespace tools {
  template <typename T>
  concept signed_integral = tools::integral<T> && tools::is_signed_v<T>;
}

#endif
