// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc270/tasks/abc270_c
// competitive-verifier: IGNORE

#include <iostream>
#include <ranges>
#include "tools/join.hpp"
#include "tools/zero_one_bfs.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, X, Y;
  std::cin >> N >> X >> Y;
  --X, --Y;
  tools::zero_one_bfs<false, int> graph(N);
  for (int i = 0; i < N - 1; ++i) {
    int U, V;
    std::cin >> U >> V;
    --U, --V;
    graph.add_edge(U, V, 1);
  }

  std::cout << tools::join(graph.query<true>(X).vertex_path(Y) | std::views::transform([](const auto v) { return v + 1; }), " ") << '\n';

  return 0;
}
