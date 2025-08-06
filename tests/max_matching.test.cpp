// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/general_matching

#include <iostream>
#include "tools/max_matching.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::max_matching graph(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  const auto answer = graph.query();
  std::cout << answer.size() << '\n';
  for (const auto& [a, b] : answer) {
    std::cout << a << ' ' << b << '\n';
  }

  return 0;
}
