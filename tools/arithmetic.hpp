#ifndef TOOLS_ARITHMETIC_HPP
#define TOOLS_ARITHMETIC_HPP

#include <concepts>
#include "tools/integral.hpp"

namespace tools {
  template <typename T>
  concept arithmetic = ::tools::integral<T> || ::std::floating_point<T>;
}

#endif
