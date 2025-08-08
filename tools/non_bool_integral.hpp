#ifndef TOOLS_NON_BOOL_INTEGRAL_HPP
#define TOOLS_NON_BOOL_INTEGRAL_HPP

#include <type_traits>
#include "tools/is_integral.hpp"

namespace tools {
  template <typename T>
  concept non_bool_integral = ::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>;
}

#endif
