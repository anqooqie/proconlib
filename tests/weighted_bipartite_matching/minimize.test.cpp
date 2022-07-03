#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <cstdint>
#include <iostream>
#include <variant>
#include <vector>
#include "tools/weighted_bipartite_matching.hpp"
#include "tools/join.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;

  tools::weighted_bipartite_matching<i64> graph(N, N, false);
  for (i64 i = 0; i < N; ++i) {
    for (i64 j = 0; j < N; ++j) {
      i64 a_ij;
      std::cin >> a_ij;
      graph.add_edge(i, j, a_ij);
    }
  }

  std::vector<i64> p(N);
  const auto [cost, edges] = *graph.query(N);
  for (const auto& edge : edges) {
    p[edge.from] = edge.to;
  }

  std::cout << cost << '\n';
  std::cout << tools::join(p.begin(), p.end(), " ") << '\n';
  return 0;
}
