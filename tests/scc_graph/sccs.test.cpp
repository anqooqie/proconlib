#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include "tools/scc_graph.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::scc_graph graph(N);
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b);
  }

  graph.build();

  std::cout << graph.sccs().size() << '\n';
  for (const auto& scc : graph.sccs()) {
    std::cout << scc.size();
    for (const auto v : scc) {
      std::cout << ' ' << v;
    }
    std::cout << '\n';
  }
  return 0;
}
