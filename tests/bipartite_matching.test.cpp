// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bipartitematching

#include <iostream>
#include <ranges>
#include "tools/bipartite_matching.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int L, R, M;
  std::cin >> L >> R >> M;
  tools::bipartite_matching graph(L, R);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b);
  }

  const auto edges = graph.query<true>();
  std::cout << edges.size() << '\n';
  for (const auto& edge : edges | std::views::transform([&](const auto k) { return graph.get_edge(k); })) {
    std::cout << edge.from << ' ' << edge.to << '\n';
  }

  return 0;
}
