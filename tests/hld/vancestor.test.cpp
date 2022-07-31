#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

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
  for (i64 i = 0; i < N - 1; ++i) {
    i64 a, b;
    std::cin >> a >> b;
    hld.add_edge(a, b);
  }
  hld.build(0);

  for (i64 q = 0; q < Q; ++q) {
    i64 s, t, i;
    std::cin >> s >> t >> i;
    const i64 lca = hld.lca(s, t);
    const i64 s_depth = hld.depth(s) - hld.depth(lca);
    const i64 t_depth = hld.depth(t) - hld.depth(lca);
    if (i <= s_depth) {
      std::cout << hld.vancestor(s, i) << '\n';
    } else if (i <= s_depth + t_depth) {
      std::cout << hld.vancestor(t, s_depth + t_depth - i) << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }

  return 0;
}
