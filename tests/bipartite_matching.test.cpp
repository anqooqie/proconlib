#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "tools/bipartite_matching.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll L, R, M;
  std::cin >> L >> R >> M;
  tools::bipartite_matching graph(L, R);
  for (ll i = 0; i < M; ++i) {
    ll a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b);
  }

  const auto edges = graph.query();
  std::cout << edges.size() << '\n';
  for (const auto& edge : edges) {
    std::cout << edge.from << ' ' << edge.to << '\n';
  }

  return 0;
}
