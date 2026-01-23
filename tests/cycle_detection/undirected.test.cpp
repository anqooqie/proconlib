// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cycle_detection_undirected

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/cycle_detection.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::cycle_detection<false> graph(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  if (const auto answer = graph.query<true>(); answer) {
    const auto& [vids, eids] = *answer;
    std::cout << vids.size() << '\n';
    std::cout << tools::join(vids, ' ') << '\n';
    std::cout << tools::join(eids, ' ') << '\n';
    assert_that(graph.query());
  } else {
    std::cout << -1 << '\n';
    assert_that(!graph.query());
  }

  return 0;
}
