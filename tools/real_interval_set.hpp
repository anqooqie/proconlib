#ifndef TOOLS_REAL_INTERVAL_SET_HPP
#define TOOLS_REAL_INTERVAL_SET_HPP

#include "tools/detail/interval_set.hpp"

namespace tools {
  template <typename T>
  using real_interval_set = ::tools::detail::interval_set<T, false>;
}

#endif
