#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "atcoder/dsu.hpp"
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

  atcoder::dsu dsu(N);
  for (int k = 0; tools::cmp_less(k, graph.edges().size()); ++k) {
    if (!graph.is_bridge(k)) {
      const auto& edge = graph.get_edge(k);
      dsu.merge(edge.from, edge.to);
    }
  }

  const auto groups = dsu.groups();
  std::cout << groups.size() << '\n';
  for (const auto& group : groups) {
    std::cout << group.size() << ' ' << tools::join(group.begin(), group.end(), " ") << '\n';
  }

  return 0;
}
