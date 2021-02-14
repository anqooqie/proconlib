#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <cstdint>
#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
#include "tools/dijkstra.hpp"

using i64 = std::int_fast64_t;

int main() {
  i64 N, M, s, t;
  std::cin >> N >> M >> s >> t;

  tools::dijkstra<i64> dijkstra(N);
  for (i64 i = 0; i < M; ++i) {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    dijkstra.add_edge(a, b, c);
  }

  const auto result = dijkstra.query(s);
  std::vector<i64> path;
  for (std::size_t i = t; i != tools::dijkstra<i64>::NONE; i = result.prev_nodes[i]) {
    path.push_back(i);
  }

  if (result.distances[t] == tools::dijkstra<i64>::INF) {
    std::cout << -1 << '\n';
  } else {
    std::cout << result.distances[t] << ' ' << path.size() - 1 << '\n';
    for (auto it = std::next(path.rbegin()), prev_it = path.rbegin(); it != path.rend(); ++it, ++prev_it) {
      std::cout << *prev_it << ' ' << *it << '\n';
    }
  }

  return 0;
}
