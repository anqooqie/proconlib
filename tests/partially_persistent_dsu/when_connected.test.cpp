// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc394/tasks/abc394_g

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/less_equal_zeta_inplace.hpp"
#include "tools/lower_bound.hpp"
#include "tools/partially_persistent_dsu.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const int H = 3;
  const int W = 3;
  const std::vector<std::vector<int>> F = {
    {12, 10, 6},
    {1, 1, 3},
    {8, 6, 7},
  };

  const auto p = [&](const auto y, const auto x) {
    return y * W + x;
  };

  std::vector<std::vector<std::pair<int, int>>> edges(1000000);
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (y - 1 >= 0) {
        edges[1000000 - std::min(F[y][x], F[y - 1][x])].emplace_back(p(y, x), p(y - 1, x));
      }
      if (x - 1 >= 0) {
        edges[1000000 - std::min(F[y][x], F[y][x - 1])].emplace_back(p(y, x), p(y, x - 1));
      }
    }
  }

  std::vector<int> tally(1000001, 0);
  for (int f = 0; f < 1000000; ++f) {
    tally[f + 1] = edges[f].size();
  }
  tools::less_equal_zeta_inplace(tally);

  tools::partially_persistent_dsu dsu(H * W);
  for (const auto& edges_at_f : edges) {
    for (const auto& [u, v] : edges_at_f) {
      dsu.merge(u, v);
    }
  }

  const auto query = [&](const int A, const int B, const int Y, const int C, const int D, const int Z) {
    const auto f = 1000001 - tools::lower_bound(tally, dsu.when_connected(p(A, B), p(C, D)));
    return Y <= f && Z <= f ? std::abs(Y - Z) : std::abs(Y - f) + std::abs(Z - f);
  };

  assert_that(query(0, 0, 10, 2, 0, 6) == 10);
  assert_that(query(0, 0, 6, 0, 1, 4) == 2);

  return 0;
}
