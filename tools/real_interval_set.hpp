#ifndef TOOLS_REAL_INTERVAL_SET_HPP
#define TOOLS_REAL_INTERVAL_SET_HPP

#include "tools/detail/interval_set.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  using real_interval_set = tools::detail::interval_set<T, false>;
}

#endif
