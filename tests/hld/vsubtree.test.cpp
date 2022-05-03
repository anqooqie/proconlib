#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <cstdint>
#include <iostream>
#include <vector>
#include "atcoder/fenwicktree.hpp"
#include "tools/hld.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, Q;
  std::cin >> N >> Q;
  std::vector<i64> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::hld hld(N);
  for (i64 v = 1; v < N; ++v) {
    i64 p;
    std::cin >> p;
    hld.add_edge(p, v);
  }

  hld.build(0);
  atcoder::fenwick_tree<i64> fw(N);
  for (i64 v = 0; v < N; ++v) {
    fw.add(hld.vid2dfs(v), a[v]);
  }

  for (i64 q = 0; q < Q; ++q) {
    i64 t;
    std::cin >> t;
    if (t == 0) {
      i64 u, x;
      std::cin >> u >> x;
      fw.add(hld.vid2dfs(u), x);
    } else {
      i64 u;
      std::cin >> u;
      const auto& [l, r] = hld.vsubtree(u);
      std::cout << fw.sum(l, r) << '\n';
    }
  }

  return 0;
}
