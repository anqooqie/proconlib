// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/shortest_path

#include <iostream>
#include <limits>
#include <ranges>
#include <vector>
#include "tools/dijkstra.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, s, t;
  std::cin >> N >> M >> s >> t;

  tools::dijkstra<true, ll> graph(N);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph.add_edge(a, b, c);
  }

  const auto qr = graph.query<true>(s);
  if (qr.dist(t) == std::numeric_limits<ll>::max()) {
    std::cout << -1 << '\n';
  } else {
    const auto path = qr.edge_id_path(t);
    std::cout << qr.dist(t) << ' ' << path.size() << '\n';
    for (const auto& edge : path | std::views::transform([&](const auto k) { return graph.get_edge(k); })) {
      std::cout << edge.from << ' ' << edge.to << '\n';
    }
  }

  return 0;
}
