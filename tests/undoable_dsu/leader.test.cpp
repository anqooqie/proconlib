// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc302/tasks/abc302_h

#include <iostream>
#include <ranges>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/fix.hpp"
#include "tools/hld.hpp"
#include "tools/undoable_dsu.hpp"

std::vector<int> solve(const int N, const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& U, const std::vector<int>& V) {
  tools::hld graph(N);
  for (int i = 0; i < N - 1; ++i) {
    graph.add_edge(U[i], V[i]);
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

  return answers | std::views::drop(1) | std::ranges::to<std::vector>();
}

void sample01() {
  const int N = 4;
  const std::vector<int> A{0, 1, 2, 0};
  const std::vector<int> B{1, 2, 0, 1};
  const std::vector<int> U{0, 1, 2};
  const std::vector<int> V{1, 2, 3};
  assert_that(solve(N, A, B, U, V) == std::vector<int>{2, 3, 3});
}

void sample02() {
  const int N = 10;
  const std::vector<int> A{1, 1, 7, 3, 5, 7, 8, 0, 8, 4};
  const std::vector<int> B{4, 1, 7, 2, 9, 0, 9, 6, 2, 9};
  const std::vector<int> U{8, 0, 2, 3, 2, 9, 4, 6, 8};
  const std::vector<int> V{2, 8, 5, 0, 7, 8, 3, 1, 6};
  assert_that(solve(N, A, B, U, V) == std::vector<int>{4, 3, 2, 3, 4, 3, 4, 2, 3});
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample01();
  sample02();

  return 0;
}
