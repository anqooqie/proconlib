// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B

#include <algorithm>
#include <iostream>
#include <limits>
#include "tools/bellman_ford.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, r;
  std::cin >> N >> M >> r;
  tools::bellman_ford<int> graph(N);
  for (int i = 0; i < M; ++i) {
    int s, t, d;
    std::cin >> s >> t >> d;
    graph.add_edge(s, t, d);
  }

  const auto dist = graph.query(r);
  if (std::ranges::find(dist, std::numeric_limits<int>::min()) != dist.end()) {
    std::cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (const auto d : dist) {
      if (d == std::numeric_limits<int>::max()) {
        std::cout << "INF" << '\n';
      } else {
        std::cout << d << '\n';
      }
    }
  }

  return 0;
}
