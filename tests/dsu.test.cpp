// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind

#include <iostream>
#include "tools/dsu.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::dsu dsu(N);
  for (int q = 0; q < Q; ++q) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t == 0) {
      dsu.merge(u, v);
    } else {
      std::cout << (dsu.same(u, v) ? 1 : 0) << '\n';
    }
  }

  return 0;
}
