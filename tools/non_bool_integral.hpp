#ifndef TOOLS_NON_BOOL_INTEGRAL_HPP
#define TOOLS_NON_BOOL_INTEGRAL_HPP

#include <concepts>
#include <type_traits>
#include "tools/integral.hpp"

namespace tools {
  template <typename T>
  concept non_bool_integral = tools::integral<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}

#endif
