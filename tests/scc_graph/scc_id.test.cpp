#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include <iostream>
#include "tools/scc_graph.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll V, E;
  std::cin >> V >> E;
  tools::scc_graph graph(V);
  for (ll i = 0; i < E; ++i) {
    ll s, t;
    std::cin >> s >> t;
    graph.add_edge(s, t);
  }

  graph.build();

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll u, v;
    std::cin >> u >> v;
    std::cout << (graph.scc_id(u) == graph.scc_id(v) ? 1 : 0) << '\n';
  }

  return 0;
}
