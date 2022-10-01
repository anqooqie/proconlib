#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"

#include <cstdint>
#include <iostream>
#include "tools/prim.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 V, E;
  std::cin >> V >> E;
  tools::prim<i64> prim(V);
  for (i64 i = 0; i < E; ++i) {
    i64 s, t, w;
    std::cin >> s >> t >> w;
    prim.add_edge(s, t, w);
  }

  std::cout << prim.query().first[0].first << '\n';
  return 0;
}
