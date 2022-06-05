#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <cstdint>
#include <iostream>
#include "tools/scc_graph.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  tools::scc_graph graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 a, b;
    std::cin >> a >> b;
    graph.add_edge(a, b);
  }

  graph.build();

  std::cout << graph.sccs().size() << '\n';
  for (const auto& scc : graph.sccs()) {
    std::cout << scc.size();
    for (const auto v : scc) {
      std::cout << ' ' << v;
    }
    std::cout << '\n';
  }
  return 0;
}
