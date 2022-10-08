#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include <variant>
#include <vector>
#include "tools/weighted_bipartite_matching.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;

  tools::weighted_bipartite_matching<ll> graph(N, N, false);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      ll a_ij;
      std::cin >> a_ij;
      graph.add_edge(i, j, a_ij);
    }
  }

  std::vector<ll> p(N);
  const auto [cost, edges] = *graph.query(N);
  for (const auto& edge : edges) {
    p[edge.from] = edge.to;
  }

  std::cout << cost << '\n';
  std::cout << tools::join(p.begin(), p.end(), " ") << '\n';
  return 0;
}
