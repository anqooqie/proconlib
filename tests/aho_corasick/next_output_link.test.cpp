// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/430

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <vector>
#include "tools/aho_corasick.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string S;
  int M;
  std::cin >> S >> M;
  tools::aho_corasick<[](const char c) { return c - 'A'; }> ac;
  for (int i = 0; i < M; ++i) {
    std::string C_i;
    std::cin >> C_i;
    ac.add_pattern(C_i);
  }
  ac.build();

  std::vector<int> dp(ac.nodes().size(), 0);
  int v = 0;
  for (const auto S_i : S) {
    v = ac.get_node(v).next[ac.encode(S_i)];
    ++dp[v];
  }

  for (const int v : ac.bfs_ordered() | std::views::reverse) {
    const auto& node = ac.get_node(v);
    if (node.output_link >= 0) {
      dp[node.output_link] += dp[v];
    }
  }

  std::cout << std::ranges::fold_left(std::views::iota(0, M) | std::views::transform([&](const auto k) { return dp[ac.pattern_to_node(k)]; }), 0, std::plus{}) << '\n';
  return 0;
}
