#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/stirling_2nd.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int N = 0; N < 50; ++N) {
    for (int K = 0; K < 50; ++K) {
      const auto all = tools::stirling_2nd::all<mint>(N, K);

      for (int n = 0; n <= N; ++n) {
        const auto fixed_n = tools::stirling_2nd::fixed_n<mint>(n, K);
        for (int k = 0; k <= K; ++k) {
          assert_that(all[n][k] == fixed_n[k]);
        }
      }

      for (int k = 0; k <= K; ++k) {
        const auto fixed_k = tools::stirling_2nd::fixed_k<mint>(N, k);
        for (int n = 0; n <= N; ++n) {
          assert_that(all[n][k] == fixed_k[n]);
        }
      }

      if (N == K) {
        const auto diagonal = tools::stirling_2nd::diagonal<mint>(N);
        for (int n = 0; n <= N; ++n) {
          assert_that(all[n][n] == diagonal[n]);
        }
      }
    }
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
