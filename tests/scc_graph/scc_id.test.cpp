#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include <cstdint>
#include <iostream>
#include "tools/scc_graph.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 V, E;
  std::cin >> V >> E;
  tools::scc_graph graph(V);
  for (i64 i = 0; i < E; ++i) {
    i64 s, t;
    std::cin >> s >> t;
    graph.add_edge(s, t);
  }

  graph.build();

  i64 Q;
  std::cin >> Q;
  for (i64 q = 0; q < Q; ++q) {
    i64 u, v;
    std::cin >> u >> v;
    std::cout << (graph.scc_id(u) == graph.scc_id(v) ? 1 : 0) << '\n';
  }

  return 0;
}
