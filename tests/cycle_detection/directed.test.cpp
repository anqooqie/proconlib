// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cycle_detection

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/cycle_detection.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::cycle_detection<true> graph(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  if (const auto answer = graph.query<true>(); answer) {
    std::cout << answer->second.size() << '\n';
    for (const auto e : answer->second) {
      std::cout << e << '\n';
    }
    assert_that(graph.query());
  } else {
    std::cout << -1 << '\n';
    assert_that(!graph.query());
  }

  return 0;
}
