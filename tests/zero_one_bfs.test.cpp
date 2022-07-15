#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2945"

#include <cstdint>
#include <iostream>
#include <array>
#include <utility>
#include <tuple>
#include "tools/zero_one_bfs.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const auto P = [](const i64 x, const i64 y) {
    return 100 * y + x;
  };
  for (i64 N; std::cin >> N, N > 0;) {
    i64 A, B, C, D;
    std::cin >> A >> B >> C >> D;
    --A, --B;
    tools::zero_one_bfs<i64> graph(100 * 100);
    for (i64 x = 0; x < 100; ++x) {
      for (i64 y = 0; y < 100; ++y) {
        for (const auto& [dx, dy] : std::array<std::pair<i64, i64>, 4>({std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {
          if (0 <= x + dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {
            graph.add_edge(P(x, y), P(x + dx, y + dy), A <= x + dx && x + dx < C && B <= y + dy && y + dy < D ? 0 : 1);
          }
        }
      }
    }

    i64 answer = 0;
    i64 pX, pY;
    std::cin >> pX >> pY;
    --pX, --pY;
    for (i64 i = 0; i < N; ++i) {
      i64 X, Y;
      std::cin >> X >> Y;
      --X, --Y;
      answer += graph.query(P(pX, pY)).first[P(X, Y)];
      std::tie(pX, pY) = std::make_pair(X, Y);
    }

    std::cout << answer << '\n';
  }

  return 0;
}
