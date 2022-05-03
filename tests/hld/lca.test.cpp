#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <cstdint>
#include <iostream>
#include "tools/hld.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, Q;
  std::cin >> N >> Q;

  tools::hld hld(N);
  for (i64 v = 1; v < N; ++v) {
    i64 p;
    std::cin >> p;
    hld.add_edge(p, v);
  }

  hld.build(0);

  for (i64 q = 0; q < Q; ++q) {
    i64 u, v;
    std::cin >> u >> v;
    std::cout << hld.lca(u, v) << '\n';
  }

  return 0;
}
