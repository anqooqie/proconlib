// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/tree_diameter

#include <algorithm>
#include <iostream>
#include <iterator>
#include "tools/dijkstra.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::dijkstra<false, ll> graph(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph.add_edge(a, b, c);
  }

  const auto dist_from_0 = graph.query(0);
  const auto u = std::distance(dist_from_0.begin(), std::ranges::max_element(dist_from_0));
  const auto res_from_u = graph.query<true>(u);
  const auto v = std::distance(res_from_u.dist().begin(), std::ranges::max_element(res_from_u.dist()));
  const auto path = res_from_u.vertex_path(v);

  std::cout << res_from_u.dist(v) << ' ' << path.size() << '\n';
  std::cout << tools::join(path, ' ') << '\n';

  return 0;
}
