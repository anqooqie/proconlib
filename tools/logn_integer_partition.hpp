#ifndef TOOLS_LOGN_INTEGER_PARTITION_HPP
#define TOOLS_LOGN_INTEGER_PARTITION_HPP

#include <vector>
#include <cassert>

namespace tools {
  template <typename T>
  std::vector<T> logn_integer_partition(T n) {
    assert(n >= 0);
    std::vector<T> res;
    for (T pow2 = 1; pow2 < n; n -= pow2, pow2 *= 2) {
      res.push_back(pow2);
    }
    if (n > 0) res.push_back(n);
    return res;
  }
}

#endif
