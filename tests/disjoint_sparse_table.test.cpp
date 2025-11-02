// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq

#include <iostream>
#include "tools/monoids.hpp"
#include "tools/disjoint_sparse_table.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  std::vector<ll> a(N);
  for (auto& a_i : a) {
    std::cin >> a_i;
  }

  tools::disjoint_sparse_table<tools::monoids::min<ll>> dst(a.begin(), a.end());
  for (ll q = 0; q < Q; ++q) {
    ll l, r;
    std::cin >> l >> r;
    std::cout << dst.prod(l, r) << '\n';
  }

  return 0;
}
