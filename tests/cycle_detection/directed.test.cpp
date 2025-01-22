// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cycle_detection

#include <iostream>
#include "tools/cycle_detection.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::cycle_detection<true> graph(N);
  for (ll i = 0; i < M; ++i) {
    ll u, v;
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
