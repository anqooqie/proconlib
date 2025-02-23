// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cycle_detection_undirected

#include <iostream>
#include <cstddef>
#include "tools/cycle_detection.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::size_t N, M;
  std::cin >> N >> M;
  tools::cycle_detection<false> graph(N);
  for (std::size_t i = 0; i < M; ++i) {
    std::size_t u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  if (const auto answer = graph.query(); answer) {
    const auto& [vids, eids] = *answer;
    std::cout << vids.size() << '\n';
    std::cout << tools::join(vids, " ") << '\n';
    std::cout << tools::join(eids, " ") << '\n';
  } else {
    std::cout << -1 << '\n';
  }

  return 0;
}
