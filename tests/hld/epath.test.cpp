#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D"

#include <iostream>
#include <vector>
#include <algorithm>
#include "atcoder/fenwicktree.hpp"
#include "tools/hld.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<ll> parent(n, -1);
  for (ll i = 0; i < n; ++i) {
    ll k;
    std::cin >> k;
    for (ll j = 0; j < k; ++j) {
      ll c;
      std::cin >> c;
      parent[c] = i;
    }
  }

  tools::hld hld(n);
  for (ll i = 1; i < n; ++i) {
    hld.add_edge(parent[i], i);
  }
  hld.build(0);
  atcoder::fenwick_tree<ll> fw(n - 1);
  ll q;
  std::cin >> q;
  for (ll i = 0; i < q; ++i) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll v, w;
      std::cin >> v >> w;
      fw.add(hld.eid2dfs(v - 1), w);
    } else {
      ll u;
      std::cin >> u;
      ll sum = 0;
      for (const auto& [from, to] : hld.epath(0, u)) {
        const auto [l, r] = std::minmax(from, to);
        sum += fw.sum(l, r);
      }
      std::cout << sum << '\n';
    }
  }

  return 0;
}
