#ifndef TOOLS_PARTITION_FUNCTION_HPP
#define TOOLS_PARTITION_FUNCTION_HPP

#include <cassert>
#include "tools/fps.hpp"

namespace tools {
  template <typename M>
  ::tools::fps<M> partition_function(const int n) {
    assert(n >= 0);

    ::tools::fps<M> p(n + 1);
    if (M::mod() == 1) return p;

    ++p[0];
    for (int k = 1; k * (3 * k + 1) / 2 <= n; k += 2) --p[k * (3 * k + 1) / 2];
    for (int k = 2; k * (3 * k + 1) / 2 <= n; k += 2) ++p[k * (3 * k + 1) / 2];
    for (int k = 1; k * (3 * k - 1) / 2 <= n; k += 2) --p[k * (3 * k - 1) / 2];
    for (int k = 2; k * (3 * k - 1) / 2 <= n; k += 2) ++p[k * (3 * k - 1) / 2];
    return p.inv();
  }
}

#endif
