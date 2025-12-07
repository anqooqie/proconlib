#ifndef TOOLS_PARTITION_FUNCTION_HPP
#define TOOLS_PARTITION_FUNCTION_HPP

#include <cassert>
#include <vector>
#include "tools/fps.hpp"

namespace tools {

  namespace partition_function {
    template <typename M>
    std::vector<M> diagonal(const int N) {
      assert(N >= 0);

      tools::fps<M> p(N + 1);

      ++p[0];
      for (int k = 1; k * (3 * k + 1) / 2 <= N; k += 2) --p[k * (3 * k + 1) / 2];
      for (int k = 2; k * (3 * k + 1) / 2 <= N; k += 2) ++p[k * (3 * k + 1) / 2];
      for (int k = 1; k * (3 * k - 1) / 2 <= N; k += 2) --p[k * (3 * k - 1) / 2];
      for (int k = 2; k * (3 * k - 1) / 2 <= N; k += 2) ++p[k * (3 * k - 1) / 2];
      p = p.inv();

      return std::vector<M>(p.begin(), p.end());
    }

    template <typename M>
    std::vector<std::vector<M>> all(const int N, const int K) {
      assert(N >= 0);
      assert(K >= 0);

      auto dp = std::vector(N + 1, std::vector<M>(K + 1, M::raw(0)));

      dp[0][0] = M(1);
      for (int i = 0; i <= N; ++i) {
        for (int j = !i; j <= K; ++j) {
          if (j > 0) dp[i][j] += dp[i][j - 1];
          if (i >= j) dp[i][j] += dp[i - j][j];
        }
      }

      return dp;
    }
  }
}

#endif
