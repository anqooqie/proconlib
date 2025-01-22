// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca

#include <iostream>
#include "tools/lca.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::lca lca(N);
  for (int i = 1; i < N; ++i) {
    int p;
    std::cin >> p;
    lca.add_edge(i, p);
  }
  lca.build(0);

  for (int q = 0; q < Q; ++q) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lca.query(u, v) << '\n';
  }

  return 0;
}
