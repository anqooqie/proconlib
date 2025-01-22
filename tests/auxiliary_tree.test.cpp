// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc340/tasks/abc340_g

#include <iostream>
#include <vector>
#include <array>
#include "atcoder/modint.hpp"
#include "tools/auxiliary_tree.hpp"
#include "tools/fix.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto&& A_i : A) {
    std::cin >> A_i;
    --A_i;
  }
  tools::auxiliary_tree graph(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    graph.add_edge(u, v);
  }

  graph.build(0);

  std::vector<std::vector<int>> colors(N);
  for (int v = 0; v < N; ++v) {
    colors[A[v]].push_back(v);
  }
  auto answer = mint::raw(0);
  std::vector<std::array<mint, 3>> dp(N);
  for (int c = 0; c < N; ++c) {
    if (!colors[c].empty()) {
      const auto aux = graph.query(colors[c]);
      tools::fix([&](auto&& dfs, const auto v) -> void {
        dp[v][0] = mint::raw(0);
        dp[v][1] = mint::raw(0);
        dp[v][2] = mint::raw(1);
        for (const auto u : aux.children(v)) {
          dfs(u);
          dp[v][0] += dp[u][0] + mint::raw(A[u] == c) * (mint::raw(1) + dp[u][1]) + dp[u][2];
          dp[v][1] += mint::raw(A[u] == c) + dp[u][1] + dp[u][2];
          dp[v][2] *= mint::raw(A[u] == c) + dp[u][1] + dp[u][2] + mint::raw(1);
        }
        dp[v][2] -= dp[v][1];
        --dp[v][2];
      })(aux.root());
      answer += dp[aux.root()][0] + mint::raw(A[aux.root()] == c) * (mint::raw(1) + dp[aux.root()][1]) + dp[aux.root()][2];
    }
  }

  std::cout << answer.val() << '\n';
  return 0;
}
