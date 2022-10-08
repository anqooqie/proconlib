#define PROBLEM "https://atcoder.jp/contests/abc204/tasks/abc204_c"

#include <iostream>
#include "tools/scc_graph.hpp"
#include "tools/dynamic_bitset.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::scc_graph graph(N);
  for (ll i = 0; i < M; ++i) {
    ll A, B;
    std::cin >> A >> B;
    --A, --B;
    graph.add_edge(A, B);
  }

  graph.build();

  std::vector<tools::dynamic_bitset> dp(graph.sccs().size(), tools::dynamic_bitset(N));
  for (ll i = graph.sccs().size() - 1; i >= 0; --i) {
    for (const auto v : graph.sccs()[i]) {
      dp[i].set(v);
    }
    for (const auto& [j, unused] : graph.edges_to_scc(i)) {
      dp[j] |= dp[i];
    }
  }

  ll answer = 0;
  for (ll i = 0; i < N; ++i) {
    answer += dp[graph.scc_id(i)].count();
  }
  std::cout << answer << '\n';
  return 0;
}
