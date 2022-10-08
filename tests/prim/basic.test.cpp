#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"

#include <iostream>
#include "tools/prim.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll V, E;
  std::cin >> V >> E;
  tools::prim<ll> prim(V);
  for (ll i = 0; i < E; ++i) {
    ll s, t, w;
    std::cin >> s >> t >> w;
    prim.add_edge(s, t, w);
  }

  std::cout << prim.query().first[0].first << '\n';
  return 0;
}
