#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <cstdint>
#include <iostream>
#include <variant>
#include "tools/bipartite_matching.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 L, R, M;
  std::cin >> L >> R >> M;
  tools::bipartite_matching<std::monostate> graph(L, R);
  for (i64 i = 0; i < M; ++i) {
    i64 a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b, std::monostate());
  }

  const auto edges = graph.query();
  std::cout << edges.size() << '\n';
  for (const auto& edge : edges) {
    std::cout << edge.from << ' ' << edge.to << '\n';
  }

  return 0;
}
