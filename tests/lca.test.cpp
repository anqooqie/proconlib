#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "tools/lca.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  ::tools::lca lca(N);
  for (ll i = 1; i <= N - 1; ++i) {
    ll p;
    std::cin >> p;
    lca.add_edge(i, p);
  }
  lca.build(0);

  for (ll q = 0; q < Q; ++q) {
    ll u, v;
    std::cin >> u >> v;
    std::cout << lca.query(u, v) << '\n';
  }

  return 0;
}
