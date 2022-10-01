#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "tools/dijkstra.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M, s, t;
  std::cin >> N >> M >> s >> t;

  tools::dijkstra<true, i64> graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    graph.add_edge(a, b, c);
  }

  const auto [dist, prev] = graph.query(s);
  if (dist[t] == std::numeric_limits<i64>::max()) {
    std::cout << -1 << '\n';
  } else {
    std::vector<i64> path;
    for (auto v = t; v != s; v = graph.get_edge(prev[v]).from) {
      path.push_back(v);
    }
    path.push_back(s);
    std::reverse(path.begin(), path.end());

    std::cout << dist[t] << ' ' << path.size() - 1 << '\n';
    for (::std::size_t i = 0; i + 1 < path.size(); ++i) {
      std::cout << path[i] << ' ' << path[i + 1] << '\n';
    }
  }

  return 0;
}
