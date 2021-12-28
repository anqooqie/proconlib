#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <cstdint>
#include <iostream>
#include "tools/lca.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, Q;
  std::cin >> N >> Q;
  ::tools::lca lca(N);
  for (i64 i = 1; i <= N - 1; ++i) {
    i64 p;
    std::cin >> p;
    lca.add_edge(i, p);
  }
  lca.build(0);

  for (i64 q = 0; q < Q; ++q) {
    i64 u, v;
    std::cin >> u >> v;
    std::cout << lca.query(u, v) << '\n';
  }

  return 0;
}
