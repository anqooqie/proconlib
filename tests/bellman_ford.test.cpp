// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc137/tasks/abc137_e

#include <iostream>
#include <limits>
#include <algorithm>
#include "tools/bellman_ford.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M, P;
  std::cin >> N >> M >> P;
  tools::bellman_ford<ll> graph(N);
  for (ll i = 0; i < M; ++i) {
    ll A, B, C;
    std::cin >> A >> B >> C;
    --A, --B;
    graph.add_edge(A, B, -C + P);
  }

  const auto [dist, prev] = graph.query(0);
  if (dist[N - 1] == std::numeric_limits<ll>::min()) {
    std::cout << -1 << '\n';
  } else {
    std::cout << std::max<ll>(0, -dist[N - 1]) << '\n';
  }

  return 0;
}
