#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>
#include "tools/hld.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  tools::hld hld(N);
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    std::cin >> a >> b;
    hld.add_edge(a, b);
  }
  hld.build(0);

  for (ll q = 0; q < Q; ++q) {
    ll s, t, i;
    std::cin >> s >> t >> i;
    const ll lca = hld.lca(s, t);
    const ll s_depth = hld.depth(s) - hld.depth(lca);
    const ll t_depth = hld.depth(t) - hld.depth(lca);
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
