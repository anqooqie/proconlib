#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <cstdint>
#include <iostream>
#include "tools/cycle_detection.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  tools::cycle_detection graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  const auto answer = graph.query();
  if (answer) {
    std::cout << answer->second.size() << '\n';
    for (const auto& e : answer->second) {
      std::cout << e << '\n';
    }
  } else {
    std::cout << -1 << '\n';
  }

  return 0;
}
