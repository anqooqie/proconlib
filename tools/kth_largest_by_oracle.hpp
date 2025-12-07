#ifndef TOOLS_KTH_LARGEST_BY_ORACLE_HPP
#define TOOLS_KTH_LARGEST_BY_ORACLE_HPP

#include <utility>
#include "tools/detail/kth_largest_by_oracle.hpp"

namespace tools {
  template <typename... Args>
  auto kth_largest_by_oracle(Args&&... args) {
    return tools::detail::kth_largest_by_oracle::impl<true>(std::forward<Args>(args)...);
  }
}

#endif
