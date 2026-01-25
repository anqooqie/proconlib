// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc270/tasks/abc270_c

#include <iostream>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/zero_one_bfs.hpp"

std::vector<int> solve(const int N, const int X, const int Y, const std::vector<std::pair<int, int>>& edges) {
  tools::zero_one_bfs<false, int> graph(N);
  for (const auto& [U, V] : edges) {
    graph.add_edge(U, V, 1);
  }
  return graph.query<true>(X).vertex_path(Y);
}

void sample01() {
  const int N = 5;
  const int X = 1;
  const int Y = 4;
  const std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
  assert_that(solve(N, X, Y, edges) == std::vector<int>{1, 0, 2, 4});
}

void sample02() {
  const int N = 6;
  const int X = 0;
  const int Y = 1;
  const std::vector<std::pair<int, int>> edges = {{2, 0}, {1, 4}, {0, 1}, {3, 0}, {1, 5}};
  assert_that(solve(N, X, Y, edges) == std::vector<int>{0, 1});
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample01();
  sample02();

  return 0;
}
