#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <cstdint>
#include <iostream>
#include <algorithm>
#include <limits>
#include "tools/bellman_ford.hpp"

using i64 = std::int_fast64_t;

int main() {
  i64 V_size, E_size, r;
  std::cin >> V_size >> E_size >> r;

  tools::bellman_ford<i64> bf(V_size);
  for (i64 i = 0; i < E_size; ++i) {
    i64 s, t, d;
    std::cin >> s >> t >> d;
    bf.add_edge(s, t, d);
  }

  const auto result = bf.query(r);
  if (std::any_of(result.distances.begin(), result.distances.end(), [](const i64& distance) { return distance == std::numeric_limits<i64>::min(); })) {
    std::cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (const i64& distance : result.distances) {
      if (distance == std::numeric_limits<i64>::max()) {
        std::cout << "INF" << '\n';
      } else {
        std::cout << distance << '\n';
      }
    }
  }

  return 0;
}
