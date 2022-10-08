#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "atcoder/fenwicktree.hpp"
#include "tools/hld.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  std::vector<ll> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::hld hld(N);
  for (ll v = 1; v < N; ++v) {
    ll p;
    std::cin >> p;
    hld.add_edge(p, v);
  }

  hld.build(0);
  atcoder::fenwick_tree<ll> fw(N);
  for (ll v = 0; v < N; ++v) {
    fw.add(hld.vid2dfs(v), a[v]);
  }

  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll u, x;
      std::cin >> u >> x;
      fw.add(hld.vid2dfs(u), x);
    } else {
      ll u;
      std::cin >> u;
      const auto& [l, r] = hld.vsubtree(u);
      std::cout << fw.sum(l, r) << '\n';
    }
  }

  return 0;
}
