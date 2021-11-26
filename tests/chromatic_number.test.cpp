#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <cstdint>
#include <iostream>
#include "tools/chromatic_number.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, M;
  std::cin >> N >> M;
  tools::chromatic_number graph(N);
  for (i64 i = 0; i < M; ++i) {
    i64 u, v;
    std::cin >> u >> v;
    graph.add_edge(u, v);
  }

  std::cout << graph.query() << '\n';
  return 0;
}
