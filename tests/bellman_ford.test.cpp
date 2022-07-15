#define PROBLEM "https://atcoder.jp/contests/abc137/tasks/abc137_e"

#include <cstdint>
#include <iostream>
#include <limits>
#include <algorithm>
#include "tools/bellman_ford.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M, P;
  std::cin >> N >> M >> P;
  tools::bellman_ford<i64> graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 A, B, C;
    std::cin >> A >> B >> C;
    --A, --B;
    graph.add_edge(A, B, -C + P);
  }

  const auto [dist, prev] = graph.query(0);
  if (dist[N - 1] == std::numeric_limits<i64>::min()) {
    std::cout << -1 << '\n';
  } else {
    std::cout << std::max<i64>(0, -dist[N - 1]) << '\n';
  }

  return 0;
}
