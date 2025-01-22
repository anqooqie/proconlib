// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc227/tasks/abc227_g

#include <iostream>
#include <unordered_map>
#include "atcoder/modint.hpp"
#include "tools/segmented_sieve.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, K;
  std::cin >> N >> K;

  std::unordered_map<ll, ll> nCk;
  if (K > 0) {
    tools::segmented_sieve<ll> sieve(K, N - K + 1, N);
    for (ll i = N - K + 1; i <= N; ++i) {
      for (const ll& p : sieve.prime_factor_range(i)) {
        ++nCk[p];
      }
    }

    for (ll i = 1; i <= K; ++i) {
      for (const ll& p : sieve.prime_factor_range(i)) {
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
