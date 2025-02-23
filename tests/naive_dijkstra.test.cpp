// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc325/tasks/abc325_e
// competitive-verifier: IGNORE

#include <iostream>
#include <vector>
#include <limits>
#include "tools/naive_dijkstra.hpp"
#include "tools/chmin.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, A, B, C;
  std::cin >> N >> A >> B >> C;
  auto D = std::vector(N, std::vector<ll>(N));
  for (auto& D_i : D) for (auto& D_ij : D_i) std::cin >> D_ij;

  tools::naive_dijkstra<true, ll> graph1(N);
  tools::naive_dijkstra<true, ll> graph2(N);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      graph1.add_edge(i, j, D[i][j] * A);
      graph2.add_edge(i, j, D[j][i] * B + C);
    }
  }

  const auto dist1 = graph1.query(0);
  const auto dist2 = graph2.query(N - 1);
  ll answer = std::numeric_limits<ll>::max();
  for (ll i = 0; i < N; ++i) {
    tools::chmin(answer, dist1[i] + dist2[i]);
  }
  std::cout << answer << '\n';

  return 0;
}
