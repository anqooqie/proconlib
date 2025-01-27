// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/1040

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "atcoder/dsu.hpp"
#include "tools/assert_that.hpp"
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
    auto qr = graph.query<true>(terminals);
    std::ranges::sort(qr.vertices);
    std::ranges::sort(qr.edge_ids);
    assert_that(qr.vertices.size() == qr.edge_ids.size() + 1);
    assert_that(std::ranges::all_of(qr.vertices, [&](const auto v) { return 0 <= v && v < H * W; }));
    assert_that(std::ranges::adjacent_find(qr.vertices) == qr.vertices.end());
    assert_that(std::ranges::includes(qr.vertices, terminals));
    assert_that(std::ranges::all_of(qr.edge_ids, [&](const auto e) { return 0 <= e && std::cmp_less(e, graph.edges().size()); }));
    assert_that(std::ranges::adjacent_find(qr.edge_ids) == qr.edge_ids.end());
    assert_that(std::accumulate(qr.edge_ids.begin(), qr.edge_ids.end(), 0, [&](const auto sum, const auto e) { return sum + graph.get_edge(e).cost; }) == qr.cost);
    auto component = [&]() {
      atcoder::dsu dsu(H * W);
      for (const auto edge_id : qr.edge_ids) {
        const auto& edge = graph.get_edge(edge_id);
        dsu.merge(edge.from, edge.to);
      }
      for (const auto& group : dsu.groups()) {
        if (std::ranges::find(group, terminals[0]) != group.end()) {
          return group;
        }
      }
      std::exit(EXIT_FAILURE);
    }();
    std::ranges::sort(component);
    assert_that(qr.vertices == component);
    std::cout << H * W - qr.vertices.size() << '\n';
  }

  return 0;
}
