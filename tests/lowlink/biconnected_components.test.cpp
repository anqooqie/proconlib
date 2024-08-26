#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <iostream>
#include "tools/lowlink.hpp"
#include "tools/cmp_less.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::lowlink graph(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b);
  }

  graph.build();

  const auto groups = graph.biconnected_components();
  std::cout << groups.size() << '\n';
  for (const auto& group : groups) {
    std::cout << group.size() << ' ' << tools::join(group.begin(), group.end(), " ") << '\n';
  }

  return 0;
}
