#define PROBLEM "https://atcoder.jp/contests/abc227/tasks/abc227_g"

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include "atcoder/modint.hpp"
#include "tools/segmented_sieve.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, K;
  std::cin >> N >> K;

  std::unordered_map<i64, i64> nCk;
  if (K > 0) {
    tools::segmented_sieve<i64> sieve(K, N - K + 1, N);
    for (i64 i = N - K + 1; i <= N; ++i) {
      for (const i64& p : sieve.prime_factor_range(i)) {
        ++nCk[p];
      }
    }

    for (i64 i = 1; i <= K; ++i) {
      for (const i64& p : sieve.prime_factor_range(i)) {
        --nCk[p];
      }
    }
  }

  mint answer(1);
  for (const auto& [p, q] : nCk) {
    answer *= mint(q + 1);
  }
  std::cout << answer.val() << '\n';
  return 0;
}
