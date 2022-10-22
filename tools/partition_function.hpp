#ifndef TOOLS_PARTITION_FUNCTION_HPP
#define TOOLS_PARTITION_FUNCTION_HPP

#include <cassert>
#include <vector>
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

  template <typename M>
  ::std::vector<::std::vector<M>> partition_function(const int n, const int k) {
    assert(n >= 0);
    assert(k >= 0);

    auto dp = ::std::vector(n + 1, ::std::vector<M>(k + 1));

    dp[0][0] = M(1);
    for (int i = 0; i <= n; ++i) {
      for (int j = !i; j <= k; ++j) {
        dp[i][j] = M(0);
        if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
        if (i - j >= 0) dp[i][j] += dp[i - j][j];
      }
    }

    return dp;
  }
}

#endif
