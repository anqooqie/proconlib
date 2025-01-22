// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc302/tasks/abc302_ex

#include <iostream>
#include <vector>
#include "tools/hld.hpp"
#include "tools/undoable_dsu.hpp"
#include "tools/fix.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  tools::hld graph(N);
  for (int i = 0; i < N - 1; ++i) {
    int U, V;
    std::cin >> U >> V;
    --U, --V;
    graph.add_edge(U, V);
  }
  graph.build(0);

  std::vector<int> answers(N);
  std::vector<bool> has_cycle(N, false);
  tools::undoable_dsu dsu(N);
  tools::fix([&](auto&& dfs, const int v) -> void {
    const auto same = dsu.same(A[v], B[v]);
    const bool has_cycle_A = has_cycle[dsu.leader(A[v])];
    const bool has_cycle_B = has_cycle[dsu.leader(B[v])];

    dsu.merge(A[v], B[v]);
    answers[v] = (v == 0 ? 0 : answers[graph.vparent(v)]);
    if (same || has_cycle_A || has_cycle_B) {
      has_cycle[dsu.leader(A[v])] = true;
    }
    if (!has_cycle_A || !has_cycle_B) {
      ++answers[v];
    }

    for (const auto c : graph.vchildren(v)) {
      dfs(c);
    }

    dsu.undo();
    has_cycle[dsu.leader(A[v])] = has_cycle_A;
    has_cycle[dsu.leader(B[v])] = has_cycle_B;
  })(0);

  std::cout << tools::join(answers.begin() + 1, answers.end(), " ") << '\n';
  return 0;
}
