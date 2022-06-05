#define PROBLEM "https://atcoder.jp/contests/abc204/tasks/abc204_c"

#include <cstdint>
#include <iostream>
#include "tools/scc_graph.hpp"
#include "tools/dynamic_bitset.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  tools::scc_graph graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 A, B;
    std::cin >> A >> B;
    --A, --B;
    graph.add_edge(A, B);
  }

  graph.build();

  std::vector<tools::dynamic_bitset> dp(graph.sccs().size(), tools::dynamic_bitset(N));
  for (i64 i = graph.sccs().size() - 1; i >= 0; --i) {
    for (const auto v : graph.sccs()[i]) {
      dp[i].set(v);
    }
    for (const auto& [j, unused] : graph.edges_to_scc(i)) {
      dp[j] |= dp[i];
    }
  }

  i64 answer = 0;
  for (i64 i = 0; i < N; ++i) {
    answer += dp[graph.scc_id(i)].count();
  }
  std::cout << answer << '\n';
  return 0;
}
