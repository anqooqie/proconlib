// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse

#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/join.hpp"
#include "tools/sparse_fps_pow.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, K, M;
  std::cin >> N >> K >> M;
  std::vector<std::pair<int, mint>> a;
  a.reserve(K);
  for (ll k = 0; k < K; ++k) {
    ll i, a_i;
    std::cin >> i >> a_i;
    a.emplace_back(i, mint::raw(a_i));
  }

  std::cout << tools::join(tools::sparse_fps_pow(a, M, N) | std::views::transform(&mint::val), ' ') << '\n';
  return 0;
}
