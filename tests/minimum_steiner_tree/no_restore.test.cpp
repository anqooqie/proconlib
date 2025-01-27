// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1040

#include <iostream>
#include <vector>
#include "atcoder/dsu.hpp"
#include "tools/minimum_steiner_tree.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  while (true) {
    int H, W;
    std::cin >> H >> W;
    if (H == 0 && W == 0) break;

    std::vector grid(H, std::vector<int>(W));
    for (auto&& row : grid) for (auto&& cell : row) std::cin >> cell;

    std::vector<int> terminals;
    for (int r = 0; r < H; ++r) {
      for (int c = 0; c < W; ++c) {
        if (grid[r][c] == 1) terminals.push_back(r * W + c);
      }
    }

    tools::minimum_steiner_tree<int> graph(H * W);
    for (int r = 0; r < H; ++r) {
      for (int c = 0; c < W; ++c) {
        if (r > 0) graph.add_edge(r * W + c, (r - 1) * W + c, 1);
        if (c > 0) graph.add_edge(r * W + c, r * W + (c - 1), 1);
      }
    }

    std::cout << H * W - graph.query(terminals) - 1 << '\n';
  }

  return 0;
}
