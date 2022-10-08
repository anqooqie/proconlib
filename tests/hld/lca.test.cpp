#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "tools/hld.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;

  tools::hld hld(N);
  for (ll v = 1; v < N; ++v) {
    ll p;
    std::cin >> p;
    hld.add_edge(p, v);
  }

  hld.build(0);

  for (ll q = 0; q < Q; ++q) {
    ll u, v;
    std::cin >> u >> v;
    std::cout << hld.lca(u, v) << '\n';
  }

  return 0;
}
