#ifndef TOOLS_INTEGER_INTERVAL_SET_HPP
#define TOOLS_INTEGER_INTERVAL_SET_HPP

#include "tools/detail/interval_set.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  using integer_interval_set = tools::detail::interval_set<T, true>;
}

#endif
