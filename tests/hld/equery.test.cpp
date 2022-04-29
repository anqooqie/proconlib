#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include "atcoder/fenwicktree.hpp"
#include "tools/hld.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<i64> parent(n, -1);
  for (i64 i = 0; i < n; ++i) {
    i64 k;
    std::cin >> k;
    for (i64 j = 0; j < k; ++j) {
      i64 c;
      std::cin >> c;
      parent[c] = i;
    }
  }

  tools::hld hld(n);
  for (i64 i = 1; i < n; ++i) {
    hld.add_edge(parent[i], i);
  }
  hld.build();
  atcoder::fenwick_tree<i64> fw(n - 1);
  i64 q;
  std::cin >> q;
  for (i64 i = 0; i < q; ++i) {
    i64 t;
    std::cin >> t;
    if (t == 0) {
      i64 v, w;
      std::cin >> v >> w;
      fw.add(hld.eid2dfs()[v - 1], w);
    } else {
      i64 u;
      std::cin >> u;
      i64 sum = 0;
      for (const auto& [from, to] : hld.equery(0, u)) {
        const auto [l, r] = std::minmax(from, to);
        sum += fw.sum(l, r);
      }
      std::cout << sum << '\n';
    }
  }

  return 0;
}
