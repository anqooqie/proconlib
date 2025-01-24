// competitive-verifier: STANDALONE

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/partition_function.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int N = 0; N < 50; ++N) {
    for (int K = 0; K < 50; ++K) {
      const auto all = tools::partition_function::all<mint>(N, K);

      if (N == K) {
        const auto diagonal = tools::partition_function::diagonal<mint>(N);
        for (int n = 0; n <= N; ++n) {
          assert_that(all[n][n] == diagonal[n]);
        }
      }
    }
  }

  return 0;
}
